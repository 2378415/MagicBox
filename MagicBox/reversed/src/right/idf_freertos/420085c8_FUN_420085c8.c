undefined4 FUN_420085c8(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + DAT_42000844) == 0) {
      uVar2 = 0x103;
    }
    else {
      iVar1 = (*(code *)PTR_FUN_42000484)(param_2 << 2,DAT_4200077c);
      if (iVar1 == 0) {
        uVar2 = 0x101;
      }
      else {
        puVar3 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
        (*(code *)PTR_FUN_420003a8)(puVar3,0xffffffff);
        iVar4 = *(int *)(param_1 * 4 + DAT_42000844);
        uVar2 = *(undefined4 *)(iVar4 + 0x38);
        *(int *)(iVar4 + 0x38) = iVar1;
        *(int *)(iVar4 + 0x34) = param_2;
        *(undefined4 *)(iVar4 + 0x30) = 0;
        *(undefined4 *)(iVar4 + 0x2c) = 0;
        (*(code *)PTR_FUN_420003ac)(puVar3);
        (*(code *)PTR_FUN_420004c0)(uVar2);
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}