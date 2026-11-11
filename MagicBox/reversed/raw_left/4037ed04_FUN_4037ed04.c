// 4037ed04  FUN_4037ed04  FUN_4037ed04  size=61

void FUN_4037ed04(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  if (param_2 < 1) {
    FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
    if (param_1 == 0) {
      uVar3 = rsil(3);
      uVar2 = rsr(in_PRID);
      memw();
      param_1 = *(int *)((uVar2 >> 0xd & 1) * 4 + DAT_40374e18);
      (*DAT_40374db8)(uVar3);
    }
    puVar1 = PTR_DAT_40374ef4;
    param_1 = param_2 * 4 + param_1;
    *(undefined4 *)(param_1 + 0x54) = param_3;
    *(undefined4 *)(param_1 + 0x58) = param_4;
    FUN_4037c094(puVar1);
  }
  return;
}


