int FUN_4201ca54(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_30 [48];
  
  if (param_5 == (undefined4 *)0x0) {
    iVar3 = 0x102;
  }
  else {
    iVar3 = DAT_42001a70;
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar2 = FUN_4201c81c(param_1,param_2);
      if (iVar2 == 0) {
        iVar3 = DAT_42001a8c;
      }
      else {
        if ((param_4 == 1) && (iVar3 = (**(code **)(**(int **)(iVar2 + 8) + 0x28))(), iVar3 != 0)) {
          return 0x10d;
        }
        iVar3 = FUN_4201c208(iVar2,param_3,param_4 == 1,local_30);
        if (iVar3 == 0) {
          puVar4 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x14);
          puVar1 = PTR_PTR_42001a78;
          if (puVar4 == (undefined4 *)0x0) {
            iVar3 = 0x101;
          }
          else {
            *(ushort *)(puVar4 + 4) = CONCAT11(param_4 == 0,local_30[0]);
            iVar5 = *(int *)(param_1 + 8);
            *puVar4 = puVar1;
            puVar4[3] = iVar2;
            *(undefined1 *)((int)puVar4 + 0x12) = 1;
            if (iVar5 != 0) {
              *(undefined4 **)(iVar5 + 8) = puVar4;
            }
            puVar4[1] = iVar5;
            iVar2 = *(int *)(param_1 + 4);
            puVar4[2] = 0;
            *(undefined4 **)(param_1 + 8) = puVar4;
            if (iVar2 == 0) {
              *(undefined4 **)(param_1 + 4) = puVar4;
            }
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
            *param_5 = puVar4;
          }
        }
      }
    }
  }
  return iVar3;
}