import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

/** Dump C pseudocode for functions containing the given addresses. */
public class DumpDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: DumpDecomp.java <outdir> <hexaddr> [hexaddr...]");
            return;
        }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (int i = 1; i < args.length; i++) {
            String hex = args[i].trim().replace("0x", "");
            Address a = toAddr(Long.parseLong(hex, 16));
            Function f = fm.getFunctionAt(a);
            if (f == null) f = fm.getFunctionContaining(a);
            if (f == null) {
                println("NOFUNC " + args[i]);
                continue;
            }
            DecompileResults res = di.decompileFunction(f, 60, monitor);
            String body = res.decompileCompleted() ? res.getDecompiledFunction().getC()
                    : ("// decompile failed: " + res.getErrorMessage());
            String fileName = String.format("%08x_%s.c",
                    f.getEntryPoint().getOffset(), f.getName().replaceAll("[^A-Za-z0-9_.-]", "_"));
            try (PrintWriter pw = new PrintWriter(new File(outDir, fileName), "UTF-8")) {
                pw.println("// entry: " + f.getEntryPoint() + "  name: " + f.getName());
                pw.println(body);
            }
            println("WROTE " + fileName + " <- " + f.getEntryPoint() + " " + f.getName());
        }
        di.dispose();
    }
}
