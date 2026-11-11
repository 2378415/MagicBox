// 42012794  FUN_42012794  FUN_42012794  size=86
// strings: tx7@

undefined4 FUN_42012794(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) {
    uVar2 = 0x102;
  }
  else {
    iVar1 = (*(code *)PTR_FUN_42000ee0)(0,param_1,1,3);
    if (iVar1 == 0) {
      uVar2 = 0x102;
    }
    else {
      local_30 = 0;
      auStack_2c[0] = 0;
      iVar1 = (*(code *)PTR_FUN_42000ee4)(param_1,&local_30,auStack_2c);
      if (iVar1 == 0) {
        uVar2 = 0x105;
      }
      else {
        *param_2 = local_30;
        *param_3 = auStack_2c[0];
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


