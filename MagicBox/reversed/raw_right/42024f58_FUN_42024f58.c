// 42024f58  FUN_42024f58  FUN_42024f58  size=84

undefined4 FUN_42024f58(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x3c) == param_2) {
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    uVar3 = *(uint *)(param_1 + 0x38);
    if (0x7e < uVar3) {
      uVar3 = 0x7e;
    }
    for (uVar2 = param_2 + param_3; uVar2 < uVar3; uVar2 = uVar2 + 1) {
      if (0x7d < uVar2) {
        return 0xffffffff;
      }
      if ((*(uint *)((uVar2 >> 4) * 4 + param_1 + 0x18) >> (uVar2 & 0xf) * 2 & 3) == 2) {
        *(uint *)(param_1 + 0x3c) = uVar2;
        return 0;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


