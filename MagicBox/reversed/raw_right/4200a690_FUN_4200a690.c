// 4200a690  FUN_4200a690  FUN_4200a690  size=76

void FUN_4200a690(char param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_1 == '\0') {
    for (uVar1 = 0; uVar1 < *DAT_42000980; uVar1 = uVar1 + 1) {
      iVar2 = *(int *)(uVar1 * 4 + DAT_4200097c);
      if (((iVar2 != 0) && (iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0x34), iVar2 != 0)) &&
         (pcVar3 = *(code **)(iVar2 + 8), pcVar3 != (code *)0x0)) {
        (*pcVar3)(param_2);
        return;
      }
    }
  }
  else {
    (*(code *)PTR_FUN_42000358)(param_2,0,0);
  }
  return;
}


