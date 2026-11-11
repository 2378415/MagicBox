// 42003658  esp_cpu_intr_edge_ack  FUN_42003658  size=717
// strings: intr_num >= 0 && intr_num < SOC_CPU_INTR_NUM | \e7@ | esp_cpu.h | esp_cpu_intr_edge_ack | pf7@

undefined4
FUN_42003658(uint param_1,uint param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 *param_7)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  ushort *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  undefined1 in_PRID;
  
  if ((~param_2 & 0x300) == 0) {
    return 0x102;
  }
  if (((param_2 >> 4 & 0xf) != 0) && (param_5 != 0)) {
    return 0x102;
  }
  if (((param_2 & 0x100) != 0) && (param_5 == 0 || (int)param_1 < 0)) {
    return 0x102;
  }
  if (param_3 != 0 && param_4 == 0) {
    return 0x102;
  }
  if ((((param_2 & 0x400) != 0) && (param_5 != 0)) && (iVar3 = FUN_42003630(param_5), iVar3 == 0)) {
    return 0x102;
  }
  if ((param_2 >> 1 & 0x7f) == 0) {
    if ((param_2 & 0x100) == 0) {
      param_2 = param_2 | 0xe;
    }
    else {
      param_2 = param_2 | 2;
    }
  }
  if (param_1 == 0xffffffff) {
    uVar7 = 6;
LAB_420036d0:
    if (param_1 != 0xfffffffd) goto LAB_420036da;
    uVar7 = 0x10;
LAB_420036e4:
    if (param_1 == 0xfffffffb) {
      uVar7 = 0x1d;
      goto LAB_420036fd;
    }
  }
  else {
    if (param_1 != 0xfffffffe) {
      uVar7 = 0xffffffff;
      goto LAB_420036d0;
    }
    uVar7 = 0xf;
LAB_420036da:
    if (param_1 != 0xfffffffc) goto LAB_420036e4;
    uVar7 = 7;
  }
  if (param_1 == 0xfffffffa) {
    uVar7 = 0xb;
  }
LAB_420036fd:
  puVar4 = (undefined4 *)(*(code *)PTR_FUN_42000484)(8,DAT_42000424);
  if (puVar4 == (undefined4 *)0x0) {
    uVar7 = 0x101;
  }
  else {
    (*(code *)PTR_FUN_420003a8)(PTR_DAT_420004a0,0xffffffff);
    uVar8 = rsr(in_PRID);
    uVar9 = uVar8 >> 0xd & 1;
    uVar8 = FUN_420034e8(param_2,uVar9,uVar7,param_1);
    if (uVar8 == 0xffffffff) {
      (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004a0);
      (*(code *)PTR_FUN_420004c0)(puVar4);
      uVar7 = 0x105;
    }
    else {
      puVar5 = (uint *)FUN_42003354(uVar8,uVar9);
      if (puVar5 == (uint *)0x0) {
        (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004a0);
        (*(code *)PTR_FUN_420004c0)(puVar4);
        uVar7 = 0x101;
      }
      else {
        if ((param_2 & 0x100) == 0) {
          *(ushort *)puVar5 = 8;
          if (param_5 != 0) {
            if (0x1f < uVar8) {
              (*(code *)PTR_FUN_42000044)
                        (PTR_s_esp_cpu_h_3c031700_0x28_420004ac,0x168,
                         PTR_s_esp_cpu_intr_set_handler_420004a8,
                         PTR_s_intr_num_>__0____intr_num_<_SOC__420004a4);
            }
            FUN_42026a8c(uVar8,param_5,param_6);
          }
          if ((param_2 & 0x200) != 0) {
            if (0x1f < uVar8) {
              (*(code *)PTR_FUN_42000044)
                        (PTR_s_esp_cpu_h_3c031700_0x28_420004ac,0x1b7,
                         PTR_s_esp_cpu_intr_edge_ack_420004b4,
                         PTR_s_intr_num_>__0____intr_num_<_SOC__420004a4);
            }
            (*DAT_420004c4)(1 << 0x20 - (0x20 - (uVar8 & 0x1f)));
          }
          *puVar5 = *puVar5 & DAT_420004b8 | (param_1 & 0xff) << 0x16;
        }
        else {
          puVar6 = (ushort *)(*(code *)PTR_FUN_42000484)(0x18,DAT_42000424);
          if (puVar6 == (ushort *)0x0) {
            (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004a0);
            (*(code *)PTR_FUN_420004c0)(puVar4);
            return 0x101;
          }
          (*DAT_42000240)(puVar6,0,0x18);
          *(int *)(puVar6 + 2) = param_3;
          *(int *)(puVar6 + 4) = param_4;
          *(int *)(puVar6 + 6) = param_5;
          *(undefined4 *)(puVar6 + 8) = param_6;
          *(uint *)(puVar6 + 10) = puVar5[1];
          uVar2 = ((ushort)param_1 & 0xff) * 2;
          uVar1 = *puVar6;
          *puVar6 = uVar1 & 0xfe01 | uVar2;
          *puVar6 = uVar1 & 0xfe00 | uVar2;
          puVar5[1] = (uint)puVar6;
          *(ushort *)puVar5 = (ushort)*puVar5 | 4;
          if (0x1f < uVar8) {
            (*(code *)PTR_FUN_42000044)
                      (PTR_s_esp_cpu_h_3c031700_0x28_420004ac,0x168,
                       PTR_s_esp_cpu_intr_set_handler_420004a8,
                       PTR_s_intr_num_>__0____intr_num_<_SOC__420004a4);
          }
          FUN_42026a8c(uVar8,PTR_FUN_420004b0,puVar5);
        }
        if ((param_2 & 0x400) == 0) {
          *(ushort *)puVar5 = (ushort)*puVar5 & 0xfffd;
          puVar10 = (uint *)(uVar9 * 4 + DAT_420004bc);
          *puVar10 = *puVar10 | 1 << 0x20 - (0x20 - (uVar8 & 0x1f));
        }
        else {
          *(ushort *)puVar5 = (ushort)*puVar5 | 2;
          puVar10 = (uint *)(uVar9 * 4 + DAT_420004bc);
          uVar11 = *puVar10;
          *puVar10 = 1 << 0x20 - (0x20 - (uVar8 & 0x1f)) & uVar11 ^ uVar11;
        }
        if (-1 < (int)param_1) {
          (*DAT_4200005c)(uVar9,param_1,uVar8);
        }
        *puVar4 = puVar5;
        puVar4[1] = puVar5[1];
        (*(code *)PTR_FUN_42000144)(uVar8);
        if ((param_2 & 0x800) != 0) {
          (*(code *)PTR_FUN_420004c8)(puVar4);
        }
        (*(code *)PTR_FUN_420003ac)(PTR_DAT_420004a0);
        if (param_7 == (undefined4 *)0x0) {
          (*(code *)PTR_FUN_420004c0)(puVar4);
          uVar7 = 0;
        }
        else {
          *param_7 = puVar4;
          uVar7 = 0;
        }
      }
    }
  }
  return uVar7;
}


