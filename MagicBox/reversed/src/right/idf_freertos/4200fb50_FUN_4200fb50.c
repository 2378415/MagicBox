undefined4 FUN_4200fb50(undefined1 *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)*param_2;
  if (uVar3 < 2) {
    uVar2 = 0;
  }
  else if (param_1[1] == '\x03') {
    iVar1 = (*DAT_420001e4)(param_3);
    if (0x14 < iVar1) {
      iVar1 = 0x14;
    }
    iVar5 = (iVar1 + 1) * 2;
    if (iVar5 < 0x100) {
      if ((int)uVar3 < iVar5) {
        iVar1 = (int)(uVar3 - 2) / 2;
        iVar5 = (iVar1 + 1) * 2;
      }
      *param_1 = (char)iVar5;
      iVar4 = 0;
      while (iVar4 < iVar1) {
        param_1[(iVar4 + 1) * 2] = *(undefined1 *)(param_3 + iVar4);
        param_1[iVar4 * 2 + 3] = 0;
        iVar4 = iVar4 + 1;
      }
      *param_2 = (ushort)iVar5;
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}