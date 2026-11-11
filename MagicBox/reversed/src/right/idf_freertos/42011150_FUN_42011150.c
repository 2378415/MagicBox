undefined4 FUN_42011150(uint param_1,uint param_2)

{
  uint *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((int)param_1 < 0) {
    uVar3 = 0x102;
  }
  else {
    uVar4 = DAT_42000504 << 0x20 - (0x20 - ((param_1 ^ 0xffffffff) & 0x1f)) |
            DAT_42000508 >> (param_1 & 0x1f);
    if ((param_1 & 0x20) != 0) {
      uVar4 = DAT_4200050c >> (param_1 & 0x1f);
    }
    if ((uVar4 & 1) == 0) {
      uVar3 = 0x102;
    }
    else if (param_2 < 6) {
      (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000dfc,0xffffffff);
      iVar6 = (param_1 + 0x1c) * 4 + **(int **)PTR_PTR_42000e00;
      memw();
      memw();
      *(uint *)(iVar6 + 4) = *(uint *)(iVar6 + 4) & 0xfffffc7f | (param_2 & 7) << 7;
      puVar2 = PTR_PTR_42000e00;
      if (param_2 - 1 < 3) {
        puVar1 = (uint *)(PTR_PTR_42000e00 + 0x1c);
        uVar4 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        if ((param_1 & 0x20) == 0) {
          uVar5 = uVar4;
          uVar4 = 0;
        }
        else {
          uVar5 = 0;
        }
        *(uint *)(PTR_PTR_42000e00 + 0x18) = *(uint *)(PTR_PTR_42000e00 + 0x18) | uVar5;
        *(uint *)(puVar2 + 0x1c) = *puVar1 | uVar4;
      }
      else {
        puVar1 = (uint *)(PTR_PTR_42000e00 + 0x1c);
        uVar4 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
        if ((param_1 & 0x20) == 0) {
          uVar5 = uVar4;
          uVar4 = 0;
        }
        else {
          uVar5 = 0;
        }
        *(uint *)(PTR_PTR_42000e00 + 0x18) =
             uVar5 & *(uint *)(PTR_PTR_42000e00 + 0x18) ^ *(uint *)(PTR_PTR_42000e00 + 0x18);
        *(uint *)(puVar2 + 0x1c) = uVar4 & *puVar1 ^ *puVar1;
      }
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000dfc);
      uVar3 = 0;
    }
    else {
      uVar3 = 0x102;
    }
  }
  return uVar3;
}