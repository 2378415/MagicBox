// 42018ab8  partition  size=436
// strings: partition

/* WARNING: Control flow encountered bad instruction data */

int partition(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined1 auStack_b0 [88];
  ushort uStack_58;
  byte bStack_56;
  byte bStack_55;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [16];
  uint uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int iStack_30;
  undefined4 *puStack_2c;
  
  (*(code *)PTR_FUN_420008d8)(DAT_4200168c);
  if (*DAT_42001690 == 0) {
    (*DAT_420016b0)(auStack_b0);
    iVar1 = FUN_42019854(0,DAT_42000988,0,&iStack_34,&uStack_38);
    puVar6 = PTR_s_partition_42001698;
    if (iVar1 == 0) {
      iVar1 = iStack_34 + DAT_42000288;
      iStack_30 = iStack_34 + DAT_42001694;
      puStack_2c = (undefined4 *)0x0;
      puVar5 = (undefined4 *)0x0;
      iStack_34 = iVar1;
      while( true ) {
        (*DAT_42000064)(&uStack_58,iVar1,0x20);
        puVar2 = puStack_2c;
        if (uStack_58 == DAT_420016a8) break;
        if (uStack_58 != DAT_420016ac) goto LAB_42018bfb;
        (*DAT_420016b4)(auStack_b0,&uStack_58,0x20);
        puVar2 = (undefined4 *)(*(code *)PTR_FUN_42000910)(1,0x34);
        if (puVar2 == (undefined4 *)0x0) goto LAB_42018bfb;
        *puVar2 = *DAT_42000cbc;
        puVar2[1] = (uint)bStack_56;
        puVar2[3] = uStack_54;
        puVar2[2] = (uint)bStack_55;
        puVar2[4] = uStack_50;
        puVar2[5] = DAT_42000988;
        iVar3 = (*(code *)PTR_FUN_42000cc4)();
        if (iVar3 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        *(undefined1 *)((int)puVar2 + 0x29) = 0;
        *(byte *)((int)puVar2 + 0x2a) = (byte)(uStack_3c >> 1) & 1;
        *(undefined1 *)(puVar2 + 0xb) = 0;
        (*DAT_42000da8)(puVar2 + 6,auStack_4c,0x10);
        if (puVar5 == (undefined4 *)0x0) {
          puVar2[0xc] = puStack_2c;
          puStack_2c = puVar2;
        }
        else {
          puVar2[0xc] = puVar5[0xc];
          puVar5[0xc] = puVar2;
        }
        iVar1 = iVar1 + 0x20;
        if (iVar1 == iStack_30) goto LAB_42018bfb;
        puVar5 = puVar2;
      }
      if (iVar1 == 0) {
LAB_42018bfb:
        puVar2 = puStack_2c;
        uVar4 = (*(code *)PTR_FUN_4200005c)();
        puVar6 = PTR_s_partition_42001698;
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_partition_42001698,PTR_DAT_4200169c,uVar4,PTR_s_partition_42001698);
        iVar1 = 0x105;
      }
      else {
        (*DAT_420016b8)(&uStack_58,auStack_b0);
        iVar1 = (*DAT_42000114)(&uStack_58,iVar1 + 0x10);
        if (iVar1 == 0) {
          *DAT_42001690 = (int)puVar2;
          spi_flash_munmap(uStack_38);
          goto LAB_42018c66;
        }
        uVar4 = (*(code *)PTR_FUN_4200005c)();
        puVar6 = PTR_s_partition_42001698;
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_partition_42001698,PTR_DAT_420016a0,uVar4,PTR_s_partition_42001698);
        iVar1 = 0x103;
      }
      while (puVar2 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)puVar2[0xc];
        (*(code *)PTR_FUN_42000570)(puVar2);
        puVar2 = puVar5;
      }
      spi_flash_munmap(uStack_38);
    }
    uVar4 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,puVar6,PTR_DAT_420016a4,uVar4,puVar6,iVar1);
  }
  else {
LAB_42018c66:
    iVar1 = 0;
  }
  (*(code *)PTR_FUN_420008dc)(DAT_4200168c);
  return iVar1;
}


