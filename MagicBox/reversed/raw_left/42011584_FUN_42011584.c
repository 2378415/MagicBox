// 42011584  FUN_42011584  FUN_42011584  size=65
// strings: PARSE

bool FUN_42011584(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_2;
  bVar1 = iVar3 < param_3 + -1;
  if (bVar1) {
    *param_2 = iVar3 + 1;
    (*DAT_42000064)(param_1 + (iVar3 + 1) * 0x164,param_4);
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,PTR_s_PARSE_42000efc,PTR_DAT_42000f4c,uVar2,PTR_s_PARSE_42000efc);
  }
  return bVar1;
}


