// 4037c624  FUN_4037c624  FUN_4037c624  size=310
// strings: esp_intr_alloc(ETS_SYSTIMER_TARGET0_INTR_SOURCE  | vSystimerSetup

void FUN_4037c624(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  piVar1 = DAT_40374e58;
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  iVar2 = (*(code *)PTR_FUN_40374e70)(uVar4 + 0x39,0x402,PTR_FUN_40374e5c,DAT_40374e58,0);
  if (iVar2 != 0) {
    FUN_4037b37c(iVar2,PTR_s__IDF_components_freertos_port_sy_40374e68,0x48,
                 PTR_s_vSystimerSetup_40374e64,PTR_s_esp_intr_alloc_ETS_SYSTIMER_TARG_40374e60);
  }
  if (uVar4 == 0) {
    iVar3 = (*(code *)PTR_FUN_40374b3c)(0x24);
    iVar2 = DAT_40374b2c;
    uVar4 = DAT_40374a60;
    if (iVar3 == 0) {
      memw();
      memw();
      *(uint *)(DAT_40374b2c + 0x18) = *(uint *)(DAT_40374b2c + 0x18) | DAT_40374a60;
      memw();
      memw();
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | uVar4;
      memw();
      memw();
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & DAT_40374864;
    }
    (*(code *)PTR_FUN_40374b40)(0x24,iVar3);
    FUN_40380624(piVar1);
    local_30 = *(undefined4 *)PTR_PTR_40374e6c;
    uStack_2c = *(undefined4 *)(PTR_PTR_40374e6c + 4);
    FUN_40380798(piVar1,&local_30);
    iVar2 = *piVar1;
    memw();
    memw();
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfff00000;
    memw();
    *(undefined4 *)(iVar2 + 0x18) = 0;
    memw();
    *(undefined4 *)(iVar2 + 0x60) = 1;
    FUN_40380874(piVar1,1,0,0);
    FUN_40380758(piVar1,0,0);
    FUN_40380874(piVar1,1,1,0);
    FUN_40380758(piVar1,1,0);
    iVar2 = 0;
    while( true ) {
      FUN_40380850(piVar1,iVar2,1);
      FUN_40380688(piVar1,iVar2,1000);
      FUN_40380758(piVar1,iVar2,1);
      FUN_40380874(piVar1,1,iVar2,1);
      if (iVar2 != 0) break;
      FUN_4038080c(piVar1,0);
      FUN_4038082c(piVar1,1);
      FUN_40380704(piVar1,1,500,0);
      iVar2 = 1;
    }
  }
  else {
    FUN_4038080c(piVar1,uVar4);
  }
  return;
}


