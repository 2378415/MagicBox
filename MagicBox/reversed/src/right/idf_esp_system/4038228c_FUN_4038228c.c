undefined4 FUN_4038228c(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x18);
  *param_2 = 0;
  uVar2 = uVar3 & 0xffff;
  if (uVar2 == 0 || uVar2 == DAT_40374460) {
    uVar1 = DAT_4037488c;
  }
  else {
    *param_2 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar1 = 0;
  }
  return uVar1;
}