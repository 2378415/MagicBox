// 42013188  FUN_42013188  FUN_42013188  size=451
// strings: storage | config

void FUN_42013188(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int iStack_30;
  undefined4 auStack_2c [11];
  
  FUN_42012b38();
  iVar5 = DAT_420011cc;
  puVar1 = PTR_s_storage_42001174;
  iVar6 = 3;
  do {
    iVar2 = FUN_4201b0d0(puVar1);
    if ((iVar2 == iVar5) || (iVar2 == DAT_420011d0 || iVar2 == iVar5)) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(2,puVar1,PTR_DAT_420011d4,uVar3,puVar1);
      iVar2 = FUN_4201b0f8(puVar1);
      if (iVar2 == 0) {
        iVar2 = FUN_4201b0d0(puVar1);
        if (iVar2 == 0) goto LAB_42013251;
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar4 = FUN_42004180(iVar2);
        puVar7 = PTR_DAT_420011dc;
      }
      else {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar4 = FUN_42004180(iVar2);
        puVar7 = PTR_DAT_420011d8;
      }
    }
    else {
      if (iVar2 == 0) {
LAB_42013251:
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_420011e4,uVar3,puVar1);
        iVar5 = FUN_4201b14c(puVar1,PTR_s_config_42001194,1,auStack_2c);
        if (iVar5 != 0) {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          uVar4 = FUN_42004180(iVar5);
          (*(code *)PTR_FUN_42000118)
                    (1,puVar1,PTR_DAT_420011ec,uVar3,puVar1,PTR_s_config_42001194,uVar4);
          return;
        }
        FUN_4201b16c(auStack_2c[0]);
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_420011f0,uVar3,puVar1);
        iStack_30 = iVar5;
        iVar5 = FUN_420130a4(&iStack_30);
        if (iVar5 == 0) {
          iVar5 = DAT_420009b0;
        }
        else {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          iVar5 = DAT_420009b0;
          (*(code *)PTR_FUN_42000118)(2,puVar1,PTR_DAT_420011f4,uVar3,puVar1,DAT_420009b0);
          iStack_30 = iVar5;
        }
        puVar7 = PTR_DAT_420011f8;
        *(int *)PTR_DAT_420011f8 = iStack_30;
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_420011fc,uVar3,puVar1,iStack_30);
        *PTR_DAT_4200118c = *(int *)puVar7 == iVar5;
        return;
      }
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = FUN_42004180(iVar2);
      puVar7 = PTR_DAT_420011e0;
    }
    (*(code *)PTR_FUN_42000118)(1,puVar1,puVar7,uVar3,puVar1,uVar4);
    (*(code *)PTR_FUN_42000098)(100);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(1,puVar1,PTR_DAT_420011e8,uVar3,puVar1,3);
      return;
    }
  } while( true );
}


