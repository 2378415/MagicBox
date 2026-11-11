int FUN_42013da4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_30 [4];
  int *apiStack_2c [11];
  
  iVar1 = FUN_42024e5c();
  if (iVar1 == 0) {
    FUN_420154e8(auStack_30);
    uVar2 = FUN_4201523c();
    iVar1 = FUN_42015440(uVar2,param_1,param_2,param_3,apiStack_2c);
    if (iVar1 == 0) {
      puVar3 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x14);
      if (puVar3 == (undefined4 *)0x0) {
        if (apiStack_2c[0] != (int *)0x0) {
          (**(code **)(*apiStack_2c[0] + 4))();
        }
        iVar1 = 0x101;
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = apiStack_2c[0];
        iVar4 = *DAT_42001098;
        *DAT_42001098 = iVar4 + 1;
        puVar3[3] = iVar4 + 1;
        puVar3[4] = param_1;
        FUN_42024c0c(DAT_42001090,puVar3);
        *param_4 = puVar3[3];
      }
    }
    FUN_420154f8(auStack_30);
  }
  return iVar1;
}