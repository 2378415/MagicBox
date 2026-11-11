// 42024898  FUN_42024898  FUN_42024898  size=75

void FUN_42024898(byte *param_1,ushort param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if ((1 < param_2) && (param_1[1] == 3)) {
    uVar2 = (*param_1 - 2) - ((int)(*param_1 - 2) >> 0x1f) >> 1 & 0xff;
    if (param_4 - 1 < uVar2) {
      uVar2 = (param_4 & 0xff) - 1 & 0xff;
    }
    for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1 & 0xff) {
      *(byte *)(param_3 + uVar1) = param_1[(uVar1 + 1) * 2];
    }
    *(undefined1 *)(param_3 + uVar2) = 0;
  }
  return;
}


