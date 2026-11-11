// 42010198  FUN_42010198  FUN_42010198  size=168

void FUN_42010198(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (((param_1 != (int *)0x0) && (param_1[1] != 0)) &&
     (bVar1 = *(byte *)(param_1[1] + 2), uVar4 = bVar1 & 0xf, (bVar1 & 8) == 0)) {
    memw();
    memw();
    *DAT_42000d84 = (int)param_1;
    memw();
    memw();
    *(int **)(uVar4 * 4 + DAT_42000d70) = param_1;
    memw();
    memw();
    *(undefined1 *)(uVar4 + DAT_42000d6c) = 1;
    iVar6 = *(int *)((uVar4 * 9 + (uint)*(byte *)(uVar4 * 0x24 + DAT_42000d68 + 0x20)) * 4 +
                    DAT_42000d68);
    iVar5 = param_1[1];
    uVar2 = *(ushort *)(iVar5 + 4);
    param_1[5] = *param_1;
    param_1[6] = iVar5;
    param_1[8] = 0;
    param_1[9] = iVar6 + 8;
    param_1[10] = (uint)uVar2;
    param_1[0xd] = 0;
    param_1[0x11] = (int)PTR_FUN_42000d74;
    param_1[0x12] = (int)param_1;
    if (*(byte *)(*param_1 + 3) < 3) {
      uVar3 = *(undefined1 *)(iVar5 + 6);
    }
    else {
      uVar3 = (undefined1)(1 << 0x20 - (0x20 - (*(byte *)(iVar5 + 6) - 1 & 0x1f)));
    }
    *(undefined1 *)((int)param_1 + 0x1d) = uVar3;
    FUN_4200d3e4(param_1 + 3);
  }
  return;
}


