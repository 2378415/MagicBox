// 4037b894  FUN_4037b894  FUN_4037b894  size=62

void FUN_4037b894(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_4037c428(0x54);
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar2 + 0x11) = 0;
    puVar2[0xf] = 1;
    *puVar2 = puVar2;
    puVar2[0x10] = 0;
    FUN_4037b4b8();
    uVar1 = DAT_40374bf4;
    puVar2[0x12] = 0;
    puVar2[2] = 0;
    *puVar2 = 0;
    puVar2[3] = 0;
    puVar2[0x13] = uVar1;
    puVar2[0x14] = 0;
    FUN_4037b768(puVar2,0,0,0);
  }
  return;
}


