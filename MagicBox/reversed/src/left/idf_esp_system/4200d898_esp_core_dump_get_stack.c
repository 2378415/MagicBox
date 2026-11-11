// strings: stk_paddr != ((void *)0) && stk_vaddr != ((void  | core_dump_port.c | esp_core_dump_get_stack

int FUN_4200d898(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *in_t0;
  
  uVar4 = *(uint *)(param_1 + 8);
  uVar6 = *(uint *)(param_1 + 4);
  puVar5 = (undefined *)((uVar4 < uVar6) * uVar4 + (uVar4 >= uVar6) * uVar6);
  iVar3 = ((uVar4 < uVar6) * uVar6 + (uVar4 >= uVar6) * uVar4) - (int)puVar5;
  if ((param_3 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    puVar5 = in_t0;
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_core_dump_port_c_3c0363f8_0x2d_42000d54,0x15e,
               PTR_s_esp_core_dump_get_stack_42000d50,
               PTR_s_stk_paddr______void___0_____stk__42000d4c);
  }
  puVar2 = DAT_42000d5c;
  iVar1 = DAT_42000d58;
  *param_2 = puVar5;
  if (puVar5 + iVar1 <= puVar2) {
    puVar5 = PTR_DAT_42000d60;
  }
  *param_3 = puVar5;
  return iVar3;
}