// strings: uart_param_config(UART_NUM_0, &uart0_config) | uart_set_pin(UART_NUM_0, UART_0_TX, UART_0_RX, U | uart_driver_install(UART_NUM_0, RX_BUFFER_SIZE,  | uart0_in

void uart0_setup(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_28;
  
  uVar5 = (*(code *)PTR_FUN_42000e7c)(0x14,0x268,0);
  *DAT_42001294 = uVar5;
  uVar5 = (*(code *)PTR_FUN_42000e7c)(0x14,0xc,0);
  puVar2 = DAT_420012b0;
  *DAT_420012b0 = uVar5;
  puVar1 = PTR_DAT_420011f8;
  local_38 = 0;
  uStack_40 = *(undefined4 *)PTR_DAT_420011f8;
  uStack_3c = 3;
  uStack_34 = 1;
  uStack_28 = 4;
  iVar6 = FUN_4200a808(0,&uStack_40);
  uVar5 = 0;
  if (iVar6 != 0) {
    uVar5 = (*(code *)PTR_FUN_42000a1c)
                      (iVar6,PTR_s___main_components_UART_uart0_c_420012e8,0x19d,
                       PTR_s_setupUart0_420012e4,PTR_s_uart_param_config_UART_NUM_0___u_420012e0);
  }
  iVar6 = FUN_4200a268(uVar5,0xffffffff,0xffffffff,0xffffffff);
  uVar5 = 0;
  if (iVar6 != 0) {
    uVar5 = (*(code *)PTR_FUN_42000a1c)
                      (iVar6,PTR_s___main_components_UART_uart0_c_420012e8,0x19e,
                       PTR_s_setupUart0_420012e4,PTR_s_uart_set_pin_UART_NUM_0__UART_0__420012ec);
  }
  iVar6 = FUN_4200b2f0(uVar5,DAT_420006dc,0x400,0x14,puVar2,uVar5);
  if (iVar6 != 0) {
    (*(code *)PTR_FUN_42000a1c)
              (iVar6,PTR_s___main_components_UART_uart0_c_420012e8,0x19f,PTR_s_setupUart0_420012e4,
               PTR_s_uart_driver_install_UART_NUM_0__R_420012f0);
  }
  uVar5 = DAT_42000664;
  (*(code *)PTR_FUN_420004b0)
            (PTR_LAB_420012fc,PTR_s_uart0_in_420012f8,DAT_420012f4,iVar6,5,iVar6,DAT_42000664);
  (*(code *)PTR_FUN_420004b0)
            (PTR_LAB_42001304,PTR_s_UART0_Send_Task_42001300,DAT_420012f4,iVar6,4,iVar6,uVar5);
  uVar7 = (*(code *)PTR_FUN_42000e7c)(0x32,0xc,iVar6);
  puVar4 = PTR_FUN_4200130c;
  puVar3 = PTR_s_UART0FrameConsumer_42001308;
  uVar8 = DAT_42000988;
  *DAT_420012a8 = uVar7;
  (*(code *)PTR_FUN_420004b0)(puVar4,puVar3,uVar8,iVar6,1,iVar6,uVar5);
  uVar8 = (*(code *)PTR_FUN_42000e7c)(1,iVar6,3);
  *DAT_420012ac = uVar8;
  (*(code *)PTR_FUN_42000488)(uVar8,iVar6,iVar6,iVar6);
  (*(code *)PTR_FUN_420004b0)
            (PTR_LAB_4200131c,PTR_s_Reset_Baud_Rate_Task_42001318,DAT_42001314,iVar6,3,DAT_42001310,
             uVar5);
  serial_setup(*(undefined4 *)puVar1);
  return;
}