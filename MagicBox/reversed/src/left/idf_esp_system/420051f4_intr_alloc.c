// strings: find_desc_for_source | intr_alloc | esp_cpu.h | esp_cpu_intr_set_handler | intr_num >= 0 && intr_num < SOC_CPU_INTR_NUM | esp_cpu_intr_edge_ack

undefined4
FUN_420051f4(uint param_1,uint param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 *param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ushort *puVar6;
  uint uVar7;
  uint extraout_a3;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  int *piVar13;
  undefined *puVar14;
  uint uVar15;
  uint in_t0;
  undefined1 in_PRID;
  int aiStack_70 [3];
  uint local_64 [5];
  uint uStack_50;
  uint uStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  uint uStack_38;
  int iStack_34;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  
  if ((~param_2 & 0x300) == 0) {
    return 0x102;
  }
  uVar10 = param_2 & 0xf0;
  if ((param_2 & 0xf0) == 0) {
    uVar7 = param_2 & 0x100;
    if ((param_2 & 0x100) != 0) {
      if (param_5 == 0) {
        uVar10 = 1;
      }
      if (uVar10 != 0) {
        return 0x102;
      }
      if ((int)param_1 < 0) {
        return 0x102;
      }
      uVar7 = 0x100;
    }
    if ((param_3 != 0) && (param_4 == 0)) {
      return 0x102;
    }
    uStack_38 = (uint)(param_5 != 0);
    uVar10 = param_2 >> 10 & 1;
    if ((uStack_38 & uVar10) != 0) {
      if ((DAT_4200035c < (uint)(param_5 + DAT_42000358)) &&
         (DAT_42000360 < (uint)(param_5 + DAT_42000668))) {
        return 0x102;
      }
      uStack_38 = uStack_38 & uVar10;
    }
    if ((param_2 >> 1 & 0x7f) == 0) {
      if (uVar7 == 0) goto LAB_4200527e;
      param_2 = param_2 | 2;
    }
  }
  else {
    if (param_5 != 0) {
      return 0x102;
    }
    if ((param_2 & 0x100) != 0) {
      return 0x102;
    }
    if (param_3 != 0 && param_4 == 0) {
      return 0x102;
    }
    uStack_38 = 0;
    if ((param_2 >> 1 & 0x7f) == 0) {
LAB_4200527e:
      param_2 = param_2 | 0xe;
    }
  }
  uStack_50 = 6;
  if (((((param_1 != 0xffffffff) && (uStack_50 = 0xf, param_1 != 0xfffffffe)) &&
       (uStack_50 = 0x10, param_1 != 0xfffffffd)) &&
      ((uStack_50 = 7, param_1 != 0xfffffffc && (uStack_50 = 0x1d, param_1 != 0xfffffffb)))) &&
     (uStack_50 = 0xb, param_1 != 0xfffffffa)) {
    uStack_50 = 0xffffffff;
  }
  uStack_4c = param_2;
  iStack_48 = param_3;
  iStack_44 = param_4;
  uStack_40 = param_6;
  puStack_3c = (undefined4 *)(*(code *)PTR_FUN_42000660)(8,DAT_420005d8);
  if (puStack_3c == (undefined4 *)0x0) {
    return 0x101;
  }
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200066c,0xffffffff);
  uVar10 = rsr(in_PRID);
  uVar7 = uVar10 >> 0xd & 1;
  (*DAT_42000094)(local_64,0,0xc);
  puVar1 = DAT_42000654;
  puVar9 = (uint *)*DAT_42000654;
  uVar10 = uStack_4c | 0xe;
  if ((uStack_4c & 0xfe) != 0) {
    uVar10 = uStack_4c;
  }
  uVar11 = uStack_4c;
  if (puVar9 == (uint *)0x0) {
    if (uStack_50 == 0xffffffff) goto LAB_42005357;
LAB_420053bf:
    local_64[0] = local_64[0] & DAT_42000658 | (uStack_50 & 0x1f) << 0x11;
    puVar9 = local_64;
LAB_420053d6:
    uVar2 = uStack_50;
    uStack_50 = uVar11;
    iVar3 = FUN_420050ac(puVar9,uVar10,uVar7,uVar2);
    if (iVar3 == 0) {
LAB_4200549d:
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200066c);
      (*(code *)PTR_FUN_42000570)(puStack_3c);
      uVar5 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_intr_alloc_4200067c,PTR_DAT_42000680,uVar5,PTR_s_intr_alloc_4200067c,
                 *(undefined4 *)(PTR_PTR_42000678 + param_1 * 4),uStack_50);
      return 0x105;
    }
    uStack_4c = *puVar9 >> 0x11 & 0x1f;
  }
  else {
    uVar15 = 4;
    puVar8 = puVar9;
    uVar2 = uStack_50;
    do {
      puVar14 = (undefined *)*puVar8;
      if (((ushort)*puVar8 & uVar15) == 0) {
        if ((param_1 == ((int)puVar14 << 2) >> 0x18) && (uVar7 == ((uint)puVar14 >> 0x10 & 1))) {
LAB_42005714:
          uStack_50 = uVar11;
          if (((uVar2 != 0xffffffff) && (uVar2 != ((uint)puVar14 >> 0x11 & 0x1f))) ||
             (iVar3 = FUN_420050ac(puVar8,uVar10,uVar7,uVar2), iVar3 == 0)) goto LAB_4200549d;
          uStack_4c = *puVar8 >> 0x11 & 0x1f;
          goto LAB_420054dc;
        }
      }
      else if (uVar7 == ((uint)puVar14 >> 0x10 & 1)) {
        piVar13 = (int *)puVar8[1];
        if (piVar13 == (int *)0x0) {
          piVar13 = (int *)PTR_s_find_desc_for_source_42000674;
          puVar14 = PTR_s_svd____NULL_42000670;
          uVar2 = in_t0;
          (*(code *)PTR_FUN_420000a8)(PTR_s_intr_alloc_c_3c033c58_0x20_42000650,0xc0);
          uVar11 = uVar2;
          uVar10 = extraout_a3;
          in_t0 = uVar2;
        }
        do {
          if (param_1 == (*piVar13 << 0x17) >> 0x18) goto LAB_42005714;
          piVar13 = (int *)piVar13[5];
        } while (piVar13 != (int *)0x0);
      }
      puVar8 = (uint *)puVar8[2];
    } while (puVar8 != (uint *)0x0);
    if (uVar2 != 0xffffffff) {
      do {
        uStack_50 = uVar2;
        if ((uVar7 == (*puVar9 >> 0x10 & 1)) && (uVar2 == (*puVar9 >> 0x11 & 0x1f)))
        goto LAB_420053d6;
        puVar9 = (uint *)puVar9[2];
      } while (puVar9 != (uint *)0x0);
      goto LAB_420053bf;
    }
LAB_42005357:
    iStack_34 = DAT_42000664;
    uStack_4c = 0xffffffff;
    uVar2 = 0;
    iVar3 = 9;
    uStack_50 = uVar10;
    uStack_30 = param_1;
    uStack_2c = uVar11;
    iStack_28 = param_5;
LAB_42005404:
    for (; puVar9 != (uint *)0x0; puVar9 = (uint *)puVar9[2]) {
      if ((uVar7 == (*puVar9 >> 0x10 & 1)) && ((*puVar9 >> 0x11 & 0x1f) == uVar2))
      goto LAB_4200541d;
    }
    local_64[0] = local_64[0] & DAT_42000658 | (uVar2 & 0x1f) << 0x11;
    puVar9 = local_64;
LAB_4200541d:
    FUN_4200779c(uVar7,uVar2,aiStack_70);
    iVar4 = FUN_420050ac(puVar9,uStack_50,uVar7,0xffffffff);
    if (iVar4 != 0) {
      if ((uVar10 & 0x100) == 0) {
LAB_42005469:
        if (aiStack_70[0] < iVar3) {
          iVar3 = aiStack_70[0];
          uStack_4c = uVar2;
        }
      }
      else if ((*puVar9 & 4) == 0) {
        if (uStack_4c == 0xffffffff) goto LAB_42005469;
      }
      else {
        uVar11 = puVar9[1];
        if (uVar11 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 0;
          do {
            uVar11 = *(uint *)(uVar11 + 0x14);
            iVar4 = iVar4 + 1;
          } while (uVar11 != 0);
        }
        if ((iVar4 < iStack_34) || (aiStack_70[0] < iVar3)) {
          iVar3 = aiStack_70[0];
          uStack_4c = uVar2;
          iStack_34 = iVar4;
        }
      }
    }
    uVar2 = uVar2 + 1;
    if (uVar2 != 0x20) {
      puVar9 = (uint *)*puVar1;
      goto LAB_42005404;
    }
    param_1 = uStack_30;
    param_5 = iStack_28;
    uStack_50 = uStack_2c;
    if (uStack_4c == 0xffffffff) goto LAB_4200549d;
  }
LAB_420054dc:
  puVar9 = (uint *)FUN_4200514c(uStack_4c,uVar7);
  uVar10 = uStack_4c;
  if (puVar9 == (uint *)0x0) {
LAB_4200550b:
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200066c);
    (*(code *)PTR_FUN_42000570)(puStack_3c);
    return 0x101;
  }
  if ((uStack_50 & 0x100) != 0) {
    puVar6 = (ushort *)(*(code *)PTR_FUN_42000660)(0x18,DAT_420005d8);
    if (puVar6 == (ushort *)0x0) goto LAB_4200550b;
    (*DAT_42000094)(puVar6,0,0x18);
    uVar10 = *puVar9;
    uVar11 = puVar9[1];
    *(int *)(puVar6 + 2) = iStack_48;
    *(int *)(puVar6 + 4) = iStack_44;
    *puVar6 = ((ushort)param_1 & 0xff) * 2 | *puVar6 & 0xfe00;
    *(undefined4 *)(puVar6 + 8) = uStack_40;
    *(int *)(puVar6 + 6) = param_5;
    *(uint *)(puVar6 + 10) = uVar11;
    puVar9[1] = (uint)puVar6;
    *(ushort *)puVar9 = (ushort)uVar10 | 4;
    if (0x1f < uStack_4c) {
LAB_4200556d:
      (*(code *)PTR_FUN_420000a8)
                (PTR_s_esp_cpu_h_3c033d20_0x28_4200068c,0x168,
                 PTR_s_esp_cpu_intr_set_handler_42000688,
                 PTR_s_intr_num_>__0____intr_num_<_SOC__42000684);
      uStack_50 = in_t0;
    }
    uVar10 = uStack_4c;
    FUN_4202f014(uStack_4c,PTR_FUN_42000690,puVar9);
    uVar12 = (ushort)*puVar9;
    uVar10 = 1 << 0x20 - (0x20 - (uVar10 & 0x1f));
    goto LAB_42005629;
  }
  *(ushort *)puVar9 = 8;
  if (uStack_38 == 0) {
    if ((uStack_50 & 0x200) == 0) {
      uVar10 = 1 << 0x20 - (0x20 - (uStack_4c & 0x1f));
      uVar12 = 8;
    }
    else {
      if (0x1f < uStack_4c) {
        (*(code *)PTR_FUN_420000a8)
                  (PTR_s_esp_cpu_h_3c033d20_0x28_4200068c,0x1b7,PTR_s_esp_cpu_intr_edge_ack_42000694
                   ,PTR_s_intr_num_>__0____intr_num_<_SOC__42000684);
        uStack_50 = in_t0;
      }
LAB_420055fd:
      uVar10 = 1 << 0x20 - (0x20 - (uStack_4c & 0x1f));
      (*DAT_420006a4)(uVar10);
      uVar12 = (ushort)*puVar9;
    }
  }
  else {
    if (0x1f < uStack_4c) goto LAB_4200556d;
    FUN_4202f014(uStack_4c,param_5,uStack_40);
    if ((uStack_50 & 0x200) != 0) goto LAB_420055fd;
    uVar12 = (ushort)*puVar9;
    uVar10 = 1 << 0x20 - (0x20 - (uVar10 & 0x1f));
  }
  *puVar9 = *puVar9 & DAT_42000698 | (param_1 & 0xff) << 0x16;
LAB_42005629:
  uVar11 = *(uint *)(uVar7 * 4 + DAT_4200069c);
  if ((uStack_50 & 0x400) == 0) {
    uVar12 = uVar12 & 0xfffd;
    uVar11 = uVar10 | uVar11;
  }
  else {
    uVar12 = uVar12 | 2;
    uVar11 = uVar10 & uVar11 ^ uVar11;
  }
  *(uint *)(DAT_4200069c + uVar7 * 4) = uVar11;
  *(ushort *)puVar9 = uVar12;
  if (-1 < (int)param_1) {
    (*DAT_42000268)(uVar7,param_1,uStack_4c);
  }
  puStack_3c[1] = puVar9[1];
  *puStack_3c = puVar9;
  (*(code *)PTR_FUN_420006a8)(uVar10);
  if ((uStack_50 & 0x800) != 0) {
    (*(code *)PTR_FUN_420006ac)(puStack_3c);
  }
  (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200066c);
  if (param_7 == (undefined4 *)0x0) {
    (*(code *)PTR_FUN_42000570)(puStack_3c);
  }
  else {
    *param_7 = puStack_3c;
  }
  if (3 < *(uint *)PTR_DAT_42000028) {
    uVar5 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_420006a0,uVar5,PTR_s_intr_alloc_4200067c,param_1,uStack_4c,uVar7);
  }
  return 0;
}