void FUN_4201ab5c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 local_40 [5];
  undefined4 auStack_2c [11];
  
  puVar1 = local_40;
  (*DAT_42000064)(local_40,PTR_DAT_420019a8,0x14);
  do {
    uVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    FUN_4202d8e0(uVar2,0);
  } while (puVar1 != auStack_2c);
  FUN_4202d8e0(1);
  return;
}