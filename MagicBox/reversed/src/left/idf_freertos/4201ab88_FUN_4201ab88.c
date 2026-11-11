undefined4 FUN_4201ab88(void)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_420019ac,0xffffffff);
  pcVar2 = DAT_420019b0;
  cVar4 = *DAT_420019b0;
  if (cVar4 == '\0') {
    (*(code *)PTR_FUN_420019b8)();
    iVar3 = FUN_42007950(2);
    *DAT_420019b4 = iVar3;
    if (iVar3 == 0) {
      (*(code *)PTR_FUN_420019bc)();
      (*(code *)PTR_FUN_420004e0)(PTR_DAT_420019ac);
      return 0;
    }
    cVar4 = *pcVar2;
  }
  puVar1 = PTR_DAT_420019ac;
  *pcVar2 = cVar4 + '\x01';
  (*(code *)PTR_FUN_420004e0)(puVar1);
  return 1;
}