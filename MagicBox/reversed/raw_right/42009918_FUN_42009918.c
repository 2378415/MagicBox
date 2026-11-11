// 42009918  FUN_42009918  FUN_42009918  size=97

undefined4 FUN_42009918(undefined4 param_1,int param_2,ushort *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 == (ushort *)0x0) {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  else {
    if (param_2 == 1) {
      FUN_420098dc(param_1);
    }
    else if ((param_2 != 2) && (param_2 != 0)) {
      puVar1 = (undefined4 *)FUN_420180e4();
      *puVar1 = 0x16;
      return 0xffffffff;
    }
    if ((*param_3 & 8) == 0) {
      if ((*param_3 & 2) == 0) {
        *(undefined4 *)(PTR_DAT_42000920 + 0x14) = 2;
        uVar2 = 0;
      }
      else {
        *(undefined4 *)(PTR_DAT_42000920 + 0x14) = 1;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
      *(undefined4 *)(PTR_DAT_42000920 + 0x14) = 0;
    }
  }
  return uVar2;
}


