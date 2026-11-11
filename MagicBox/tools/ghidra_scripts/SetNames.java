import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

/** Apply "hexaddr<TAB>newname" renames to functions. */
public class SetNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) { println("usage: SetNames.java <map.tsv>"); return; }
        List<String> lines = Files.readAllLines(Paths.get(args[0]), StandardCharsets.UTF_8);
        FunctionManager fm = currentProgram.getFunctionManager();
        int ok = 0, miss = 0, fail = 0;
        for (String line : lines) {
            if (line.isBlank()) continue;
            String[] p = line.split("\t");
            if (p.length < 2) continue;
            Address a = toAddr(Long.parseLong(p[0].replace("0x", ""), 16));
            Function f = fm.getFunctionAt(a);
            if (f == null) f = fm.getFunctionContaining(a);
            if (f == null) { miss++; continue; }
            try {
                f.setName(p[1].trim(), SourceType.USER_DEFINED);
                ok++;
            } catch (Exception e) {
                fail++;
            }
        }
        println("RENAMED=" + ok + " MISSING=" + miss + " FAILED=" + fail);
    }
}
