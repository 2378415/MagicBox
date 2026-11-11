undefined4 FUN_40382df0(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x18) & 0xffff;
  if ((uVar3 == 0) || (uVar3 == DAT_403748e8 || uVar3 == 0)) {
    iVar2 = 0;
    uVar1 = DAT_40374914;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x18) & 0xff;
    if (0x30 < uVar3) {
      uVar3 = uVar3 - 0x20;
    }
    iVar2 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar1 = 0;
  }
  *param_2 = iVar2;
  return uVar1;
}