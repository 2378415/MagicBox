void FUN_42014698(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [2];
  byte bStack_4e;
  ushort uStack_38;
  int aiStack_30 [12];
  
  for (iVar2 = *(int *)(param_1 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    aiStack_30[0] = 0;
    while( true ) {
      uStack_8c = 0xff;
      local_90 = 0xff;
      iVar1 = FUN_42015dbc(iVar2,0xff,0x42,0,aiStack_30,auStack_50);
      if (iVar1 != 0) break;
      iVar1 = *param_2;
      (*DAT_420002fc)(auStack_70,auStack_50,0x20);
      (*DAT_420002fc)(&local_90,auStack_70,0x20);
      iVar1 = FUN_42013ebc(iVar1,0);
      if (iVar1 != 0) {
        *(uint *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + (uint)uStack_38;
        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
      }
      aiStack_30[0] = aiStack_30[0] + (uint)bStack_4e;
    }
  }
  iVar2 = *param_2;
  while (iVar1 = iVar2, iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x20) == *(int *)(iVar1 + 0x1c)) &&
       (*(uint *)(iVar1 + 0x24) == (uint)*(byte *)(iVar1 + 0x19))) {
      iVar2 = *(int *)(iVar1 + 4);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x10);
      while ((iVar2 != 0 &&
             ((((iVar3 = *(int *)(iVar2 + 0xc), iVar3 == -0x10 || (iVar3 == 0)) || (iVar3 == -1)) ||
              (iVar3 = FUN_42016228(iVar2,*(undefined1 *)(iVar1 + 0x18),0x48,iVar1 + 8,0xff,
                                    *(undefined1 *)(iVar1 + 0x1a)), iVar3 != 0))))) {
        iVar2 = *(int *)(iVar2 + 4);
      }
      iVar2 = *(int *)(iVar1 + 4);
      FUN_42024c54(param_2,iVar1);
      if (iVar1 != 0) {
        (*(code *)PTR_FUN_420004c0)(iVar1);
      }
    }
  }
  return;
}