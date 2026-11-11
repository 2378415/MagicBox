// 40382720  FUN_40382720  FUN_40382720  size=46

undefined4 FUN_40382720(undefined4 *param_1,undefined2 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined4 *puStack_48;
  undefined2 uStack_3c;
  undefined4 auStack_30 [12];
  
  auStack_30[0] = param_4;
  (*DAT_4037448c)(&uStack_50,0,0x1c);
  uStack_4f = (undefined1)(param_3 >> 3);
  puStack_48 = auStack_30;
  uStack_3c = param_2;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,&uStack_50);
  return uVar1;
}


