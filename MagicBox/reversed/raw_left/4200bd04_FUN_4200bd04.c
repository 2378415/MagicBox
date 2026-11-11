// 4200bd04  FUN_4200bd04  FUN_4200bd04  size=26

undefined4 FUN_4200bd04(undefined4 param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = 0x106;
  pcVar2 = *(code **)(*(int *)(*DAT_42000c30 + 0x34) + 0x14);
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)(param_1);
  }
  return uVar1;
}


