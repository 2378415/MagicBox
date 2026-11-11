// 420020fc  efuse_init  FUN_420020fc  size=148
// strings: Db7@,b7@(' | efuse_init | (constraint ignored) | ,b7@('

undefined4 FUN_420020fc(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  
  puVar1 = PTR_DAT_42000028;
  if (2 < *(uint *)PTR_DAT_42000028) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42000074,uVar2,PTR_s_efuse_init_42000070,0);
    if (2 < *(uint *)puVar1) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      iVar3 = (*DAT_42000084)();
      puVar5 = PTR_s__constraint_ignored__42000068;
      if (iVar3 == 0) {
        puVar5 = PTR_DAT_4200006c;
      }
      (*DAT_42000060)(PTR_DAT_42000078,uVar2,PTR_s_efuse_init_42000070,0,99,puVar5);
    }
  }
  uVar4 = (*DAT_42000088)();
  if (2 < *(uint *)puVar1) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    uVar6 = (uint)((ulonglong)uVar4 * (ulonglong)DAT_4200007c >> 0x25);
    (*DAT_42000060)(PTR_DAT_42000080,uVar2,PTR_s_efuse_init_42000070,uVar6,uVar4 + uVar6 * -100);
  }
  return 0;
}


