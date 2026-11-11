// 42013d1c  FUN_42013d1c  FUN_42013d1c  size=176

undefined4 FUN_42013d1c(undefined4 param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_30;
  undefined1 uStack_2c;
  undefined1 auStack_2b [43];
  
  auStack_2b[0] = 0x5a;
  (*(code *)PTR_FUN_42000480)(*DAT_42001258,0xffffffff);
  iVar1 = DAT_42001220;
  local_30 = param_3 + 8;
  *(undefined2 *)(DAT_42001220 + 2) = 0;
  uStack_2c = 0xa1;
  FUN_4200ad84(1,auStack_2b);
  FUN_4200ad84(1,&uStack_2c);
  FUN_4200ad84(1,&local_30,2);
  FUN_4200ad84(1,param_1,8);
  if ((param_2 != 0) && (param_3 != 0)) {
    FUN_4200ad84(1,param_2,param_3);
  }
  iVar2 = (*(code *)PTR_FUN_42000480)(*DAT_42001230,DAT_4200128c);
  if (iVar2 == 1) {
    if ((*(short *)(iVar1 + 2) == 0) || (*(char *)(iVar1 + 4) != -1)) {
      if ((param_4 != 0) && (param_5 != (uint *)0x0)) {
        (*DAT_42000064)(param_4,DAT_42001234);
        *param_5 = (uint)*(ushort *)(iVar1 + 2);
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 0xfffffffe;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  (*(code *)PTR_FUN_42000488)(*DAT_42001258,0,0);
  return uVar3;
}


