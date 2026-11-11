int FUN_40382b04(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_30 [12];
  
  uVar3 = param_2 + 1;
  if (uVar3 == 0) {
    uVar3 = 1;
  }
  while( true ) {
    while (iVar1 = (**(code **)(*(int *)*param_1 + 0x38))(), iVar1 == 0) {
      if (uVar3 != 1) {
        (**(code **)(param_1[2] + 0xc))(param_1[3],1);
        uVar3 = uVar3 - 1;
      }
    }
    iVar1 = (**(code **)(param_1[1] + 100))(param_1,1,local_30);
    iVar2 = (uVar3 < 0x14) * uVar3 + (uint)(uVar3 >= 0x14) * 0x14;
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((local_30[0] & 1) == 0) break;
    (**(code **)(param_1[2] + 0xc))(param_1[3],iVar2);
    if ((param_2 != -1) && (uVar3 = uVar3 - iVar2, uVar3 == 0)) {
      return 0x107;
    }
  }
  if ((param_1[7] & 1) == 0) {
    return 0;
  }
  param_1[7] = param_1[7] & 0xfffffffe;
  if ((local_30[0] >> 1 & 1) == 0) {
    return 0;
  }
  return 0x106;
}