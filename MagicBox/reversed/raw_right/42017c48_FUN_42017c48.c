// 42017c48  FUN_42017c48  FUN_42017c48  size=58

int FUN_42017c48(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_4200a198(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  if (iVar1 == -1) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  }
  else {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x1000;
    *(int *)(param_2 + 0x54) = iVar1;
  }
  return iVar1;
}


