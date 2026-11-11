// 40382050  FUN_40382050  FUN_40382050  size=99

undefined4 FUN_40382050(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar2 = PTR_PTR_403752fc;
  if ((((-(DAT_40374e34 + -1) | -((int)param_1 + DAT_40374e38 + -1)) & 0xffU) == 0) &&
     ((-((int)param_1 + DAT_40374604 + -1) & 0xffU) == 0)) {
    puVar3 = DAT_40374608;
    if (*(int *)(param_2 + 0x1c) == 0) {
      return 0x102;
    }
  }
  else {
    puVar3 = PTR_PTR_403752f8;
    if (*(int *)(param_2 + 0x1c) == 0) {
      puVar2 = PTR_PTR_403752f8;
    }
  }
  *param_1 = puVar2;
  uVar1 = (*(code *)PTR_FUN_40375300)(param_1,param_2,puVar3);
  return uVar1;
}


