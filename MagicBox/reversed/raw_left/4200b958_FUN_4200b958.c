// 4200b958  FUN_4200b958  FUN_4200b958  size=79
// strings: Pm7@L

void FUN_4200b958(undefined4 param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  (*(code *)PTR_FUN_420000b8)(PTR_DAT_42000c04);
  puVar2 = PTR_DAT_42000bf0;
  pcVar3 = param_2 + param_3;
  if (param_3 != 0) {
    do {
      cVar1 = *param_2;
      if (((cVar1 != '\n') || (*(int *)(puVar2 + 0x10) == 2)) ||
         ((**(code **)(puVar2 + 0x18))(param_1,0xd), *(int *)(puVar2 + 0x10) != 1)) {
        (**(code **)(puVar2 + 0x18))(param_1,cVar1);
      }
      param_2 = param_2 + 1;
    } while (pcVar3 != param_2);
  }
  (*(code *)PTR_FUN_420000bc)(PTR_DAT_42000c04);
  return;
}


