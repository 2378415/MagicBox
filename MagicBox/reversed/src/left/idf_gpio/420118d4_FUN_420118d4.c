// strings: PARSE

void FUN_420118d4(int param_1,int param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,PTR_s_PARSE_42000efc,PTR_DAT_42000f84,uVar1,PTR_s_PARSE_42000efc);
  }
  else if (param_2 == 0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,PTR_s_PARSE_42000efc,PTR_DAT_42000f88,uVar1,PTR_s_PARSE_42000efc);
  }
  else {
    *(undefined1 *)(param_1 + 8) = param_3;
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_42000f8c,uVar1,PTR_s_PARSE_42000efc,param_3);
  }
  return;
}