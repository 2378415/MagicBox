// 420206bc  FUN_420206bc  FUN_420206bc  size=32

undefined4 FUN_420206bc(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((~*(ushort *)(param_2 + 0xc) & 9) == 0) {
    uVar1 = (*(code *)PTR_FUN_420006f0)();
    uVar1 = FUN_4201742c(uVar1,param_2);
  }
  return uVar1;
}


