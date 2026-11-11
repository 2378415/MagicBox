// strings: Lk7@

void FUN_4200997c(undefined4 param_1,int param_2,uint param_3)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  
  (*(code *)PTR_FUN_42000818)(PTR_DAT_42000938);
  for (uVar3 = 0; puVar2 = PTR_DAT_42000920, uVar3 < param_3; uVar3 = uVar3 + 1) {
    cVar1 = *(char *)(param_2 + uVar3);
    if (((cVar1 != '\n') || (*(int *)(PTR_DAT_42000920 + 0x10) == 2)) ||
       ((**(code **)(PTR_DAT_42000920 + 0x18))(param_1,0xd), *(int *)(puVar2 + 0x10) != 1)) {
      (**(code **)(PTR_DAT_42000920 + 0x18))(param_1,cVar1);
    }
  }
  (*(code *)PTR_FUN_4200081c)(PTR_DAT_42000938);
  return;
}