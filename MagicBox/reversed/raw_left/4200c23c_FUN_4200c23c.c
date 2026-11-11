// 4200c23c  FUN_4200c23c  FUN_4200c23c  size=105

undefined4 FUN_4200c23c(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  code *pcVar4;
  
  if ((((0x3f < param_2) || (uVar2 = (uint)(char)PTR_DAT_42000c70[param_2 * 3 + 1], (int)uVar2 < 0))
      || (*DAT_42000c4c <= uVar2)) ||
     (puVar3 = *(uint **)(uVar2 * 4 + DAT_42000c48), puVar3 == (uint *)0x0)) {
    *param_1 = 9;
    return 0xffffffff;
  }
  pcVar4 = *(code **)puVar3[1];
  if (pcVar4 == (code *)0x0) {
    *param_1 = 0x58;
    return 0xffffffff;
  }
  if ((*puVar3 & 2) == 0) {
    uVar1 = (*pcVar4)(PTR_DAT_42000c70[param_2 * 3 + 2],param_3,param_4);
    return uVar1;
  }
  uVar1 = (*pcVar4)(puVar3[7],PTR_DAT_42000c70[param_2 * 3 + 2],param_3,param_4);
  return uVar1;
}


