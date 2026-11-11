undefined4
FUN_42004288(uint param_1,byte *param_2,byte *param_3,undefined1 *param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 < 2) {
    if (param_5 == 1) {
      if (param_6 == 1) {
        if (param_1 == 0) {
          memw();
          uVar2 = *DAT_42000570 & 7;
        }
        else {
          memw();
          uVar2 = *DAT_42000574 >> 6 & 7;
        }
      }
      else {
        if (param_6 != 2) {
          return 5;
        }
        if (param_1 == 0) {
          memw();
          uVar2 = *DAT_42000570 >> 3 & 7;
        }
        else {
          memw();
          uVar2 = *DAT_42000574 >> 3 & 7;
        }
      }
    }
    else {
      if (param_5 != 0x10) {
        return 6;
      }
      if (param_6 == 1) {
        if (param_1 == 0) {
          memw();
          uVar2 = *DAT_42000570 >> 6 & 7;
        }
        else {
          memw();
          uVar2 = *DAT_42000574 >> 6 & 7;
        }
      }
      else {
        if (param_6 != 2) {
          return 5;
        }
        if (param_1 == 0) {
          memw();
          uVar2 = *DAT_42000570 >> 9 & 7;
        }
        else {
          memw();
          uVar2 = *DAT_42000574 >> 9 & 7;
        }
      }
    }
    *param_2 = (byte)(uVar2 >> 1) & 1;
    *param_3 = (byte)uVar2 & 1;
    *param_4 = (char)(uVar2 >> 2);
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}