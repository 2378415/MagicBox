// 4200c860  FUN_4200c860  FUN_4200c860  size=121

undefined4 FUN_4200c860(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  code *pcVar6;
  
  if ((((param_1 < 0x40) && (uVar5 = (uint)(char)PTR_DAT_42000c70[param_1 * 3 + 1], -1 < (int)uVar5)
       ) && (uVar5 < *DAT_42000c4c)) &&
     (puVar2 = *(uint **)(uVar5 * 4 + DAT_42000c48), puVar2 != (uint *)0x0)) {
    uVar1 = PTR_DAT_42000c70[param_1 * 3 + 2];
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_420008c8)();
    if ((*(undefined4 **)(puVar2[1] + 0x30) != (undefined4 *)0x0) &&
       (pcVar6 = (code *)**(undefined4 **)(puVar2[1] + 0x30), pcVar6 != (code *)0x0)) {
      if ((*puVar2 & 2) == 0) {
        uVar4 = (*pcVar6)(uVar1,param_2,param_3);
        return uVar4;
      }
      uVar4 = (*pcVar6)(puVar2[7],uVar1,param_2,param_3);
      return uVar4;
    }
    *puVar3 = 0x58;
  }
  else {
    puVar3 = (undefined4 *)(*(code *)PTR_FUN_420008c8)();
    *puVar3 = 9;
  }
  return 0xffffffff;
}


