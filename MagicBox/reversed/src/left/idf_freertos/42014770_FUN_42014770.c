void FUN_42014770(uint param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  
  pbVar2 = (byte *)(DAT_4200135c + param_1 * DAT_42001360 + DAT_42001364);
  if (*pbVar2 != 0) {
    bVar4 = 0;
    piVar3 = (int *)(DAT_4200135c + (param_1 & 0xffff) * (DAT_42001360 & 0xffff) + DAT_42001368);
    iVar5 = *piVar3;
    bVar1 = 0;
    if (param_3 == 0) {
      while( true ) {
        if ((iVar5 != 0) && (*(code **)(iVar5 + 0xc) != (code *)0x0)) {
          (**(code **)(iVar5 + 0xc))(param_1,param_2,0);
        }
        bVar1 = bVar1 + 1;
        piVar3 = piVar3 + 1;
        if (*pbVar2 <= bVar1) break;
        iVar5 = *piVar3;
      }
    }
    else {
      while( true ) {
        if (((iVar5 != 0) && (*(code **)(iVar5 + 0xc) != (code *)0x0)) &&
           (*(char *)(param_3 + 2) == *(char *)(iVar5 + 0x18))) {
          (**(code **)(iVar5 + 0xc))(param_1,param_2,param_3);
        }
        bVar4 = bVar4 + 1;
        piVar3 = piVar3 + 1;
        if (*pbVar2 <= bVar4) break;
        iVar5 = *piVar3;
      }
    }
  }
  return;
}