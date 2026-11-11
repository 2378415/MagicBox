undefined4 FUN_4201a3dc(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if ((param_1 == (int *)0x0) || (param_3 == (undefined4 *)0x0 || param_1 == (int *)0x0)) {
    uVar6 = 0x103;
  }
  else {
    FUN_42005720(0x34,0,param_2,param_3 == (undefined4 *)0x0 || param_1 == (int *)0x0,DAT_4200191c);
    iVar5 = FUN_4202dd8c(10);
    iVar3 = DAT_42001920;
    uVar2 = DAT_420009f8;
    iVar1 = DAT_42000284;
    if (iVar5 == 0) {
      memw();
      memw();
      *(uint *)(DAT_42000284 + 0x18) = *(uint *)(DAT_42000284 + 0x18) | DAT_420009f8;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000a74;
      memw();
      memw();
      *(uint *)(iVar3 + 0x48) = *(uint *)(iVar3 + 0x48) & DAT_42000294;
    }
    FUN_4202ddac(10,iVar5);
    uVar4 = DAT_42001924;
    (*DAT_420002a4)(DAT_42001924,1,DAT_42000298);
    (*DAT_42000174)(uVar4);
    (*DAT_420001f4)(uVar4,0,*param_1 * 2,1);
    (*DAT_420001f4)(uVar4,1,*param_1 << 2,3);
    (*DAT_4200017c)(uVar4);
    uVar6 = 0;
    *param_3 = uVar4;
  }
  return uVar6;
}