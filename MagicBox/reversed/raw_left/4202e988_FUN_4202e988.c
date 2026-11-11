// 4202e988  FUN_4202e988  FUN_4202e988  size=117
// strings: \d7@L

int FUN_4202e988(undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_FUN_42000660)(0x54,param_4);
  iVar2 = 0;
  if (iVar1 != 0) {
    if (param_3 == '\x01') {
      iVar2 = (*(code *)PTR_FUN_420004a8)(1,iVar1);
    }
    else if (param_3 == '\x02') {
      iVar2 = (*(code *)PTR_FUN_42001f40)(param_1,param_2,iVar1);
    }
    else if (param_3 == '\x03') {
      iVar2 = (*(code *)PTR_FUN_420004ac)(1,0,0,iVar1,3);
    }
    else {
      iVar2 = (*(code *)PTR_FUN_420004a8)(4,iVar1);
    }
    if (iVar2 == 0) {
      (*(code *)PTR_FUN_42000a4c)(iVar1);
    }
  }
  return iVar2;
}


