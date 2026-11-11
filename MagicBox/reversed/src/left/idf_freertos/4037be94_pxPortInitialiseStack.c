// strings: (uxStackPointer & ( 0x000f )) == 0 | Xs7@

void FUN_4037be94(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = param_1 & 0xf;
  if (uVar5 != 0) {
    FUN_40381ce4(PTR_s_port_c_3c035418_0x3a_40374d9c,0x1a1,PTR_s_pxPortInitialiseStack_40374d98,
                 PTR_s__uxStackPointer_____0x000f_______40374d94);
  }
  iVar1 = DAT_40374da0;
  puVar7 = (uint *)(param_1 - 0x13c & 0xfffffff0);
  iVar6 = (int)puVar7 - (DAT_40374db4 - DAT_40374da0 & 0xfffffff0U);
  *puVar7 = uVar5;
  puVar7[1] = uVar5;
  puVar7[2] = (uint)(puVar7 + 4);
  (*DAT_4037450c)(iVar6,iVar1);
  puVar2 = PTR_s_app_init_40374da8;
  uVar8 = -DAT_40374da4;
  uVar9 = DAT_40374da4 + 7;
  (*DAT_403744c4)((undefined4 *)(iVar6 + -0xc0),uVar5,0xc0);
  *(undefined4 *)(iVar6 + -0xc0) = PTR_LAB_40374804;
  puVar3 = PTR_FUN_40374dac;
  *(int *)(iVar6 + -0xb0) = iVar6;
  *(undefined **)(iVar6 + -0xbc) = puVar3;
  uVar4 = DAT_40374db0;
  *(uint *)(iVar6 + -0xb4) = uVar5;
  *(undefined4 *)(iVar6 + -0x9c) = param_2;
  *(undefined4 *)(iVar6 + -0x98) = param_3;
  *(undefined4 *)(iVar6 + -0xb8) = uVar4;
  *(undefined **)(iVar6 + -0x50) = puVar2 + iVar6 + (-(uVar9 & uVar8) - iVar1);
  return;
}