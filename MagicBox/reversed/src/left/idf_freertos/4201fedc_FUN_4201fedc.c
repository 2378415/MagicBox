void FUN_4201fedc(undefined4 *param_1,undefined2 param_2,undefined2 param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x19] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 3) = param_2;
  *(undefined2 *)((int)param_1 + 0xe) = param_3;
  (*DAT_42000094)(param_1 + 0x17,0,8);
  puVar2 = DAT_42001c58;
  param_1[9] = PTR_FUN_42001c48;
  param_1[10] = PTR_FUN_42001c4c;
  param_1[0xb] = PTR_FUN_42001c50;
  puVar1 = PTR_FUN_42001c54;
  param_1[8] = param_1;
  param_1[0xc] = puVar1;
  if ((param_1 == puVar2 || param_1 == DAT_42001c5c) ||
     (param_1 == DAT_42001c60 || (param_1 == puVar2 || param_1 == DAT_42001c5c))) {
    (*(code *)PTR_FUN_42001c64)(param_1 + 0x16);
  }
  return;
}