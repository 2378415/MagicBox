// 420034e8  FUN_420034e8  FUN_420034e8  size=324

uint FUN_420034e8(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_50 [3];
  int aiStack_44 [5];
  uint uStack_30;
  int iStack_2c;
  
  (*DAT_42000240)(local_50,0,0xc);
  if ((param_1 >> 1 & 0x7f) == 0) {
    param_1 = param_1 | 0xe;
  }
  puVar1 = (uint *)FUN_420033ac(param_4,param_2);
  if (puVar1 == (uint *)0x0) {
    if (param_3 == 0xffffffff) {
      iStack_2c = DAT_4200049c;
      iVar2 = 9;
      uStack_30 = 0xffffffff;
      for (uVar4 = 0; (int)uVar4 < 0x20; uVar4 = uVar4 + 1) {
        puVar1 = (uint *)FUN_42003330(uVar4,param_2);
        if (puVar1 == (uint *)0x0) {
          local_50[0] = local_50[0] & DAT_4200047c | (uVar4 & 0x1f) << 0x11;
          puVar1 = local_50;
        }
        FUN_42005af8(param_2,uVar4,aiStack_44);
        iVar3 = FUN_42003420(puVar1,param_1,param_2,0xffffffff);
        if (iVar3 != 0) {
          if ((param_1 & 0x100) == 0) {
            if (aiStack_44[0] < iVar2) {
              iVar2 = aiStack_44[0];
              uStack_30 = uVar4;
            }
          }
          else if ((*(ushort *)puVar1 & 4) == 0) {
            if ((uStack_30 == 0xffffffff) && (aiStack_44[0] < iVar2)) {
              iVar2 = aiStack_44[0];
              uStack_30 = uVar4;
            }
          }
          else {
            iVar5 = 0;
            for (iVar3 = *(int *)((int)puVar1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
              iVar5 = iVar5 + 1;
            }
            if ((iVar5 < iStack_2c) || (aiStack_44[0] < iVar2)) {
              iVar2 = aiStack_44[0];
              uStack_30 = uVar4;
              iStack_2c = iVar5;
            }
          }
        }
      }
    }
    else {
      puVar1 = (uint *)FUN_42003330(param_3,param_2);
      if (puVar1 == (uint *)0x0) {
        local_50[0] = local_50[0] & DAT_4200047c | (param_3 & 0x1f) << 0x11;
        puVar1 = local_50;
      }
      iVar2 = FUN_42003420(puVar1,param_1,param_2,param_3);
      if (iVar2 == 0) {
        uStack_30 = 0xffffffff;
      }
      else {
        uStack_30 = *puVar1 >> 0x11 & 0x1f;
      }
    }
  }
  else if ((param_3 == 0xffffffff) || ((*puVar1 >> 0x11 & 0x1f) == param_3)) {
    iVar2 = FUN_42003420(puVar1,param_1,param_2,param_3);
    if (iVar2 == 0) {
      uStack_30 = 0xffffffff;
    }
    else {
      uStack_30 = *puVar1 >> 0x11 & 0x1f;
    }
  }
  else {
    uStack_30 = 0xffffffff;
  }
  return uStack_30;
}


