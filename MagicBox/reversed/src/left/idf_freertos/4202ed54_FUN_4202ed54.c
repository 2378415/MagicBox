/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4202ed54(undefined4 param_1,uint param_2)

{
  if ((param_2 & 3) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_420204ec(PTR_s_tlsf_add_pool__Memory_must_be_al_42001f98,4);
  return 0;
}