import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.Reference;

import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedHashSet;
import java.util.Set;

/** List callers/references of a function and dump the distinct caller functions. */
public class Callers extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) { println("usage: Callers.java <hexaddr> [outdir]"); return; }
        Address target = toAddr(Long.parseLong(args[0].replace("0x", ""), 16));
        FunctionManager fm = currentProgram.getFunctionManager();
        Function self = fm.getFunctionAt(target);
        if (self == null) self = fm.getFunctionContaining(target);
        println("TARGET " + (self == null ? "none" : self.getEntryPoint() + " " + self.getName()));
        Set<Function> callers = new LinkedHashSet<>();
        for (Reference r : getReferencesTo(target)) {
            Function f = fm.getFunctionContaining(r.getFromAddress());
            println("  ref from " + r.getFromAddress() + " in " + (f == null ? "?" : f.getEntryPoint() + " " + f.getName()));
            if (f != null) callers.add(f);
        }
        if (args.length > 1) {
            File outDir = new File(args[1]);
            outDir.mkdirs();
            DecompInterface di = new DecompInterface();
            di.openProgram(currentProgram);
            for (Function f : callers) {
                DecompileResults res = di.decompileFunction(f, 60, monitor);
                String body = res.decompileCompleted() ? res.getDecompiledFunction().getC() : "// failed";
                String name = String.format("%08x_%s.c", f.getEntryPoint().getOffset(),
                        f.getName().replaceAll("[^A-Za-z0-9_.-]", "_"));
                try (PrintWriter pw = new PrintWriter(new File(outDir, name), "UTF-8")) {
                    pw.println("// entry: " + f.getEntryPoint() + " name: " + f.getName());
                    pw.println(body);
                }
                println("WROTE " + name);
            }
            di.dispose();
        }
    }
}
