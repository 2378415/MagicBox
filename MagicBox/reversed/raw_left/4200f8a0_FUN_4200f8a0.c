// 4200f8a0  FUN_4200f8a0  FUN_4200f8a0  size=66

int FUN_4200f8a0(byte param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (((param_1 & 0x7f) == 0) || (uVar3 = (uint)(byte)((param_1 & 0x7f) - 1), 5 < uVar3)) {
    iVar1 = 0;
  }
  else {
    iVar2 = uVar3 * 0x738 + DAT_42000e84;
    if ((*(byte *)(iVar2 + 3) == param_1) || (iVar1 = 0, *(byte *)(iVar2 + 4) == param_1)) {
      iVar1 = uVar3 * 0x738 + DAT_42000e84;
    }
  }
  return iVar1;
}


