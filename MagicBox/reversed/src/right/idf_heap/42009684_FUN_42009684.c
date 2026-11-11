int FUN_42009684(undefined4 param_1,uint *param_2,uint *param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 param_6,int *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  *param_7 = 0;
  iVar1 = FUN_42009a98();
  if (iVar1 == 0) {
    return 0x103;
  }
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_42000484)(0x2c,DAT_4200077c);
  if (puVar2 == (undefined4 *)0x0) {
    return 0x101;
  }
  *puVar2 = param_5;
  puVar2[1] = param_6;
  puVar2[2] = param_2;
  puVar2[3] = param_3;
  puVar2[4] = param_4;
  uVar4 = param_2[1];
  puVar2[5] = *param_2;
  puVar2[6] = uVar4;
  uVar4 = param_3[1];
  puVar2[7] = *param_3;
  puVar2[8] = uVar4;
  uVar5 = param_4[1];
  puVar2[9] = *param_4;
  puVar2[10] = uVar5;
  iVar1 = 2;
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    param_2[iVar1] = 0;
  }
  iVar1 = 2;
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    param_3[iVar1] = 0;
  }
  iVar1 = 2;
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    param_4[iVar1] = 0;
  }
  iVar1 = FUN_4200961c(puVar2);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_420004c0)(puVar2);
    return iVar1;
  }
  if ((puVar2[5] & 1) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_42009abc();
    if (iVar1 != 0) {
      *param_2 = *param_2 | 1;
    }
  }
  if (((puVar2[7] & 1) == 0) || (iVar3 = FUN_42009ae4(), iVar3 == 0)) {
    if (iVar1 == 0) goto LAB_4200975c;
  }
  else {
    *param_3 = *param_3 | 1;
  }
  FUN_4200a690(*puVar2,puVar2[1]);
LAB_4200975c:
  *param_7 = (int)puVar2;
  return 0;
}