// 40382eb0  FUN_40382eb0  FUN_40382eb0  size=64

undefined4 FUN_40382eb0(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  *param_2 = 0;
  uVar3 = uVar2 & 0xffff;
  if (uVar3 == 0 || uVar3 == DAT_40374460) {
    uVar1 = DAT_4037488c;
  }
  else {
    uVar2 = uVar2 & 0xff;
    if (0x30 < uVar2) {
      uVar2 = uVar2 - 0x20;
    }
    *param_2 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    uVar1 = 0;
  }
  return uVar1;
}


