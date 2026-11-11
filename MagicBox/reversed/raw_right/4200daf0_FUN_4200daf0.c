// 4200daf0  FUN_4200daf0  FUN_4200daf0  size=100

undefined4 FUN_4200daf0(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  byte *pbVar5;
  
  pbVar5 = (byte *)*DAT_42000b98;
  do {
    if ((byte *)*DAT_42000b9c <= pbVar5) {
      return 0;
    }
    bVar1 = *pbVar5;
    if (((((bVar1 & 4) == 0) || (pbVar5[1] == param_1)) &&
        (((bVar1 & 8) == 0 || (pbVar5[2] == param_2)))) &&
       (((bVar1 & 0x10) == 0 || (pbVar5[3] == param_3)))) {
      if (((bVar1 & 3) == 0) || (*(int *)(pbVar5 + 4) == 0)) {
LAB_4200db44:
        return *(undefined4 *)(pbVar5 + 8);
      }
      iVar3 = 0;
      while( true ) {
        puVar4 = (ushort *)(iVar3 * 4 + *(int *)(pbVar5 + 4));
        uVar2 = (uint)*puVar4;
        if ((uVar2 == 0) || ((uVar2 == param_4 && (puVar4[1] == param_5)))) break;
        iVar3 = iVar3 + 1;
      }
      if (uVar2 != 0) goto LAB_4200db44;
    }
    pbVar5 = pbVar5 + 0xc;
  } while( true );
}


