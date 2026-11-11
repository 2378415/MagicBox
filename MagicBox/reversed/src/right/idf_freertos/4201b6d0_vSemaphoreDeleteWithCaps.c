// strings: Hl7@

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_4201b6d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uStack_68;
  
  puVar1 = (undefined4 *)FUN_420207dc(param_1);
  (*DAT_420001e4)(*puVar1);
  if ((param_1 != 0) && (*(int *)(param_1 + 0x28) == 0)) {
    FUN_42017694(param_1);
  }
  if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
    (*(code *)PTR_FUN_42001154)(*(undefined4 *)(param_2 + 0x58));
  }
  if ((((*(ushort *)(param_2 + 0xc) & 8) == 0) || (*(int *)(param_2 + 0x10) == 0)) &&
     (iVar2 = FUN_42017c98(param_1,param_2), iVar2 != 0)) {
    if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001158)(*(undefined4 *)(param_2 + 0x58));
    }
    uStack_68 = 0xffffffff;
  }
  else {
    if (((*(ushort *)(param_2 + 0xc) & 0x1a) != 10) || (*(short *)(param_2 + 0xe) < 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001158)(*(undefined4 *)(param_2 + 0x58));
    }
    uStack_68 = FUN_4201e324(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uStack_68;
}