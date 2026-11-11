// strings: 3.2.0

void FUN_4200daa4(void)

{
  FUN_420204ec(PTR_s_________________________MAKCU_20_42000d78,PTR_s_3_2_0_42000d74);
  (*(code *)PTR_FUN_42000098)(0xfa);
  FUN_420112b8();
  uart_event_task();
  uart0_setup();
  FUN_42013188();
  FUN_4200f7ec();
  FUN_42014214();
  led_init();
  (*(code *)PTR_FUN_42000d7c)(0);
  return;
}