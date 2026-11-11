import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;

import java.io.File;
import java.io.PrintWriter;

/** Dump the raw instruction listing of the function containing each address. */
public class DumpAsm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) { println("usage: DumpAsm.java <outdir> <hexaddr> [...]"); return; }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        for (int i = 1; i < args.length; i++) {
            Address a = toAddr(Long.parseLong(args[i].replace("0x", ""), 16));
            Function f = fm.getFunctionAt(a);
            if (f == null) f = fm.getFunctionContaining(a);
            if (f == null) { println("NOFUNC " + args[i]); continue; }
            AddressSetView body = f.getBody();
            String name = String.format("%08x_%s.asm", f.getEntryPoint().getOffset(),
                    f.getName().replaceAll("[^A-Za-z0-9_.-]", "_"));
            try (PrintWriter pw = new PrintWriter(new File(outDir, name), "UTF-8")) {
                pw.println("// entry " + f.getEntryPoint() + " name " + f.getName()
                        + " size " + body.getNumAddresses());
                Instruction ins = listing.getInstructionAt(f.getEntryPoint());
                int n = 0;
                while (ins != null && body.contains(ins.getAddress()) && n < 4000) {
                    pw.println(ins.getAddress() + "  " + ins.toString());
                    ins = ins.getNext();
                    n++;
                }
                pw.println("// instructions: " + n);
            }
            println("WROTE " + name + " size=" + body.getNumAddresses());
        }
    }
}
