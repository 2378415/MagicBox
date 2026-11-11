// 4037eb00  xTaskCreateStaticPinnedToCore  FUN_4037eb00  size=214
// strings: xPortcheckValidStackMem(puxStackBuffer) | xPortCheckValidTCBMem(pxTaskBuffer) | ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT | freertos_tasks_c_additions.h | xTaskCreateStaticPinnedToCore | xSize == sizeof( TCB_t )

/* WARNING: Removing unreachable block (ram,0x4037eb79) */

undefined4
FUN_4037eb00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7,int param_8)

{
  int iVar1;
  undefined4 auStack_2c [11];
  
  iVar1 = FUN_4037c4d0(param_6);
  if (iVar1 == 0) {
    FUN_40381ce4(PTR_s_freertos_tasks_c_additions_h_3c034f28_0x28_40375058,299,
                 PTR_s_xTaskCreateStaticPinnedToCore_40375068,
                 PTR_s_xPortcheckValidStackMem_puxStack_40375064);
  }
  iVar1 = FUN_4037c48c(param_7);
  if (iVar1 == 0) {
    FUN_40381ce4(PTR_s_freertos_tasks_c_additions_h_3c034f28_0x28_40375058,300,
                 PTR_s_xTaskCreateStaticPinnedToCore_40375068,
                 PTR_s_xPortCheckValidTCBMem_pxTaskBuff_4037506c);
  }
  if (((-(param_8 + -1) & 0xffU) == 0) && (param_8 != DAT_40374eac)) {
    FUN_40381ce4(PTR_s_freertos_tasks_c_additions_h_3c034f28_0x28_40375058,0x12d,
                 PTR_s_xTaskCreateStaticPinnedToCore_40375068,
                 PTR_s_________BaseType_t___xCoreID___>_4037505c);
  }
  memw();
  memw();
  memw();
  if ((param_7 == 0) || (param_6 == 0)) {
    auStack_2c[0] = 0;
  }
  else {
    (*DAT_403744c4)(param_7,0);
    *(int *)(param_7 + 0x30) = param_6;
    *(undefined1 *)(param_7 + 0x151) = 2;
    FUN_4037d148(param_1,param_2,param_3,param_4,param_5,auStack_2c,param_7,param_8);
    FUN_4037ceb4(param_7);
  }
  return auStack_2c[0];
}


