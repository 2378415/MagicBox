// 4200f9f8  FUN_4200f9f8  FUN_4200f9f8  size=42

void FUN_4200f9f8(int param_1,undefined1 param_2)

{
  undefined *puVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x210) != 0)) {
    (*(code *)PTR_FUN_420004dc)(PTR_DAT_42000e50,0xffffffff);
    puVar1 = PTR_DAT_42000e50;
    *(undefined1 *)(*(int *)(param_1 + 0x210) + 0x9c) = param_2;
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  return;
}


