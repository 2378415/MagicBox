// 40376618  heap_caps_realloc_base  FUN_40376618  size=320
// strings: heap != NULL && 'realloc() pointer is outside he | heap_caps_base.c | heap_caps_realloc_base | old_size > 0

int FUN_40376618(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint extraout_a3;
  uint *puVar3;
  int in_t0;
  undefined8 uVar4;
  uint local_40 [4];
  uint local_30;
  uint local_2c [11];
  
  local_40[0] = 4;
  local_30 = param_2;
  local_2c[0] = param_3;
  FUN_40377e80(local_40,&local_30,local_2c);
  if (param_1 == 0) {
    iVar1 = FUN_403764a8(local_40[0],local_30,local_2c[0]);
    return iVar1;
  }
  if (local_30 == 0) {
    FUN_4037645c(param_1);
    return 0;
  }
  if (DAT_403746e8 < local_30) {
    return 0;
  }
  puVar3 = (uint *)*DAT_403746b4;
  uVar2 = local_30;
  if (DAT_403746b0 < (uint)(param_1 + DAT_403746ac)) goto LAB_403766ac;
  param_4 = *(int *)(param_1 + -4);
  for (; puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[8]) {
    uVar4 = CONCAT44(local_30,puVar3[7]);
    if (((puVar3[7] != 0) && ((int)puVar3[3] <= param_4)) && (param_4 < (int)puVar3[4])) {
      in_t0 = 0;
      param_3 = 1;
      goto LAB_403766be;
    }
  }
  FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0xd8,
               PTR_s_heap_caps_realloc_base_403746f0,PTR_s_heap____NULL_____realloc___point_403746ec
              );
  uVar2 = extraout_a3;
  do {
    uVar4 = CONCAT44(uVar2,puVar3[7]);
    if (((puVar3[7] != 0) && ((int)puVar3[3] <= param_1)) && (param_1 < (int)puVar3[4])) {
      param_4 = 0;
      in_t0 = 1;
      param_3 = 0;
      goto LAB_403766be;
    }
    puVar3 = (uint *)puVar3[8];
LAB_403766ac:
  } while (puVar3 != (uint *)0x0);
  uVar4 = FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0xe1,
                       PTR_s_heap_caps_realloc_base_403746f0,
                       PTR_s_heap____NULL_____realloc___point_403746ec);
LAB_403766be:
  uVar2 = (uint)((ulonglong)uVar4 >> 0x20);
  if (((~(*puVar3 | puVar3[1] | puVar3[2]) & local_2c[0]) == 0) && (in_t0 != 0)) {
    if (local_40[0] < 5) {
      iVar1 = FUN_40380a1c((int)uVar4,param_1,uVar2);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = local_30;
    }
    iVar1 = FUN_403764a8(local_40[0],uVar2,local_2c[0]);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = FUN_403764a8(local_40[0]);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_3 != 0) {
      uVar2 = FUN_403809ac(puVar3[7],param_4);
      goto LAB_40376711;
    }
  }
  uVar2 = FUN_403809ac(puVar3[7],param_1);
LAB_40376711:
  if (uVar2 == 0) {
    uVar2 = FUN_40381ce4(PTR_s_heap_caps_base_c_3c033a7c_0x16_403746c0,0x10a,
                         PTR_s_heap_caps_realloc_base_403746f0,PTR_s_old_size_>_0_403746f4);
  }
  (*DAT_4037450c)(iVar1,param_1,(uVar2 < local_30) * uVar2 + (uVar2 >= local_30) * local_30);
  FUN_4037645c(param_1);
  return iVar1;
}


