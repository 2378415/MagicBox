// strings: gpio_config(&io_conf)

void led_init(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_40 [64];
  
  (*DAT_42000064)(auStack_40,PTR_DAT_420010fc,0x18);
  iVar2 = FUN_42018028(auStack_40);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = (*(code *)PTR_FUN_42000a1c)
                      (iVar2,PTR_s___main_components_RGB_RGB_c_42001108,0x62,PTR_s_led_init_42001104
                       ,PTR_s_gpio_config__io_conf__42001100);
  }
  FUN_42017f70(9,uVar3);
  memw();
  memw();
  *DAT_420010e8 = (char)iVar2;
  memw();
  iVar4 = (*(code *)PTR_FUN_42000e7c)(1,8,iVar2);
  piVar1 = DAT_420010e4;
  *DAT_420010e4 = iVar4;
  if (iVar4 == 0) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_LED_3c032a5c_0x24_4200110c,PTR_DAT_42001110,uVar3,
               PTR_s_LED_3c032a5c_0x24_4200110c);
  }
  else {
    iVar4 = (*(code *)PTR_FUN_420004b0)
                      (PTR_FUN_42001118,PTR_s_LedFlashTask_42001114,0x400,iVar2,1,iVar2,DAT_42000664
                      );
    if (iVar4 == 1) {
      *DAT_420010f0 = 1;
    }
    else {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_LED_3c032a5c_0x24_4200110c,PTR_DAT_4200111c,uVar3,
                 PTR_s_LED_3c032a5c_0x24_4200110c);
      (*(code *)PTR_FUN_42001120)(*piVar1);
      *piVar1 = iVar2;
    }
  }
  return;
}