undefined4 FUN_420206dc(undefined4 *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[10] == 0)) {
    FUN_42017694(param_1);
  }
  param_2[1] = 0;
  uVar5 = *(ushort *)(param_2 + 3);
  if ((uVar5 & 0x20) != 0) {
    return 0xffffffff;
  }
  if ((uVar5 & 4) == 0) {
    if ((uVar5 & 0x10) != 0) {
      if ((uVar5 & 8) != 0) {
        iVar4 = FUN_4201742c(param_1,param_2);
        if (iVar4 != 0) {
          return 0xffffffff;
        }
        uVar5 = *(ushort *)(param_2 + 3) & 0xfff7;
        param_2[2] = 0;
        param_2[6] = 0;
      }
      *(ushort *)(param_2 + 3) = uVar5 | 4;
      goto LAB_42020762;
    }
    *param_1 = 9;
  }
  else {
    if ((undefined4 *)param_2[0xd] != (undefined4 *)0x0) {
      if ((undefined4 *)param_2[0xd] != param_2 + 0x11) {
        (*(code *)PTR_FUN_4200115c)(param_1);
      }
      param_2[0xd] = 0;
      param_2[1] = param_2[0x10];
      if (param_2[0x10] != 0) {
        *param_2 = param_2[0xf];
        return 0;
      }
    }
LAB_42020762:
    if (param_2[4] == 0) {
      FUN_42020634(param_1,param_2);
    }
    puVar3 = PTR_FUN_4200129c;
    puVar2 = PTR_DAT_420006d0;
    puVar1 = PTR_DAT_420006c4;
    uVar5 = *(ushort *)(param_2 + 3);
    if ((uVar5 & 3) != 0) {
      *(undefined2 *)(param_2 + 3) = 1;
      FUN_42025144(puVar1,puVar3,puVar2);
      *(ushort *)(param_2 + 3) = uVar5;
      if ((~uVar5 & 9) == 0) {
        FUN_420172f8(param_1,param_2);
      }
    }
    *param_2 = param_2[4];
    iVar4 = (*(code *)param_2[9])(param_1,param_2[8],param_2[4],param_2[5]);
    param_2[1] = iVar4;
    if (0 < iVar4) {
      return 0;
    }
    uVar5 = *(ushort *)(param_2 + 3);
    uVar6 = 0x20;
    if (iVar4 == 0) goto LAB_42020704;
    param_2[1] = 0;
  }
  uVar6 = 0x40;
LAB_42020704:
  *(ushort *)(param_2 + 3) = uVar5 | uVar6;
  return 0xffffffff;
}