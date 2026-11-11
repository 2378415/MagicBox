// 4037ea60  FUN_4037ea60  FUN_4037ea60  size=91
// strings: ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT | freertos_tasks_c_additions.h | xTaskCreatePinnedToCore

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4037ea60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_stack_00000000;
  
  if (((-(in_stack_00000000 + -1) & 0xffU) == 0) && (in_stack_00000000 != DAT_40374eac)) {
    FUN_40381ce4(PTR_s_freertos_tasks_c_additions_h_3c034f28_0x28_40375058,0xa3,
                 PTR_s_xTaskCreatePinnedToCore_40375060,
                 PTR_s_________BaseType_t___xCoreID___>_4037505c);
  }
  iVar1 = FUN_4037c428(param_3);
  if (iVar1 != 0) {
    iVar2 = FUN_4037c428(0x154);
    if (iVar2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    FUN_4037c43c(iVar1);
  }
  return 0xffffffff;
}


