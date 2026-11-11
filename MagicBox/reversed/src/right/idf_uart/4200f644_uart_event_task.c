void FUN_4200f644(void)

{
  undefined4 uVar1;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_28;
  
  bridge_init();
  uVar1 = DAT_4200077c;
  FUN_42009294(1,DAT_4200077c,DAT_4200077c,0x14,DAT_42000d00,0);
  (*DAT_42000240)(&uStack_40,0,0x20);
  uStack_40 = DAT_42000d14;
  uStack_3c = 3;
  uStack_34 = 1;
  uStack_28 = 4;
  FUN_42008b58(1,&uStack_40);
  FUN_42008848(1,1,2,0xffffffff);
  (*(code *)PTR_FUN_42000380)
            (PTR_FUN_42000d1c,PTR_s_uart_event_task_42000d18,uVar1,0,6,0,DAT_4200049c);
  return;
}