// 4200b8b0  FUN_4200b8b0  FUN_4200b8b0  size=90

undefined4 FUN_4200b8b0(undefined4 param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 == (ushort *)0x0) {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  else {
    (*DAT_42000094)(param_2,0,0x1c);
    if (*(int *)(PTR_DAT_42000bf0 + 0x14) == 0) {
      *param_2 = *param_2 | 8;
    }
    else if (*(int *)(PTR_DAT_42000bf0 + 0x14) == 1) {
      *param_2 = *param_2 | 2;
    }
    uVar2 = DAT_4200087c;
    param_2[2] = param_2[2] | 3;
    *(undefined4 *)(param_2 + 0xc) = uVar2;
    *(undefined4 *)(param_2 + 10) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}


