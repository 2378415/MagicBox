// 4200bd34  esp_core_dump_get_stack  FUN_4200bd34  size=73
// strings: stk_paddr != ((void *)0) && stk_vaddr != ((void  | core_dump_port.c | esp_core_dump_get_stack

int FUN_4200bd34(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_t0;
  
  uVar2 = *(uint *)(param_1 + 8);
  uVar4 = *(uint *)(param_1 + 4);
  iVar3 = (uVar2 < uVar4) * uVar2 + (uVar2 >= uVar4) * uVar4;
  iVar1 = ((uVar2 < uVar4) * uVar4 + (uVar2 >= uVar4) * uVar2) - iVar3;
  if (param_3 == (int *)0x0 || param_2 == (int *)0x0) {
    iVar3 = in_t0;
    (*(code *)PTR_FUN_42000044)
              (PTR_s_core_dump_port_c_3c0333b0_0x2d_42000ab0,0x15e,
               PTR_s_esp_core_dump_get_stack_42000aac,
               PTR_s_stk_paddr______void___0_____stk__42000aa8);
  }
  *param_2 = iVar3;
  if (DAT_42000ab8 < (uint)(iVar3 + DAT_42000ab4)) {
    *param_3 = iVar3;
  }
  else {
    *param_3 = (int)PTR_DAT_42000abc;
  }
  return iVar1;
}


