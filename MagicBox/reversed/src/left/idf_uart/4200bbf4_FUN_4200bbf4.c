// strings: Pm7@L

undefined4 FUN_4200bbf4(undefined4 param_1,uint param_2,ushort *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  if (param_3 == (ushort *)0x0) {
LAB_4200bc35:
    puVar3 = (undefined4 *)FUN_42020b54();
    *puVar3 = 0x16;
    uVar4 = 0xffffffff;
  }
  else {
    if (param_2 == 1) {
      (*(code *)PTR_FUN_420000b8)(PTR_DAT_42000c04);
      puVar5 = PTR_DAT_42000bf0;
      iVar1 = (**(code **)(PTR_DAT_42000bf0 + 0x20))(param_1);
      (*(code *)PTR_FUN_420000bc)(PTR_DAT_42000c04);
      if (iVar1 != 0) {
        piVar2 = (int *)FUN_42020b54();
        *piVar2 = iVar1;
      }
    }
    else {
      if ((param_2 & 0xfffffffd) != 0) goto LAB_4200bc35;
      puVar5 = PTR_DAT_42000bf0;
    }
    if ((*param_3 & 8) == 0) {
      uVar4 = 1;
      if ((*param_3 >> 1 & 1) == 0) {
        uVar4 = 2;
      }
      *(undefined4 *)(puVar5 + 0x14) = uVar4;
    }
    else {
      *(undefined4 *)(puVar5 + 0x14) = 0;
    }
    uVar4 = 0;
  }
  return uVar4;
}