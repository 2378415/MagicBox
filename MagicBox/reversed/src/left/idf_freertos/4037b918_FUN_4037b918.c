// strings: pxStaticQueue | xSize == sizeof( Queue_t ) | xQueueGenericCreateStatic

/* (1 unreachable decompiler blocks omitted) */

void FUN_4037b918(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    FUN_40381ce4(PTR_s_queue_c_3c034a20_0x2a_40374ce4,0x19f,PTR_s_xQueueGenericCreateStatic_40374d00
                 ,PTR_s_pxStaticQueue_40374cfc);
  }
  memw();
  memw();
  *(undefined1 *)(param_2 + 0x11) = 1;
  param_2[0xf] = 1;
  memw();
  *param_2 = param_2;
  param_2[0x10] = 0;
  FUN_4037b4b8(param_2);
  uVar1 = DAT_40374bf4;
  param_2[0x12] = 0;
  param_2[2] = 0;
  *param_2 = 0;
  param_2[3] = 0;
  param_2[0x13] = uVar1;
  param_2[0x14] = 0;
  FUN_4037b768(param_2,0,0,0);
  return;
}