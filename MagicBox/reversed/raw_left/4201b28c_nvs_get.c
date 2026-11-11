// 4201b28c  nvs_get  FUN_4201b28c  size=94
// strings: nvs_get

undefined4 FUN_4201b28c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_30 [48];
  
  FUN_4201cb08(auStack_30);
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (4,PTR_DAT_42001a2c,PTR_DAT_42001a54,uVar1,PTR_DAT_42001a2c,PTR_s_nvs_get_42001a50,
             param_2,4);
  iVar2 = *DAT_42001a38;
  do {
    if (iVar2 == 0) {
      uVar1 = DAT_42001a44;
LAB_4201b2e2:
      FUN_4201cb18(auStack_30);
      return uVar1;
    }
    if (param_1 == *(int *)(iVar2 + 0xc)) {
      uVar1 = (**(code **)(**(int **)(iVar2 + 8) + 0x34))
                        (*(int **)(iVar2 + 8),0x14,param_2,param_3,4);
      goto LAB_4201b2e2;
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}


