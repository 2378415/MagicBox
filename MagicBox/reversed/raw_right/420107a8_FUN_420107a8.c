// 420107a8  FUN_420107a8  FUN_420107a8  size=232

undefined4 FUN_420107a8(int *param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  uint local_30;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x102;
  }
  else if (param_2 < 4) {
    if (param_1[1] == 0) {
      iVar3 = *param_1;
      if (iVar3 == 2) {
        uVar1 = 0xffffffff;
      }
      else if (param_1[3] == 2) {
        if ((iVar3 == 1) == (param_2 == 3)) {
          param_1[4] = param_2;
          if (iVar3 == 1) {
            uVar1 = 0;
          }
          else {
            if (param_2 == 1) {
              local_30 = 0x100;
            }
            else {
              local_30 = 1;
            }
            puVar2 = (uint *)param_1[6];
            memw();
            memw();
            *puVar2 = *puVar2 & DAT_4200088c | (local_30 & 0xff) << 0xd;
            memw();
            memw();
            *puVar2 = *puVar2 & DAT_4200016c;
            memw();
            memw();
            *puVar2 = *puVar2 & DAT_42000164 | (local_30 >> 8) << 0xf;
            memw();
            memw();
            *puVar2 = *puVar2 & DAT_42000480;
            memw();
            memw();
            *puVar2 = *puVar2 | DAT_4200077c;
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0x106;
        }
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}


