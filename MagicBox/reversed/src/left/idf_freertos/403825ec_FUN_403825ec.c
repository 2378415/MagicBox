undefined4 FUN_403825ec(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_30 [4];
  uint auStack_2c [11];
  
  pcVar1 = *(code **)(*(int *)(param_1 + 8) + 0x18);
  uVar3 = 0;
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(*(undefined4 *)(param_1 + 0xc),param_2 != 0,auStack_2c);
    if (iVar2 == 0) {
      uVar3 = 0;
      if ((auStack_2c[0] & 1) != 0) {
        uVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x1c))
                          (*(undefined4 *)(param_1 + 0xc),auStack_30);
      }
    }
    else {
      if (iVar2 != 0x107) {
                    /* WARNING: Subroutine does not return */
        FUN_40381c60();
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}