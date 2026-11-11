// 42001608  FUN_42001608  FUN_42001608  size=53

undefined4 FUN_42001608(void)

{
  int iVar1;
  code *pcVar2;
  
  for (iVar1 = 4; -1 < iVar1; iVar1 = iVar1 + -1) {
    pcVar2 = *(code **)(iVar1 * 4 + DAT_42000028);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)();
    }
  }
  (*(code *)PTR_FUN_4200002c)();
  (*(code *)PTR_FUN_42000030)();
  cust0();
  return 0;
}


