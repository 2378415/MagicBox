// 4200bff8  FUN_4200bff8  FUN_4200bff8  size=69

undefined4 FUN_4200bff8(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((param_2 & 0xff) * 0x144 + param_1 + 0x3c);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_4200d388(iVar1 + 0xc);
    }
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_4200d388(iVar1 + 0x4c);
    }
    if (*(char *)((param_2 & 0xff) * 0x144 + param_1 + 0x28) != '\0') {
      FUN_42010244(iVar1);
    }
    FUN_4200be78(iVar1);
  }
  return 0;
}


