// 4200ddbc  FUN_4200ddbc  FUN_4200ddbc  size=130
// strings: buttons()

void FUN_4200ddbc(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,
                 char *param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_42000c68)(*param_4,PTR_s_buttons___42000d8c,9);
  if ((param_6 == 0) || (iVar1 == 0 || param_6 == 0)) {
LAB_4200dde7:
    if (param_3 != 0) {
      uVar2 = FUN_42010c64(param_3);
      FUN_4200dc18(PTR_s_buttons___42000d8c,9,uVar2);
    }
  }
  else {
    if (param_6 == 1) {
      if (*param_5 == ')') goto LAB_4200dde7;
    }
    else if (((param_6 == 2) && ((byte)(*param_5 - 0x30U) < 2)) && (param_5[1] == ')')) {
      FUN_42010c44(param_3,*param_5 == '1');
      FUN_420143e8(param_1,param_2,0);
      return;
    }
    FUN_420143e8(param_1,param_2,0);
  }
  return;
}


