// 42013fe4  FUN_42013fe4  FUN_42013fe4  size=36

void FUN_42013fe4(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 < 0x11) {
    uVar1 = param_3;
  }
  else {
    uVar1 = 0x10;
  }
  (*DAT_42000cfc)(param_2,param_1 + 8,uVar1);
  *(undefined1 *)(param_2 + (param_3 - 1)) = 0;
  return;
}


