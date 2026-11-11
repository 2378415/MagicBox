// strings: bus overflow | No memory to alloc for g_usbd_core[busid].usbd_e

undefined4 FUN_420153a0(char param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  byte bVar5;
  code *pcVar6;
  
  if (param_1 != '\0') {
    (*DAT_42000060)(PTR_DAT_420013a0);
    (*DAT_42000060)(PTR_s_bus_overflow_420013dc);
    (*DAT_42000060)(PTR_DAT_420013a8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(DAT_420013e0 + 4) = param_2;
  iVar2 = FUN_42016acc(1);
  iVar1 = DAT_4200135c;
  *(int *)(DAT_4200135c + 0x824) = iVar2;
  if (iVar2 == 0) {
    (*DAT_42000060)(PTR_DAT_420013a0);
    (*DAT_42000060)(PTR_s_No_memory_to_alloc_for_g_usbd_co_420013e4);
    (*DAT_42000060)(PTR_DAT_420013a8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar2 = FUN_42016a40(PTR_s_usbd_ep0_420013ec,DAT_42000988,0,PTR_FUN_420013e8,0);
  *(int *)(iVar1 + 0x828) = iVar2;
  if (iVar2 == 0) {
    (*DAT_42000060)(PTR_DAT_420013a0);
    (*DAT_42000060)(PTR_s_No_memory_to_alloc_for_g_usbd_co_420013f0);
    (*DAT_42000060)(PTR_DAT_420013a8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(iVar1 + 0x928) = param_3;
  uVar3 = FUN_420154f4(0);
  if (*(char *)(iVar1 + 0x87c) != '\0') {
    bVar5 = 0;
    piVar4 = DAT_420013f4;
    do {
      if ((*piVar4 != 0) && (pcVar6 = *(code **)(*piVar4 + 0xc), pcVar6 != (code *)0x0)) {
        (*pcVar6)(0,0xb);
      }
      bVar5 = bVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar5 < *(byte *)(iVar1 + 0x87c));
  }
  (**(code **)(iVar1 + 0x928))(0,0xb);
  return uVar3;
}