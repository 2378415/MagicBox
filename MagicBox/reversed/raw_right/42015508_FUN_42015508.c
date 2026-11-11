// 42015508  FUN_42015508  FUN_42015508  size=68

uint FUN_42015508(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = FUN_42016b98(param_3);
  iVar4 = *param_1;
  do {
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    for (uVar2 = 0; uVar2 < *(uint *)(iVar4 + 8); uVar2 = uVar2 + 1) {
      uVar3 = (uint)*(byte *)(uVar2 * 4 + iVar4 + 0xc);
      if (((param_2 <= uVar3) && (*(uint *)(uVar2 * 4 + iVar4 + 0xc) >> 8 == (uVar1 & 0xffffff))) &&
         (uVar3 != 0xff)) {
        return uVar3;
      }
    }
    iVar4 = *(int *)(iVar4 + 4);
  } while( true );
}


