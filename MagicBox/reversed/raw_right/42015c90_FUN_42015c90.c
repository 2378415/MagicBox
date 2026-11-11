// 42015c90  FUN_42015c90  FUN_42015c90  size=291

int FUN_42015c90(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [2];
  byte bStack_4a;
  
  FUN_42015770(param_1,auStack_50);
  if (param_2 < 0x7e) {
    if ((*(uint *)((param_2 >> 4) * 4 + param_1 + 0x18) >> (param_2 & 0xf) * 2 & 3) == 2) {
      iVar1 = FUN_42024fd8(param_1,param_2,auStack_4c);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_42016bd4(auStack_4c,param_2 & 0xff);
      if (iVar1 == 0) {
        FUN_42015580(param_1 + 0x44,param_2);
        iVar1 = FUN_42015874(param_1,param_2,0);
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
        *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = 1;
      }
      else {
        FUN_42015580(param_1 + 0x44,param_2);
        uVar2 = (uint)bStack_4a;
        uVar3 = param_2 + uVar2;
        while (uVar3 = uVar3 - 1, (int)param_2 <= (int)uVar3) {
          if (0x7d < uVar3) {
            return -1;
          }
          if ((*(uint *)((uVar3 >> 4) * 4 + param_1 + 0x18) >> (uVar3 & 0xf) * 2 & 3) == 2) {
            *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
          }
          *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
        }
        if (uVar2 == 1) {
          iVar1 = FUN_42015874(param_1,param_2,0);
        }
        else {
          iVar1 = FUN_420159d4(param_1,param_2,param_2 + uVar2,0);
        }
        if (iVar1 != 0) {
          return iVar1;
        }
      }
    }
    else {
      iVar1 = FUN_42015874(param_1,param_2,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = 1;
    }
    if ((*(uint *)(param_1 + 0x3c) != param_2) ||
       (iVar1 = FUN_42024f58(param_1,param_2,uVar2), iVar1 == 0)) {
      if (*(uint *)(param_1 + 0x38) < uVar2 + param_2) {
        *(uint *)(param_1 + 0x38) = uVar2 + param_2;
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


