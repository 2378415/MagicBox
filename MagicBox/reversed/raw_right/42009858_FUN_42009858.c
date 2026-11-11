// 42009858  FUN_42009858  FUN_42009858  size=99

undefined4 FUN_42009858(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (ushort *)0x0) {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 0x16;
    uVar3 = 0xffffffff;
  }
  else {
    (*DAT_42000240)(param_2,0,0x1c);
    if (*(int *)(PTR_DAT_42000920 + 0x14) == 0) {
      *param_2 = *param_2 | 8;
    }
    else if (*(int *)(PTR_DAT_42000920 + 0x14) == 1) {
      *param_2 = *param_2 | 2;
    }
    uVar1 = param_2[2];
    param_2[2] = uVar1 & 0xfffc;
    param_2[2] = uVar1 | 3;
    uVar3 = DAT_42000698;
    *(undefined4 *)(param_2 + 0xc) = DAT_42000698;
    *(undefined4 *)(param_2 + 10) = uVar3;
    uVar3 = 0;
  }
  return uVar3;
}


