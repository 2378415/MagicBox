undefined4 FUN_420205c8(undefined4 param_1,int param_2,int *param_3,uint *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_80 [4];
  uint uStack_7c;
  int iStack_38;
  
  if ((*(short *)(param_2 + 0xe) < 0) ||
     (iVar3 = FUN_4200a33c(param_1,(int)*(short *)(param_2 + 0xe),auStack_80), iVar3 < 0)) {
    uVar1 = *(ushort *)(param_2 + 0xc);
    *param_4 = 0;
    iVar3 = 0x80;
    if ((uVar1 >> 7 & 1) != 0) {
      iVar3 = 0x40;
    }
    *param_3 = iVar3;
    uVar2 = 0;
  }
  else {
    uVar4 = uStack_7c >> 0xc & 0xf;
    *param_4 = (uint)(uVar4 == 2);
    if (iStack_38 < 1) {
      *param_3 = 0x80;
    }
    else {
      *param_3 = iStack_38;
      *(int *)(param_2 + 0x50) = iStack_38;
      if (uVar4 == 8) {
        return 0x400;
      }
    }
    uVar2 = 0x800;
  }
  return uVar2;
}