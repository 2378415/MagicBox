// 4200cd88  FUN_4200cd88  FUN_4200cd88  size=427

void FUN_4200cd88(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uStack_2c;
  
  puVar1 = (uint *)(*(int *)(param_1 + 8) + 0x440);
  memw();
  uVar2 = *puVar1;
  memw();
  memw();
  memw();
  memw();
  uStack_2c = *puVar1 & 0xffffffd1;
  memw();
  memw();
  if ((uVar2 & 2) != 0) {
    memw();
    if ((uVar2 & 1) != 0) {
      **(undefined1 **)(param_1 + 0x2b4c) = 2;
      FUN_4200f0f0(param_1 + 0x10);
    }
    memw();
    uStack_2c = uStack_2c | 2;
    memw();
    memw();
    *(undefined1 *)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8) = 1;
  }
  memw();
  if ((uVar2 & 8) != 0) {
    memw();
    uStack_2c = uStack_2c | 8;
    memw();
    memw();
    *(undefined1 *)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8 + 1) = 1;
    memw();
    if ((uVar2 & 4) != 0) {
      memw();
      if ((uVar2 >> 0x11 & 3) << 0x11 == DAT_420003b4) {
        memw();
        *(undefined4 *)(*(int *)(param_1 + 8) + 0x404) = DAT_42000b10;
        puVar1 = (uint *)(*(int *)(param_1 + 8) + 0x400);
        memw();
        if ((*puVar1 & 3) != 2) {
          memw();
          memw();
          memw();
          memw();
          memw();
          memw();
          memw();
          memw();
          *puVar1 = *puVar1 & 0xfffffffc | 2;
        }
      }
      else {
        memw();
        *(undefined4 *)(*(int *)(param_1 + 8) + 0x404) = DAT_42000b14;
        puVar1 = (uint *)(*(int *)(param_1 + 8) + 0x400);
        memw();
        if ((*puVar1 & 3) != 1) {
          memw();
          memw();
          memw();
          memw();
          memw();
          memw();
          memw();
          memw();
          *puVar1 = *puVar1 & 0xfffffffc | 1;
        }
      }
    }
  }
  memw();
  if ((uVar2 & 0x20) != 0) {
    memw();
    uStack_2c = uStack_2c | 0x20;
    memw();
    memw();
    *(undefined1 *)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8 + 2) = 1;
  }
  memw();
  memw();
  *(uint *)(*(int *)(param_1 + 8) + 0x440) = uStack_2c;
  return;
}


