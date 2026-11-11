void FUN_4200ba28(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  undefined *puVar2;
  int unaff_retaddr;
  uint unaff_a10;
  int unaff_a11;
  undefined8 uVar3;
  
  puVar2 = PTR_DAT_42000bf0;
  puVar1 = DAT_420002b0;
  while( true ) {
    memw();
    if ((DAT_420002b0[1] & 2) != 0) {
      memw();
      if ((DAT_420002b0[1] & 2) != 0) {
        memw();
        *DAT_420002b0 = param_2 & 0xff;
      }
      if (param_2 == 10) {
        memw();
        memw();
        puVar1[1] = puVar1[1] | 1;
      }
      uVar3 = (*(code *)PTR_FUN_4200092c)();
      *(undefined8 *)(puVar2 + 0x28) = uVar3;
      return;
    }
    flix();
    unaff_a11 = unaff_a11 + *(int *)(PTR_DAT_42000bf0 + 0x2c) * -2;
    unaff_a10 = unaff_a10 - *(int *)(unaff_retaddr + 4);
    if (0 < unaff_a11) break;
    if ((unaff_a11 == 0) && (DAT_42000c10 < unaff_a10)) {
      return;
    }
  }
  return;
}