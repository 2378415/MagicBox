// 40382d0c  FUN_40382d0c  FUN_40382d0c  size=145

int FUN_40382d0c(undefined4 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint local_30 [12];
  
  if (param_2 == -1) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2;
  }
  uVar1 = iVar2 + 1;
  do {
    if (uVar1 == 0) {
LAB_40382d94:
      if (uVar1 == 0) {
        iVar2 = 0x107;
      }
      else {
        iVar2 = 0;
      }
      return iVar2;
    }
    while ((iVar2 = (**(code **)(*(int *)*param_1 + 0x38))(), iVar2 == 0 && (uVar1 != 0))) {
      if (1 < uVar1) {
        iVar2 = (uVar1 == 0) * uVar1 + (uint)(uVar1 != 0);
        (**(code **)(param_1[2] + 0xc))(param_1[3],iVar2);
        uVar1 = uVar1 - iVar2;
      }
    }
    iVar2 = (**(code **)(param_1[1] + 100))(param_1,1,local_30);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((local_30[0] & 1) == 0) {
      if (((param_1[7] & 1) != 0) && (param_1[7] = param_1[7] & 0xfffffffe, (local_30[0] & 2) != 0))
      {
        return 0x106;
      }
      goto LAB_40382d94;
    }
    if (uVar1 != 0) {
      iVar2 = (uVar1 < 0x14) * uVar1 + (uint)(uVar1 >= 0x14) * 0x14;
      (**(code **)(param_1[2] + 0xc))(param_1[3],iVar2);
      if (param_2 != -1) {
        uVar1 = uVar1 - iVar2;
      }
    }
  } while( true );
}


