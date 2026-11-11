// 42015580  FUN_42015580  FUN_42015580  size=104

undefined4 FUN_42015580(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  bool bVar5;
  
  iVar2 = *param_1;
  do {
    if (iVar2 == 0) {
      return 0;
    }
    bVar3 = false;
    bVar5 = false;
    for (uVar4 = 0; uVar4 < *(uint *)(iVar2 + 8); uVar4 = uVar4 + 1) {
      if (*(byte *)(uVar4 * 4 + iVar2 + 0xc) == param_2) {
        *(undefined1 *)(uVar4 * 4 + iVar2 + 0xc) = 0xff;
        bVar3 = true;
      }
      if (*(char *)(uVar4 * 4 + iVar2 + 0xc) != -1) {
        bVar5 = true;
      }
      if ((bool)(bVar5 & bVar3)) {
        return 1;
      }
    }
    if (bVar5) {
      iVar1 = *(int *)(iVar2 + 4);
    }
    else {
      iVar1 = *(int *)(iVar2 + 4);
      FUN_42024e9c(param_1,iVar2);
      if (iVar2 != 0) {
        (*(code *)PTR_FUN_420004c0)(iVar2);
      }
    }
    iVar2 = iVar1;
    if (bVar3) {
      return 1;
    }
  } while( true );
}


