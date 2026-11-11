void FUN_420151d0(uint param_1)

{
  int iVar1;
  int iVar2;
  uint3 local_30;
  undefined1 uStack_2d;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  
  param_1 = param_1 & 0xff;
  FUN_420159e4(param_1,0);
  iVar1 = DAT_42001394;
  iVar2 = DAT_4200135c + param_1 * DAT_42001360;
  *(undefined2 *)(DAT_420013bc + param_1 * DAT_42001360 + DAT_420013b8) = 0;
  *(undefined1 *)(iVar2 + iVar1) = 0;
  uStack_2c = 0x40;
  _local_30 = DAT_420013c0;
  uStack_2a = 0;
  FUN_42015a20(param_1,&local_30);
  local_30 = (uint3)(ushort)local_30;
  FUN_42015a20(param_1,&local_30);
  FUN_42014770(param_1,1,0);
  (**(code **)(iVar2 + DAT_42001388))(param_1,1);
  return;
}