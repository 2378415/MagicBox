// 40375e54  FUN_40375e54  FUN_40375e54  size=147

uint FUN_40375e54(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1[2];
  *param_1 = uVar3;
  param_1[2] = *(uint *)(param_1[1] - 0x10);
  uVar2 = DAT_40374600;
  iVar1 = DAT_403745fc;
  uVar4 = *(uint *)(param_1[1] - 0xc);
  param_1[1] = uVar4;
  if (uVar2 < uVar4 + iVar1) {
    if (DAT_40374608 < uVar4 + DAT_40374604) {
      return 0;
    }
  }
  else if ((uVar4 & 0xf) != 0) {
    return 0;
  }
  if ((int)uVar3 < 0) {
    uVar3 = uVar3 & 0x3fffffff | DAT_4037460c;
  }
  uVar2 = (-(DAT_40374614 + -1) | -(DAT_4037461c + -1)) & 0xff;
  if ((uVar2 == 0) && (uVar2 = 1, DAT_40374624 < uVar3 + DAT_40374620)) {
    uVar2 = -(DAT_40374608 - 1) & 0xff;
  }
  return uVar2;
}


