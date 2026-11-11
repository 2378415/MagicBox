// 420174ac  FUN_420174ac  FUN_420174ac  size=111
// strings: pk7@

void FUN_420174ac(undefined4 *param_1,undefined2 param_2,undefined2 param_3)

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
  (*DAT_42000240)(param_1 + 0x17,0,8);
  puVar2 = DAT_4200117c;
  param_1[9] = PTR_FUN_4200116c;
  param_1[10] = PTR_FUN_42001170;
  param_1[0xb] = PTR_FUN_42001174;
  puVar1 = PTR_FUN_42001178;
  param_1[8] = param_1;
  param_1[0xc] = puVar1;
  if ((param_1 == puVar2 || param_1 == DAT_42001180) ||
     (param_1 == DAT_42001184 || (param_1 == puVar2 || param_1 == DAT_42001180))) {
    (*(code *)PTR_FUN_42001188)(param_1 + 0x16);
  }
  return;
}


