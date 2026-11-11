void FUN_42012c78(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = DAT_42000f78;
  FUN_4201319c(*(undefined4 *)*DAT_42000f78);
  for (puVar2 = *(undefined4 **)(*piVar1 + 4); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    *(undefined1 *)(puVar2 + 3) = 0;
  }
  return;
}