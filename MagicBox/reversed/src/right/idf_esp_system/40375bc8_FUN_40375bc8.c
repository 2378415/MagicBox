// strings:  0x%08lX:0x%08lX

void FUN_40375bc8(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    (*DAT_403745cc)(PTR_s_0x_08lX_0x_08lX_403745c0,param_1,param_2);
  }
  else {
    (*(code *)PTR_FUN_403745c4)(PTR_DAT_403745b8);
    (*(code *)PTR_FUN_403745c8)(param_1);
    (*(code *)PTR_FUN_403745c4)(PTR_DAT_403745bc);
    (*(code *)PTR_FUN_403745c8)(param_2);
  }
  return;
}