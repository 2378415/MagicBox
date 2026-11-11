// strings: 498@088@

undefined4 FUN_40383994(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 local_30 [48];
  
  local_30[0] = 0;
  iVar2 = -1;
  piVar1 = (int *)PTR_PTR_403752dc;
  do {
    if ((undefined4 *)*piVar1 == (undefined4 *)0x0) {
LAB_403839d2:
      *DAT_403752e4 = piVar1;
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_40381ce0();
      }
      return 0;
    }
    iVar2 = (**(code **)*piVar1)(param_1,local_30);
    if (iVar2 == 0) {
      *DAT_403752e0 = param_1;
      (**(code **)(*piVar1 + 4))(6);
      FUN_403837c0();
      goto LAB_403839d2;
    }
    piVar1 = piVar1 + 1;
  } while( true );
}