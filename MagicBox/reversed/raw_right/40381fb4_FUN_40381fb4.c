// 40381fb4  FUN_40381fb4  FUN_40381fb4  size=105

undefined4 FUN_40381fb4(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint local_40;
  undefined1 auStack_3c [2];
  undefined1 uStack_3a;
  undefined1 *puStack_30;
  undefined2 uStack_28;
  
  local_40 = 0;
  (*DAT_4037448c)(auStack_3c,0,0x1c);
  uStack_3a = 3;
  uStack_28 = 0x9f;
  puStack_30 = (undefined1 *)&local_40;
  (**(code **)(*param_1 + 4))(param_1,auStack_3c);
  if (local_40 == DAT_40375214 || local_40 == 0) {
    uVar1 = 0x108;
  }
  else {
    *param_2 = local_40 >> 0x10 | local_40 & 0xff00 | (local_40 & 0xff) << 0x10;
    uVar1 = 0;
  }
  return uVar1;
}


