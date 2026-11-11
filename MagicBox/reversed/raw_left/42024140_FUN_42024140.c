// 42024140  FUN_42024140  FUN_42024140  size=263
// strings:  n7@

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_42024140(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uStack_68;
  
  puVar1 = (undefined4 *)FUN_4202924c(param_1);
  (*DAT_4200030c)(*puVar1);
  if ((param_1 != 0) && (*(int *)(param_1 + 0x28) == 0)) {
    FUN_420200c4(param_1);
  }
  if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
    (*(code *)PTR_FUN_42001c30)(*(undefined4 *)(param_2 + 0x58));
  }
  if ((((*(ushort *)(param_2 + 0xc) & 8) == 0) || (*(int *)(param_2 + 0x10) == 0)) &&
     (iVar2 = FUN_42020708(param_1,param_2), iVar2 != 0)) {
    if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001c34)(*(undefined4 *)(param_2 + 0x58));
    }
    uStack_68 = 0xffffffff;
  }
  else {
    if (((*(ushort *)(param_2 + 0xc) & 0x1a) != 10) || (*(short *)(param_2 + 0xe) < 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (((*(uint *)(param_2 + 100) & 1) == 0) && ((*(ushort *)(param_2 + 0xc) & 0x200) == 0)) {
      (*(code *)PTR_FUN_42001c34)(*(undefined4 *)(param_2 + 0x58));
    }
    uStack_68 = FUN_42026d94(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uStack_68;
}


