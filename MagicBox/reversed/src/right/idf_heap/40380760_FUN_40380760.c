// strings: CORRUPT HEAP: multi_heap.c:%d detected at 0x%08x

void FUN_40380760(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_40380d68(*(undefined4 *)(param_1 + 0x10));
  uVar2 = param_2 + 8;
  if ((uVar2 < uVar1) || (uVar1 + *(int *)(param_1 + 0xc) <= uVar2)) {
    (*DAT_403745cc)(PTR_s_CORRUPT_HEAP__multi_heap_c__d_de_40375118,0x74,uVar2);
                    /* WARNING: Subroutine does not return */
    FUN_40381ce0();
  }
  return;
}