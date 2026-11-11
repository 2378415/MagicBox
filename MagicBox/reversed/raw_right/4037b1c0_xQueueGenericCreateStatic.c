// 4037b1c0  xQueueGenericCreateStatic  FUN_4037b1c0  size=142
// strings: pxStaticQueue | queue.c | xQueueGenericCreateStatic | xSize == sizeof( Queue_t ) | pxNewQueue

/* WARNING: Removing unreachable block (ram,0x4037b21f) */

int FUN_4037b1c0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint in_t0;
  undefined8 uVar2;
  
  uVar2 = CONCAT44(param_2,param_1);
  uVar1 = 1;
  if (param_4 == 0) {
    uVar1 = in_t0;
    uVar2 = FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x19f,
                         PTR_s_xQueueGenericCreateStatic_40374c4c,PTR_s_pxStaticQueue_40374c48);
  }
  if ((((uVar1 & (int)uVar2 != 0) == 0) || (param_3 != 0 && param_2 == 0)) ||
     (param_3 == 0 && param_2 != 0)) {
    uVar2 = FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x1c8,
                         PTR_s_xQueueGenericCreateStatic_40374c4c,PTR_s_pxNewQueue_40374c54);
  }
  else {
    memw();
    memw();
  }
  memw();
  *(undefined1 *)(param_4 + 0x44) = 1;
  FUN_4037b1a0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  return param_4;
}


