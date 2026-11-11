// 42019854  FUN_42019854  FUN_42019854  size=134
// strings: 8d7@H

int FUN_42019854(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_40 [4];
  undefined4 uStack_30;
  undefined4 *puStack_2c;
  
  local_40[0] = 0;
  uStack_30 = param_1;
  piVar1 = (int *)(*(code *)PTR_FUN_42000bd4)(1,8,DAT_420006dc);
  if (piVar1 == (int *)0x0) {
    return 0x101;
  }
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_42000bd4)(1,4,DAT_420006dc);
  iVar3 = 0x101;
  if (puVar2 == (undefined4 *)0x0) {
LAB_420198d0:
    (*(code *)PTR_FUN_42000570)(piVar1);
  }
  else {
    *piVar1 = (int)puVar2;
    uVar4 = 9;
    if (param_3 != 1) {
      uVar4 = 0x12;
    }
    puStack_2c = puVar2;
    iVar3 = FUN_4201924c(uStack_30,param_2,1,uVar4,1,local_40);
    if (iVar3 == 0) {
      *puStack_2c = local_40[0];
      piVar1[1] = 1;
    }
    else {
      if (iVar3 != 0x103) {
        (*(code *)PTR_FUN_42000570)(puStack_2c);
        goto LAB_420198d0;
      }
      piVar1[1] = 0;
    }
    *param_4 = local_40[0];
    *param_5 = (int)piVar1;
    iVar3 = 0;
  }
  return iVar3;
}


