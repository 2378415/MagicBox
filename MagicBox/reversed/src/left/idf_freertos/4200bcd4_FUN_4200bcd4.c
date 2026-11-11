undefined4
FUN_4200bcd4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  uVar1 = 0x106;
  if ((code *)**(undefined4 **)(*DAT_42000c30 + 0x34) != (code *)0x0) {
    uVar1 = (*(code *)**(undefined4 **)(*DAT_42000c30 + 0x34))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}