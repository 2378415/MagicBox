// 4200afe4  FUN_4200afe4  FUN_4200afe4  size=176

int FUN_4200afe4(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_30 [12];
  
  local_30[0] = 0;
  uVar1 = FUN_420246b8();
  if ((char)param_1[9] != '\0') {
    iVar2 = FUN_4200ae14(*DAT_420009f8 + *param_1,param_1 + 1,0x20);
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_4200b990(param_1 + 10,param_1 + 1,0x20);
    *param_1 = *param_1 + 0x20;
    *(undefined1 *)(param_1 + 9) = 0;
  }
  FUN_4200b9ac(param_1 + 10,local_30);
  if (uVar1 < 0x20) {
    piVar3 = param_1 + 1;
    (*DAT_420002fc)(piVar3,local_30[0],uVar1);
    (*DAT_42000240)((int)piVar3 + uVar1,0,-(uVar1 - 0x20));
    iVar2 = FUN_4200ae14(*DAT_420009f8 + *param_1,piVar3,0x20);
  }
  else {
    if ((uVar1 & 0xf) != 0) {
      (*(code *)PTR_FUN_4200006c)();
    }
    iVar2 = FUN_4200ae14(*DAT_420009f8 + *param_1,local_30[0],uVar1);
  }
  if (iVar2 == 0) {
    *param_1 = *param_1 + uVar1;
  }
  return iVar2;
}


