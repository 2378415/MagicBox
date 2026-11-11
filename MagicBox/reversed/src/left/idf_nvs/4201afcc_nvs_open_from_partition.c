// strings: nvs_open_from_partition

int FUN_4201afcc(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piStack_30;
  undefined1 auStack_2c [44];
  
  FUN_4201cb08(auStack_2c);
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (4,PTR_DAT_42001a2c,PTR_DAT_42001a30,uVar3,PTR_DAT_42001a2c,
             PTR_s_nvs_open_from_partition_42001a28,param_2,param_3);
  uVar3 = FUN_4201c7b0();
  iVar4 = FUN_4201ca54(uVar3,param_1,param_2,param_3,&piStack_30);
  if (iVar4 == 0) {
    piVar5 = (int *)(*(code *)PTR_FUN_4200056c)(0x14);
    piVar2 = DAT_42001a38;
    piVar1 = DAT_42001a34;
    if (piVar5 == (int *)0x0) {
      if (piStack_30 != (int *)0x0) {
        (**(code **)(*piStack_30 + 4))(piStack_30);
      }
      iVar4 = 0x101;
    }
    else {
      iVar7 = DAT_42001a38[1];
      iVar6 = *DAT_42001a34 + 1;
      piVar5[2] = (int)piStack_30;
      *piVar1 = iVar6;
      piVar5[3] = iVar6;
      piVar5[4] = param_1;
      if (iVar7 != 0) {
        *(int **)(iVar7 + 4) = piVar5;
      }
      *piVar5 = iVar7;
      iVar7 = *piVar2;
      piVar5[1] = 0;
      piVar2[1] = (int)piVar5;
      if (iVar7 == 0) {
        *piVar2 = (int)piVar5;
      }
      piVar2[2] = piVar2[2] + 1;
      *param_4 = iVar6;
    }
  }
  FUN_4201cb18(auStack_2c);
  return iVar4;
}