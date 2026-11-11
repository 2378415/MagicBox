// 4200778c  FUN_4200778c  FUN_4200778c  size=83
// strings: <k7@

void FUN_4200778c(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_42000848 + param_1 * 0x18;
  (*(code *)PTR_FUN_42000700)(puVar2);
  if (puVar2[0x14] != '\0') {
    if (param_1 - 1U < 2) {
      for (iVar1 = 1; iVar1 != 0; iVar1 = iVar1 + -1) {
        (*(code *)PTR_FUN_4200086c)();
        FUN_420074f0(param_1,0);
        (*(code *)PTR_FUN_42000870)();
      }
    }
    PTR_DAT_42000848[param_1 * 0x18 + 0x14] = 0;
  }
  (*(code *)PTR_FUN_42000704)(puVar2);
  return;
}


