// 420112c4  FUN_420112c4  FUN_420112c4  size=618
// strings: PARSE

void FUN_420112c4(char *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  puVar1 = PTR_s_PARSE_42000efc;
  (*(code *)PTR_FUN_42000118)(3,PTR_s_PARSE_42000efc,PTR_DAT_42000f00,uVar3,PTR_s_PARSE_42000efc);
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f04,uVar3,puVar1,param_1[3],param_1[4]);
  if ((*param_1 != '\0') && (iVar5 = *(int *)(param_1 + 0x210), iVar5 != 0)) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f08,uVar3,puVar1);
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f0c,uVar3,puVar1,
               *(undefined1 *)(*(int *)(param_1 + 0x210) + 0x1d5));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f10,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x1d6));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f14,uVar3,puVar1);
    puVar2 = PTR_DAT_42000f18;
    pcVar6 = (char *)(iVar5 + 0x44);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      if (*pcVar6 != '\0') {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(3,puVar1,puVar2,uVar3,puVar1,iVar4,*pcVar6);
      }
      pcVar6 = pcVar6 + 1;
    } while (iVar4 != 0x10);
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f1c,uVar3,puVar1);
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f20,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x1b4));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f24,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x1bc));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f28,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x1c4));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f2c,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x1cc));
  }
  if ((param_1[1] != '\0') && (iVar5 = *(int *)(param_1 + 0x214), iVar5 != 0)) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f30,uVar3,puVar1);
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f0c,uVar3,puVar1,
               *(undefined1 *)(*(int *)(param_1 + 0x214) + 0x62));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f10,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x61));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f34,uVar3,puVar1,*(undefined1 *)(iVar5 + 4));
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f38,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x58));
    puVar2 = PTR_DAT_42000f18;
    iVar4 = 0;
    if (*(char *)(iVar5 + 0x58) != '\0') {
      do {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        iVar4 = iVar4 + 1;
        (*(code *)PTR_FUN_42000118)
                  (3,puVar1,puVar2,uVar3,puVar1,iVar4,*(undefined1 *)(iVar5 + iVar4 + 0x47));
      } while (iVar4 < (int)(uint)*(byte *)(iVar5 + 0x58));
    }
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,puVar1,PTR_DAT_42000f3c,uVar3,puVar1,*(undefined1 *)(iVar5 + 0x60));
  }
  uVar3 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42000f40,uVar3,puVar1);
  return;
}


