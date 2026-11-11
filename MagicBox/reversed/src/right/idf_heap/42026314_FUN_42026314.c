// strings: Db7@8a7@

int FUN_42026314(undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_FUN_42000484)(0x54,param_4);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    if (param_3 == '\x01') {
      iVar2 = (*(code *)PTR_FUN_42000378)(1,iVar1);
    }
    else if (param_3 == '\x02') {
      iVar2 = (*(code *)PTR_FUN_42001490)(param_1,param_2,iVar1);
    }
    else if (param_3 == '\x03') {
      iVar2 = (*(code *)PTR_FUN_4200037c)(1,0,0,iVar1,3);
    }
    else {
      iVar2 = (*(code *)PTR_FUN_42000378)(4,iVar1);
    }
    if (iVar2 == 0) {
      (*(code *)PTR_FUN_420008b4)(iVar1);
    }
  }
  return iVar2;
}