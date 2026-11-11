// 4037c7d4  FUN_4037c7d4  FUN_4037c7d4  size=38

int FUN_4037c7d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_4037c04c(0x28);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x24) = 0;
    FUN_4037c744(param_1,param_2,param_3,param_4,param_5,iVar1);
  }
  return iVar1;
}


