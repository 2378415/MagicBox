undefined4 FUN_4200cf50(undefined4 param_1,uint *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = FUN_4202d058();
  puVar1 = DAT_42000cc0;
  uVar4 = *param_2 & 0x1f;
  iVar5 = 0;
  if (uVar4 != 0) {
    iVar5 = -(uVar4 - 0x20);
  }
  uVar4 = *param_2 + iVar2 + iVar5;
  if ((uint)DAT_42000cc0[1] < uVar4) {
    uVar3 = 0x101;
  }
  else {
    *param_2 = uVar4;
    (*DAT_42000094)(param_1,0,0x30);
    uVar4 = *param_2 >> 0xc;
    if ((*param_2 & 0xfff) != 0) {
      uVar4 = uVar4 + 1;
    }
    if ((uint)puVar1[1] < uVar4 << 0xc) {
      (*(code *)PTR_FUN_42000330)();
    }
    uVar3 = (*(code *)PTR_FUN_42000cdc)(*DAT_42000cbc,*puVar1);
  }
  return uVar3;
}