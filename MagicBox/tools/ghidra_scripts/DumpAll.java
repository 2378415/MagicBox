import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;

import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * Decompile every function to <outdir>/<entry>_<name>.c, and write
 * _index.csv (metadata) plus _edges.csv (call graph).
 */
public class DumpAll extends GhidraScript {

    private String readCString(Address a, int max) {
        Memory mem = currentProgram.getMemory();
        byte[] buf = new byte[max];
        int n;
        try {
            n = mem.getBytes(a, buf);
        } catch (Exception e) {
            return null;
        }
        int len = 0;
        while (len < n && buf[len] >= 0x20 && buf[len] < 0x7f) len++;
        if (len < 4) return null;
        return new String(buf, 0, len, StandardCharsets.US_ASCII);
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) { println("usage: DumpAll.java <outdir>"); return; }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        DecompInterface di = new DecompInterface();
        di.toggleCCode(true);
        di.toggleSyntaxTree(true);
        di.setSimplificationStyle("decompile");
        di.openProgram(currentProgram);

        PrintWriter idx = new PrintWriter(new File(outDir, "_index.csv"), "UTF-8");
        PrintWriter edges = new PrintWriter(new File(outDir, "_edges.csv"), "UTF-8");
        idx.println("entry,name,size,callers,callees,file,strings");
        edges.println("caller,callee");

        int total = 0, ok = 0, failed = 0;
        long t0 = System.currentTimeMillis();
        for (Function f : fm.getFunctions(true)) {
            if (f.isExternal() || f.isThunk()) continue;
            total++;
            String clean = f.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
            String fileName = String.format("%08x_%s.c", f.getEntryPoint().getOffset(), clean);
            long size = f.getBody().getNumAddresses();
            int ncallers = 0, ncallees = 0;
            List<Function> callees = new ArrayList<>();
            try { ncallers = f.getCallingFunctions(monitor).size(); } catch (Exception ignore) { }
            try {
                callees = new ArrayList<>(f.getCalledFunctions(monitor));
                ncallees = callees.size();
            } catch (Exception ignore) { }

            List<String> strs = new ArrayList<>();
            for (Instruction ins = listing.getInstructionAt(f.getEntryPoint());
                 ins != null && f.getBody().contains(ins.getAddress());
                 ins = ins.getNext()) {
                for (Reference r : ins.getReferencesFrom()) {
                    Address to = r.getToAddress();
                    if (to == null || !currentProgram.getMemory().contains(to)) continue;
                    String s = readCString(to, 48);
                    if (s != null && !strs.contains(s)) strs.add(s);
                }
                if (strs.size() >= 16) break;
            }
            String joined = String.join(" | ", strs).replace("\"", "'");

            DecompileResults res = di.decompileFunction(f, 45, monitor);
            String body;
            if (res != null && res.decompileCompleted()) {
                body = res.getDecompiledFunction().getC();
                ok++;
            } else {
                body = "/* decompile failed: " + (res == null ? "null" : res.getErrorMessage()) + " */\n";
                failed++;
            }
            try (PrintWriter pw = new PrintWriter(new File(outDir, fileName), "UTF-8")) {
                pw.println("// " + f.getEntryPoint() + "  " + f.getName() + "  size=" + size);
                if (!strs.isEmpty()) pw.println("// strings: " + joined);
                pw.println(body);
            }
            idx.println(String.format("%s,%s,%d,%d,%d,%s,\"%s\"",
                    f.getEntryPoint(), f.getName(), size, ncallers, ncallees, fileName, joined));
            for (Function c : callees) {
                edges.println(f.getEntryPoint() + "," + c.getEntryPoint());
            }
            if (total % 400 == 0) println("progress " + total + " ok=" + ok + " failed=" + failed);
        }
        idx.close();
        edges.close();
        di.dispose();
        println("DONE total=" + total + " ok=" + ok + " failed=" + failed
                + " seconds=" + ((System.currentTimeMillis() - t0) / 1000));
    }
}
