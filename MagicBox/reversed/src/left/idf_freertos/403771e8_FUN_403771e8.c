void FUN_403771e8(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int local_30 [12];
  
  iVar3 = FUN_4037d570();
  puVar1 = DAT_403747e4;
  local_30[0] = 0;
  if (99 < (uint)(iVar3 - *DAT_403747e0)) {
    *DAT_403747e0 = iVar3;
    piVar2 = DAT_403747e8;
    if (*puVar1 == 0) {
      *DAT_403747e8 = iVar3;
      *puVar1 = 1;
    }
    else if ((uint)(iVar3 - *DAT_403747e8) < 0x7d1) {
      uVar4 = *puVar1 + 1;
      *puVar1 = uVar4;
      if (3 < uVar4) {
        uVar5 = *DAT_403747f0;
        *PTR_DAT_403747ec = *PTR_DAT_403747ec ^ 1;
        FUN_4037e634(uVar5,0,0,0,0,local_30);
        *puVar1 = 0;
        *piVar2 = 0;
        if (local_30[0] == 1) {
          FUN_4037c210();
        }
      }
    }
    else {
      *puVar1 = 1;
      *piVar2 = iVar3;
    }
  }
  return;
}