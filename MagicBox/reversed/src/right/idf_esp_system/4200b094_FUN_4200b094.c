int FUN_4200b094(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint local_30 [12];
  
  local_30[0] = 0;
  if (param_1 == (int *)0x0 && param_2 == (uint *)0x0) {
    iVar2 = 0x102;
  }
  else {
    iVar1 = FUN_42011e9c(1,3,0);
    if (iVar1 == 0) {
      iVar2 = 0x105;
    }
    else if (*(uint *)(iVar1 + 0x10) < 4) {
      iVar2 = 0x104;
    }
    else {
      iVar2 = FUN_420120b8(iVar1,0,local_30,4);
      if (iVar2 == 0) {
        if (local_30[0] == 0xffffffff) {
          iVar2 = 0x104;
        }
        else if (local_30[0] < 4) {
          iVar2 = 0x104;
        }
        else if (*(uint *)(iVar1 + 0x10) < local_30[0]) {
          iVar2 = 0x104;
        }
        else {
          if (param_1 != (int *)0x0) {
            *param_1 = iVar1;
          }
          if (param_2 != (uint *)0x0) {
            *param_2 = local_30[0];
          }
        }
      }
    }
  }
  return iVar2;
}