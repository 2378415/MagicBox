void FUN_4037c17c(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_1 + 0x58);
  if (pcVar2 != (code *)0x0) {
    if ((-(DAT_40374614 + -1) & 0xffU) == 0) {
      if ((((-(DAT_4037461c + -1) & 0xffU) == 0) && (DAT_40374624 < pcVar2 + DAT_403747fc)) &&
         (DAT_40374608 < pcVar2 + DAT_40374604)) {
        if (*(int *)PTR_DAT_40374414 != 0) {
          uVar1 = FUN_40381bb0();
          (*DAT_40374438)(PTR_DAT_40374e10,uVar1,PTR_s_FreeRTOS_40374d88,0,
                          *(undefined4 *)(param_1 + 0x58));
        }
                    /* WARNING: Subroutine does not return */
        FUN_40381c60();
      }
    }
    (*pcVar2)(0,*(undefined4 *)(param_1 + 0x54));
  }
  FUN_40383b50(*(int *)(param_1 + 0x48) - 0x13cU & 0xfffffff0,*(undefined4 *)(param_1 + 0x44));
  return;
}