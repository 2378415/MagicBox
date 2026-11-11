uint FUN_4201cc84(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = FUN_4201e298(param_3);
  iVar6 = *param_1;
  do {
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    iVar4 = 0;
    for (iVar3 = *(int *)(iVar6 + 8); iVar3 != 0; iVar3 = iVar3 + -1) {
      iVar5 = iVar4 * 4 + iVar6;
      uVar2 = (uint)*(byte *)(iVar5 + 0xc);
      iVar4 = iVar4 + 1;
      if (((param_2 <= uVar2) && (*(uint *)(iVar5 + 0xc) >> 8 == (uVar1 & 0xffffff))) &&
         (uVar2 != 0xff)) {
        return uVar2;
      }
    }
    iVar6 = *(int *)(iVar6 + 4);
  } while( true );
}