/* WARNING: Control flow encountered bad instruction data */
/* (8 unreachable decompiler blocks omitted) */

undefined4 FUN_42009de4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    uVar3 = 0x102;
  }
  else if (param_2 == -1) {
    iVar1 = FUN_42009cac();
    if (iVar1 < 0) {
      uVar3 = 0x101;
    }
    else if (*(int *)(iVar1 * 4 + DAT_4200097c) == 0) {
      if (iVar1 == *DAT_42000980) {
        *DAT_42000980 = *DAT_42000980 + 1;
      }
      iVar2 = (*(code *)PTR_FUN_42000484)(0x24,DAT_4200077c);
      if (iVar2 != 0) {
        *(int *)(iVar1 * 4 + DAT_4200097c) = iVar2;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      uVar3 = 0x101;
    }
    else {
      uVar3 = 0x103;
    }
  }
  else {
    uVar3 = 0x102;
  }
  return uVar3;
}