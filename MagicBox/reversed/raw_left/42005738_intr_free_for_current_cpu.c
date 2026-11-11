// 42005738  intr_free_for_current_cpu  FUN_42005738  size=203
// strings: intr_free_for_current_cpu | _free_for_current_cpu

void FUN_42005738(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200066c,0xffffffff);
  (*(code *)PTR_FUN_420006ac)(param_1);
  puVar5 = (uint *)*param_1;
  uVar1 = (ushort)*puVar5;
  if ((uVar1 & 4) == 0) {
LAB_4200575c:
    if ((uVar1 & 8) == 0) goto LAB_420057f4;
  }
  else {
    uVar4 = puVar5[1];
    if (uVar4 == 0) {
      puVar5 = (uint *)PTR_s_intr_free_for_current_cpu_420006b4;
      uVar4 = (*(code *)PTR_FUN_420000a8)
                        (PTR_s_intr_alloc_c_3c033c58_0x20_42000650,0x300,
                         PTR_s_intr_free_for_current_cpu_420006b4,PTR_DAT_420006b0);
    }
    uVar3 = 0;
    while (uVar2 = *(uint *)(uVar4 + 0x14), param_1[1] != uVar4) {
      if (uVar2 == 0) goto LAB_42005759;
      uVar3 = uVar4;
      uVar4 = uVar2;
    }
    if (uVar3 == 0) {
      puVar5[1] = uVar2;
    }
    else {
      *(uint *)(uVar3 + 0x14) = uVar2;
    }
    (*(code *)PTR_FUN_42000570)();
    puVar5 = (uint *)*param_1;
    if (puVar5[1] != 0) {
LAB_42005759:
      uVar1 = (ushort)*puVar5;
      goto LAB_4200575c;
    }
  }
  uVar4 = *puVar5 >> 0x11 & 0x1f;
  FUN_4202f014(uVar4,0,uVar4);
  puVar5 = (uint *)*param_1;
  *(ushort *)puVar5 = (ushort)*puVar5 & 0xfff2;
  uVar4 = *puVar5 & DAT_42000698 | DAT_420006b8;
  *puVar5 = uVar4;
  puVar5 = (uint *)((uVar4 >> 0x10 & 1) * 4 + DAT_4200069c);
  *puVar5 = (uint)(0xfffffffefffffffe >> 0x20 - (uVar4 >> 0x11 & 0x1f)) & *puVar5;
LAB_420057f4:
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200066c);
  (*(code *)PTR_FUN_42000570)(param_1);
  return;
}


