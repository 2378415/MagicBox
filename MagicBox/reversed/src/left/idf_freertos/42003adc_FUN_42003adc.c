// strings: Debug exception reason:  | SingleStep  | HwBreakpoint  | Watchpoint 1 triggered  | Watchpoint 0 triggered  | BREAK instr  | BREAKN instr  | DebugIntr 

void FUN_42003adc(void)

{
  uint uVar1;
  undefined1 in_DEBUGCAUSE;
  
  uVar1 = rsr(in_DEBUGCAUSE);
  FUN_4200330c(PTR_s_Debug_exception_reason__42000390);
  if ((uVar1 & 1) != 0) {
    FUN_4200330c(PTR_s_SingleStep_42000394);
  }
  if ((uVar1 & 2) != 0) {
    FUN_4200330c(PTR_s_HwBreakpoint_42000398);
  }
  if ((uVar1 & 4) != 0) {
    if ((uVar1 & 0x100) == 0) {
      FUN_4200330c(PTR_s_Watchpoint_0_triggered_420003a0);
    }
    else {
      FUN_4200330c(PTR_s_Watchpoint_1_triggered_4200039c);
    }
  }
  if ((uVar1 & 8) != 0) {
    FUN_4200330c(PTR_s_BREAK_instr_420003a4);
  }
  if ((uVar1 & 0x10) != 0) {
    FUN_4200330c(PTR_s_BREAKN_instr_420003a8);
  }
  if ((uVar1 & 0x20) != 0) {
    FUN_4200330c(PTR_s_DebugIntr_420003ac);
  }
  return;
}