undefined4 FUN_40382948(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined1 auStack_30 [4];
  uint auStack_2c [11];
  
  pcVar3 = *(code **)(*(int *)(param_1 + 8) + 0x18);
  if (pcVar3 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (*pcVar3)(*(undefined4 *)(param_1 + 0xc),param_2 != 0,auStack_2c);
    if (iVar1 == 0) {
      uVar2 = 0;
      if ((auStack_2c[0] & 1) != 0) {
        uVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x1c))
                          (*(undefined4 *)(param_1 + 0xc),auStack_30);
      }
    }
    else {
      if (iVar1 != 0x107) {
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}