// 4201400c  FUN_4201400c  FUN_4201400c  size=126

void FUN_4201400c(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined1 auStack_70 [32];
  undefined1 uStack_50;
  undefined1 uStack_4f;
  byte bStack_4e;
  undefined1 uStack_4d;
  undefined1 auStack_48 [24];
  int aiStack_30 [12];
  
  for (iVar3 = *(int *)(param_1 + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    aiStack_30[0] = 0;
    while( true ) {
      uStack_8c = 0xff;
      local_90 = 0xff;
      iVar1 = FUN_42015dbc(iVar3,0xff,0x42,0,aiStack_30,&uStack_50);
      if (iVar1 != 0) break;
      uVar2 = *param_2;
      (*DAT_420002fc)(auStack_70,&uStack_50,0x20);
      (*DAT_420002fc)(&local_90,auStack_70,0x20);
      iVar1 = FUN_42013f68(uVar2,0);
      if (iVar1 == 0) {
        FUN_42016228(iVar3,uStack_50,uStack_4f,auStack_48,uStack_4d,0xff);
      }
      aiStack_30[0] = aiStack_30[0] + (uint)bStack_4e;
    }
  }
  return;
}


