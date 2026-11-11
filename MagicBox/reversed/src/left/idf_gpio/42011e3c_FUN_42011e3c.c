// strings: rbr' | rbt' | PARSE | Tilt

void FUN_42011e3c(int param_1,int *param_2,byte param_3,int param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = *param_2;
  if (param_4 == 0x238) {
    *(int *)(param_1 + 0x1c8) = iVar3;
    puVar2 = PTR_DAT_42001044;
    *(byte *)(param_1 + 0x1cc) = param_3;
  }
  else {
    if (param_4 != 0x239) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_PARSE_42000efc,PTR_DAT_42001048,uVar1,PTR_s_PARSE_42000efc,param_4);
      iVar3 = *param_2;
      goto LAB_42011eb8;
    }
    *(int *)(param_1 + 0x1d0) = iVar3;
    puVar2 = PTR_DAT_42001040;
    *(byte *)(param_1 + 0x1d4) = param_3;
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (3,PTR_s_PARSE_42000efc,PTR_DAT_4200102c,uVar1,PTR_s_PARSE_42000efc,puVar2,iVar3,
             (uint)param_3);
  iVar3 = *param_2;
LAB_42011eb8:
  *param_2 = (uint)param_3 + iVar3;
  return;
}