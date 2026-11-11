void FUN_42003360(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_30;
  undefined1 auStack_2c [44];
  
  puVar2 = PTR_DAT_420002bc;
  iVar4 = 8;
  do {
    uVar1 = param_1 >> 0x1c;
    iVar5 = *(int *)puVar2;
    if (uVar1 < 10) {
      iVar3 = uVar1 + 0x30;
      auStack_2c[0] = (undefined1)iVar3;
      do {
        memw();
      } while ((*(uint *)(iVar5 + 0x1c) >> 0x10 & 0x3ff) == 0x80);
    }
    else {
      iVar3 = uVar1 + 0x57;
      auStack_2c[0] = (undefined1)iVar3;
      do {
        memw();
      } while ((*(uint *)(iVar5 + 0x1c) >> 0x10 & 0x3ff) == 0x80);
    }
    local_30 = 0;
    FUN_4202cec4(puVar2,auStack_2c,1,&local_30);
    iVar4 = iVar4 + -1;
    FUN_420032b0(iVar3);
    param_1 = param_1 << 4;
  } while (iVar4 != 0);
  return;
}