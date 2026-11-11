void FUN_4200fc00(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_4200e4b8(0,1);
  iVar4 = param_2 + 4;
  iVar3 = FUN_4200df94(uVar2,param_1,iVar4);
  if (iVar3 < 8) {
    *(undefined2 *)(param_2 + 2) = 1;
    *(undefined1 *)(param_2 + 4) = 0xff;
  }
  else {
    *(short *)(param_2 + 2) = (short)iVar3 + -8;
    if (*(char *)(param_1 + 1) == '\x06') {
      cVar1 = *(char *)(param_1 + 3);
      if (cVar1 == '\x01') {
        FUN_4200f93c(iVar4);
      }
      else if (cVar1 == '\x02') {
        FUN_4200fb40(iVar4,param_2 + 2);
      }
      else if (cVar1 == '\x03') {
        FUN_4200fa0c(param_1,iVar4,param_2 + 2);
        FUN_4200fbc8(param_1,iVar4,param_2 + 2);
      }
    }
  }
  return;
}