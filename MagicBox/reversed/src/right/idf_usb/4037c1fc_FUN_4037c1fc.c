// strings: esp_intr_alloc(ETS_SYSTIMER_TARGET0_INTR_SOURCE  | vSystimerSetup

void FUN_4037c1fc(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  undefined1 in_PRID;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar5 = rsr(in_PRID);
  uVar5 = uVar5 >> 0xd & 1;
  iVar2 = (*(code *)PTR_FUN_40374db8)(uVar5 + 0x39,0x402,PTR_FUN_40374da4,DAT_40374da0,0);
  if (iVar2 != 0) {
    FUN_4037af64(iVar2,PTR_s__IDF_components_freertos_port_sy_40374db0,0x48,
                 PTR_s_vSystimerSetup_40374dac,PTR_s_esp_intr_alloc_ETS_SYSTIMER_TARG_40374da8);
  }
  if (uVar5 == 0) {
    for (cVar4 = '\x01'; piVar1 = DAT_40374da0, cVar4 != '\0'; cVar4 = cVar4 + -1) {
      iVar3 = (*(code *)PTR_FUN_40374a84)(0x24);
      iVar2 = DAT_40374a70;
      uVar5 = DAT_403749c8;
      if (iVar3 == 0) {
        memw();
        memw();
        *(uint *)(DAT_40374a70 + 0x18) = *(uint *)(DAT_40374a70 + 0x18) | DAT_403749c8;
        memw();
        memw();
        *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | uVar5;
        memw();
        memw();
        *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & DAT_403747e0;
      }
      (*(code *)PTR_FUN_40374a80)(0x24,iVar3);
    }
    FUN_40380514(DAT_40374da0);
    local_30 = *(undefined4 *)PTR_PTR_40374db4;
    uStack_2c = *(undefined4 *)(PTR_PTR_40374db4 + 4);
    FUN_40380698(piVar1,&local_30);
    iVar2 = *piVar1;
    memw();
    memw();
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfff00000;
    memw();
    *(undefined4 *)(iVar2 + 0x18) = 0;
    memw();
    *(undefined4 *)(iVar2 + 0x60) = 1;
    for (uVar5 = 0; uVar5 < 2; uVar5 = uVar5 + 1) {
      FUN_40380710(DAT_40374da0,1,uVar5,0);
      FUN_40380658(DAT_40374da0,uVar5,0);
    }
    for (uVar5 = 0; piVar1 = DAT_40374da0, uVar5 < 2; uVar5 = uVar5 + 1) {
      FUN_403806ec(DAT_40374da0,uVar5,1);
      FUN_40380580(piVar1,uVar5,1000);
      FUN_40380658(piVar1,uVar5,1);
      FUN_40380710(piVar1,1,uVar5);
      piVar1 = DAT_40374da0;
      if (uVar5 == 0) {
        FUN_403806a8(DAT_40374da0,0);
        FUN_403806c8(piVar1,1);
        FUN_40380604(piVar1,1,500,0);
      }
    }
  }
  else {
    FUN_403806a8(DAT_40374da0,uVar5);
  }
  return;
}