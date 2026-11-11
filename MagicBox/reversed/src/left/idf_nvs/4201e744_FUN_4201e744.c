/* WARNING: Control flow encountered bad instruction data */

void FUN_4201e744(code *param_1)

{
  (*param_1)();
  (*(code *)PTR_FUN_42000330)();
  FUN_4201e5e4(param_1);
  (*(code *)PTR_FUN_42000330)();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}