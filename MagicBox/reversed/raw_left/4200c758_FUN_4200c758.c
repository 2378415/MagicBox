// 4200c758  FUN_4200c758  FUN_4200c758  size=71

void FUN_4200c758(char param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  
  if (param_1 == '\0') {
    piVar2 = DAT_42000c48;
    for (iVar1 = *DAT_42000c4c; iVar1 != 0; iVar1 = iVar1 + -1) {
      iVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      if (((iVar3 != 0) && (iVar3 = *(int *)(*(int *)(iVar3 + 4) + 0x34), iVar3 != 0)) &&
         (pcVar4 = *(code **)(iVar3 + 8), pcVar4 != (code *)0x0)) {
        (*pcVar4)();
        return;
      }
    }
  }
  else {
    (*(code *)PTR_FUN_42000488)(param_2,0,0);
  }
  return;
}


