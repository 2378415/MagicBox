// 42018fe8  FUN_42018fe8  FUN_42018fe8  size=74

undefined4 FUN_42018fe8(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_42018d30(0xff,0xff,0);
  if (iVar1 != 0) {
    do {
      iVar2 = FUN_42018db0(iVar1);
      if (*(char *)(iVar2 + 0x2a) != '\0') {
        uVar3 = *(uint *)(iVar2 + 0xc);
        if (param_1 < uVar3) {
          if (uVar3 < param_1 + param_2) {
            return 0;
          }
        }
        else if (param_1 < uVar3 + *(int *)(iVar2 + 0x10)) {
          return 0;
        }
      }
      iVar1 = FUN_42018ca8(iVar1);
    } while (iVar1 != 0);
  }
  return 1;
}


