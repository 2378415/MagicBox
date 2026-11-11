// 40376c88  FUN_40376c88  FUN_40376c88  size=76

undefined4 FUN_40376c88(undefined4 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (param_2 != (undefined8 *)0x0) {
    uVar4 = (*(code *)PTR_FUN_40374754)();
    uVar5 = (*(code *)PTR_FUN_40374758)();
    iVar3 = (int)((ulonglong)uVar4 >> 0x20) + (int)((ulonglong)uVar5 >> 0x20);
    uVar2 = (int)uVar4 + (uint)uVar5;
    if (uVar2 < (uint)uVar5) {
      iVar3 = iVar3 + 1;
    }
    uVar4 = (*DAT_403744c8)(uVar2,iVar3,DAT_403746b8,0);
    *param_2 = uVar4;
    uVar1 = (*DAT_4037475c)(uVar2,iVar3,DAT_403746b8,0);
    *(undefined4 *)(param_2 + 1) = uVar1;
  }
  return 0;
}


