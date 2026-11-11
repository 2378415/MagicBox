// 4201b16c  nvs_close  FUN_4201b16c  size=126
// strings: nvs_close | D (%lu) %s: %s %d

void FUN_4201b16c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStack_30 [48];
  
  FUN_4201cb08(auStack_30);
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (4,PTR_DAT_42001a2c,PTR_DAT_42001a40,uVar2,PTR_DAT_42001a2c,PTR_s_nvs_close_42001a3c,
             param_1);
  piVar1 = DAT_42001a38;
  piVar3 = (int *)*DAT_42001a38;
  do {
    if (piVar3 == (int *)0x0) {
LAB_4201b1d7:
      FUN_4201cb18(auStack_30);
      return;
    }
    if (param_1 == piVar3[3]) {
      iVar4 = *piVar3;
      piVar5 = (int *)piVar3[1];
      if (iVar4 == 0) {
        *DAT_42001a38 = (int)piVar5;
      }
      else {
        *(int **)(iVar4 + 4) = piVar5;
      }
      if (piVar5 == (int *)0x0) {
        piVar1[1] = iVar4;
      }
      else {
        *piVar5 = iVar4;
      }
      piVar5 = (int *)piVar3[2];
      piVar1[2] = piVar1[2] + -1;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))();
      }
      (*(code *)PTR_FUN_42000570)(piVar3);
      goto LAB_4201b1d7;
    }
    piVar3 = (int *)piVar3[1];
  } while( true );
}


