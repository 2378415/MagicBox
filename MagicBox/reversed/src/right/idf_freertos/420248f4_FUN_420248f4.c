/* (5 unreachable decompiler blocks omitted) */

undefined1 FUN_420248f4(int param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0 && param_2 != (ushort *)0x0) && (1 < *param_2)) {
    iVar1 = 0;
    while( true ) {
      iVar2 = iVar1 + 1;
      if ((int)(uint)*param_2 <= iVar2) break;
      if ((1 < *(byte *)(param_1 + iVar1)) &&
         (iVar1 = (uint)*(byte *)(param_1 + iVar1) + iVar1, iVar1 <= (int)(uint)*param_2)) {
        iVar2 = iVar1;
      }
      iVar1 = iVar2;
    }
  }
  return 0;
}