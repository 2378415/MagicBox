// 4200ba94  FUN_4200ba94  FUN_4200ba94  size=54

undefined4 FUN_4200ba94(undefined4 param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 == 3) {
    uVar2 = 2;
    if (PTR_DAT_42000bf0[0xc] != '\0') {
      uVar2 = DAT_420009e4;
    }
  }
  else if (param_2 == 4) {
    PTR_DAT_42000bf0[0xc] = (byte)(param_3 >> 0xe) & 1;
    uVar2 = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x58;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


