uint FUN_420105c0(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_1 == (undefined4 *)0x0 || param_2 == (undefined4 *)0x0) {
    uVar11 = 0x102;
  }
  else {
    uVar1 = FUN_42010468(*param_1,*param_2);
    uVar2 = FUN_42010468(param_1[1],param_2[1]);
    uVar3 = FUN_42010468(param_1[2],param_2[3]);
    uVar4 = FUN_42010468(param_1[7],param_2[2]);
    uVar5 = FUN_42010468(param_1[8],param_2[4]);
    uVar6 = FUN_420104dc(param_1[3],param_2[5]);
    uVar7 = FUN_420104dc(param_1[4],param_2[6]);
    uVar8 = FUN_420104dc(param_1[5],param_2[7]);
    uVar9 = FUN_420104dc(param_1[6],param_2[8]);
    uVar10 = FUN_420104dc(param_1[9],param_2[9]);
    uVar11 = FUN_420104dc(param_1[10],param_2[10]);
    uVar11 = uVar3 | uVar2 | uVar1 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11
    ;
  }
  return uVar11;
}