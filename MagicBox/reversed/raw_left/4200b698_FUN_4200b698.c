// 4200b698  FUN_4200b698  FUN_4200b698  size=111

undefined4 FUN_4200b698(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  uVar3 = 0;
  if (param_1 != 0) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000bf4,0xffffffff);
    puVar2 = DAT_42000bfc;
    piVar1 = DAT_42000bf8;
    uVar3 = DAT_42000988;
    if ((*DAT_42000bf8 < 1) || (piVar5 = (int *)*DAT_42000bfc, param_1 != *piVar5)) {
      uVar3 = 0x103;
    }
    else {
      iVar4 = *DAT_42000bf8 + -1;
      *piVar5 = piVar5[iVar4];
      uVar3 = (*(code *)PTR_FUN_42000990)(piVar5,iVar4 * 4,uVar3);
      *puVar2 = uVar3;
      *piVar1 = iVar4;
      if (iVar4 == 0) {
        FUN_4200bc80(0);
      }
      uVar3 = 0;
    }
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_42000bf4);
    (*(code *)PTR_FUN_42000570)(param_1);
  }
  return uVar3;
}


