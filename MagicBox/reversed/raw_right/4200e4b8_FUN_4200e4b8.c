// 4200e4b8  FUN_4200e4b8  FUN_4200e4b8  size=48

undefined4 FUN_4200e4b8(uint param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_4200da44();
  uVar2 = FUN_4200de3c((param_1 & 0xff) * DAT_42000b2c + DAT_42000b30 + 0x10,param_2,param_3);
  FUN_4200da70(uVar1);
  return uVar2;
}


