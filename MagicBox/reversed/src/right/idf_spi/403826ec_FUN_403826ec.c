undefined4 FUN_403826ec(undefined4 *param_1,undefined2 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 local_40;
  undefined1 auStack_3c [2];
  undefined1 uStack_3a;
  undefined1 *puStack_30;
  undefined2 uStack_28;
  
  local_40 = 0;
  (*DAT_4037448c)(auStack_3c,0,0x1c);
  uStack_3a = (undefined1)(param_3 >> 3);
  puStack_30 = (undefined1 *)&local_40;
  uStack_28 = param_2;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_3c);
  *param_4 = local_40;
  return uVar1;
}