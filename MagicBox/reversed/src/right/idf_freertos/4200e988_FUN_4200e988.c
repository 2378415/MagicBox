undefined4 FUN_4200e988(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)((param_2 & 0xff) * 0x144 + param_1 + 0x3c);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 11000) != 0) {
      FUN_4200d388(iVar1 + DAT_42000c64);
    }
    if (*(int *)(iVar1 + 0x2b40) != 0) {
      FUN_4200d9c0();
    }
    for (uVar2 = 0; uVar2 < *(byte *)(iVar1 + 5); uVar2 = uVar2 + 1 & 0xff) {
      iVar3 = uVar2 * DAT_42000bcc;
      FUN_4200dee0(iVar1 + iVar3 + 0x20);
      *(undefined4 *)(iVar1 + iVar3 + DAT_42000c68) = 0;
    }
    FUN_4200e904(iVar1);
  }
  return 0;
}