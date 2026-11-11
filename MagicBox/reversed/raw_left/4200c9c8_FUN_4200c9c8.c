// 4200c9c8  FUN_4200c9c8  FUN_4200c9c8  size=166

undefined4 FUN_4200c9c8(char *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if ((*param_1 == '/') && (param_1[1] == '\0')) {
    uVar2 = *DAT_42000c74;
    if ((uVar2 & 3) == 0) {
      param_2 = param_2 & 3;
      if (param_2 == 2) {
        uVar2 = uVar2 | 3;
      }
      else if (param_2 == 1) {
        uVar2 = uVar2 | 2;
      }
      else {
        if (param_2 != 0) {
          puVar1 = (undefined4 *)FUN_42020b54();
          *puVar1 = 0x16;
          return 0xffffffff;
        }
        uVar2 = uVar2 | 1;
      }
      *DAT_42000c74 = uVar2;
      return 0;
    }
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 0x18;
  }
  else {
    puVar1 = (undefined4 *)FUN_42020b54();
    *puVar1 = 2;
  }
  return 0xffffffff;
}


