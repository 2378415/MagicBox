undefined4 uart0_read_string(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_30 [12];
  
  local_30[0] = 0;
  iVar1 = FUN_42013b20(0x1a,0,0,param_1,local_30);
  if (((iVar1 == 0) && (local_30[0] < param_2)) && (local_30[0] != 0)) {
    *(undefined1 *)(param_1 + local_30[0]) = 0;
    uVar2 = 0;
    if (param_3 != (uint *)0x0) {
      *param_3 = local_30[0];
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}