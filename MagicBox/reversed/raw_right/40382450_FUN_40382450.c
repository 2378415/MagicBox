// 40382450  FUN_40382450  FUN_40382450  size=334
// strings: &H*&X

undefined4 FUN_40382450(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  uint uVar5;
  
  uVar5 = param_1[4];
  param_2 = param_2 & 1;
  uVar1 = uVar5 & 0xffff;
  if (uVar1 == 3) {
    if ((param_1[7] & 2) == 0) {
      uVar4 = **(undefined1 **)PTR_PTR_40375254;
    }
    else {
      uVar4 = **(undefined1 **)PTR_PTR_40375250;
    }
    if (param_2 == 0) {
      param_2 = 1;
      uVar2 = 0xbb;
      uVar3 = 0x18;
    }
    else {
      uVar2 = 0xbc;
      uVar3 = 0x20;
    }
  }
  else if (uVar1 < 4) {
    if (uVar1 == 1) {
      if ((param_1[7] & 2) == 0) {
        uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375254 + 4);
      }
      else {
        uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375250 + 4);
      }
      if (param_2 == 0) {
        uVar2 = 0xb;
        uVar3 = 0x18;
      }
      else {
        param_2 = 0;
        uVar2 = 0xc;
        uVar3 = 0x20;
      }
    }
    else if (uVar1 == 2) {
      if ((param_1[7] & 2) == 0) {
        uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375254 + 3);
      }
      else {
        uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375250 + 3);
      }
      if (param_2 == 0) {
        uVar2 = 0x3b;
        uVar3 = 0x18;
      }
      else {
        param_2 = 0;
        uVar2 = 0x3c;
        uVar3 = 0x20;
      }
    }
    else {
      if (uVar1 != 0) {
        return DAT_40374880;
      }
      if ((param_1[7] & 2) == 0) {
        uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375254 + 5);
      }
      else {
        uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375250 + 5);
      }
      if (param_2 == 0) {
        uVar2 = 3;
        uVar3 = 0x18;
      }
      else {
        param_2 = 0;
        uVar2 = 0x13;
        uVar3 = 0x20;
      }
    }
  }
  else if (uVar1 == 4) {
    if ((param_1[7] & 2) == 0) {
      uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375254 + 2);
    }
    else {
      uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375250 + 2);
    }
    if (param_2 == 0) {
      uVar2 = 0x6b;
      uVar3 = 0x18;
    }
    else {
      param_2 = 0;
      uVar2 = 0x6c;
      uVar3 = 0x20;
    }
  }
  else {
    if (uVar1 != 5) {
      return DAT_40374880;
    }
    if ((param_1[7] & 2) == 0) {
      uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375254 + 1);
    }
    else {
      uVar4 = *(undefined1 *)(*(int *)PTR_PTR_40375250 + 1);
    }
    if (param_2 == 0) {
      param_2 = 1;
      uVar2 = 0xeb;
      uVar3 = 0x18;
    }
    else {
      uVar2 = 0xec;
      uVar3 = 0x20;
    }
  }
  if (param_2 != 0) {
    uVar5 = uVar5 | DAT_4037450c;
  }
  uVar2 = (**(code **)(*(int *)*param_1 + 0x3c))((int *)*param_1,uVar2,uVar3,uVar4,uVar5);
  return uVar2;
}


