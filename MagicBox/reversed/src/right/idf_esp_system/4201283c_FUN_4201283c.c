// strings: 8a7@

int FUN_4201283c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_40 [4];
  int *piStack_30;
  
  local_40[0] = 0;
  piStack_30 = param_5;
  piVar1 = (int *)(*(code *)PTR_FUN_420008b8)(1,8,DAT_420004fc);
  if (piVar1 == (int *)0x0) {
    iVar3 = 0x101;
  }
  else {
    puVar2 = (undefined4 *)(*(code *)PTR_FUN_420008b8)(1,4,DAT_420004fc);
    if (puVar2 != (undefined4 *)0x0) {
      *piVar1 = (int)puVar2;
      if (param_3 == 1) {
        uVar4 = 9;
      }
      else {
        uVar4 = 0x12;
      }
      iVar3 = FUN_42012444(param_1,param_2,1,uVar4,1,local_40);
      if (iVar3 == 0) {
        *puVar2 = local_40[0];
        piVar1[1] = 1;
      }
      else {
        if (iVar3 != 0x103) {
          (*(code *)PTR_FUN_420004c0)(puVar2);
          goto LAB_420128c3;
        }
        piVar1[1] = 0;
      }
      *param_4 = local_40[0];
      *piStack_30 = (int)piVar1;
      return 0;
    }
    iVar3 = 0x101;
  }
LAB_420128c3:
  if (piVar1 != (int *)0x0) {
    (*(code *)PTR_FUN_420004c0)(piVar1);
  }
  return iVar3;
}