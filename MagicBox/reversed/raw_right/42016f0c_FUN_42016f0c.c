// 42016f0c  FUN_42016f0c  FUN_42016f0c  size=42

/* WARNING: Control flow encountered bad instruction data */

void FUN_42016f0c(code *param_1)

{
  (*param_1)();
  (*(code *)PTR_FUN_4200006c)();
  FUN_42016dac(param_1);
  (*(code *)PTR_FUN_4200006c)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


