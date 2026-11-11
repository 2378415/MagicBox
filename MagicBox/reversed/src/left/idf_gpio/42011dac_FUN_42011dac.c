// strings: rbn' | rbp' | PARSE | X-axis

void FUN_42011dac(int param_1,int *param_2,byte param_3,int param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = *param_2;
  if (param_4 == 0x31) {
    *(int *)(param_1 + 0x1b8) = iVar3;
    puVar2 = PTR_s_Y_axis_42001030;
    *(byte *)(param_1 + 0x1bc) = param_3;
  }
  else if (param_4 == 0x38) {
    *(int *)(param_1 + 0x1c0) = iVar3;
    puVar2 = PTR_s_Wheel_42001038;
    *(byte *)(param_1 + 0x1c4) = param_3;
  }
  else {
    if (param_4 != 0x30) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_PARSE_42000efc,PTR_DAT_4200103c,uVar1,PTR_s_PARSE_42000efc,param_4);
      iVar3 = *param_2;
      goto LAB_42011e38;
    }
    *(int *)(param_1 + 0x1b0) = iVar3;
    puVar2 = PTR_s_X_axis_42001034;
    *(byte *)(param_1 + 0x1b4) = param_3;
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_PARSE_42000efc,PTR_DAT_4200102c,uVar1,PTR_s_PARSE_42000efc,puVar2,iVar3,
             (uint)param_3);
  iVar3 = *param_2;
LAB_42011e38:
  *param_2 = (uint)param_3 + iVar3;
  return;
}