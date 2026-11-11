// 42014480  FUN_42014480  FUN_42014480  size=82
// strings: b'ELL

bool FUN_42014480(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_4200132c,0xffffffff);
  iVar3 = *(int *)(param_1 + 0x118);
  if (iVar3 != 0) {
    iVar2 = *(int *)(param_1 + 0x114);
    (*DAT_42000064)(param_2,iVar2 * 0x44 + param_1,0x44);
    puVar1 = PTR_DAT_4200132c;
    *(uint *)(param_1 + 0x114) = iVar2 + 1U & 3;
    *(int *)(param_1 + 0x118) = iVar3 + -1;
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  else {
    (*(code *)PTR_FUN_420004e0)(PTR_DAT_4200132c);
  }
  return iVar3 != 0;
}


