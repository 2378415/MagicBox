undefined4 FUN_4038325c(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_50;
  uint uStack_4c;
  char acStack_48 [4];
  undefined1 auStack_44 [2];
  char cStack_42;
  undefined1 uStack_41;
  undefined1 *puStack_38;
  undefined2 uStack_30;
  char cStack_2e;
  
  local_50 = 0;
  uStack_4c = 0;
  FUN_40383230(param_1[4],acStack_48);
  (*DAT_4037448c)(auStack_44,0,0x1c);
  cStack_42 = acStack_48[0] * '\x03';
  uStack_41 = 0x20;
  uStack_30 = (undefined2)DAT_4037529c;
  cStack_2e = acStack_48[0] << 2;
  puStack_38 = (undefined1 *)&local_50;
  (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_44);
  if (param_1[4] == 0x11) {
    local_50 = local_50 & 0xff | (local_50 >> 0x10 & 0xff) << 8 | (uStack_4c & 0xff) << 0x10;
    uStack_4c = 0;
  }
  uVar1 = local_50;
  uVar2 = (*DAT_403752a0)(local_50);
  if (uVar1 == 0xffffff00 || uVar1 == 0) {
    uVar3 = 0x108;
  }
  else {
    *param_2 = uVar2 >> 8;
    uVar3 = 0;
  }
  return uVar3;
}