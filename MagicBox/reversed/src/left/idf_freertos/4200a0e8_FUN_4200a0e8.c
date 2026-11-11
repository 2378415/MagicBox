uint FUN_4200a0e8(uint param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  
  piVar2 = (int *)(param_1 * 4 + DAT_42000a40);
  iStack_28 = param_1 << 2;
  uStack_30 = param_1;
  uStack_2c = param_5;
  (*(code *)PTR_FUN_42000480)(*(undefined4 *)(*piVar2 + 0x6c),0xffffffff);
  iVar7 = *piVar2;
  *(undefined1 *)(iVar7 + 0x10) = 0;
  if (*(int *)(iVar7 + 0x3c) < 1) {
    if (param_3 != 0) {
      uVar6 = param_3;
      while( true ) {
        while( true ) {
          do {
            iVar7 = (*(code *)PTR_FUN_42000480)(*(undefined4 *)(*piVar2 + 0x70),0xffffffff);
          } while (iVar7 != 1);
          iStack_24 = iVar7;
          uVar3 = FUN_42008f48(uStack_30,param_2,uVar6);
          if (uVar6 <= uVar3) break;
          *(char *)(*piVar2 + 0x40) = (char)iStack_24;
          FUN_4200a054(uStack_30,iStack_24,10);
          uVar6 = uVar6 - uVar3;
          param_2 = param_2 + uVar3;
        }
        uVar6 = uVar6 - uVar3;
        if (uVar6 == 0) break;
        param_2 = param_2 + uVar3;
      }
    }
    uVar6 = uStack_30;
    puVar1 = PTR_DAT_42000a3c;
    if (param_4 != 0) {
      iVar7 = (uStack_30 & 0xffff) * 0x18;
      puVar4 = PTR_DAT_42000a3c + iVar7 + 0xc;
      memw();
      *(uint *)(*(int *)(PTR_DAT_42000a3c + uStack_30 * 0x18 + 8) + 0x10) = DAT_42000988;
      (*(code *)PTR_FUN_420004dc)(puVar4,0xffffffff);
      FUN_4202ce68(puVar1 + iVar7 + 8,uStack_2c);
      iVar7 = *(int *)(puVar1 + uVar6 * 0x18 + 8);
      memw();
      memw();
      *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | DAT_42000988;
      (*(code *)PTR_FUN_420004e0)(puVar4);
      (*(code *)PTR_FUN_42000480)
                (*(undefined4 *)(*(int *)(DAT_42000a40 + iStack_28) + 0x78),0xffffffff);
    }
    (*(code *)PTR_FUN_42000488)(*(undefined4 *)(*(int *)(DAT_42000a40 + iStack_28) + 0x70),0,0);
  }
  else {
    uVar6 = (*(code *)PTR_FUN_42000b04)(*(undefined4 *)(iVar7 + 100));
    local_40 = 6;
    if (param_4 == 0) {
      local_40 = 0;
    }
    uStack_3c = uStack_2c;
    uStack_38 = param_3;
    (*(code *)PTR_FUN_42000a5c)(*(undefined4 *)(*piVar2 + 100),&local_40,0xc,0xffffffff);
    iVar7 = 0;
    uStack_2c = uVar6 >> 1;
    for (uVar6 = param_3; uVar6 != 0; uVar6 = uVar6 - iVar5) {
      iVar5 = (uStack_2c < uVar6) * uStack_2c + (uStack_2c >= uVar6) * uVar6;
      (*(code *)PTR_FUN_42000a5c)(*(undefined4 *)(*piVar2 + 100),param_2 + iVar7,iVar5,0xffffffff);
      iVar7 = iVar5 + iVar7;
      FUN_4200a054(uStack_30,1,10);
    }
  }
  (*(code *)PTR_FUN_42000488)(*(undefined4 *)(*(int *)(DAT_42000a40 + iStack_28) + 0x6c),0,0);
  return param_3;
}