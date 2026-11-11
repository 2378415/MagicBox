undefined4 * FUN_42012c40(int param_1,byte *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte bVar3;
  
  bVar3 = 0;
  puVar1 = (undefined4 *)0x0;
  for (puVar2 = *(undefined4 **)(*DAT_42000f78 + 4); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[1] == param_1) {
      puVar1 = puVar2;
    }
    else if (*(char *)(puVar2 + 3) == '\0') {
      bVar3 = 1;
    }
  }
  *param_2 = bVar3 ^ 1;
  return puVar1;
}