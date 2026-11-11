void frame_ep0_dir(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  *(undefined2 *)(param_1 + 2) = 1;
  iVar1 = FUN_42010364();
  if (iVar1 == 0) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = 0;
  }
  *(undefined1 *)(param_1 + 4) = uVar2;
  return;
}