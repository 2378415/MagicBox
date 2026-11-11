int FUN_40382020(int *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 local_40;
  undefined1 auStack_3c [2];
  undefined1 uStack_3a;
  undefined1 *puStack_30;
  undefined2 uStack_28;
  
  local_40 = 0;
  (*DAT_4037448c)(auStack_3c,0,0x1c);
  uStack_3a = 1;
  uStack_28 = 5;
  puStack_30 = (undefined1 *)&local_40;
  iVar1 = (**(code **)(*param_1 + 4))(param_1,auStack_3c);
  if (iVar1 == 0) {
    *param_2 = (char)local_40;
  }
  return iVar1;
}