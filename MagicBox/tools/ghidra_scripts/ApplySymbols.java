import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.SourceType;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

/**
 * Rename functions from a "name<TAB>rodata_vaddr<TAB>code_addrs" table.
 * Prefers resolving references to the rodata string; falls back to the
 * literal-pool code addresses recovered by the external l32r scanner.
 * A function is renamed only when exactly one distinct owner is found.
 */
public class ApplySymbols extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: ApplySymbols.java <symbols.tsv> [report.txt]");
            return;
        }
        String reportPath = args.length > 1 ? args[1] : null;
        List<String> lines = Files.readAllLines(Paths.get(args[0]), StandardCharsets.UTF_8);
        FunctionManager fm = currentProgram.getFunctionManager();
        int renamed = 0, same = 0, conflict = 0, unresolved = 0, badAddr = 0, fallbackUsed = 0;
        List<String> report = new ArrayList<>();
        for (String line : lines) {
            if (line.isBlank()) continue;
            String[] parts = line.split("\t");
            if (parts.length < 2) continue;
            String name = parts[0].trim();
            Set<Function> owners = new LinkedHashSet<>();
            try {
                Address dataAddr = toAddr(Long.parseLong(parts[1].trim().replace("0x", ""), 16));
                for (Reference r : getReferencesTo(dataAddr)) {
                    collect(fm, r.getFromAddress(), owners);
                }
                if (owners.isEmpty() && parts.length > 2 && !parts[2].isBlank()) {
                    fallbackUsed++;
                    for (String c : parts[2].split(",")) {
                        Address ca = toAddr(Long.parseLong(c.trim().replace("0x", ""), 16));
                        if (ca != null) collect(fm, ca, owners);
                    }
                }
            } catch (Exception e) {
                badAddr++;
                continue;
            }
            if (owners.isEmpty()) {
                unresolved++;
                report.add("UNRESOLVED\t" + name);
                continue;
            }
            if (owners.size() > 1) {
                conflict++;
                StringBuilder sb = new StringBuilder("CONFLICT\t" + name + "\t");
                for (Function f : owners) sb.append(f.getEntryPoint()).append(",");
                report.add(sb.toString());
                continue;
            }
            Function f = owners.iterator().next();
            if (f.getName().equals(name)) { same++; continue; }
            try {
                f.setName(name, SourceType.USER_DEFINED);
                renamed++;
            } catch (Exception e) {
                report.add("RENAME_FAILED\t" + name + "\t" + e.getMessage());
            }
        }
        println("RENAMED=" + renamed + " SAME=" + same + " CONFLICT=" + conflict
                + " UNRESOLVED=" + unresolved + " BADADDR=" + badAddr + " FALLBACK=" + fallbackUsed);
        report.add("TOTALS\trenamed=" + renamed + "\tsame=" + same + "\tconflict=" + conflict
                + "\tunresolved=" + unresolved + "\tbad=" + badAddr + "\tfallback=" + fallbackUsed);
        if (reportPath != null) {
            Files.write(Paths.get(reportPath), report, StandardCharsets.UTF_8);
            println("report: " + reportPath);
        }
    }

    private void collect(FunctionManager fm, Address from, Set<Function> owners) {
        Function f = fm.getFunctionAt(from);
        if (f == null) f = fm.getFunctionContaining(from);
        if (f != null) owners.add(f);
    }
}
