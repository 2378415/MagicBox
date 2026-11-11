// strings: 8j7@

int FUN_42005864(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  int *piVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  
  puVar1 = PTR_DAT_420006c4;
  (*(code *)PTR_FUN_420004dc)(PTR_DAT_420006c4,0xffffffff);
  if (*DAT_420006c8 == 0) {
    memw();
    *DAT_420006cc = 0;
    puVar3 = PTR_FUN_420006d4;
    piVar2 = DAT_420006c8;
    memw();
    *DAT_420006d0 = 0xffffffff;
    iVar5 = FUN_42005720(0x27,0x400,puVar3,0,piVar2);
    if (iVar5 != 0) {
      (*(code *)PTR_FUN_420004e0)(puVar1);
      return iVar5;
    }
    uVar6 = FUN_4202cf74(*DAT_420006c8);
    *(undefined4 *)PTR_DAT_420006d8 = uVar6;
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  else {
    (*(code *)PTR_FUN_420004e0)(puVar1);
  }
  puVar7 = (uint *)(*(code *)PTR_FUN_42000660)(0x14,DAT_420006dc);
  if (puVar7 == (uint *)0x0) {
    iVar5 = 0x101;
  }
  else {
    *puVar7 = param_3;
    puVar7[3] = param_4;
    puVar7[1] = param_1;
    puVar7[2] = param_2;
    (*(code *)PTR_FUN_420004dc)(puVar1,0xffffffff);
    puVar4 = PTR_DAT_420006e4;
    puVar3 = PTR_DAT_420006e0;
    uVar9 = *(uint *)PTR_DAT_420006e0;
    uVar8 = param_3 & uVar9 ^ uVar9;
    if ((param_4 & 1) != 0) {
      uVar8 = uVar9 | param_3;
    }
    puVar7[4] = *(uint *)PTR_DAT_420006e4;
    *(uint **)puVar4 = puVar7;
    *(uint *)puVar3 = uVar8;
    (*(code *)PTR_FUN_420004e0)(puVar1);
    iVar5 = 0;
  }
  return iVar5;
}