// 40380134  FUN_40380134  FUN_40380134  size=175

void FUN_40380134(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint local_40 [4];
  int *piStack_30;
  
  puVar1 = (uint *)param_1[1];
  memw();
  memw();
  puVar1[0xf] = puVar1[0xf] & 0xfffffffd;
  memw();
  memw();
  puVar1[7] = puVar1[7] & 0x3ffffff | DAT_403751ac;
  memw();
  memw();
  puVar1[6] = puVar1[6] | DAT_4037460c;
  memw();
  puVar1[1] = param_3 & 0xffffff | param_4 << 0x18;
  memw();
  memw();
  puVar1[6] = puVar1[6] & DAT_40374864;
  uVar2 = param_4 + 3 >> 2;
  piStack_30 = param_1;
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      iVar3 = (param_4 < 4) * param_4 + (uint)(param_4 >= 4) * 4;
      local_40[0] = 0;
      (*DAT_4037450c)(local_40,param_2,iVar3);
      memw();
      puVar1[uVar4 + 0x16] = local_40[0];
      uVar4 = uVar4 + 1;
      param_4 = param_4 - iVar3;
      param_2 = param_2 + iVar3;
    } while (uVar2 != uVar4);
  }
  memw();
  pcVar5 = *(code **)(*piStack_30 + 0x40);
  memw();
  *puVar1 = *puVar1 | DAT_403746e8;
  (*pcVar5)(piStack_30);
  return;
}


