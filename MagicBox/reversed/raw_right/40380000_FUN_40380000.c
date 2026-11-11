// 40380000  FUN_40380000  FUN_40380000  size=94

void FUN_40380000(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  
  iVar1 = param_1[1];
  memw();
  memw();
  *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xfffffffd;
  memw();
  memw();
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0x3ffffff | DAT_403750ec;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_403745e0;
  memw();
  *(uint *)(iVar1 + 4) = param_3 & 0xffffff | param_4 << 0x18;
  FUN_4037fa48(iVar1,param_2,param_4);
  (**(code **)(*param_1 + 0x40))(param_1);
  return;
}


