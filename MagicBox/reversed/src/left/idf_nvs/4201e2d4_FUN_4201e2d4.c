undefined1 FUN_4201e2d4(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = (*DAT_42000cd4)(0xffffffff,param_1,4);
  uVar2 = (*DAT_42000cd4)(uVar2,param_1 + 8,0x10);
  param_2 = param_2 & 0xff;
  iVar3 = (*DAT_42000cd4)(uVar2,param_1 + 0x18,8);
  uVar4 = DAT_42001acc;
  if (iVar1 != iVar3) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(4,PTR_DAT_42001ab4,PTR_DAT_42001ab8,uVar2,PTR_DAT_42001ab4,param_2);
    return 0;
  }
  bVar5 = *(byte *)(param_1 + 1);
  if (bVar5 < 0x43) {
    if (0x40 < bVar5) {
      if ((bVar5 == 0x42) && (*(char *)(param_1 + 3) == -1)) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (4,PTR_DAT_42001ab4,PTR_DAT_42001ad4,uVar2,PTR_DAT_42001ab4,
                   *(undefined1 *)(param_1 + 3));
        return 0;
      }
LAB_4201e43c:
      uVar4 = (param_2 - 0x7d) * -0x20 & 0xffff;
      if (uVar4 < *(ushort *)(param_1 + 0x18)) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (4,PTR_DAT_42001ab4,PTR_DAT_42001ad8,uVar2,PTR_DAT_42001ab4,
                   *(undefined2 *)(param_1 + 0x18),uVar4,*(undefined1 *)(param_1 + 1));
        return 0;
      }
      uVar4 = -(param_2 - 0x7e) & 0xff;
      if (uVar4 < *(byte *)(param_1 + 2)) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (4,PTR_DAT_42001ab4,PTR_DAT_42001adc,uVar2,PTR_DAT_42001ab4,
                   *(undefined1 *)(param_1 + 2),uVar4,*(undefined1 *)(param_1 + 1));
        return 0;
      }
      uVar4 = (*(ushort *)(param_1 + 0x18) + 0x1f >> 5 & 0xff) + 1 & 0xff;
      if (*(byte *)(param_1 + 2) == uVar4) {
        return 1;
      }
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (4,PTR_DAT_42001ab4,PTR_DAT_42001ae0,uVar2,PTR_DAT_42001ab4,
                 *(undefined1 *)(param_1 + 2),uVar4,*(undefined2 *)(param_1 + 0x18),
                 *(undefined1 *)(param_1 + 1));
      return 0;
    }
    if (bVar5 < 3) {
      if (bVar5 != 0) {
LAB_4201e364:
        if (*(char *)(param_1 + 2) == '\x01') {
          return 1;
        }
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (4,PTR_DAT_42001ab4,PTR_DAT_42001ac0,uVar2,PTR_DAT_42001ab4,
                   *(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 1));
        return 0;
      }
    }
    else {
      bVar5 = bVar5 - 4;
      if (bVar5 < 0x1e) {
        if ((DAT_42001abc & 1 << (bVar5 & 0x1f)) != 0) goto LAB_4201e364;
        if (bVar5 == 0x1d) goto LAB_4201e43c;
      }
    }
  }
  else if (bVar5 == 0x48) {
    if (*(char *)(param_1 + 2) != '\x01') {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (4,PTR_DAT_42001ab4,PTR_DAT_42001ac4,uVar2,PTR_DAT_42001ab4,
                 *(undefined1 *)(param_1 + 2));
      return 0;
    }
    if (*(char *)(param_1 + 3) != -1) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (4,PTR_DAT_42001ab4,PTR_DAT_42001ac8,uVar2,PTR_DAT_42001ab4,
                 *(undefined1 *)(param_1 + 3));
      return 0;
    }
    if (DAT_42001acc < *(uint *)(param_1 + 0x18)) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (4,PTR_DAT_42001ab4,PTR_DAT_42001ad0,uVar2,PTR_DAT_42001ab4,
                 *(undefined4 *)(param_1 + 0x18),uVar4);
      return 0;
    }
    return 1;
  }
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (4,PTR_DAT_42001ab4,PTR_DAT_42001ae4,uVar2,PTR_DAT_42001ab4,*(undefined1 *)(param_1 + 1)
            );
  return 0;
}