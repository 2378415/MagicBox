// 42017c0c  FUN_42017c0c  FUN_42017c0c  size=57

undefined4 FUN_42017c0c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((*(ushort *)(param_2 + 0xc) & 0x100) != 0) {
    FUN_4200a198(param_1,(int)*(short *)(param_2 + 0xe),0,2);
  }
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  uVar1 = FUN_4200a128(param_1,(int)*(short *)(param_2 + 0xe),param_3,param_4);
  return uVar1;
}


