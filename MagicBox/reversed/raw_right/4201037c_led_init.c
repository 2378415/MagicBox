// 4201037c  led_init  FUN_4201037c  size=58
// strings: gpio_config(&io_conf)

void FUN_4201037c(void)

{
  int iVar1;
  undefined1 auStack_40 [64];
  
  (*DAT_420002fc)(auStack_40,PTR_DAT_42000d90,0x18);
  iVar1 = FUN_4201160c(auStack_40);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000840)
              (iVar1,PTR_s___main_components_RGB_RGB_c_42000d9c,0x14,PTR_s_led_init_42000d98,
               PTR_s_gpio_config__io_conf__42000d94);
  }
  FUN_4201156c(9,0);
  *DAT_42000da0 = 1;
  return;
}


