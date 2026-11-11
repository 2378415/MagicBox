// 42011204  FUN_42011204  FUN_42011204  size=177
// strings: EFUSE_BURN

void FUN_42011204(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined1 local_30;
  char acStack_2f [47];
  
  acStack_2f[0] = '\0';
  iVar1 = FUN_420021cc(PTR_PTR_42000ee8,acStack_2f,2);
  if (iVar1 == 0) {
    if (acStack_2f[0] == '\x03') {
      return;
    }
    local_30 = 3;
    iVar4 = FUN_42002238(PTR_PTR_42000ee8,&local_30,2);
    iVar1 = iVar4;
    if (iVar4 == 0) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_EFUSE_BURN_42000ed8,PTR_DAT_42000ef0,uVar2,PTR_s_EFUSE_BURN_42000ed8);
      iVar1 = FUN_42002ba8();
    }
    if (iVar1 == 0x106) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (3,PTR_s_EFUSE_BURN_42000ed8,PTR_DAT_42000ef4,uVar2,PTR_s_EFUSE_BURN_42000ed8);
      return;
    }
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = FUN_42004180(iVar4);
    puVar5 = PTR_DAT_42000ef8;
  }
  else {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    uVar3 = FUN_42004180(iVar1);
    puVar5 = PTR_DAT_42000eec;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_s_EFUSE_BURN_42000ed8,puVar5,uVar2,PTR_s_EFUSE_BURN_42000ed8,uVar3);
  return;
}


