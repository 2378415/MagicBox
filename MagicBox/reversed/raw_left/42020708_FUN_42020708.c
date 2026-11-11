// 42020708  FUN_42020708  FUN_42020708  size=164

undefined4 FUN_42020708(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_FUN_420008c8)();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x28) == 0)) {
    FUN_420200c4();
  }
  uVar2 = *(ushort *)(param_2 + 3);
  if ((uVar2 & 8) == 0) {
    if ((uVar2 & 0x10) == 0) {
      *param_1 = 9;
      goto LAB_420207a0;
    }
    if ((uVar2 & 4) != 0) {
      if ((undefined4 *)param_2[0xd] != (undefined4 *)0x0) {
        if ((undefined4 *)param_2[0xd] != param_2 + 0x11) {
          (*(code *)PTR_FUN_42001c38)(param_1);
        }
        param_2[0xd] = 0;
      }
      uVar2 = *(ushort *)(param_2 + 3) & 0xffdb;
      param_2[1] = 0;
      *param_2 = param_2[4];
    }
    uVar2 = uVar2 | 8;
    *(ushort *)(param_2 + 3) = uVar2;
  }
  if ((param_2[4] == 0) && ((uVar2 & 0x280) != 0x200)) {
    FUN_420290a4(param_1,param_2);
  }
  uVar2 = *(ushort *)(param_2 + 3);
  uVar3 = 0;
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) == 0) {
      uVar3 = param_2[5];
    }
    param_2[2] = uVar3;
  }
  else {
    param_2[2] = 0;
    param_2[6] = -param_2[5];
  }
  if (param_2[4] != 0) {
    return 0;
  }
  if ((uVar2 & 0x80) == 0) {
    return 0;
  }
LAB_420207a0:
  *(ushort *)(param_2 + 3) = uVar2 | 0x40;
  return 0xffffffff;
}


