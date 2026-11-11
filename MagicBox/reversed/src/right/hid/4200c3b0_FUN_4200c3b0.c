void FUN_4200c3b0(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                 char param_7)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_6 & 0x7ff | (param_4 & 0xf) << 0xb | (param_5 & 3) << 0x12 |
          (param_3 & 0x7f) << 0x16;
  if ((char)param_4 < '\0') {
    uVar2 = uVar2 | DAT_42000160;
  }
  iVar1 = FUN_42024764(param_1,0);
  if (iVar1 == 3) {
    if (param_7 != '\x03') {
      (*DAT_42000634)(PTR_DAT_42000b00);
      (*DAT_42000634)(PTR_s_Do_not_support_LS_FS_device_on_H_42000b04);
      (*DAT_42000634)(PTR_DAT_42000b08);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else if ((param_7 == '\x01') && (iVar1 = FUN_42024764(param_1,0), iVar1 != 1)) {
    uVar2 = uVar2 | DAT_420003bc;
  }
  if (param_5 == 3) {
    uVar2 = uVar2 | DAT_420003d0;
  }
  memw();
  *(uint *)(*(int *)(param_1 + 8) + param_2 * 0x20 + 0x500) = uVar2;
  return;
}