// 4037b294  xQueueGenericCreate  FUN_4037b294  size=83
// strings: pxNewQueue | queue.c | xQueueGenericCreate

uint FUN_4037b294(uint param_1,uint param_2,undefined1 param_3)

{
  uint uVar1;
  
  if (((param_1 == 0) || ((int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20) != 0)) ||
     (0xffffffab < param_1 * param_2)) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x23d,PTR_s_xQueueGenericCreate_40374c60,
                 PTR_s_pxNewQueue_40374c54);
    uVar1 = param_1;
  }
  else {
    uVar1 = FUN_4037c04c(param_1 * param_2 + 0x54);
    if (uVar1 != 0) {
      *(undefined1 *)(uVar1 + 0x44) = 0;
      FUN_4037b1a0(param_1,param_2,uVar1 + 0x54,param_3,uVar1);
    }
  }
  return uVar1;
}


