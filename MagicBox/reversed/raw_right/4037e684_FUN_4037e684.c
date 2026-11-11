// 4037e684  FUN_4037e684  FUN_4037e684  size=148
// strings: ( ( ( ( BaseType_t ) xCoreID ) >= 0 && ( ( BaseT

undefined4
FUN_4037e684(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_7 != DAT_403747f4) {
    FUN_40381d9c(PTR_s_freertos_tasks_c_additions_h_3c03295c_0x28_40374f8c,0xa3,
                 PTR_s_xTaskCreatePinnedToCore_40374f94,
                 PTR_s_________BaseType_t___xCoreID___>_40374f90);
  }
  iVar1 = FUN_4037c04c(param_3);
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = FUN_4037c04c(0x154);
    if (iVar2 == 0) {
      FUN_4037c060(iVar1);
      uVar3 = 0xffffffff;
    }
    else {
      (*DAT_4037448c)(iVar2,0,0x154);
      *(int *)(iVar2 + 0x30) = iVar1;
      *(undefined1 *)(iVar2 + 0x151) = 0;
      FUN_4037cee8(param_1,param_2,param_3,param_4,param_5,param_6,iVar2,0,param_7);
      FUN_4037cff0(iVar2);
      uVar3 = 1;
    }
  }
  return uVar3;
}


