void FUN_4202658c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  (*DAT_42000240)(param_2,0,0x1c);
  if (param_1 != 0) {
    (*(code *)PTR_FUN_420014c4)(param_1);
    uVar1 = (*(code *)PTR_FUN_420014c8)(*(undefined4 *)(param_1 + 0x10));
    FUN_420267b0(uVar1,PTR_FUN_420014c0,param_2);
    iVar4 = param_2[4];
    iVar2 = (*(code *)PTR_FUN_420014cc)();
    iVar5 = *(int *)(param_1 + 0xc);
    iVar3 = (*(code *)PTR_FUN_420014bc)(*(undefined4 *)(param_1 + 0x10));
    param_2[1] = ((iVar5 - iVar3) - *(int *)(param_1 + 4)) - iVar4 * iVar2;
    param_2[3] = *(undefined4 *)(param_1 + 8);
    *param_2 = *(undefined4 *)(param_1 + 4);
    uVar1 = FUN_42026808(*(undefined4 *)(param_1 + 0x10),param_2[2]);
    param_2[2] = uVar1;
    (*(code *)PTR_FUN_420014d0)(param_1);
  }
  return;
}