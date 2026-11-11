// 4037c400  FUN_4037c400  FUN_4037c400  size=40

undefined4 FUN_4037c400(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)*DAT_40374dc0;
  memw();
  uVar2 = (uint)(*piVar3 == 0);
  *param_1 = uVar2;
  if (uVar2 == 0) {
    memw();
    memw();
    uVar1 = *(undefined4 *)piVar3[3];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


