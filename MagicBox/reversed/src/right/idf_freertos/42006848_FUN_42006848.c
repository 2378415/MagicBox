void FUN_42006848(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000774,0xffffffff);
  for (iVar1 = 0; iVar1 < *DAT_42000780; iVar1 = iVar1 + 1) {
    puVar2 = *(undefined4 **)(iVar1 * 4 + *DAT_42000778);
    if (puVar2 != (undefined4 *)0x0) {
      if (param_2 == 1) {
        if (param_1 < 0x40) {
          uVar3 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
          if ((puVar2[(param_1 >> 5) + 7] & uVar3) != 0) {
            puVar4 = (uint *)((param_1 >> 5) * 4 + puVar2[3]);
            *puVar4 = uVar3 | *puVar4;
            FUN_4200a6e0(*puVar2,puVar2[1],param_3);
          }
        }
      }
      else if (param_2 == 2) {
        if (param_1 < 0x40) {
          uVar3 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
          if ((puVar2[(param_1 >> 5) + 9] & uVar3) != 0) {
            puVar4 = (uint *)((param_1 >> 5) * 4 + puVar2[4]);
            *puVar4 = uVar3 | *puVar4;
            FUN_4200a6e0(*puVar2,puVar2[1],param_3);
          }
        }
      }
      else if ((param_2 == 0) && (param_1 < 0x40)) {
        uVar3 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        if ((puVar2[(param_1 >> 5) + 5] & uVar3) != 0) {
          puVar4 = (uint *)((param_1 >> 5) * 4 + puVar2[2]);
          *puVar4 = uVar3 | *puVar4;
          FUN_4200a6e0(*puVar2,puVar2[1],param_3);
        }
      }
    }
  }
  (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000774);
  return;
}