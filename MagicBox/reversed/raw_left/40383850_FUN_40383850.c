// 40383850  FUN_40383850  FUN_40383850  size=103
// strings: Octal Flash

undefined4 FUN_40383850(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined1 local_30 [48];
  
  puVar4 = *(undefined4 **)PTR_PTR_403753d0;
  local_30[0] = 0;
  piVar3 = (int *)PTR_PTR_403753d0;
  while( true ) {
    if (puVar4 == (undefined4 *)0x0) {
      iVar1 = *(int *)PTR_DAT_40374414;
      *DAT_403753e0 = (int)piVar3;
      if (iVar1 != 0) {
        uVar2 = FUN_40381bb0();
        (*DAT_40374438)(PTR_DAT_403753e4,uVar2,PTR_s_Octal_Flash_403753a4);
      }
                    /* WARNING: Subroutine does not return */
      FUN_40381c60();
    }
    iVar1 = (*(code *)*puVar4)(param_1,local_30);
    if (iVar1 == 0) break;
    puVar4 = (undefined4 *)piVar3[1];
    piVar3 = piVar3 + 1;
  }
  pcVar5 = *(code **)(*piVar3 + 4);
  *DAT_403753d4 = param_1;
  (*pcVar5)(6);
  *DAT_403753d8 = PTR_DAT_403753dc;
  *DAT_403753e0 = (int)piVar3;
  return 0;
}


