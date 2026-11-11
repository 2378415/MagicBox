// strings: heap_caps_calloc

int FUN_40376138(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_403764dc(param_1,param_2,param_3);
  if (iVar1 == 0 && param_2 != 0) {
    FUN_40375fec(param_1 * param_2,param_3,PTR_s_heap_caps_calloc_40374668);
  }
  return iVar1;
}