void FUN_4200f770(int param_1,undefined2 param_2,undefined2 param_3,uint param_4)

{
  undefined *puVar1;
  
  memw();
  memw();
  *DAT_42000e44 = param_2;
  memw();
  memw();
  memw();
  *DAT_42000e48 = param_3;
  memw();
  memw();
  memw();
  *DAT_42000e4c = 1;
  memw();
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000e50,0xffffffff);
  puVar1 = PTR_DAT_42000e50;
  *(uint *)(*(int *)(param_1 + 0x210) + 0xa0) = param_4 & 0xff;
  (*(code *)PTR_FUN_420004e0)(puVar1);
  memw();
  memw();
  *DAT_42000e04 = 1;
  memw();
  if (*DAT_42000e08 != 0) {
    (*(code *)PTR_FUN_42000484)(*DAT_42000e08,0,0,2);
  }
  return;
}