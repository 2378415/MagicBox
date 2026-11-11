undefined4 FUN_4200c4f0(uint param_1)

{
  undefined1 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  code *pcVar6;
  
  if ((((0x3f < param_1) || (uVar5 = (uint)(char)PTR_DAT_42000c70[param_1 * 3 + 1], (int)uVar5 < 0))
      || (*DAT_42000c4c <= uVar5)) ||
     (puVar2 = *(uint **)(uVar5 * 4 + DAT_42000c48), puVar2 == (uint *)0x0)) {
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_420008c8)();
    *puVar3 = 9;
    return 0xffffffff;
  }
  uVar1 = PTR_DAT_42000c70[param_1 * 3 + 2];
  puVar3 = (undefined4 *)(*(code *)PTR_FUN_420008c8)();
  pcVar6 = *(code **)(puVar2[1] + 0x28);
  if (pcVar6 == (code *)0x0) {
    *puVar3 = 0x58;
    return 0xffffffff;
  }
  if ((*puVar2 & 2) == 0) {
    uVar4 = (*pcVar6)(uVar1);
    return uVar4;
  }
  uVar4 = (*pcVar6)(puVar2[7],uVar1);
  return uVar4;
}