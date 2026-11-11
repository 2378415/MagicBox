// strings: (uxStackPointer & ( 0x000f )) == 0

void FUN_4037bb28(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((param_1 & 0xf) != 0) {
    FUN_40381d9c(PTR_s_port_c_3c032bc8_0x3a_40374cf4,0x1a1,PTR_s_pxPortInitialiseStack_40374cf0,
                 PTR_s__uxStackPointer_____0x000f_______40374cec);
  }
  puVar3 = (undefined4 *)(param_1 - 0x13c & 0xfffffff0);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = puVar3 + 4;
  iVar1 = DAT_40374cf8;
  iVar4 = (int)puVar3 - (DAT_40374d0c - DAT_40374cf8 & 0xfffffff0U);
  (*DAT_403744d4)(iVar4,DAT_40374cf8);
  puVar2 = PTR_s_flash_ret____ESP_OK_40374d00 +
           ((iVar4 - iVar1) - (DAT_40374cfc + 7U & -DAT_40374cfc));
  puVar3 = (undefined4 *)(iVar4 + -0xc0);
  (*DAT_4037448c)(puVar3,0,iVar4 - (int)puVar3);
  *(undefined4 *)(iVar4 + -0xb4) = 0;
  *(int *)(iVar4 + -0xb0) = iVar4;
  *puVar3 = PTR_LAB_40374784;
  *(undefined **)(iVar4 + -0xbc) = PTR_FUN_40374d04;
  *(undefined4 *)(iVar4 + -0x9c) = param_2;
  *(undefined4 *)(iVar4 + -0x98) = param_3;
  *(undefined4 *)(iVar4 + -0xb8) = DAT_40374d08;
  *(undefined **)(iVar4 + -0x50) = puVar2;
  return;
}