// 42011d3c  FUN_42011d3c  FUN_42011d3c  size=111
// strings: PARSE

void FUN_42011d3c(int param_1,int *param_2,byte param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_4 - 1;
  if (uVar3 < 0x11) {
    *(int *)(uVar3 * 4 + param_1) = *param_2;
    *(byte *)(param_1 + uVar3 + 0x44) = param_3;
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar2 = FUN_42011ca0(param_4);
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_4200102c,uVar1,PTR_s_PARSE_42000efc,uVar2,*param_2,
               (uint)param_3);
    iVar4 = *param_2;
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (2,PTR_s_PARSE_42000efc,PTR_DAT_42001028,uVar1,PTR_s_PARSE_42000efc,param_4);
    iVar4 = *param_2;
  }
  *param_2 = (uint)param_3 + iVar4;
  return;
}


