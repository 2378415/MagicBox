byte button_flags_get(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x210) == 0) {
      bVar1 = 0;
    }
    else {
      bVar1 = 0;
      if (param_2 - 1U < 0x10) {
        iVar2 = param_2 * 4 + *(int *)(param_1 + 0x210);
        bVar1 = *(int *)(iVar2 + 0x124) != 0 | (*(int *)(iVar2 + 0x9c) != 0) * '\x02';
      }
    }
  }
  return bVar1;
}