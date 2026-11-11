undefined4 FUN_4202912c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((~*(ushort *)(param_2 + 0xc) & 9) == 0) {
    uVar1 = (*(code *)PTR_FUN_420008c8)();
    uVar1 = FUN_4201fe5c(uVar1,param_2);
  }
  return uVar1;
}