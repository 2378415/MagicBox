void FUN_4200a6e0(char param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_1 == '\0') {
    for (uVar1 = 0; uVar1 < *DAT_42000980; uVar1 = uVar1 + 1) {
      iVar2 = *(int *)(uVar1 * 4 + DAT_4200097c);
      if (((iVar2 != 0) && (iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0x34), iVar2 != 0)) &&
         (pcVar3 = *(code **)(iVar2 + 0xc), pcVar3 != (code *)0x0)) {
        (*pcVar3)(param_2,param_3);
        return;
      }
    }
  }
  else {
    (*(code *)PTR_FUN_42000898)(param_2);
  }
  return;
}