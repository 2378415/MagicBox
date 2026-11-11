undefined4 FUN_420062bc(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = FUN_420061d8(param_1);
  if (iVar1 == 0) {
    uVar3 = 2;
  }
  else {
    piVar2 = (int *)(*(code *)PTR_FUN_42000730)(0);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)(*(code *)PTR_FUN_42000738)(1,4);
      if (piVar2 == (int *)0x0) {
        return 0xc;
      }
      (*(code *)PTR_FUN_4200073c)(0,0,piVar2,PTR_FUN_42000734);
    }
    iVar1 = FUN_420245f4(piVar2,param_1);
    if (iVar1 == 0) {
      if (param_2 == 0) {
        uVar3 = 0;
      }
      else {
        puVar4 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          uVar3 = 0xc;
        }
        else {
          *puVar4 = param_1;
          puVar4[1] = param_2;
          iVar1 = 0;
          for (iVar5 = *piVar2; iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
            iVar1 = iVar5;
          }
          if (iVar1 == 0) {
            puVar4[2] = *piVar2;
            *piVar2 = (int)puVar4;
            uVar3 = 0;
          }
          else {
            puVar4[2] = *(undefined4 *)(iVar1 + 8);
            *(undefined4 **)(iVar1 + 8) = puVar4;
            uVar3 = 0;
          }
        }
      }
    }
    else if (param_2 == 0) {
      iVar5 = *piVar2;
      if (iVar5 == iVar1) {
        *piVar2 = *(int *)(iVar5 + 8);
      }
      else {
        do {
          iVar6 = iVar5;
          iVar5 = *(int *)(iVar6 + 8);
        } while (iVar5 != iVar1);
        *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar5 + 8);
      }
      (*(code *)PTR_FUN_420004c0)(iVar1);
      uVar3 = 0;
    }
    else {
      *(int *)(iVar1 + 4) = param_2;
      uVar3 = 0;
    }
  }
  return uVar3;
}