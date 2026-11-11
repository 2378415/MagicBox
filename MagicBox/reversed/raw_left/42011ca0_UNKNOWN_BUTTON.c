// 42011ca0  UNKNOWN_BUTTON  FUN_42011ca0  size=150
// strings: BUTTON_MIDDLE | BUTTON_SIDE1 | BUTTON_LEFT | UNKNOWN_BUTTON | BUTTON_7 | BUTTON_8 | BUTTON_11 | BUTTON_12 | BUTTON_15 | BUTTON_16 | BUTTON_9 | BUTTON_SIDE2 | BUTTON_13

undefined * FUN_42011ca0(uint param_1)

{
  undefined *puVar1;
  
  if (param_1 == 9) {
    puVar1 = PTR_s_BUTTON_9_42001004;
  }
  else if (param_1 < 10) {
    if (param_1 == 5) {
      puVar1 = PTR_s_BUTTON_SIDE2_42000ff4;
    }
    else if (param_1 < 6) {
      puVar1 = PTR_s_BUTTON_MIDDLE_42000ff0;
      if ((((param_1 != 3) && (puVar1 = PTR_s_BUTTON_SIDE1_42000fec, param_1 != 4)) &&
          (puVar1 = PTR_s_BUTTON_LEFT_42000fe4, param_1 != 1)) &&
         (puVar1 = PTR_s_BUTTON_RIGHT_42000fe8, param_1 != 2)) {
        puVar1 = PTR_s_UNKNOWN_BUTTON_42001024;
      }
    }
    else {
      puVar1 = PTR_s_BUTTON_7_42000ffc;
      if ((param_1 != 7) && (puVar1 = PTR_s_BUTTON_6_42000ff8, param_1 == 8)) {
        puVar1 = PTR_s_BUTTON_8_42001000;
      }
    }
  }
  else if (param_1 == 0xd) {
    puVar1 = PTR_s_BUTTON_13_42001014;
  }
  else if (param_1 < 0xe) {
    puVar1 = PTR_s_BUTTON_11_4200100c;
    if ((param_1 != 0xb) && (puVar1 = PTR_s_BUTTON_10_42001008, param_1 == 0xc)) {
      puVar1 = PTR_s_BUTTON_12_42001010;
    }
  }
  else {
    puVar1 = PTR_s_BUTTON_15_4200101c;
    if (((param_1 != 0xf) && (puVar1 = PTR_s_BUTTON_16_42001020, param_1 != 0x10)) &&
       (puVar1 = PTR_s_BUTTON_14_42001018, param_1 != 0xe)) {
      puVar1 = PTR_s_UNKNOWN_BUTTON_42001024;
    }
  }
  return puVar1;
}


