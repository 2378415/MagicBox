bool lock_axis_get(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x210);
    if (iVar2 == 0) {
      bVar1 = false;
    }
    else if (param_2 == 1) {
      bVar1 = *(char *)(iVar2 + 0x9c) != '\0';
    }
    else {
      bVar1 = false;
      if (param_2 == 2) {
        bVar1 = *(char *)(iVar2 + 0x9d) != '\0';
      }
    }
  }
  return bVar1;
}