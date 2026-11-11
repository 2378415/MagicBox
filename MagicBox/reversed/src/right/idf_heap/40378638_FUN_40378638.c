int FUN_40378638(undefined4 param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 5;
  while ((iVar3 == 0 && (iVar2 != 0))) {
    uVar1 = (*(code *)PTR_FUN_403748c8)(DAT_403748c4);
    if (uVar1 <= param_2) {
      param_2 = (*(code *)PTR_FUN_403748c8)(DAT_403748c4);
    }
    param_2 = param_2 + 3 & 0xfffffffc;
    iVar3 = FUN_40376004(param_2,DAT_403748c4);
    iVar2 = iVar2 + -1;
  }
  if (iVar3 == 0) {
    param_2 = 0;
  }
  *param_3 = param_2;
  return iVar3;
}