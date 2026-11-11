// strings: Guru Meditation Error: Core  |  panic'ed ( | Setting breakpoint at 0x |  and returning... | pZ7@ | Rebooting... | cpu_start

void FUN_420034e8(undefined4 *param_1)

{
  char *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  int local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  FUN_42003468(1000);
  pcVar1 = DAT_420002d8;
  if (*DAT_420002d8 == '\0') {
    if (param_1[2] != 0) {
      FUN_4200330c(PTR_s_Guru_Meditation_Error__Core_420002dc);
      FUN_420033bc(*param_1);
      FUN_4200330c(PTR_s_panic_ed___420002e0);
      FUN_4200330c(param_1[2]);
      FUN_4200330c(PTR_DAT_420002e4);
    }
    if (param_1[3] != 0) {
      FUN_4200330c();
    }
  }
  else {
    puVar9 = PTR_FUN_420002d4;
    if (*DAT_420002c0 == 0) {
      puVar9 = (undefined *)0x0;
    }
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[4] = puVar9;
    param_1[1] = 3;
  }
  puVar9 = PTR_s__3c039338_0x14_420002e8;
  FUN_4200330c(PTR_s__3c039338_0x14_420002e8);
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(param_1[7]);
  }
  FUN_4200330c(puVar9);
  puVar2 = PTR_DAT_420002f8;
  uVar8 = rer(DAT_420002ec);
  if ((uVar8 & 1) == 0) {
    iVar5 = (*DAT_42000310)(PTR_DAT_420002f8);
    if (iVar5 == 0) {
      (*DAT_420002a4)(puVar2,0,0,0);
      iVar5 = (*(code *)PTR_FUN_420001e8)();
      (*DAT_42000174)(puVar2);
      (*DAT_420001f4)(puVar2,0,iVar5 * 7,3);
      (*DAT_420002a8)(puVar2);
      (*DAT_4200017c)(puVar2);
    }
    FUN_42003468(1000);
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(param_1[7]);
    }
    FUN_4200330c(puVar9);
    puVar3 = PTR_s_ELF_file_SHA256__420002fc;
    *pcVar1 = '\0';
    FUN_4200330c(puVar3);
    FUN_4200330c(DAT_42000024);
    FUN_4200330c(puVar9);
    FUN_4200330c(puVar9);
    pcVar1 = DAT_42000300;
    if (*DAT_42000300 == '\0') {
      uStack_28 = *(undefined4 *)PTR_DAT_420002c8;
      uStack_24 = *(undefined4 *)(PTR_DAT_420002c8 + 4);
      local_30 = *(int *)PTR_DAT_420002cc;
      uStack_2c = *(undefined4 *)(PTR_DAT_420002cc + 4);
      (*DAT_42000174)(&uStack_28);
      (*DAT_42000178)(&uStack_28);
      (*DAT_4200017c)(&uStack_28);
      (*DAT_42000174)(&local_30);
      (*DAT_42000178)(&local_30);
      (*DAT_4200017c)(&local_30);
      *pcVar1 = '\x01';
      FUN_4200cd60(param_1);
      *pcVar1 = '\0';
      FUN_42003468(1000);
    }
    else {
      FUN_4200330c(PTR_s_Re_entered_core_dump__Exception_h_42000304);
    }
    (*DAT_42000174)(puVar2);
    (*DAT_42000178)(puVar2);
    (*DAT_4200017c)(puVar2);
    iVar5 = FUN_4200302c();
    if (iVar5 == 0) {
      if (param_1[1] == 1) {
        (*(code *)PTR_FUN_42000314)(5);
      }
      else if (param_1[1] == 2) {
        (*(code *)PTR_FUN_42000314)(6);
      }
      else {
        (*(code *)PTR_FUN_42000314)(4);
      }
    }
    FUN_4200330c(PTR_s_Rebooting____42000308);
    FUN_42003a8c();
    puVar4 = DAT_4200031c;
    puVar9 = PTR_DAT_42000028;
    cust0();
    uVar8 = (uint)pcVar1 >> 0xd & 1;
    if (PTR_PTR_42000318 < DAT_4200031c) {
      puVar7 = (undefined4 *)PTR_PTR_42000318;
      do {
        if (((undefined *)(uint)*(ushort *)((int)puVar7 + 6) == puVar2) &&
           (((uint)*(ushort *)(puVar7 + 1) & 1 << 0x20 - (0x20 - ((uint)pcVar1 >> 0xd & 1))) != 0))
        {
          if (3 < *(uint *)puVar9) {
            uVar6 = (*(code *)PTR_FUN_4200005c)();
            (*DAT_42000060)(PTR_DAT_42000324,uVar6,PTR_s_cpu_start_42000320,*puVar7,uVar8);
          }
          iVar5 = (*(code *)*puVar7)();
          if (iVar5 != 0) {
            local_30 = iVar5;
            if (*(int *)puVar9 != 0) {
              uVar6 = (*(code *)PTR_FUN_4200005c)();
              (*DAT_42000060)(PTR_DAT_42000328,uVar6,PTR_s_cpu_start_42000320,*puVar7,local_30);
            }
            (*(code *)PTR_FUN_42000330)();
          }
        }
        puVar7 = puVar7 + 2;
      } while (puVar7 < puVar4);
    }
    memw();
    *(undefined1 *)(DAT_4200032c + uVar8) = 1;
    return;
  }
  if (*(char *)(param_1 + 8) == '\0') {
    if (*pcVar1 == '\0') goto LAB_42003599;
    iVar5 = *DAT_420002c0;
  }
  else {
    iVar5 = param_1[2];
  }
  if (iVar5 != 0) {
    local_30 = iVar5;
    uStack_2c = (*DAT_4200030c)();
    breakpoint(0x1000,0x42003596,1,0xe);
  }
LAB_42003599:
  FUN_4200330c(PTR_s_Setting_breakpoint_at_0x_420002f0);
  FUN_42003360(param_1[6]);
  FUN_4200330c(PTR_s_and_returning____420002f4);
  uStack_28 = *(undefined4 *)PTR_DAT_420002c8;
  uStack_24 = *(undefined4 *)(PTR_DAT_420002c8 + 4);
  local_30 = *(int *)PTR_DAT_420002cc;
  uStack_2c = *(undefined4 *)(PTR_DAT_420002cc + 4);
  (*DAT_42000174)(&uStack_28);
  (*DAT_42000178)(&uStack_28);
  (*DAT_4200017c)(&uStack_28);
  (*DAT_42000174)(&local_30);
  (*DAT_42000178)(&local_30);
  (*DAT_4200017c)(&local_30);
  FUN_4202da48(0,param_1[6]);
  return;
}