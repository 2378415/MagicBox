// 42010898  FUN_42010898  FUN_42010898  size=76

undefined4 FUN_42010898(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_1 < 3) {
    piVar2 = (int *)*DAT_42000dac;
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x103;
    }
    else if ((param_1 == 2) && (piVar2[2] != 0)) {
      *param_2 = *(undefined4 *)(piVar2[2] + 8);
      uVar1 = 0;
    }
    else if ((param_1 == 0) && (*piVar2 != 0)) {
      *param_2 = *(undefined4 *)(*piVar2 + 8);
      uVar1 = 0;
    }
    else if ((param_1 == 1) && (piVar2[1] != 0)) {
      *param_2 = *(undefined4 *)(piVar2[1] + 8);
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      *param_2 = 0;
    }
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}


