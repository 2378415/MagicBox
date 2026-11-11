undefined4 FUN_42013b20(char param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_40 [16];
  char acStack_30 [4];
  int aiStack_2c [11];
  
  puVar2 = DAT_42001258;
  local_40[0] = 0x5a;
  acStack_30[0] = param_1;
  aiStack_2c[0] = param_3;
  (*(code *)PTR_FUN_42000480)(*DAT_42001258,0xffffffff);
  iVar1 = DAT_42001220;
  *(undefined2 *)(DAT_42001220 + 2) = 0;
  FUN_4200ad84(1,local_40);
  FUN_4200ad84(1,acStack_30);
  FUN_4200ad84(1,aiStack_2c,2);
  if ((param_2 != 0) && (aiStack_2c[0] != 0)) {
    FUN_4200ad84(1,param_2);
  }
  iVar3 = (*(code *)PTR_FUN_42000480)(*DAT_42001230,1000);
  if (iVar3 != 1) {
    uVar4 = 0xffffffff;
    goto LAB_42013bda;
  }
  if (acStack_30[0] == -0x60) {
LAB_42013b88:
    if (*(short *)(iVar1 + 2) != 0) {
LAB_42013b8e:
      if (*(char *)(iVar1 + 4) != -1) goto LAB_42013bb6;
    }
    uVar4 = 0xfffffffe;
  }
  else {
    if (acStack_30[0] == -0x5f) {
      if (*(short *)(iVar1 + 2) != 0) goto LAB_42013b8e;
    }
    else if (acStack_30[0] == -0x5c) goto LAB_42013b88;
LAB_42013bb6:
    if ((param_4 != 0) && (param_5 != (uint *)0x0)) {
      (*DAT_42000064)(param_4,DAT_42001234,*(undefined2 *)(iVar1 + 2));
      *param_5 = (uint)*(ushort *)(iVar1 + 2);
    }
    uVar4 = 0;
  }
LAB_42013bda:
  (*(code *)PTR_FUN_42000488)(*puVar2,0,0);
  return uVar4;
}