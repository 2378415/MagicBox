// 420027d8  FUN_420027d8  FUN_420027d8  size=151
// strings: efuse

undefined4 FUN_420027d8(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined *puVar5;
  
  puVar4 = *(uint **)(PTR_DAT_420000d4 + param_1 * 8);
  puVar3 = *(uint **)(PTR_DAT_420000cc + param_1 * 8);
  iVar1 = (*DAT_42000114)(puVar4,puVar3,param_2);
  if (iVar1 == 0) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    puVar5 = PTR_DAT_42000108;
  }
  else {
    if ((param_2 >> 2 != 0) && ((~*puVar3 & *puVar4) != 0)) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_efuse_420000e8,PTR_DAT_42000110,uVar2,PTR_s_efuse_420000e8,param_1);
      return 0;
    }
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    puVar5 = PTR_DAT_4200010c;
  }
  (*(code *)PTR_FUN_42000118)(3,PTR_s_efuse_420000e8,puVar5,uVar2,PTR_s_efuse_420000e8,param_1);
  return 1;
}


