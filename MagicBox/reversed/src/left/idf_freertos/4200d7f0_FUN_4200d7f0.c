uint FUN_4200d7f0(int param_1,int param_2)

{
  int iVar1;
  
  if (DAT_42000d2c < (uint)(param_1 + DAT_4200074c)) {
    iVar1 = DAT_42000d3c;
    if ((DAT_4200036c < (uint)(param_1 + DAT_42000d38)) &&
       (iVar1 = DAT_42000d40, DAT_4200036c < (uint)(param_1 + DAT_42000368))) {
      iVar1 = (*(code *)PTR_FUN_42000d48)(param_1);
      if ((iVar1 != 0) && (iVar1 = (*(code *)PTR_FUN_42000d48)(param_2 + -1 + param_1), iVar1 != 0))
      {
        return 1;
      }
      if (DAT_4200035c < (uint)(param_1 + DAT_42000358)) {
        return 0;
      }
      return -(param_1 + -1) & 0xff;
    }
    if ((uint)(param_2 + iVar1 + param_1) <= DAT_4200036c) {
      return 1;
    }
  }
  else if ((uint)(param_2 + DAT_42000d34 + param_1) <= DAT_42000d2c) {
    return 1;
  }
  iVar1 = (*(code *)PTR_FUN_42000d48)(param_1);
  if ((iVar1 == 0) || (iVar1 = (*(code *)PTR_FUN_42000d48)(param_2 + -1 + param_1), iVar1 == 0)) {
    return 0;
  }
  return 1;
}