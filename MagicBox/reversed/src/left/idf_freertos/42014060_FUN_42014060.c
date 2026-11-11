void FUN_42014060(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_30;
  undefined4 uStack_2c;
  byte bStack_28;
  
  puVar3 = DAT_420012ac;
  puVar2 = DAT_420012a8;
  puVar1 = DAT_420012a0;
  do {
    do {
      iVar4 = (*(code *)PTR_FUN_420010f8)(*puVar2,&local_30,0xffffffff);
    } while (iVar4 != 1);
    (*(code *)PTR_FUN_42000480)(*puVar3,0xffffffff);
    uart_rx_frame(local_30,uStack_2c);
    uVar6 = *puVar3;
    if (bStack_28 < 0x14) {
      uVar5 = *puVar1;
      *puVar1 = 1 << 0x20 - (0x20 - (bStack_28 & 0x1f)) & uVar5 ^ uVar5;
    }
    (*(code *)PTR_FUN_42000488)(uVar6,0,0);
    (*(code *)PTR_FUN_42000098)(1);
  } while( true );
}