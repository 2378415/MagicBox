// 4200f270  COREDUMP_START  FUN_4200f270  size=114

void FUN_4200f270(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_230;
  undefined1 auStack_22c [556];
  
  iVar1 = FUN_42011e9c(1,3,0);
  if (iVar1 != 0) {
    local_230 = 0;
    iVar2 = FUN_420120b8(iVar1,0,&local_230,4);
    if (((iVar2 == 0) && (local_230 != 0)) && (local_230 <= *(uint *)(iVar1 + 0x10))) {
      FUN_42008f7c(0,PTR_s_COREDUMP_START_42000cd8,0xf);
      for (uVar3 = 0; uVar3 < local_230; uVar3 = uVar3 + iVar5) {
        uVar4 = local_230 - uVar3;
        iVar5 = (uVar4 < 0x200) * uVar4 + (uint)(uVar4 >= 0x200) * 0x200;
        iVar2 = FUN_420120b8(iVar1,uVar3,auStack_22c,iVar5);
        if (iVar2 != 0) {
          return;
        }
        FUN_42008f7c(0,auStack_22c,iVar5);
      }
      FUN_42008f7c(0,PTR_s_COREDUMP_END_42000cdc,0xe);
      FUN_42011fd8(iVar1,0,*(undefined4 *)(iVar1 + 0x10));
    }
  }
  return;
}


