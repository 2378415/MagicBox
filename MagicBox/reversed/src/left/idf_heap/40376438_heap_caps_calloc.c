// strings: heap_caps_calloc

int FUN_40376438(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_40376760(param_1,param_2,param_3);
  if ((iVar1 == 0) && (param_2 != 0)) {
    FUN_403762fc(param_1 * param_2,param_3,PTR_s_heap_caps_calloc_403746a8);
  }
  return iVar1;
}