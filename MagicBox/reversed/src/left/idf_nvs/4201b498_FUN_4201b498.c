undefined4 FUN_4201b498(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_50 [2];
  byte bStack_4e;
  undefined1 auStack_48 [16];
  int iStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  int aiStack_30 [12];
  
  iVar3 = *(int *)(param_1 + 0x10);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    aiStack_30[0] = 0;
    while (iVar2 = FUN_4201d244(iVar3,0xff,0x48,0,aiStack_30,auStack_50,0xff,0xff), iVar2 == 0) {
      piVar1 = (int *)(*(code *)PTR_FUN_4200056c)(0x28);
      if (piVar1 == (int *)0x0) {
        return 0x101;
      }
      *piVar1 = 0;
      piVar1[1] = 0;
      (*DAT_42000da8)(piVar1 + 2,auStack_48,0x10);
      iVar4 = param_2[1];
      *(undefined1 *)(piVar1 + 6) = auStack_50[0];
      *(undefined1 *)((int)piVar1 + 0x17) = 0;
      *(undefined1 *)((int)piVar1 + 0x1a) = uStack_33;
      piVar1[8] = 0;
      *(undefined1 *)((int)piVar1 + 0x19) = uStack_34;
      piVar1[9] = 0;
      piVar1[7] = iStack_38;
      iVar2 = 0;
      if (iVar4 != 0) {
        *(int **)(iVar4 + 4) = piVar1;
        iVar2 = param_2[1];
      }
      iVar4 = *param_2;
      *piVar1 = iVar2;
      piVar1[1] = 0;
      param_2[1] = (int)piVar1;
      if (iVar4 == 0) {
        *param_2 = (int)piVar1;
      }
      aiStack_30[0] = aiStack_30[0] + (uint)bStack_4e;
      param_2[2] = param_2[2] + 1;
    }
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}