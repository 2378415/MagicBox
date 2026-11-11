// 4200e670  FUN_4200e670  FUN_4200e670  size=127

uint FUN_4200e670(int param_1,uint param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    uVar6 = 0;
    uVar4 = 0;
    do {
      cVar1 = *(char *)(param_1 + uVar4);
      uVar5 = uVar4 + 1;
      if ((cVar1 == ',') || (cVar1 == ')' || cVar1 == ',')) {
        if (uVar6 < uVar4) {
          iVar3 = FUN_4200e458(param_1 + uVar6,uVar4 - uVar6);
          *(short *)((uVar2 & 0xffff) * 2 + param_3) = (short)iVar3;
          if (iVar3 != 0) {
            uVar2 = uVar2 + 1;
          }
        }
        uVar6 = uVar5;
      }
    } while ((uVar5 < param_2) && (uVar4 = uVar5, uVar2 != 6));
    if ((uVar6 < uVar5) && (uVar2 != 6)) {
      iVar3 = FUN_4200e458(param_1 + uVar6,uVar5 - uVar6);
      *(short *)((uVar2 & 0xffff) * 2 + param_3) = (short)iVar3;
      if (iVar3 != 0) {
        uVar2 = uVar2 + 1;
      }
    }
  }
  return uVar2;
}


