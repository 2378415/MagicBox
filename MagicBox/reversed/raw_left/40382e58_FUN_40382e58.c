// 40382e58  FUN_40382e58  FUN_40382e58  size=47

undefined4 FUN_40382e58(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x18) & 0xffff;
  if ((uVar2 == 0) || (uVar2 == DAT_403748e8 || uVar2 == 0)) {
    iVar3 = 0;
    uVar1 = DAT_40374914;
  }
  else {
    iVar3 = 1 << 0x20 - (0x20 - (*(uint *)(param_1 + 0x18) & 0x1f));
    uVar1 = 0;
  }
  *param_2 = iVar3;
  return uVar1;
}


