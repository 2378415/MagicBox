void FUN_4200f93c(int param_1,ushort param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined1 auStack_6b [107];
  
  puVar1 = DAT_42000d28;
  if ((0x11 < param_2) && (*(char *)(DAT_42000d28 + 2) == '\0')) {
    *DAT_42000d28 = *(undefined2 *)(param_1 + 8);
    puVar1[1] = *(undefined2 *)(param_1 + 10);
    memw();
    memw();
    *DAT_42000d38 = (uint)*(byte *)(param_1 + 0xe);
    memw();
    memw();
    *DAT_42000d3c = (uint)*(byte *)(param_1 + 0xf);
    memw();
    memw();
    *DAT_42000d2c = (uint)*(byte *)(param_1 + 0x10);
    *(undefined1 *)(puVar1 + 2) = 1;
    iVar2 = FUN_4200f4e0(*puVar1,puVar1[1],auStack_70);
    puVar1 = DAT_42000d28;
    if (iVar2 == 0) {
      *(undefined1 *)(DAT_42000d28 + 4) = uStack_6c;
      (*DAT_42000cfc)(DAT_42000d30,auStack_6b,0x40);
      *(undefined1 *)(puVar1 + 0x84) = 0;
    }
    else {
      *(undefined1 *)(DAT_42000d28 + 4) = 0;
      *(undefined1 *)((int)puVar1 + 0xc9) = 0;
    }
  }
  return;
}