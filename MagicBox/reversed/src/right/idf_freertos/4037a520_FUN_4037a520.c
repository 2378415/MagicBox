undefined4
FUN_4037a520(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int iStack_30;
  int local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  bVar3 = false;
  bVar1 = false;
  bVar2 = false;
  uStack_28 = 0;
  iStack_30 = param_1;
  local_2c = param_5;
  uStack_24 = param_2;
  while (!bVar2) {
    FUN_4037bbe8(iStack_30 + 0x68,0xffffffff);
    iVar4 = (**(code **)(iStack_30 + 0xc))(iStack_30,param_4);
    if (iVar4 == 1) {
      if (param_3 == (undefined4 *)0x0) {
        (**(code **)(iStack_30 + 0x10))(iStack_30,uStack_24,param_4);
        if (*(int *)(iStack_30 + 100) == 0) {
          memw();
          if ((*(int *)(iStack_30 + 0x50) != 0) &&
             (iVar4 = FUN_4037d664(iStack_30 + 0x50), iVar4 == 1)) {
            uVar6 = rsr(in_PRID);
            FUN_403787f4(uVar6 >> 0xd & 1);
          }
        }
        else {
          bVar3 = true;
        }
      }
      else {
        uVar5 = FUN_4037a07c(iStack_30,param_4);
        *param_3 = uVar5;
      }
      bVar2 = true;
      uStack_28 = 1;
    }
    else if (local_2c == 0) {
      bVar2 = true;
    }
    else {
      if (!bVar1) {
        FUN_4037d860(auStack_40);
        bVar1 = true;
      }
      iVar4 = FUN_4037d87c(auStack_40,&local_2c);
      if (iVar4 == 0) {
        FUN_4037d564(iStack_30 + 0x3c,local_2c);
        uVar6 = rsr(in_PRID);
        FUN_403787f4(uVar6 >> 0xd & 1);
      }
      else {
        bVar2 = true;
      }
    }
    FUN_4037bd38(iStack_30 + 0x68);
  }
  if (bVar3) {
    FUN_4037b39c(*(undefined4 *)(iStack_30 + 100),&iStack_30,0);
  }
  return uStack_28;
}