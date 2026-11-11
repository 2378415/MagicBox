// 42025144  FUN_42025144  FUN_42025144  size=53

uint FUN_42025144(undefined4 param_1,code *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  do {
    iVar4 = param_3[2];
    iVar3 = param_3[1];
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      if ((1 < *(ushort *)(iVar4 + 0xc)) && (*(short *)(iVar4 + 0xe) != -1)) {
        uVar2 = (*param_2)(param_1,iVar4);
        uVar1 = uVar1 | uVar2;
      }
      iVar4 = iVar4 + 0x68;
    }
    param_3 = (int *)*param_3;
  } while (param_3 != (int *)0x0);
  return uVar1;
}


