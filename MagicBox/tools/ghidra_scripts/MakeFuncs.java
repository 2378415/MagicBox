import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Listing;

import java.io.File;
import java.io.PrintWriter;

/**
 * Create functions at addresses that are only reachable through a jump table
 * (Ghidra never makes a function there because nothing calls them directly),
 * then dump their decompiled C.
 *
 * usage: MakeFuncs.java <outdir> <hexaddr> [hexaddr...]
 */
public class MakeFuncs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: MakeFuncs.java <outdir> <hexaddr> [hexaddr...]");
            return;
        }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        Listing listing = currentProgram.getListing();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (int i = 1; i < args.length; i++) {
            String hex = args[i].trim().replace("0x", "");
            Address a = toAddr(Long.parseLong(hex, 16));
            Function f = getFunctionAt(a);
            if (f == null) {
                disassemble(a);
                f = createFunction(a, null);
            }
            if (f == null) {
                println("NOFUNC " + hex);
                continue;
            }
            DecompileResults res = di.decompileFunction(f, 60, monitor);
            String body = res.decompileCompleted() ? res.getDecompiledFunction().getC()
                    : "/* decompile failed: " + res.getErrorMessage() + " */";
            String name = String.format("%08x_%s.c", f.getEntryPoint().getOffset(),
                    f.getName().replaceAll("[^A-Za-z0-9_.-]", "_"));
            try (PrintWriter pw = new PrintWriter(new File(outDir, name), "UTF-8")) {
                pw.println("// " + f.getEntryPoint() + "  " + f.getName()
                        + "  size=" + f.getBody().getNumAddresses());
                pw.println(body);
            }
            println("WROTE " + name);
        }
        di.dispose();
    }
}
