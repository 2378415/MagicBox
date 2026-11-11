// strings: zDpU

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40378140(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  int unaff_retaddr;
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  int local_40 [4];
  undefined4 *puStack_30;
  int iStack_2c;
  
  piVar1 = local_40;
  puStack_30 = param_1;
  iVar3 = (**(code **)(*(int *)PTR_PTR_4037487c + 8))(&puStack_30);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*(int *)(puStack_30[1] + 0x40) == 0) {
    return DAT_4037488c;
  }
  if (param_2 == 0) {
    return 0x102;
  }
  if ((uint)puStack_30[5] < param_3) {
    return 0x102;
  }
  if ((uint)puStack_30[5] < param_3 + param_4) {
    return 0x102;
  }
  if (param_4 == 0) {
    return 0;
  }
  iVar3 = DAT_40374828 + -1;
  cVar2 = (**(code **)(*(int *)*puStack_30 + 0x30))((int *)*puStack_30,param_2);
  iStack_2c = (param_4 < DAT_40374450) * param_4 + (param_4 >= DAT_40374450) * DAT_40374450;
  if ((-iVar3 & 0xffU) == 0 && cVar2 == '\0') {
    local_40[0] = 0;
    if (*(code **)(puStack_30[2] + 0x10) != (code *)0x0) {
      iVar3 = (**(code **)(puStack_30[2] + 0x10))(puStack_30[3],iStack_2c,local_40);
      iStack_2c = local_40[0];
      piVar1 = local_40;
      if (iVar3 != 0) goto LAB_403781c8;
    }
    iVar4 = 0x101;
  }
  else {
    iVar3 = 0;
LAB_403781c8:
    while( true ) {
      uVar9 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(*(undefined4 *)((int)piVar1 + 0x10));
      iVar8 = (int)((ulonglong)uVar9 >> 0x20);
      iVar4 = (int)uVar9;
      if (iVar4 != 0) break;
      if (iVar3 == 0) {
        piVar1 = (int *)(unaff_retaddr + 0xb);
      }
      else {
        iVar8 = iVar3;
      }
      uVar6 = *(uint *)((int)piVar1 + 0x14);
      iVar5 = (param_4 < uVar6) * param_4 + (param_4 >= uVar6) * uVar6;
      iVar4 = (**(code **)(*(int *)(*(int *)((int)piVar1 + 0x10) + 4) + 0x40))
                        (*(int *)((int)piVar1 + 0x10),iVar8,param_3,iVar5);
      if (iVar4 != 0) {
        (**(code **)(*(int *)PTR_PTR_4037487c + 4))(*(undefined4 *)((int)piVar1 + 0x10),iVar4);
        break;
      }
      iVar4 = (**(code **)(*(int *)(unaff_retaddr + 4) + 4))(*(undefined4 *)((int)piVar1 + 0x10),0);
      if (iVar3 != 0) {
        (*DAT_403744d4)(param_2,iVar3,iVar5);
      }
      param_3 = param_3 + iVar5;
      param_4 = param_4 - iVar5;
      param_2 = param_2 + iVar5;
      if ((iVar4 != 0) || (param_4 == 0)) break;
    }
    pcVar7 = *(code **)(*(int *)(*(int *)((int)piVar1 + 0x10) + 8) + 0x14);
    if (pcVar7 != (code *)0x0) {
      (*pcVar7)(*(undefined4 *)(*(int *)((int)piVar1 + 0x10) + 0xc),iVar3);
    }
  }
  return iVar4;
}