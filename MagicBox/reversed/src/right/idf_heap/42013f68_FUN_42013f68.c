undefined4 FUN_42013f68(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 uStack00000000;
  undefined1 auStack_90 [32];
  undefined1 uStack_70;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [64];
  
  (*DAT_420002fc)(auStack_90,&uStack00000000,0x20);
  FUN_42013e34(auStack_40);
  (*DAT_420002fc)(auStack_60,auStack_40,0x20);
  uStack_70 = 0;
  (*DAT_420002fc)(auStack_90,auStack_60,0x20);
  uVar1 = FUN_42013f4c(param_1,param_2);
  return uVar1;
}