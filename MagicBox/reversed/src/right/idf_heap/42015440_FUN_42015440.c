int FUN_42015440(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_30 [48];
  
  if (param_5 == (undefined4 *)0x0) {
    iVar2 = 0x102;
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = DAT_420010a0;
  }
  else {
    iVar1 = FUN_42015278(param_1,param_2);
    if (iVar1 == 0) {
      iVar2 = DAT_420010d4;
    }
    else if ((param_4 == 1) && (iVar2 = (**(code **)(**(int **)(iVar1 + 8) + 0x28))(), iVar2 != 0))
    {
      iVar2 = 0x10d;
    }
    else {
      iVar2 = FUN_42014d9c(iVar1,param_3,param_4 == 1,local_30);
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x14);
        if (puVar3 == (undefined4 *)0x0) {
          iVar2 = 0x101;
        }
        else {
          puVar3[1] = 0;
          puVar3[2] = 0;
          *puVar3 = PTR_DAT_420010bc;
          *puVar3 = PTR_PTR_420010b8;
          puVar3[3] = iVar1;
          *(undefined1 *)(puVar3 + 4) = local_30[0];
          *(bool *)((int)puVar3 + 0x11) = param_4 == 0;
          *(undefined1 *)((int)puVar3 + 0x12) = 1;
          FUN_42024e38(param_1 + 4,puVar3);
          *param_5 = puVar3;
        }
      }
    }
  }
  return iVar2;
}