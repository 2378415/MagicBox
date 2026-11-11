// strings: storage | config | baud_rate

int config_load(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 auStack_30 [12];
  
  puVar1 = PTR_s_storage_42001174;
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_storage_42001174,PTR_DAT_420011b4,uVar2,PTR_s_storage_42001174);
    iVar3 = 0x102;
  }
  else {
    iVar3 = FUN_4201b14c(PTR_s_storage_42001174,PTR_s_config_42001194,0,auStack_30);
    if (iVar3 == 0) {
      iVar3 = FUN_4201b28c(auStack_30[0],PTR_s_baud_rate_4200119c,param_1);
      if (iVar3 == DAT_420011bc) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (2,puVar1,PTR_DAT_420011c0,uVar2,puVar1,PTR_s_baud_rate_4200119c,
                   PTR_s_config_42001194);
      }
      else if (iVar3 == 0) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_420011c8,uVar2,puVar1,*param_1);
      }
      else {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        uVar4 = FUN_42004180(iVar3);
        (*(code *)PTR_FUN_42000118)(1,puVar1,PTR_DAT_420011c4,uVar2,puVar1,uVar4);
      }
      FUN_4201b16c(auStack_30[0]);
    }
    else {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      uVar4 = FUN_42004180(iVar3);
      (*(code *)PTR_FUN_42000118)
                (2,puVar1,PTR_DAT_420011b8,uVar2,puVar1,PTR_s_config_42001194,uVar4);
    }
  }
  return iVar3;
}