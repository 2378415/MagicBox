// 4201cb6c  FUN_4201cb6c  FUN_4201cb6c  size=120

undefined4 FUN_4201cb6c(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = FUN_4201e298(param_2);
  iVar3 = param_1[2];
  if (iVar3 != 0) {
    iVar4 = param_1[1];
    uVar5 = *(uint *)(iVar4 + 8);
    if (uVar5 < 0x1d) {
      *(uint *)(iVar4 + 8) = uVar5 + 1;
      *(uint *)(uVar5 * 4 + iVar4 + 0xc) = param_3 & 0xff | iVar1 << 8;
      return 0;
    }
  }
  piVar2 = (int *)(*(code *)PTR_FUN_4200056c)(0x80);
  if (piVar2 == (int *)0x0) {
    return 0x101;
  }
  piVar2[3] = 0xff;
  iVar4 = param_1[1];
  if (iVar4 != 0) {
    *(int **)(iVar4 + 4) = piVar2;
  }
  *piVar2 = iVar4;
  iVar4 = *param_1;
  piVar2[1] = 0;
  param_1[1] = (int)piVar2;
  if (iVar4 == 0) {
    *param_1 = (int)piVar2;
  }
  param_1[2] = iVar3 + 1;
  piVar2[3] = param_3 & 0xff | iVar1 << 8;
  piVar2[2] = 1;
  return 0;
}


