void FUN_4201519c(uint param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = DAT_4200135c + (param_1 & 0xff) * DAT_42001360;
  if (*(char *)(iVar1 + DAT_4200138c) != '\0') {
    pcVar2 = *(code **)(iVar1 + DAT_42001388);
    *(undefined1 *)(iVar1 + DAT_42001398) = 1;
    (*pcVar2)(param_1 & 0xff,5);
  }
  return;
}