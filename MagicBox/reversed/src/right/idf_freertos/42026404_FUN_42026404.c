uint FUN_42026404(uint *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 != (uint *)0x0) {
    uVar5 = param_1[1];
    for (uVar1 = *param_1; uVar1 < 0x1f; uVar1 = uVar1 + 1) {
      piVar2 = (int *)FUN_420263c0(uVar1);
      if ((piVar2 != (int *)0x0) && (memw(), *piVar2 != 0)) {
        if (uVar5 == 0) {
          memw();
          uVar5 = piVar2[3];
        }
        iVar3 = (*(code *)PTR_FUN_420014a0)(uVar5);
        if (iVar3 != 0) {
          uVar4 = *(uint *)(uVar5 + 0xc);
          iVar3 = (*(code *)PTR_FUN_420014a4)(uVar4);
          if (iVar3 == 0) {
            uVar4 = 0;
          }
          param_1[2] = uVar4;
          *param_1 = uVar1;
          memw();
          if (piVar2[4] == uVar5) {
            *param_1 = uVar1 + 1;
            param_1[1] = 0;
            return uVar1;
          }
          memw();
          param_1[1] = *(uint *)(uVar5 + 4);
          return uVar1;
        }
        uVar5 = 0;
      }
    }
  }
  return 0xffffffff;
}