// 40376f74  FUN_40376f74  FUN_40376f74  size=86

undefined4 FUN_40376f74(undefined4 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = DAT_40374790;
  if (param_2 != (undefined8 *)0x0) {
    FUN_40376ce8(DAT_40374790);
    uVar4 = (*(code *)PTR_FUN_40374794)();
    FUN_40376d08(uVar1);
    uVar5 = (*(code *)PTR_FUN_40374798)();
    iVar2 = (int)uVar5 + (int)uVar4;
    iVar3 = (int)((ulonglong)uVar5 >> 0x20) + (int)((ulonglong)uVar4 >> 0x20) + (int)uVar4;
    uVar4 = (*DAT_40374500)(iVar2,iVar3,DAT_403746f8,0);
    uVar1 = DAT_403746f8;
    *param_2 = uVar4;
    uVar1 = (*DAT_4037479c)(iVar2,iVar3,uVar1,0);
    *(undefined4 *)(param_2 + 1) = uVar1;
  }
  return 0;
}


