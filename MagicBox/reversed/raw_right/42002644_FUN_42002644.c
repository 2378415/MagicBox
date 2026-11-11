// 42002644  FUN_42002644  FUN_42002644  size=212
// strings: hi7@hi

void FUN_42002644(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 in_EPC1;
  undefined1 in_EPC2;
  undefined1 in_EPC3;
  undefined1 in_EPC4;
  undefined4 local_80 [32];
  
  (*DAT_420002fc)(local_80,PTR_PTR_420002d4,0x60);
  FUN_42001e2c(PTR_s_Core_420002d8);
  FUN_42001e84(param_2);
  FUN_42001e2c(PTR_s_register_dump__420002dc);
  for (iVar1 = 0; iVar1 < 0x18; iVar1 = iVar1 + 4) {
    FUN_42001e2c(PTR_DAT_420002d0);
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if (*(char *)local_80[iVar1 + iVar2] != '\0') {
        FUN_42001e2c();
        FUN_42001e2c(PTR_DAT_420002e0);
        FUN_42001e58(*(undefined4 *)((iVar1 + iVar2 + 1) * 4 + param_1));
        FUN_42001e2c(PTR_DAT_420002e4);
      }
    }
  }
  iVar1 = (*(code *)PTR_FUN_42000300)();
  if ((iVar1 != 0) &&
     (((param_2 == 0 && (*(int *)(param_1 + 0x50) == 5)) ||
      ((param_2 == 1 && (*(int *)(param_1 + 0x50) == 6)))))) {
    FUN_42001e2c(PTR_DAT_420002d0);
    FUN_42001e2c(PTR_s_Core_420002d8);
    FUN_42001e84(param_2);
    FUN_42001e2c(PTR_s_was_running_in_ISR_context__420002e8);
    uVar3 = rsr(in_EPC1);
    FUN_42001e2c(PTR_DAT_420002ec);
    FUN_42001e58(uVar3);
    uVar3 = rsr(in_EPC2);
    FUN_42001e2c(PTR_s_EPC2___0x_420002f0);
    FUN_42001e58(uVar3);
    uVar3 = rsr(in_EPC3);
    FUN_42001e2c(PTR_s_EPC3___0x_420002f4);
    FUN_42001e58(uVar3);
    uVar3 = rsr(in_EPC4);
    FUN_42001e2c(PTR_s_EPC4___0x_420002f8);
    FUN_42001e58(uVar3);
  }
  return;
}


