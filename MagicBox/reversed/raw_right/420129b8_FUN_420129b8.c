// 420129b8  FUN_420129b8  FUN_420129b8  size=87
// strings: Pw7@

void FUN_420129b8(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = 0;
  uVar4 = 0;
  for (uVar5 = 0; uVar5 < 0xb; uVar5 = uVar5 + 1) {
    iVar1 = (*(code *)PTR_FUN_42000510)();
    if (((iVar1 != 0) || (4 < uVar5 - 6)) && (uVar2 = FUN_42012938(uVar5), uVar2 < 0x40)) {
      uVar6 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      if ((uVar2 & 0x20) == 0) {
        uVar2 = uVar6;
        uVar6 = 0;
      }
      else {
        uVar2 = 0;
      }
      uVar3 = uVar3 | uVar2;
      uVar4 = uVar4 | uVar6;
    }
  }
  FUN_420139ac(uVar3,uVar4);
  return;
}


