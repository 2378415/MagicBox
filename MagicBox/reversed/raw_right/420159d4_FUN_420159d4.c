// 420159d4  FUN_420159d4  FUN_420159d4  size=112

int FUN_420159d4(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_30 [12];
  
  if (param_3 < 0x7f) {
    if (param_2 < param_3) {
      param_3 = param_3 - 1;
      uVar1 = param_3 >> 4;
      for (; (int)param_2 <= (int)param_3; param_3 = param_3 - 1) {
        iVar3 = FUN_42025004(param_1 + 0x18,param_3,param_4);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (param_2 == param_3) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = param_3 - 1 >> 4;
        }
        if (uVar1 != uVar2) {
          local_30[0] = *(undefined4 *)(uVar1 * 4 + param_1 + 0x18);
          iVar3 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                            (*(int **)(param_1 + 0x50),uVar1 * 4 + *(int *)(param_1 + 8) + 0x20,
                             local_30,4);
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        uVar1 = uVar2;
      }
      iVar3 = 0;
    }
    else {
      iVar3 = -1;
    }
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}


