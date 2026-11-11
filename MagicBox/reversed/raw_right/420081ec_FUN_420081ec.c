// 420081ec  FUN_420081ec  FUN_420081ec  size=207
// strings: 8a7@

int FUN_420081ec(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = (*(code *)PTR_FUN_420008b8)(1,0x7c,DAT_4200077c);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = (*(code *)PTR_FUN_420008b8)(0x80,4,DAT_4200077c);
  *(int *)(iVar2 + 0x20) = iVar3;
  if (iVar3 != 0) {
    if (0 < param_2) {
      iVar3 = FUN_42026278(param_2,0xc,DAT_4200077c);
      *(int *)(iVar2 + 0x5c) = iVar3;
      if (iVar3 == 0) goto LAB_420082b2;
    }
    if (0 < param_3) {
      iVar3 = (*(code *)PTR_FUN_420008bc)(param_3,0,DAT_4200077c);
      *(int *)(iVar2 + 100) = iVar3;
      if (iVar3 == 0) goto LAB_420082b2;
    }
    uVar1 = DAT_4200077c;
    uVar4 = (*(code *)PTR_FUN_420008bc)(param_4,2,DAT_4200077c);
    *(undefined4 *)(iVar2 + 0x60) = uVar4;
    uVar4 = FUN_42026314(0,0,1,uVar1);
    *(undefined4 *)(iVar2 + 0x6c) = uVar4;
    uVar4 = FUN_42026314(0,0,1,uVar1);
    *(undefined4 *)(iVar2 + 0x68) = uVar4;
    uVar4 = FUN_42026314(0,0,3,uVar1);
    *(undefined4 *)(iVar2 + 0x78) = uVar4;
    uVar4 = FUN_42026314(0,0,3,uVar1);
    *(undefined4 *)(iVar2 + 0x74) = uVar4;
    iVar3 = FUN_42026314(0,0,3,uVar1);
    *(int *)(iVar2 + 0x70) = iVar3;
    if ((((*(int *)(iVar2 + 0x60) != 0) && (*(int *)(iVar2 + 0x68) != 0)) &&
        (*(int *)(iVar2 + 0x6c) != 0)) &&
       (((*(int *)(iVar2 + 0x78) != 0 && (*(int *)(iVar2 + 0x74) != 0)) && (iVar3 != 0)))) {
      return iVar2;
    }
  }
LAB_420082b2:
  FUN_4200817c(iVar2);
  return 0;
}


