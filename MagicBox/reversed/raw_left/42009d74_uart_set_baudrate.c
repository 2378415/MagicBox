// 42009d74  uart_set_baudrate  FUN_42009d74  size=292
// strings: uart_set_baudrate

/* WARNING: Instruction at (ram,0x42009ded) overlaps instruction at (ram,0x42009dec)
    */
/* WARNING: Control flow encountered bad instruction data */

int FUN_42009d74(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int unaff_retaddr;
  undefined4 *puVar8;
  int iVar7;
  int iVar6;
  int iVar5;
  int iVar4;
  int iVar3;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int in_t0;
  undefined1 auStack_28 [40];
  
  puVar1 = PTR_DAT_42000a3c;
  if (param_1 < 3) {
    iVar10 = func_0x41faa63c(PTR_DAT_42000a3c + param_1 * 0x18 + 8,auStack_28);
    iVar3 = unaff_retaddr + iVar10;
    iVar4 = unaff_retaddr + iVar10;
    iVar5 = unaff_retaddr + iVar10;
    iVar6 = unaff_retaddr + iVar10;
    iVar7 = unaff_retaddr + iVar10;
    puVar8 = (undefined4 *)(unaff_retaddr + iVar10);
    iVar10 = FUN_4201acb0(iVar10,0,unaff_retaddr + iVar10 + 0x14);
    if (iVar10 == 0) {
      if (unaff_retaddr != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      puVar13 = puVar1 + param_5;
      (*(code *)PTR_FUN_420004dc)(puVar13,0xffffffff);
      iVar12 = *(int *)(iVar3 + 0x14);
      iVar16 = -1;
      iVar15 = iVar12 + -1;
      iVar14 = *(int *)(puVar1 + param_1 * 0x18 + 8);
      if (iVar15 != -1) {
        iVar16 = 0;
      }
      iVar16 = (*DAT_420001f0)(iVar15 + param_2 * DAT_42000adc,
                               iVar16 + (int)((ulonglong)param_2 * (ulonglong)DAT_42000adc >> 0x20)
                               + iVar15);
      if (iVar16 == 0) {
        iVar16 = in_t0;
        (*(code *)PTR_FUN_42000330)();
      }
      memw();
      uVar11 = (uint)(iVar12 << 4) / (param_2 * iVar16);
      memw();
      *(uint *)(iVar14 + 0x14) = *(uint *)(iVar14 + 0x14) & 0xfffff000 | uVar11 >> 4 & 0xfff;
      memw();
      memw();
      *(uint *)(iVar14 + 0x14) = *(uint *)(iVar14 + 0x14) & DAT_42000ae0 | (uVar11 & 0xf) << 0x14;
      uVar11 = DAT_42000ae4;
      memw();
      memw();
      *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar14 + 0x78);
      memw();
      memw();
      *(uint *)(iVar6 + 0x10) = *(uint *)(iVar5 + 0x10) & uVar11 | (iVar16 - 1U & 0xff) << 0xc;
      memw();
      memw();
      *(undefined4 *)(iVar14 + 0x78) = *(undefined4 *)(iVar7 + 0x10);
      (*(code *)PTR_FUN_420004e0)(puVar13);
    }
    else {
      uVar9 = (*(code *)PTR_FUN_4200005c)();
      puVar2 = PTR_DAT_42000ad8;
      puVar13 = PTR_s_uart_set_baudrate_42000ad4;
      puVar1 = PTR_DAT_42000a54;
      *puVar8 = 0x15f;
      (*(code *)PTR_FUN_42000118)(1,puVar1,puVar2,uVar9,puVar1,puVar13);
    }
  }
  else {
    uVar9 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_DAT_42000a54,PTR_DAT_42000a58,uVar9,PTR_DAT_42000a54,
               PTR_s_uart_set_baudrate_42000ad4,0x159);
    iVar10 = -1;
  }
  return iVar10;
}


