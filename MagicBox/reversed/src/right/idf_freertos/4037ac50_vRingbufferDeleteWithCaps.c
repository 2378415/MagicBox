// strings: xResult == ( ( BaseType_t ) 1 )

void FUN_4037ac50(undefined4 param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  local_30 = 0;
  auStack_2c[0] = 0;
  iVar1 = FUN_4037abc0(param_1,auStack_2c,&local_30);
  if (iVar1 != 1) {
    FUN_40381d9c(PTR_s_ringbuf_c_3c035ff4_0x1d_40374a90,0x590,
                 PTR_s_vRingbufferDeleteWithCaps_40374bc0,
                 PTR_s_xResult________BaseType_t___1___40374bbc);
  }
  FUN_4037aae8(param_1);
  FUN_40376244(local_30);
  FUN_40376244(auStack_2c[0]);
  return;
}