undefined4 FUN_42026a0c(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if ((param_1 & 3) == 0) {
      uVar1 = FUN_4202661c(param_1,param_2);
    }
    else {
      FUN_42017abc(PTR_s_tlsf_create__Memory_must_be_alig_42001530,4);
      uVar1 = 0;
    }
  }
  return uVar1;
}