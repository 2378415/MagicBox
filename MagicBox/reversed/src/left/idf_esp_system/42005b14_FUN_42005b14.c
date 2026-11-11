// strings: ,b7@('

void FUN_42005b14(undefined4 *param_1)

{
  undefined2 uVar1;
  
  (*DAT_42000094)(param_1,0,0xc);
  *param_1 = 9;
  uVar1 = (*DAT_42000088)();
  *(undefined1 *)((int)param_1 + 10) = 2;
  *(undefined2 *)(param_1 + 2) = uVar1;
  param_1[1] = 0x12;
  return;
}