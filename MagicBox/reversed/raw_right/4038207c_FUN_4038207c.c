// 4038207c  FUN_4038207c  FUN_4038207c  size=45

undefined4 FUN_4038207c(int *param_1,char param_2)

{
  undefined1 auStack_40 [20];
  undefined2 uStack_2c;
  
  (*DAT_4037448c)(auStack_40,0,0x1c);
  if (param_2 == '\0') {
    uStack_2c = 6;
  }
  else {
    uStack_2c = 4;
  }
  (**(code **)(*param_1 + 4))(param_1,auStack_40);
  return 0;
}


