// 42013a38  FUN_42013a38  FUN_42013a38  size=250
// strings: &B9fR

undefined4 FUN_42013a38(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (0xb < param_1 - 1) {
    return 0x102;
  }
  if (2 < param_2) {
    return 0x102;
  }
  if (param_3 == (uint *)0x0) {
    return 0x102;
  }
  if (param_1 == 6) {
    uVar1 = DAT_42001088;
LAB_42013b30:
    *param_3 = uVar1;
    uVar2 = 0;
  }
  else {
    if (param_1 < 7) {
      if (param_1 == 3) {
        uVar1 = FUN_42005cd0(param_2);
        goto LAB_42013b1a;
      }
      if (param_1 < 4) {
        if (param_1 == 1) {
          uVar1 = FUN_42013560();
        }
        else {
          if (param_1 != 2) goto LAB_42013b1d;
          uVar1 = FUN_42005d30(param_2);
        }
        goto LAB_42013b1a;
      }
      if (param_1 == 4) {
        uVar1 = FUN_4201362c();
        goto LAB_42013b1a;
      }
      if (param_1 == 5) {
        uVar1 = DAT_4200100c;
        goto LAB_42013b30;
      }
    }
    else {
      if (param_1 == 10) {
        uVar1 = FUN_42005c18(param_2);
      }
      else if (param_1 < 0xb) {
        if (param_1 == 8) {
          uVar1 = FUN_42005c74(param_2);
        }
        else {
          if (param_1 == 9) goto LAB_42013afe;
          if (param_1 != 7) goto LAB_42013b1d;
          memw();
          if ((*DAT_42001024 & 4) == 0) {
            iVar3 = 0x140;
          }
          else if ((*DAT_42001024 >> 2 & 1) == 1) {
            iVar3 = 0x1e0;
          }
          else {
            iVar3 = 0;
          }
          uVar1 = (uint)(iVar3 * DAT_42000698) >> 1;
        }
      }
      else if (param_1 == 0xb) {
        iVar3 = FUN_420134dc();
        uVar1 = iVar3 * DAT_42000698;
      }
      else {
        if (param_1 != 0xc) goto LAB_42013b1d;
LAB_42013afe:
        uVar1 = FUN_42005d14(param_2);
      }
LAB_42013b1a:
      if (uVar1 != 0) goto LAB_42013b30;
    }
LAB_42013b1d:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


