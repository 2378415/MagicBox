undefined4 FUN_42008d38(uint param_1,uint *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_42000848;
  if (param_1 < 3) {
    if (param_2 == (uint *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      memw();
      *(undefined4 *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0x10) = DAT_420008e8;
      (*(code *)PTR_FUN_420003a8)(puVar1 + param_1 * 0x18 + 0xc,0xffffffff);
      if ((*param_2 & 0x100) == 0) {
        FUN_420137ac(PTR_DAT_42000848 + param_1 * 0x18 + 8,0);
      }
      else {
        FUN_420137ac(PTR_DAT_42000848 + param_1 * 0x18 + 8,(char)param_2[1]);
      }
      if ((*param_2 & 1) != 0) {
        FUN_42024b3c(PTR_DAT_42000848 + param_1 * 0x18 + 8,*(undefined1 *)((int)param_2 + 6));
      }
      if ((*param_2 & 2) != 0) {
        FUN_420136d0(PTR_DAT_42000848 + param_1 * 0x18 + 8,*(undefined1 *)((int)param_2 + 5));
      }
      memw();
      memw();
      *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) =
           *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) | *param_2;
      (*(code *)PTR_FUN_420003ac)(puVar1 + param_1 * 0x18 + 0xc);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}