// 42018314  gpio_isr_register  FUN_42018314  size=179
// strings: GPIO ISR null | gpio_isr_register | gpio

undefined4 FUN_42018314(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  
  if (param_1 == 0) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_4200159c,PTR_DAT_420015a0,uVar2,PTR_DAT_4200159c,
               PTR_s_gpio_isr_register_4200161c,0x249,PTR_s_GPIO_ISR_null_42001620);
    uVar2 = 0x102;
  }
  else {
    uStack_40 = 0x10;
    uStack_3c = param_3;
    iStack_38 = param_1;
    uStack_34 = param_2;
    uStack_30 = param_4;
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_420015a8,0xffffffff);
    puVar1 = PTR_PTR_420015e0;
    if (*(int *)(PTR_PTR_420015e0 + 0xc) == 3) {
      uVar4 = rsr(in_PRID);
      *(uint *)(PTR_PTR_420015e0 + 0xc) = uVar4 >> 0xd & 1;
    }
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_420015a8);
    iVar3 = FUN_42003f3c(*(undefined4 *)(puVar1 + 0xc),PTR_FUN_42001624,&uStack_40);
    if (iVar3 == 0) {
      if (iStack_2c == 0) {
        return 0;
      }
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_DAT_4200159c,PTR_DAT_4200162c,uVar2,PTR_DAT_4200159c,iStack_2c);
    }
    else {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(1,PTR_DAT_4200159c,PTR_DAT_42001628,uVar2,PTR_DAT_4200159c,iVar3);
    }
    uVar2 = 0x105;
  }
  return uVar2;
}


