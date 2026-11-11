// strings: ,q7@|e

/* WARNING: Control flow encountered bad instruction data */
/* (4 unreachable decompiler blocks omitted) */

void cmd_dispatch(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint local_30 [12];
  
  local_30[0] = (uint)(param_1 == 0);
  if (param_1 != 0) {
    if (param_2 == 0) {
      local_30[0] = 1;
    }
    if ((local_30[0] == 0) && (iVar1 = cmd_lookup(param_1,param_2,local_30), iVar1 != 0)) {
      (*(code *)PTR_FUN_42000dcc)(1,0x32);
      memw();
      iVar2 = *DAT_42000dc0;
      if ((iVar2 != 0) &&
         (((*(int *)(iVar2 + 0x210) != 0 && (*(uint *)(iVar1 + 0x10) < 0x1b)) &&
          (*(code **)(PTR_PTR_42000dc8 + *(uint *)(iVar1 + 0x10) * 4) != (code *)0x0)))) {
        (**(code **)(PTR_PTR_42000dc8 + *(uint *)(iVar1 + 0x10) * 4))
                  (param_1,param_2,iVar2,iVar1,param_1 + local_30[0],param_2 - local_30[0]);
      }
    }
  }
  return;
}