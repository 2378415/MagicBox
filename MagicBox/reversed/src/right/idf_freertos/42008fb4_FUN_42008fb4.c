int FUN_42008fb4(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  int local_40 [4];
  undefined4 uStack_30;
  int iStack_2c;
  
  if (param_1 < 3) {
    if (param_2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(param_1 * 4 + DAT_42000844);
      if (iVar2 == 0) {
        iVar2 = -1;
      }
      else {
        local_40[0] = 0;
        uStack_30 = param_4;
        iStack_2c = param_2;
        iVar2 = (*(code *)PTR_FUN_42000350)(*(undefined4 *)(iVar2 + 0x68),param_4);
        if (iVar2 == 1) {
          iVar2 = 0;
          do {
            while( true ) {
              if (param_3 == 0) goto LAB_42009075;
              iVar1 = (*(code *)PTR_FUN_420008fc)
                                (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x60),
                                 local_40,uStack_30,param_3);
              if (iVar1 == 0) break;
              (*DAT_420002fc)(iStack_2c + iVar2,iVar1,local_40[0]);
              puVar4 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
              (*(code *)PTR_FUN_420003a8)(puVar4,0xffffffff);
              piVar3 = (int *)(param_1 * 4 + DAT_42000844);
              iVar5 = *piVar3;
              *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) - local_40[0];
              FUN_42007458(param_1);
              (*(code *)PTR_FUN_420003ac)(puVar4);
              iVar2 = iVar2 + local_40[0];
              param_3 = param_3 - local_40[0];
              (*(code *)PTR_FUN_42000900)(*(undefined4 *)(*piVar3 + 0x60),iVar1);
              FUN_42007888(param_1);
            }
            iVar1 = FUN_42007888(param_1);
          } while (iVar1 != 0);
LAB_42009075:
          (*(code *)PTR_FUN_42000358)
                    (*(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x68),0,0);
        }
        else {
          iVar2 = -1;
        }
      }
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}