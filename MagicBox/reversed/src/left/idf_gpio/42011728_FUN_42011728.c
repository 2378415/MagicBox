// strings: PARSE

undefined4 FUN_42011728(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  
  if (param_3 == 1) {
    if (0xe < *(byte *)(param_1 + 300)) {
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (1,PTR_s_PARSE_42000efc,PTR_DAT_42000f6c,uVar2,PTR_s_PARSE_42000efc);
      return 0;
    }
    puVar4 = (undefined4 *)((uint)*(byte *)(param_1 + 300) * 0x14 + param_1);
    *puVar4 = *param_2;
    puVar4[2] = param_4;
    puVar4[3] = param_4;
    puVar4[1] = param_4;
    *(undefined1 *)((int)puVar4 + 0x11) = 1;
    *(undefined1 *)(puVar4 + 4) = *(undefined1 *)((int)param_2 + 9);
    *(undefined1 *)((int)puVar4 + 0x12) = 0;
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,PTR_DAT_42000f68,uVar2,PTR_s_PARSE_42000efc,param_4,
               *(undefined1 *)(param_1 + 300),*puVar4);
  }
  else {
    if (param_3 == 2) {
      bVar1 = *(byte *)(param_1 + 300);
      uVar7 = (uint)bVar1;
      if (0xe < uVar7) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_PARSE_42000efc,PTR_DAT_42000f74,uVar2,PTR_s_PARSE_42000efc);
        return 0;
      }
      puVar4 = (undefined4 *)(uVar7 * 0x14 + param_1);
      iVar6 = puVar4[2];
      if ((iVar6 == 0) && (*(char *)((int)puVar4 + 0x11) == '\0')) {
        *puVar4 = *param_2;
        puVar4[2] = param_4;
        iVar6 = param_4;
      }
      puVar4[3] = param_4;
      iVar3 = uVar7 * 0x14 + param_1;
      *(char *)(iVar3 + 0x11) = ((char)param_4 + '\x01') - (char)iVar6;
      puVar4[1] = iVar6;
      *(byte *)(param_1 + 300) = bVar1 + 1;
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      uVar9 = *puVar4;
      uVar5 = *(byte *)(param_1 + 300) - 1;
      uVar7 = (uint)*(byte *)(iVar3 + 0x11);
      puVar8 = PTR_DAT_42000f70;
    }
    else {
      if (param_3 != 0) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (2,PTR_s_PARSE_42000efc,PTR_DAT_42000f80,uVar2,PTR_s_PARSE_42000efc,param_3,
                   param_4);
        goto LAB_420118b7;
      }
      bVar1 = *(byte *)(param_1 + 300);
      if (0xe < bVar1) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_PARSE_42000efc,PTR_DAT_42000f7c,uVar2,PTR_s_PARSE_42000efc);
        return 0;
      }
      puVar4 = (undefined4 *)((uint)bVar1 * 0x14 + param_1);
      *puVar4 = *param_2;
      puVar4[1] = param_4;
      puVar4[2] = param_4;
      puVar4[3] = param_4;
      *(undefined1 *)((int)puVar4 + 0x11) = 1;
      *(undefined1 *)(puVar4 + 4) = *(undefined1 *)((int)param_2 + 9);
      *(undefined1 *)((int)puVar4 + 0x12) = 0;
      *(byte *)(param_1 + 300) = bVar1 + 1;
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      uVar5 = (uint)*(byte *)(param_1 + 300);
      uVar9 = *puVar4;
      uVar7 = uVar5 - 1;
      puVar8 = PTR_DAT_42000f78;
    }
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_PARSE_42000efc,puVar8,uVar2,PTR_s_PARSE_42000efc,param_4,uVar7,uVar5,uVar9);
  }
LAB_420118b7:
  if (*(byte *)(param_1 + 300) != 0) {
    param_2[1] = *(undefined4 *)((*(byte *)(param_1 + 300) - 1) * 0x14 + param_1 + 4);
  }
  return 1;
}