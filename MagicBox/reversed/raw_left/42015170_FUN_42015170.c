// 42015170  FUN_42015170  FUN_42015170  size=42

void FUN_42015170(uint param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = DAT_4200135c + (param_1 & 0xff) * DAT_42001360;
  pcVar2 = *(code **)(iVar1 + DAT_42001388);
  *(undefined1 *)(iVar1 + DAT_42001398) = 0;
  (*pcVar2)(param_1 & 0xff,6);
  return;
}


