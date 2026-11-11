// strings: Guru Meditation Error: Core  |  panic'ed ( | Setting breakpoint at 0x |  and returning... | Rebooting...

void FUN_42001f40(undefined4 *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  
  FUN_42001ec0(1000);
  if (*DAT_420001ac != '\0') {
    param_1[3] = 0;
    if (*DAT_4200019c == 0) {
      puVar3 = (undefined *)0x0;
    }
    else {
      puVar3 = PTR_FUN_420001a8;
    }
    param_1[4] = puVar3;
    param_1[2] = 0;
    param_1[1] = 3;
  }
  if (param_1[2] != 0) {
    FUN_42001e2c(PTR_s_Guru_Meditation_Error__Core_420001b0);
    FUN_42001e84(*param_1);
    FUN_42001e2c(PTR_s_panic_ed___420001b4);
    FUN_42001e2c(param_1[2]);
    FUN_42001e2c(PTR_DAT_420001b8);
  }
  if (param_1[3] != 0) {
    FUN_42001e2c();
  }
  FUN_42001e2c(PTR_DAT_420001bc);
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(param_1[7]);
  }
  FUN_42001e2c(PTR_DAT_420001bc);
  uVar4 = rer(DAT_420001c0);
  if ((uVar4 & 1) == 0) {
    iVar5 = (*DAT_420001e8)(PTR_DAT_420001cc);
    puVar3 = PTR_DAT_420001cc;
    if (iVar5 == 0) {
      (*DAT_4200017c)(PTR_DAT_420001cc,0,0,0);
      uVar4 = (*(code *)PTR_FUN_420000cc)();
      uVar2 = (*DAT_420000d0)(uVar4 * DAT_420001d0,
                              (int)((ulonglong)uVar4 * (ulonglong)DAT_420001d0 >> 0x20),1000,0);
      (*DAT_42000050)(puVar3);
      (*DAT_420000d8)(puVar3,0,uVar2,3);
      (*DAT_42000180)(puVar3);
      (*DAT_42000058)(puVar3);
    }
    FUN_42001ec0(1000);
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(param_1[7]);
    }
    puVar3 = PTR_DAT_420001bc;
    FUN_42001e2c(PTR_DAT_420001bc);
    *DAT_420001ac = '\0';
    FUN_42001e2c(PTR_s_ELF_file_SHA256__420001d4);
    FUN_42001e2c(DAT_42000020);
    FUN_42001e2c(puVar3);
    FUN_42001e2c(puVar3);
    if (*DAT_420001d8 == '\0') {
      FUN_42001dc8();
      pcVar1 = DAT_420001d8;
      *DAT_420001d8 = '\x01';
      FUN_4200ae00(param_1);
      *pcVar1 = '\0';
      FUN_42001ec0(1000);
    }
    else {
      FUN_42001e2c(PTR_s_Re_entered_core_dump__Exception_h_420001dc);
    }
    puVar3 = PTR_DAT_420001cc;
    (*DAT_42000050)(PTR_DAT_420001cc);
    (*DAT_42000054)(puVar3);
    (*DAT_42000058)(puVar3);
    iVar5 = FUN_42001b08();
    if (iVar5 == 0) {
      if (param_1[1] == 1) {
        (*(code *)PTR_FUN_420001ec)(5);
      }
      else if (param_1[1] == 2) {
        (*(code *)PTR_FUN_420001ec)(6);
      }
      else {
        (*(code *)PTR_FUN_420001ec)(4);
      }
    }
    FUN_42001e2c(PTR_s_Rebooting____420001e0);
    FUN_42002410();
    do {
      ill();
    } while( true );
  }
  if (*(char *)(param_1 + 8) == '\0') {
    if (*DAT_420001ac == '\0') goto LAB_42001fe7;
    iVar5 = *DAT_4200019c;
  }
  else {
    iVar5 = param_1[2];
  }
  if (iVar5 != 0) {
    (*DAT_420001e4)();
    breakpoint(0x1000,0x42001fe4,1,0xe);
  }
LAB_42001fe7:
  FUN_42001e2c(PTR_s_Setting_breakpoint_at_0x_420001c4);
  FUN_42001e58(param_1[6]);
  FUN_42001e2c(PTR_s_and_returning____420001c8);
  FUN_42001dc8();
  FUN_42025200(0,param_1[6]);
  return;
}