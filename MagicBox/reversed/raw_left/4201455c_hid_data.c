// 4201455c  hid_data  FUN_4201455c  size=110

void FUN_4201455c(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar6 = FUN_42016a78(0);
  *DAT_42001328 = uVar6;
  puVar2 = DAT_4200133c;
  *DAT_42001330 = 0;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 4;
  puVar5 = PTR_FUN_4200134c;
  puVar4 = PTR_s_hid_data_42001348;
  uVar3 = DAT_42001344;
  puVar2 = DAT_42001340;
  uVar1 = DAT_42000988;
  uVar6 = DAT_42000664;
  *DAT_42001340 = 0;
  *(undefined2 *)(puVar2 + 1) = 0;
  iVar7 = (*(code *)PTR_FUN_420004b0)(puVar5,puVar4,uVar1,0,6,uVar3,uVar6);
  if (iVar7 != 1) {
    uVar6 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_CommitFrame_42001350,PTR_DAT_42001354,uVar6,PTR_s_CommitFrame_42001350);
  }
  return;
}


