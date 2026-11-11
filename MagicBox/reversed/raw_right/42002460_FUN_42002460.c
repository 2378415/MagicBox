// 42002460  FUN_42002460  FUN_42002460  size=80
// strings: Debug exception reason:  | SingleStep  | HwBreakpoint  | Watchpoint 1 triggered  | Watchpoint 0 triggered  | BREAK instr  | BREAKN instr  | DebugIntr 

void FUN_42002460(void)

{
  uint uVar1;
  undefined1 in_DEBUGCAUSE;
  
  uVar1 = rsr(in_DEBUGCAUSE);
  FUN_42001e2c(PTR_s_Debug_exception_reason__42000258);
  if ((uVar1 & 1) != 0) {
    FUN_42001e2c(PTR_s_SingleStep_4200025c);
  }
  if ((uVar1 & 2) != 0) {
    FUN_42001e2c(PTR_s_HwBreakpoint_42000260);
  }
  if ((uVar1 & 4) != 0) {
    if ((uVar1 & 0x100) == 0) {
      FUN_42001e2c(PTR_s_Watchpoint_0_triggered_42000268);
    }
    else {
      FUN_42001e2c(PTR_s_Watchpoint_1_triggered_42000264);
    }
  }
  if ((uVar1 & 8) != 0) {
    FUN_42001e2c(PTR_s_BREAK_instr_4200026c);
  }
  if ((uVar1 & 0x10) != 0) {
    FUN_42001e2c(PTR_s_BREAKN_instr_42000270);
  }
  if ((uVar1 & 0x20) != 0) {
    FUN_42001e2c(PTR_s_DebugIntr_42000274);
  }
  return;
}


