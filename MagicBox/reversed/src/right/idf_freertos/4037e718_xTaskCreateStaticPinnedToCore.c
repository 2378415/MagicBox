// strings: xPortcheckValidStackMem(puxStackBuffer) | xPortCheckValidTCBMem(pxTaskBuffer) | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT | xSize == sizeof( TCB_t ) | freertos_tasks_c_additions.h | xTaskCreateStaticPinnedToCore

/* (1 unreachable decompiler blocks omitted) */

undefined4
FUN_4037e718(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7,int param_8)

{
  int iVar1;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_30;
  
  uStack_30 = param_5;
  iVar1 = FUN_4037c124(param_6);
  if (iVar1 == 0) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,299,
                 PTR_s_xTaskCreateStaticPinnedToCore_40374f9c,
                 PTR_s_xPortcheckValidStackMem_puxStack_40374f98);
  }
  iVar1 = FUN_4037c0c8(param_7);
  if (iVar1 == 0) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,300,
                 PTR_s_xTaskCreateStaticPinnedToCore_40374f9c,
                 PTR_s_xPortCheckValidTCBMem_pxTaskBuff_40374fa0);
  }
  if (param_8 != DAT_403747f4) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,0x12d,
                 PTR_s_xTaskCreateStaticPinnedToCore_40374f9c,
                 PTR_s_________BaseType_t___xCoreID___>_40374f90);
  }
  memw();
  memw();
  uStack_3c = 0x154;
  memw();
  if (param_7 == 0 || param_6 == 0) {
    uStack_40 = 0;
  }
  else {
    (*DAT_4037448c)(param_7,0,0x154);
    *(int *)(param_7 + 0x30) = param_6;
    *(undefined1 *)(param_7 + 0x151) = 2;
    FUN_4037cee8(param_1,param_2,param_3,param_4,uStack_30,&uStack_40,param_7,0,param_8);
    FUN_4037cff0(param_7);
  }
  return uStack_40;
}