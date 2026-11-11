import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

/** Print the function name containing each supplied address. */
public class NameAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String arg : getScriptArgs()) {
            Address a = toAddr(Long.parseLong(arg.replace("0x", ""), 16));
            Function f = fm.getFunctionAt(a);
            String kind = "entry";
            if (f == null) { f = fm.getFunctionContaining(a); kind = "inside"; }
            if (f == null) { println(arg + "\t<none>"); continue; }
            println(arg + "\t" + kind + "\t" + f.getEntryPoint() + "\t" + f.getName());
        }
    }
}
