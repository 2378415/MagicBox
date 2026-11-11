void FUN_4200de08(undefined4 *param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  (*DAT_42000240)(param_1,0,DAT_42000b2c);
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined1 *)(param_1 + 3) = param_2;
  param_1[2] = param_3;
  *(undefined1 *)(param_1 + 0xad5) = 2;
  puVar2 = DAT_42000bc8;
  do {
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar1;
  } while (puVar2 != (undefined4 *)0x0);
  *puVar1 = param_1;
  *param_1 = 0;
  return;
}