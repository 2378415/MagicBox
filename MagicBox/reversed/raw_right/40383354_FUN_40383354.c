// 40383354  FUN_40383354  FUN_40383354  size=115

int FUN_40383354(undefined4 *param_1,int *param_2)

{
  int iVar1;
  uint local_50;
  char acStack_4c [4];
  undefined1 auStack_48 [2];
  char cStack_46;
  undefined1 uStack_45;
  undefined1 *puStack_3c;
  undefined2 uStack_34;
  char cStack_32;
  
  local_50 = 0;
  FUN_40383230(param_1[4],acStack_4c);
  (*DAT_4037448c)(auStack_48,0,0x1c);
  cStack_46 = acStack_4c[0];
  uStack_45 = 0x20;
  uStack_34 = (undefined2)DAT_403752a4;
  cStack_32 = acStack_4c[0] << 2;
  puStack_3c = (undefined1 *)&local_50;
  iVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_48);
  if (iVar1 == 0) {
    if ((local_50 & 0xff) == 1) {
      *param_2 = 0x10;
    }
    else if ((local_50 & 0xff) == 2) {
      *param_2 = 0x11;
    }
    else {
      *param_2 = 0;
    }
    if (*param_2 != param_1[4]) {
      *param_2 = 0;
    }
  }
  return iVar1;
}


