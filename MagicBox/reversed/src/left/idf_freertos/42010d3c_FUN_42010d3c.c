void FUN_42010d3c(undefined4 param_1,short param_2,short param_3)

{
  undefined4 *puVar1;
  
  FUN_4200f770(param_1,(int)param_2,(int)param_3,1);
  puVar1 = DAT_42000e64;
  (*(code *)PTR_FUN_42000480)(*DAT_42000e64,0xffffffff);
  (*(code *)PTR_FUN_42000098)(1);
  FUN_4200f770(param_1,(int)-param_2,(int)-param_3,0);
  (*(code *)PTR_FUN_42000480)(*puVar1,0xffffffff);
  return;
}