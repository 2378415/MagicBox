undefined4
FUN_4037a964(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 in_PRID;
  undefined1 auStack_40 [16];
  int iStack_30;
  int local_2c [11];
  
  bVar1 = false;
  iStack_30 = param_1;
  local_2c[0] = param_5;
  while( true ) {
    FUN_4037bf44(iStack_30 + 0x68,0xffffffff);
    iVar2 = (**(code **)(iStack_30 + 0xc))(iStack_30,param_4);
    iVar4 = iStack_30;
    if (iVar2 == 1) {
      if (param_3 == (undefined4 *)0x0) {
        (**(code **)(iStack_30 + 0x10))(iStack_30,param_2,param_4);
        if (*(int *)(iStack_30 + 100) == 0) {
          memw();
          if ((*(int *)(iStack_30 + 0x50) != 0) &&
             (iVar4 = FUN_4037dde4(iStack_30 + 0x50), iVar4 == 1)) {
            uVar5 = rsr(in_PRID);
            FUN_40378e40(uVar5 >> 0xd & 1);
          }
          FUN_4037c094(iStack_30 + 0x68);
        }
        else {
          FUN_4037c094(iStack_30 + 0x68);
          FUN_4037b768(*(undefined4 *)(iStack_30 + 100),&iStack_30,0,0);
        }
      }
      else {
        uVar3 = FUN_4037a53c(iStack_30,param_4);
        *param_3 = uVar3;
        FUN_4037c094(iVar4 + 0x68);
      }
      return 1;
    }
    if (local_2c[0] == 0) break;
    if (!bVar1) {
      FUN_4037dfb8(auStack_40);
    }
    iVar4 = FUN_4037dfd4(auStack_40,local_2c);
    if (iVar4 != 0) {
      FUN_4037c094(iStack_30 + 0x68);
      return 0;
    }
    FUN_4037dce8(iStack_30 + 0x3c,local_2c[0]);
    uVar5 = rsr(in_PRID);
    FUN_40378e40(uVar5 >> 0xd & 1);
    FUN_4037c094(iStack_30 + 0x68);
    bVar1 = true;
  }
  FUN_4037c094(iStack_30 + 0x68);
  return 0;
}