// 40376294  FUN_40376294  FUN_40376294  size=221

int FUN_40376294(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_30;
  uint uStack_2c;
  uint auStack_28 [10];
  
  local_30 = param_1;
  uStack_2c = param_2;
  auStack_28[0] = param_3;
  FUN_40377900(&local_30,&uStack_2c,auStack_28);
  if (uStack_2c - 1 <= DAT_403745e8) {
    if ((auStack_28[0] & 1) != 0) {
      if ((auStack_28[0] >> 2 & 3) != 0) {
        return 0;
      }
      auStack_28[0] = auStack_28[0] | 2;
    }
    if ((auStack_28[0] & 2) != 0) {
      uStack_2c = uStack_2c + 3 & 0xfffffffc;
    }
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      for (iVar2 = *DAT_4037469c; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
        iVar4 = *(int *)(iVar2 + 0x1c);
        if ((iVar4 != 0) && ((*(uint *)(iVar1 * 4 + iVar2) & auStack_28[0]) != 0)) {
          uVar5 = 0;
          for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
            uVar5 = uVar5 | *(uint *)(iVar3 * 4 + iVar2);
          }
          if ((~uVar5 & auStack_28[0]) == 0) {
            if (((auStack_28[0] & 1) == 0) ||
               ((DAT_40374670 < (uint)(*(int *)(iVar2 + 0xc) + DAT_4037466c) &&
                (DAT_403745dc < (uint)(*(int *)(iVar2 + 0xc) + DAT_403745d8))))) {
              iVar4 = FUN_40376224(iVar4,uStack_2c,local_30,0);
              if (iVar4 != 0) {
                return iVar4;
              }
            }
            else {
              iVar4 = FUN_40376224(iVar4,uStack_2c + 4,local_30,0);
              if (iVar4 != 0) {
                iVar1 = FUN_40376168(iVar4,uStack_2c + 4);
                return iVar1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


