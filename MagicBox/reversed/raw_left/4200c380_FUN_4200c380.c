// 4200c380  FUN_4200c380  FUN_4200c380  size=155

undefined4 FUN_4200c380(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  byte *pbVar6;
  code *pcVar7;
  
  puVar2 = PTR_DAT_42000c70;
  if ((((0x3f < param_2) || (uVar4 = (uint)(char)PTR_DAT_42000c70[param_2 * 3 + 1], (int)uVar4 < 0))
      || (*DAT_42000c4c <= uVar4)) ||
     (puVar5 = *(uint **)(uVar4 * 4 + DAT_42000c48), puVar5 == (uint *)0x0)) {
    *param_1 = 9;
    return 0xffffffff;
  }
  pcVar7 = *(code **)(puVar5[1] + 0x18);
  if (pcVar7 == (code *)0x0) {
    *param_1 = 0x58;
    return 0xffffffff;
  }
  if ((*puVar5 & 2) == 0) {
    uVar3 = (*pcVar7)(PTR_DAT_42000c70[param_2 * 3 + 2]);
  }
  else {
    uVar3 = (*pcVar7)(puVar5[7]);
  }
  (*(code *)PTR_FUN_420008d8)(DAT_42000c6c);
  pbVar6 = puVar2 + param_2 * 3;
  bVar1 = *pbVar6;
  if ((bVar1 & 1) == 0) {
    if ((bVar1 & 4) == 0) {
      *pbVar6 = bVar1 >> 2 & 1;
      pbVar6[1] = 0xff;
      pbVar6[2] = 0xff;
    }
    else {
      *pbVar6 = bVar1 | 2;
    }
  }
  (*(code *)PTR_FUN_420008dc)(DAT_42000c6c);
  return uVar3;
}


