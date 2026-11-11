/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_42018690(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_t0;
  
  puVar1 = (undefined4 *)FUN_420207dc(param_1);
  (*DAT_420001e4)(*puVar1);
  if (((*(ushort *)(param_2 + 3) & 0x80) != 0) && (param_2[4] == 0)) {
    iVar2 = (*(code *)PTR_FUN_4200119c)(param_1,0x40);
    *param_2 = iVar2;
    param_2[4] = iVar2;
    if (iVar2 == 0) {
      *param_1 = 0xc;
      return 0xffffffff;
    }
    *(undefined4 *)(in_t0 + 0x14) = 0x40;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}