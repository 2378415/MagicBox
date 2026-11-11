bool FUN_42004400(uint param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    piVar3 = DAT_4200051c;
    do {
      memw();
      iVar2 = *piVar3;
      piVar3 = piVar3 + 1;
      if (iVar2 != 0) {
        return true;
      }
    } while (piVar3 != DAT_42000520);
    bVar1 = false;
  }
  else {
    bVar1 = false;
    if (param_1 < 0xb) {
      memw();
      bVar1 = (0xf << 0x20 - ((param_1 - 1 & 7) * -4 + 0x20) &
              *(uint *)((param_1 - 1 >> 3) * 4 + DAT_42000524)) != 0;
    }
  }
  return bVar1;
}