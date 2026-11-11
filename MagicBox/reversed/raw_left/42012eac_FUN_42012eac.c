// 42012eac  FUN_42012eac  FUN_42012eac  size=495
// strings: storage | true (115200) | false (4 Mbps) | config | baud_rate

int FUN_42012eac(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined *puVar7;
  int iStack_30;
  undefined4 uStack_2c;
  int aiStack_28 [10];
  
  if (param_1 == 0) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_storage_42001174,PTR_DAT_42001178,uVar3,PTR_s_storage_42001174);
    iVar4 = 0x102;
  }
  else {
    aiStack_28[0] = 0;
    (*DAT_42000064)(aiStack_28,param_1,4);
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    puVar1 = PTR_s_storage_42001174;
    (*(code *)PTR_FUN_42000118)
              (3,PTR_s_storage_42001174,PTR_DAT_4200117c,uVar3,PTR_s_storage_42001174,aiStack_28[0])
    ;
    iVar4 = DAT_420009dc;
    if (DAT_42001180 < aiStack_28[0]) {
      if (DAT_420009dc < aiStack_28[0]) {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)(2,puVar1,PTR_DAT_42001188,uVar3,puVar1,aiStack_28[0]);
        bVar6 = false;
        aiStack_28[0] = iVar4;
      }
      else {
        bVar6 = aiStack_28[0] == DAT_420009b0;
      }
    }
    else {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)(2,puVar1,PTR_DAT_42001184,uVar3,puVar1,aiStack_28[0]);
      bVar6 = true;
      aiStack_28[0] = DAT_420009b0;
    }
    puVar2 = PTR_DAT_4200118c;
    *PTR_DAT_4200118c = bVar6;
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    puVar7 = PTR_s_true__115200__4200116c;
    if (*puVar2 == '\0') {
      puVar7 = PTR_s_false__4_Mbps__42001170;
    }
    (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_42001190,uVar3,puVar1,puVar7);
    iVar4 = FUN_4201b14c(puVar1,PTR_s_config_42001194,1,&uStack_2c);
    if (iVar4 == 0) {
      iVar4 = FUN_4201b1ec(uStack_2c,PTR_s_baud_rate_4200119c,aiStack_28[0]);
      if (iVar4 == 0) {
        iVar4 = FUN_4201b254(uStack_2c);
        if (iVar4 == 0) {
          iStack_30 = iVar4;
          iVar4 = FUN_4201b28c(uStack_2c,PTR_s_baud_rate_4200119c,&iStack_30);
          if ((iVar4 == 0) && (iStack_30 == aiStack_28[0])) {
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_420011a0,uVar3,puVar1,aiStack_28[0]);
            FUN_4201423c(aiStack_28[0]);
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)(3,puVar1,PTR_DAT_420011a4,uVar3,puVar1);
            iVar4 = 0;
          }
          else {
            uVar3 = (*(code *)PTR_FUN_4200005c)();
            (*(code *)PTR_FUN_42000118)
                      (1,puVar1,PTR_DAT_420011a8,uVar3,puVar1,aiStack_28[0],iStack_30);
            iVar4 = 0x103;
          }
        }
        else {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          uVar5 = FUN_42004180(iVar4);
          (*(code *)PTR_FUN_42000118)(1,puVar1,PTR_DAT_420011ac,uVar3,puVar1,uVar5);
        }
      }
      else {
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        uVar5 = FUN_42004180(iVar4);
        (*(code *)PTR_FUN_42000118)(1,puVar1,PTR_DAT_420011b0,uVar3,puVar1,uVar5);
      }
      FUN_4201b16c(uStack_2c);
    }
    else {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      uVar5 = FUN_42004180(iVar4);
      (*(code *)PTR_FUN_42000118)
                (1,puVar1,PTR_DAT_42001198,uVar3,puVar1,PTR_s_config_42001194,uVar5);
    }
  }
  return iVar4;
}


