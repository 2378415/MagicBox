// 42007888  FUN_42007888  FUN_42007888  size=107

char FUN_42007888(int param_1)

{
  char cVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 * 4 + DAT_42000844);
  cVar1 = *(char *)(iVar4 + 0x1c);
  if (cVar1 != '\0') {
    iVar4 = (*(code *)PTR_FUN_42000878)
                      (*(undefined4 *)(iVar4 + 0x60),*(undefined4 *)(iVar4 + 0x20),
                       *(undefined1 *)(iVar4 + 0x24),0);
    if (iVar4 == 1) {
      puVar2 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
      (*(code *)PTR_FUN_420003a8)(puVar2,0xffffffff);
      piVar3 = (int *)(param_1 * 4 + DAT_42000844);
      iVar4 = *piVar3;
      *(uint *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + (uint)*(byte *)(iVar4 + 0x24);
      *(undefined1 *)(iVar4 + 0x1c) = 0;
      (*(code *)PTR_FUN_420003ac)(puVar2);
      FUN_42007498(*(undefined4 *)*piVar3,0x101);
    }
    else {
      cVar1 = '\0';
    }
  }
  return cVar1;
}


