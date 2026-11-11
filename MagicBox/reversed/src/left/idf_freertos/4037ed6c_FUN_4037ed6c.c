undefined4 FUN_4037ed6c(int *param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = FUN_4037c48c(param_1);
  if ((cVar1 == '\x01') && (param_2 != (int *)0x0)) {
    iVar4 = *param_1;
    iVar3 = param_1[0x12];
    *param_2 = (int)param_1;
    param_2[1] = iVar4;
    param_2[2] = iVar3;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}