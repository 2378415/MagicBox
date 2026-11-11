// strings: EFUSE_BURN

void efuse_burn(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_42002200(PTR_PTR_42000ed4);
  if (iVar1 == 0) {
    iVar2 = FUN_420022a4(PTR_PTR_42000ed4);
    iVar1 = iVar2;
    if (iVar2 == 0) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_EFUSE_BURN_42000ed8,PTR_DAT_42000edc,uVar3,PTR_s_EFUSE_BURN_42000ed8);
      iVar1 = FUN_42002ba8();
    }
    if (iVar1 == 0x106) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_EFUSE_BURN_42000ed8,PTR_DAT_42000ee0,uVar3,PTR_s_EFUSE_BURN_42000ed8);
    }
    else {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = FUN_42004180(iVar2);
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_EFUSE_BURN_42000ed8,PTR_DAT_42000ee4,uVar3,PTR_s_EFUSE_BURN_42000ed8,uVar4)
      ;
    }
  }
  return;
}