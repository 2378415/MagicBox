void FUN_40376f00(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  (*DAT_403744c4)(param_1,0,0xf0);
  uVar2 = *(undefined4 *)(PTR_DAT_4037478c + 0xc);
  uVar3 = *(undefined4 *)(PTR_DAT_4037478c + 8);
  uVar4 = *(undefined4 *)(PTR_DAT_4037478c + 4);
  uVar1 = *(undefined4 *)(PTR_DAT_4037478c + 0x18);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(PTR_DAT_4037478c + 0x28);
  *(undefined4 *)(param_1 + 4) = uVar4;
  *(undefined4 *)(param_1 + 8) = uVar3;
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}