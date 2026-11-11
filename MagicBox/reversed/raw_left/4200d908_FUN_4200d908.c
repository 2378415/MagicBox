// 4200d908  FUN_4200d908  FUN_4200d908  size=376
// strings: task != ((void *)0) && reg_dump != ((void *)0) | core_dump_port.c | esp_core_dump_get_task_regs_dump

undefined4 FUN_4200d908(undefined4 *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  undefined1 in_EPC1;
  undefined1 in_EPC2;
  undefined1 in_EPC3;
  undefined1 in_EPC4;
  undefined1 in_EPC5;
  undefined1 in_EPC6;
  undefined1 in_EPS2;
  undefined1 in_EPS3;
  undefined1 in_EPS4;
  undefined1 in_EPS5;
  undefined1 in_EPS6;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (int *)0x0)) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_core_dump_port_c_3c0363f8_0x2d_42000d54,0x1b3,
               PTR_s_esp_core_dump_get_task_regs_dump_3c03decb_1_42000d68,
               PTR_s_task______void___0_____reg_dump___42000d64);
  }
  iVar1 = DAT_42000d6c;
  uVar4 = param_1[1];
  uVar2 = param_1[2];
  piVar7 = (int *)((uVar2 < uVar4) * uVar2 + (uVar2 >= uVar4) * uVar4);
  piVar10 = (int *)PTR_DAT_42000d60;
  if (DAT_42000d5c < (undefined *)((int)piVar7 + DAT_42000d58)) {
    piVar10 = piVar7;
  }
  *(undefined4 *)(DAT_42000d6c + 0x18) = *param_1;
  *(undefined2 *)(iVar1 + 0xc) = 0;
  iVar3 = DAT_42000d10;
  if (0x6f < ((uVar2 < uVar4) * uVar4 + (uVar2 >= uVar4) * uVar2) - (int)piVar7) {
    if (*piVar10 == DAT_42000d14) {
      iVar6 = piVar10[0x14];
      *(int *)(DAT_42000d10 + 0x10) = piVar10[0x15];
      *(int *)(iVar3 + 8) = iVar6;
      *(undefined4 *)(iVar3 + 0xc) = 0xee;
      *(undefined4 *)(iVar3 + 4) = 0xe8;
      *(undefined4 *)(iVar3 + 0x14) = 0xc2;
      uVar5 = rsr(in_EPS2);
      *(undefined4 *)(iVar3 + 0x18) = uVar5;
      *(undefined4 *)(iVar3 + 0x1c) = 0xc3;
      uVar5 = rsr(in_EPS3);
      *(undefined4 *)(iVar3 + 0x20) = uVar5;
      *(undefined4 *)(iVar3 + 0x24) = 0xc4;
      uVar5 = rsr(in_EPS4);
      *(undefined4 *)(iVar3 + 0x28) = uVar5;
      *(undefined4 *)(iVar3 + 0x2c) = 0xc5;
      uVar5 = rsr(in_EPS5);
      *(undefined4 *)(iVar3 + 0x30) = uVar5;
      *(undefined4 *)(iVar3 + 0x34) = 0xc6;
      uVar5 = rsr(in_EPS6);
      *(undefined4 *)(iVar3 + 0x38) = uVar5;
      *(undefined4 *)(iVar3 + 0x3c) = 0xb1;
      uVar5 = rsr(in_EPC1);
      *(undefined4 *)(iVar3 + 0x40) = uVar5;
      *(undefined4 *)(iVar3 + 0x44) = 0xb2;
      uVar5 = rsr(in_EPC2);
      *(undefined4 *)(iVar3 + 0x48) = uVar5;
      *(undefined4 *)(iVar3 + 0x4c) = 0xb3;
      uVar5 = rsr(in_EPC3);
      *(undefined4 *)(iVar3 + 0x50) = uVar5;
      *(undefined4 *)(iVar3 + 0x54) = 0xb4;
      uVar5 = rsr(in_EPC4);
      *(undefined4 *)(iVar3 + 0x58) = uVar5;
      *(undefined4 *)(iVar3 + 0x5c) = 0xb5;
      uVar5 = rsr(in_EPC5);
      *(undefined4 *)(iVar3 + 0x60) = uVar5;
      *(undefined4 *)(iVar3 + 100) = 0xb6;
      uVar5 = rsr(in_EPC6);
      *(undefined4 *)(iVar3 + 0x68) = uVar5;
    }
    else {
      piVar10[0x14] = DAT_42000d18;
      piVar10[0x15] = 0;
      if (*piVar10 == 0) {
        uVar9 = piVar10[1];
        *(uint *)(iVar1 + 0x48) = uVar9;
        *(int *)(iVar1 + 0x4c) = piVar10[2];
        uVar4 = piVar10[4];
        *(uint *)(iVar1 + 0x148) = uVar4;
        *(int *)(iVar1 + 0x14c) = piVar10[5];
        *(int *)(iVar1 + 0x150) = piVar10[6];
        uVar2 = uVar9 & 0x3fffffff;
        if (-1 < (int)uVar9) {
          uVar2 = uVar9;
        }
        uVar9 = uVar4 & 0x3fffffff;
        if (-1 < (int)uVar4) {
          uVar9 = uVar4;
        }
        *(int *)(iVar1 + 0x154) = piVar10[7];
        *(uint *)(iVar1 + 0x48) = uVar2;
        *(uint *)(iVar1 + 0x148) = uVar9;
        goto LAB_4200da7a;
      }
    }
    piVar7 = DAT_42000d70;
    uVar2 = piVar10[2];
    *(int *)(iVar1 + 0x48) = piVar10[1];
    *(uint *)(iVar1 + 0x4c) = uVar2;
    *piVar7 = piVar10[3];
    iVar8 = piVar10[0x16];
    iVar6 = piVar10[0x17];
    iVar3 = piVar10[0x18];
    *(int *)(iVar1 + 0x5c) = piVar10[0x13];
    *(int *)(iVar1 + 0x50) = iVar8;
    *(int *)(iVar1 + 0x54) = iVar6;
    *(int *)(iVar1 + 0x58) = iVar3;
    if ((uVar2 & 0x20) != 0) {
      *(uint *)(iVar1 + 0x4c) = uVar2 & 0xffffffef;
    }
  }
LAB_4200da7a:
  *param_2 = iVar1;
  return 0x24c;
}


