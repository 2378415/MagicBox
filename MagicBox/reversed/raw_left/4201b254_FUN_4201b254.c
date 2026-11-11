// 4201b254  FUN_4201b254  FUN_4201b254  size=53

undefined4 FUN_4201b254(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_30 [48];
  
  FUN_4201cb08(auStack_30);
  iVar2 = *DAT_42001a38;
  do {
    if (iVar2 == 0) {
      uVar1 = DAT_42001a44;
LAB_4201b283:
      FUN_4201cb18(auStack_30);
      return uVar1;
    }
    if (param_1 == *(int *)(iVar2 + 0xc)) {
      uVar1 = (**(code **)(**(int **)(iVar2 + 8) + 0x28))();
      goto LAB_4201b283;
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}


