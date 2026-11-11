// 403808b0  FUN_403808b0  FUN_403808b0  size=42
// strings: CORRUPT HEAP: multi_heap.c:%d detected at 0x%08x

void FUN_403808b0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 8;
  uVar1 = FUN_40380e38(*(undefined4 *)(param_1 + 0x10));
  if ((uVar2 < uVar1) || (uVar1 + *(int *)(param_1 + 0xc) <= uVar2)) {
    (*DAT_40374438)(PTR_s_CORRUPT_HEAP__multi_heap_c__d_de_403751d0,0x74,uVar2);
                    /* WARNING: Subroutine does not return */
    FUN_40381c60();
  }
  return;
}


