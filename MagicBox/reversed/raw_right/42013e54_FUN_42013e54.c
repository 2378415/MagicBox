// 42013e54  FUN_42013e54  FUN_42013e54  size=74

undefined4 FUN_42013e54(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  iVar1 = (*DAT_4200099c)(param_1 + 8,param_2 + 8,0xf);
  if (iVar1 == 0) {
    if (*param_1 == *(char *)(param_2 + 0x18)) {
      if ((byte)param_1[3] < *(byte *)(param_2 + 0x1a)) {
        uVar2 = 0;
      }
      else {
        if (*(byte *)(param_2 + 0x1a) == 0) {
          bVar3 = 0x80;
        }
        else {
          bVar3 = 0xff;
        }
        if ((byte)param_1[3] < bVar3) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
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


