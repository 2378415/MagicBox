// 420070ec  FUN_420070ec  FUN_420070ec  size=64
// strings: d < 3

void FUN_420070ec(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
    iVar2 = (*DAT_420007e8)(param_1,*(undefined4 *)(PTR_PTR_420007ec + iVar1 * 4));
    if (iVar2 == 0) goto LAB_42007111;
  }
  iVar1 = -1;
LAB_42007111:
  if (iVar1 == -1) {
    puVar3 = (undefined4 *)FUN_420180e4();
    *puVar3 = 2;
  }
  else {
    *(byte *)(*(int *)(PTR_PTR_42000770 + iVar1 * 4) + 0x10) = (byte)(param_2 >> 0xe) & 1;
  }
  return;
}


