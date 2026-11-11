// strings: pxTCBBufferTemp != NULL | pxStackBufferTemp != NULL | port_common.c | vApplicationGetTimerTaskMemory

void FUN_4037c1bc(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4037c04c(DAT_40374d98);
  iVar2 = FUN_4037c04c(0x154);
  if (iVar2 == 0) {
    iVar2 = FUN_40381d9c(PTR_s_port_common_c_3c032d54_0x1a_40374d90,0x60,
                         PTR_s_vApplicationGetTimerTaskMemory_40374d9c,
                         PTR_s_pxTCBBufferTemp____NULL_40374d88);
  }
  if (iVar1 == 0) {
    iVar2 = FUN_40381d9c(PTR_s_port_common_c_3c032d54_0x1a_40374d90,0x61,
                         PTR_s_vApplicationGetTimerTaskMemory_40374d9c,
                         PTR_s_pxStackBufferTemp____NULL_40374d94);
  }
  *param_1 = iVar2;
  *param_2 = iVar1;
  *param_3 = DAT_40374d98;
  return;
}