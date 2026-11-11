// strings: Hl7@

int FUN_420176e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_30 [12];
  
  uVar2 = FUN_4202517c(param_1,param_3,local_30);
  if ((uVar2 != 0) && (iVar3 = FUN_420175ec(param_1), iVar3 != 0)) {
    iVar4 = FUN_4200a024(param_1,param_2,local_30[0],0x1b6);
    if (-1 < iVar4) {
      if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
        (*(code *)PTR_FUN_42001154)(*(undefined4 *)(iVar3 + 0x58));
      }
      *(undefined **)(iVar3 + 0x24) = PTR_FUN_4200116c;
      puVar1 = PTR_FUN_42001170;
      *(short *)(iVar3 + 0xe) = (short)iVar4;
      *(undefined **)(iVar3 + 0x28) = puVar1;
      puVar1 = PTR_FUN_42001174;
      *(short *)(iVar3 + 0xc) = (short)uVar2;
      *(undefined **)(iVar3 + 0x2c) = puVar1;
      puVar1 = PTR_FUN_42001178;
      *(int *)(iVar3 + 0x20) = iVar3;
      *(undefined **)(iVar3 + 0x30) = puVar1;
      if ((uVar2 & 0x100) != 0) {
        FUN_420177b0(param_1,iVar3,0,2);
      }
      if ((*(uint *)(iVar3 + 100) & 1) != 0) {
        return iVar3;
      }
      if ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0) {
        (*(code *)PTR_FUN_42001158)(*(undefined4 *)(iVar3 + 0x58));
        return iVar3;
      }
      return iVar3;
    }
    FUN_420175cc();
    *(undefined2 *)(iVar3 + 0xc) = 0;
    (*(code *)PTR_FUN_42001160)(*(undefined4 *)(iVar3 + 0x58));
    FUN_420175dc();
  }
  return 0;
}