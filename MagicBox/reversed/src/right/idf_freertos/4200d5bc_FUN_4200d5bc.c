void FUN_4200d5bc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  param_1 = param_1 & 0xff;
  iVar1 = param_1 * DAT_42000b2c + DAT_42000b30;
  iVar4 = *(int *)(iVar1 + 8);
  memw();
  memw();
  uVar2 = *(uint *)(iVar4 + 0x14) & *(uint *)(iVar4 + 0x18);
  memw();
  if (((*(uint *)(iVar4 + 0x14) & 1) != 0) && (uVar2 != 0)) {
    if ((uVar2 & 0x1000000) != 0) {
      FUN_4200cd88(iVar1);
    }
    if ((uVar2 & 0x20000000) != 0) {
      iVar4 = DAT_42000b30 + param_1 * DAT_42000b2c;
      memw();
      *(undefined1 *)((uint)*(byte *)(iVar4 + 0xc) * 0xc4 + DAT_42000af8) = 1;
      **(undefined1 **)(iVar4 + DAT_42000b34) = 2;
      FUN_4200f0f0(iVar4 + 0x10);
      memw();
      *(undefined4 *)(*(int *)(iVar4 + 8) + 0x14) = DAT_420003d0;
    }
    if ((uVar2 & 0x2000000) != 0) {
      iVar4 = *(int *)(DAT_42000b30 + param_1 * DAT_42000b2c + 8);
      memw();
      uVar2 = *(uint *)(iVar4 + 0x414);
      memw();
      uVar5 = *(uint *)(iVar4 + 0x418);
      for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1 & 0xff) {
        if ((uVar2 & uVar5 & 0xffff & 1 << ((byte)uVar3 & 0xf)) != 0) {
          memw();
          if ((*(uint *)(*(int *)(DAT_42000b30 + param_1 * DAT_42000b2c + 8) + uVar3 * 0x20 + 0x500)
              & 0x8000) == 0) {
            FUN_4200cb58(iVar1,uVar3);
          }
          else {
            FUN_4200c9c8(iVar1,uVar3);
          }
        }
      }
      memw();
      *(undefined4 *)(*(int *)(DAT_42000b30 + param_1 * DAT_42000b2c + 8) + 0x14) = DAT_420003ec;
    }
  }
  return;
}