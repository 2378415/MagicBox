void FUN_4200dee0(char *param_1)

{
  uint uVar1;
  code *pcVar2;
  
  if (*param_1 != '\0') {
    *param_1 = '\0';
    FUN_4200dad4(param_1);
    for (uVar1 = 0; uVar1 < (byte)param_1[0x20]; uVar1 = uVar1 + 1 & 0xff) {
      if ((*(int *)(param_1 + uVar1 * 0x144 + 0x38) != 0) &&
         (pcVar2 = *(code **)(*(int *)(param_1 + uVar1 * 0x144 + 0x38) + 8), pcVar2 != (code *)0x0))
      {
        (*pcVar2)(param_1,uVar1);
      }
    }
    param_1[0x20] = '\0';
    FUN_4200d388(param_1 + DAT_42000bd4);
    if (*(int *)(param_1 + 0xab0) != 0) {
      FUN_4200d834();
    }
  }
  return;
}