// 42014ff8  FUN_42014ff8  FUN_42014ff8  size=69

int FUN_42014ff8(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  byte local_30 [48];
  
  if (*(char *)(param_1 + 0x12) == '\0') {
    iVar1 = DAT_4200108c;
  }
  else {
    iVar1 = FUN_42014508(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                         local_30);
    if (iVar1 == 0) {
      if (local_30[0] == 0x48 || local_30[0] == 0x41) {
        local_30[0] = 0x42;
      }
      *param_3 = (uint)local_30[0];
    }
  }
  return iVar1;
}


