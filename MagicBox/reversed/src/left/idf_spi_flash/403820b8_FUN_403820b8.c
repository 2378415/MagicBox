int FUN_403820b8(int *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 local_40 [3];
  undefined4 *puStack_34;
  undefined2 uStack_2c;
  undefined4 auStack_24 [9];
  
  auStack_24[0] = 0;
  local_40[0] = 0x10000;
  puStack_34 = auStack_24;
  uStack_2c = 5;
  iVar1 = (**(code **)(*param_1 + 4))(param_1,local_40);
  if (iVar1 == 0) {
    *param_2 = (char)auStack_24[0];
  }
  return iVar1;
}