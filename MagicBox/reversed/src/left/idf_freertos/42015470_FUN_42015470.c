// strings: bus overflow

undefined4 FUN_42015470(char param_1)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  code *pcVar4;
  
  iVar1 = DAT_4200135c;
  if (param_1 != '\0') {
    (*DAT_42000060)(PTR_DAT_420013a0);
    (*DAT_42000060)(PTR_s_bus_overflow_420013dc);
    (*DAT_42000060)(PTR_DAT_420013a8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (**(code **)(DAT_4200135c + 0x928))(0,0xc);
  if (*(char *)(iVar1 + 0x87c) != '\0') {
    bVar2 = 0;
    piVar3 = DAT_420013f4;
    do {
      if ((*piVar3 != 0) && (pcVar4 = *(code **)(*piVar3 + 0xc), pcVar4 != (code *)0x0)) {
        (*pcVar4)(0,0xc);
      }
      bVar2 = bVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (bVar2 < *(byte *)(iVar1 + 0x87c));
  }
  FUN_420158f0(0);
  *(undefined1 *)(iVar1 + 0x87c) = 0;
  if (*(int *)(iVar1 + 0x824) != 0) {
    FUN_42016ae0();
  }
  if (*(int *)(iVar1 + 0x828) != 0) {
    FUN_42016a68();
  }
  return 0;
}