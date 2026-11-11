import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

public class CountFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        int n = 0;
        for (Function f : fm.getFunctions(true)) {
            n++;
        }
        println("FUNCTION_COUNT=" + n);
        println("LANGUAGE=" + currentProgram.getLanguageID());
        println("IMAGEBASE=" + currentProgram.getImageBase());
    }
}
