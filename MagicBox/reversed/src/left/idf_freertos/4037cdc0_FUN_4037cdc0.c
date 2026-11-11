void FUN_4037cdc0(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 in_PRID;
  
  iVar5 = DAT_40374e18;
  memw();
  uVar2 = *DAT_40374edc;
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  piVar3 = (int *)(uVar4 * 4 + DAT_40374e18);
  memw();
  memw();
  if (*(int *)(*piVar3 + 0x14) != DAT_40374ee0) {
    memw();
    memw();
    iVar6 = *piVar3;
    *(undefined1 *)(*piVar3 + 0x152) = 0;
    FUN_4037cc94(iVar6 + 4);
    piVar1 = DAT_40374ee4;
    if ((param_1 == -1) && (param_2 != 0)) {
      memw();
      iVar5 = DAT_40374ee4[1];
      memw();
      memw();
      *(int *)(*piVar3 + 8) = iVar5;
      memw();
      memw();
      memw();
      *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar5 + 8);
      memw();
      memw();
      memw();
      *(int *)(*(int *)(iVar5 + 8) + 4) = *piVar3 + 4;
      memw();
      memw();
      *(int *)(iVar5 + 8) = *piVar3 + 4;
      memw();
      memw();
      *(int **)(*piVar3 + 0x14) = piVar1;
      memw();
      memw();
      *piVar1 = *piVar1 + 1;
    }
    else {
      piVar3 = (int *)(iVar5 + uVar4 * 4);
      memw();
      uVar4 = uVar2 + param_1;
      memw();
      *(uint *)(*piVar3 + 4) = uVar4;
      if (uVar4 < uVar2) {
        memw();
        memw();
        FUN_4037cc28(*DAT_40374ee8,*piVar3 + 4);
      }
      else {
        memw();
        memw();
        FUN_4037cc28(*DAT_40374eec,*piVar3 + 4);
        memw();
        if (uVar4 < *DAT_40374ef0) {
          memw();
          *DAT_40374ef0 = uVar4;
        }
      }
    }
  }
  return;
}