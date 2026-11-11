// 42004570  FUN_42004570  FUN_42004570  size=48

void FUN_42004570(int param_1,int param_2)

{
  uint uVar1;
  
  memw();
  uVar1 = (uint)(param_1 != 0);
  if (param_2 != 0) {
    uVar1 = uVar1 | 2;
  }
  memw();
  *DAT_42000590 = *DAT_42000590 & 0xfffffffc | uVar1;
  return;
}


