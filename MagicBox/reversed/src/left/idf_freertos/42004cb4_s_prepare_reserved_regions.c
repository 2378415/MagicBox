// strings: memory_layout | memory_layout_utils.c | s_prepare_reserved_regions | reserved[i].start <= reserved[i].end | reserved[i + 1].start > reserved[i].start

/* (1 unreachable decompiler blocks omitted) */

int FUN_42004cb4(uint *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint extraout_a3;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  uint in_t0;
  int in_WindowStart;
  undefined1 auStack_70 [16];
  uint *puStack_60;
  uint uStack_5c;
  uint *puStack_40;
  uint *puStack_3c;
  uint *puStack_38;
  uint *puStack_34;
  uint *puStack_30;
  uint *puStack_2c;
  
  puStack_38 = (uint *)(*(int *)PTR_DAT_420005ec * 0x14);
  iVar4 = (uint)(in_WindowStart == 0) * (int)auStack_70;
  iVar2 = (uint)(in_WindowStart != 0) * (int)(auStack_70 + -((int)puStack_38 + 0xfU & 0xfffffff0));
  puStack_40 = (uint *)(iVar4 + iVar2 + 0x10);
  puStack_3c = param_1;
  (*DAT_42000064)(puStack_40,PTR_DAT_420005f0);
  iVar1 = (uint)(in_WindowStart == 0) * (iVar4 + iVar2);
  iVar4 = (uint)(in_WindowStart != 0) *
          ((iVar4 + iVar2) - (((int)PTR_PTR_420005e4 - (int)PTR_DAT_420005e8) + 0x17U & 0xfffffff0))
  ;
  puVar6 = (uint *)(iVar1 + iVar4 + 0x10);
  puVar9 = (uint *)((int)PTR_PTR_420005e4 - (int)PTR_DAT_420005e8 >> 3);
  *puVar6 = *(uint *)(*DAT_420005f4 + 4);
  puVar7 = (uint *)((int)puVar9 + 1);
  *(undefined4 *)(iVar1 + iVar4 + 0x14) = DAT_420005f8;
  (*DAT_42000064)(iVar1 + iVar4 + 0x18);
  (*DAT_4200062c)(puVar6,puVar7,8,PTR_FUN_420005fc);
  uVar12 = *(uint *)PTR_DAT_42000028;
  if (uVar12 < 4) {
    puVar8 = puStack_40;
    if (puVar7 == (uint *)0x0) goto LAB_42004e36;
LAB_42004d6e:
    puVar8 = (uint *)0x0;
    puStack_34 = puVar6;
    do {
      if (3 < uVar12) {
        uVar5 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42000608,uVar5,PTR_s_memory_layout_42000600,*puVar6,puVar6[1]);
      }
      uVar18 = *puVar6 & 0xfffffffc;
      uVar12 = puVar6[1] + 3 & 0xfffffffc;
      *puVar6 = uVar18;
      puVar6[1] = uVar12;
      if ((int)uVar12 < (int)uVar18) {
        uVar12 = in_t0;
        uVar18 = (*(code *)PTR_FUN_420000a8)
                           (PTR_s_memory_layout_utils_c_3c0338d0_0x1b_42000614,0x66,
                            PTR_s_s_prepare_reserved_regions_42000610,
                            PTR_s_reserved_i__start_<__reserved[i]_4200060c);
        in_t0 = uVar12;
      }
      if (puVar8 < puVar9) {
        uVar14 = puVar6[2];
        if ((int)uVar14 <= (int)uVar18) {
          uVar12 = in_t0;
          (*(code *)PTR_FUN_420000a8)
                    (PTR_s_memory_layout_utils_c_3c0338d0_0x1b_42000614,0x68,
                     PTR_s_s_prepare_reserved_regions_42000610,
                     PTR_s_reserved_i___1__start_>_reserved_42000618);
          uVar14 = extraout_a3;
          in_t0 = uVar12;
        }
        if ((int)uVar14 < (int)uVar12) {
          if (*(int *)PTR_DAT_42000028 != 0) {
            uVar5 = (*(code *)PTR_FUN_4200005c)();
            *(uint *)(iVar1 + iVar4) = puVar6[3];
            (*DAT_42000060)(PTR_DAT_4200061c,uVar5,PTR_s_memory_layout_42000600,*puVar6,puVar6[1],
                            puVar6[2]);
          }
          (*(code *)PTR_FUN_42000330)();
        }
      }
      puVar8 = (uint *)((int)puVar8 + 1);
      uVar12 = *(uint *)PTR_DAT_42000028;
      puVar6 = puVar6 + 2;
    } while (puVar8 < puVar7);
    puVar6 = puStack_34;
  }
  else {
    uVar5 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42000604,uVar5,PTR_s_memory_layout_42000600,puVar7);
    uVar12 = *(uint *)PTR_DAT_42000028;
    if (puVar7 != (uint *)0x0) goto LAB_42004d6e;
  }
  puVar8 = puStack_40;
  if (3 < *(uint *)PTR_DAT_42000028) {
    uVar5 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42000620,uVar5,PTR_s_memory_layout_42000600);
    puVar8 = puStack_40;
  }
LAB_42004e36:
  puStack_40 = (uint *)((int)puVar8 + (int)puStack_38);
  if (puVar8 == puStack_40) {
    iVar4 = 0;
  }
  else {
    puStack_38 = puStack_3c;
    do {
      (*DAT_42000064)(&puStack_60,puVar8,0x14);
      puVar3 = puStack_38;
      puVar15 = (uint *)*puVar8;
      uVar18 = puVar8[1];
      uVar12 = uVar18;
      puVar16 = puVar15;
      if (puVar7 == (uint *)0x0) {
LAB_42004f04:
        if (*(uint *)PTR_DAT_42000028 < 4) {
          puStack_38 = puStack_38 + 5;
          puStack_60 = puVar16;
          uStack_5c = uVar12;
          (*DAT_42000064)(puVar3,&puStack_60);
        }
        else {
          puStack_34 = puVar16;
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_42000628,uVar5,PTR_s_memory_layout_42000600,puStack_34,
                          (int)puStack_34 + uVar12);
          puVar3 = puStack_38;
          puStack_38 = puStack_38 + 5;
          puStack_60 = puStack_34;
          uStack_5c = uVar12;
          (*DAT_42000064)(puVar3,&puStack_60,0x14);
        }
      }
      else {
        puVar10 = puVar6;
        puVar13 = (uint *)0x0;
        uVar14 = (int)puVar15 + uVar18;
        while( true ) {
          puVar11 = (uint *)puVar10[1];
          uVar17 = uVar14;
          if ((int)puVar16 < (int)puVar11) {
            uVar17 = *puVar10;
            if ((int)uVar14 <= (int)uVar17) goto LAB_42004f04;
            if ((int)puVar16 < (int)uVar17) {
              uVar12 = uVar17 - (int)puVar16;
              if ((int)puVar11 < (int)uVar14) {
                puVar8[1] = uVar18 - ((int)puVar11 - (int)puVar15);
                *puVar8 = (uint)puVar11;
                if (0x10 < (int)uVar12) {
                  puStack_34 = puStack_38 + 5;
                  if (3 < *(uint *)PTR_DAT_42000028) {
                    puStack_30 = (uint *)uVar17;
                    puStack_2c = puVar16;
                    uVar5 = (*(code *)PTR_FUN_4200005c)();
                    puVar3 = puStack_30;
                    puStack_30 = puStack_2c;
                    (*DAT_42000060)(PTR_DAT_42000628,uVar5,PTR_s_memory_layout_42000600,puStack_2c,
                                    puVar3);
                    puVar13 = puStack_38;
                    puVar16 = puStack_30;
                  }
                  puStack_60 = puVar16;
                  uStack_5c = uVar12;
                  (*DAT_42000064)(puVar13,&puStack_60,0x14);
                  puStack_38 = puStack_34;
                }
                goto LAB_42004ec8;
              }
            }
            else {
              if ((int)uVar14 <= (int)puVar11) goto LAB_42004ec5;
              uVar12 = uVar14 - (int)puVar11;
              uVar17 = uVar14;
              puVar16 = puVar11;
            }
          }
          puVar10 = puVar10 + 2;
          if (puVar9 == puVar13) break;
          puVar13 = (uint *)((int)puVar13 + 1);
          uVar14 = uVar17;
        }
        if (0x10 < uVar12) goto LAB_42004f04;
      }
LAB_42004ec5:
      puVar8 = puVar8 + 5;
LAB_42004ec8:
    } while (puVar8 != puStack_40);
    iVar4 = ((int)puStack_38 - (int)puStack_3c >> 2) * DAT_42000624;
  }
  return iVar4;
}