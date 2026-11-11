// 4037de64  FUN_4037de64  FUN_4037de64  size=271

undefined4 FUN_4037de64(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined1 in_PRID;
  
  FUN_4037bbe8(PTR_DAT_40374e54,0xffffffff);
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    memw();
    if (*(uint *)(param_1 + 0x2c) < *(uint *)(*(int *)(uVar4 * 4 + DAT_40374d64) + 0x2c)) {
      memw();
      if (-1 < *(int *)(param_1 + 0x18)) {
        memw();
        memw();
        *(int *)(param_1 + 0x18) = -(*(int *)(*(int *)(uVar4 * 4 + DAT_40374d64) + 0x2c) + -0x19);
      }
      memw();
      if (*(int *)(param_1 + 0x14) == *(uint *)(param_1 + 0x2c) * 0x14 + DAT_40374e34) {
        iVar3 = param_1 + 4;
        FUN_4037c980(iVar3);
        memw();
        uVar4 = *(uint *)(*(int *)(uVar4 * 4 + DAT_40374d64) + 0x2c);
        *(uint *)(param_1 + 0x2c) = uVar4;
        memw();
        if (*DAT_40374e30 < uVar4) {
          memw();
          *DAT_40374e30 = uVar4;
        }
        iVar1 = DAT_40374e34;
        memw();
        iVar5 = *(int *)(uVar4 * 0x14 + DAT_40374e34 + 4);
        memw();
        *(int *)(param_1 + 8) = iVar5;
        memw();
        memw();
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 8);
        memw();
        memw();
        *(int *)(*(int *)(iVar5 + 8) + 4) = iVar3;
        memw();
        *(int *)(iVar5 + 8) = iVar3;
        piVar6 = (int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1);
        memw();
        *(int **)(param_1 + 0x14) = piVar6;
        memw();
        memw();
        *(int *)(*(int *)(param_1 + 0x2c) * 0x14 + iVar1) = *piVar6 + 1;
        uVar2 = 1;
      }
      else {
        memw();
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(uVar4 * 4 + DAT_40374d64) + 0x2c)
        ;
        uVar2 = 1;
      }
    }
    else {
      memw();
      if (*(uint *)(param_1 + 0x4c) < *(uint *)(*(int *)(uVar4 * 4 + DAT_40374d64) + 0x2c)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  FUN_4037bd38(PTR_DAT_40374e54);
  return uVar2;
}


