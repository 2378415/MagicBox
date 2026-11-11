// strings: pxTCBBufferTemp != NULL | pxStackBufferTemp != NULL | port_common.c | vApplicationGetIdleTaskMemory

void FUN_4037c514(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = DAT_40374e3c;
  iVar2 = FUN_4037c428(DAT_40374e3c);
  iVar3 = FUN_4037c428(0x154);
  if (iVar3 == 0) {
    iVar3 = FUN_40381ce4(PTR_s_port_common_c_3c035654_0x1a_40374e48,0x34,
                         PTR_s_vApplicationGetIdleTaskMemory_40374e44,
                         PTR_s_pxTCBBufferTemp____NULL_40374e40);
  }
  if (iVar2 == 0) {
    iVar3 = FUN_40381ce4(PTR_s_port_common_c_3c035654_0x1a_40374e48,0x35,
                         PTR_s_vApplicationGetIdleTaskMemory_40374e44,
                         PTR_s_pxStackBufferTemp____NULL_40374e4c);
  }
  *param_1 = iVar3;
  *param_2 = iVar2;
  *param_3 = uVar1;
  return;
}