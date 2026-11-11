// 40382114  FUN_40382114  FUN_40382114  size=45

undefined4 FUN_40382114(int *param_1,char param_2)

{
  undefined4 local_40 [5];
  undefined2 uStack_2c;
  
  local_40[0] = 0;
  uStack_2c = 6;
  if (param_2 != '\0') {
    uStack_2c = 4;
  }
  (**(code **)(*param_1 + 4))(param_1,local_40);
  return 0;
}


