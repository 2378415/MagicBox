// 420139e4  uart_event_task  FUN_420139e4  size=312

void FUN_420139e4(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_28;
  
  FUN_420045c4(PTR_s_uart_events_4200120c,3);
  local_38 = 0;
  uStack_40 = DAT_4200124c;
  uStack_28 = 4;
  uStack_3c = 3;
  uStack_34 = 1;
  FUN_4200b2f0(1,DAT_42000988,DAT_42000988,0x14,DAT_42001240,0);
  FUN_4200a808(1,&uStack_40);
  FUN_4200a268(1,*(undefined4 *)PTR_DAT_42001254,*(undefined4 *)PTR_DAT_42001250,0xffffffff);
  uVar2 = (*(code *)PTR_FUN_42001284)(1);
  *DAT_42001258 = uVar2;
  uVar2 = (*(code *)PTR_FUN_42000e7c)(1,0,3);
  *DAT_42001230 = uVar2;
  uVar2 = (*(code *)PTR_FUN_42000e7c)(1,0,3);
  *DAT_4200125c = uVar2;
  iVar3 = (*(code *)PTR_FUN_42000e7c)(10,0xc,0);
  piVar1 = DAT_42001260;
  *DAT_42001260 = iVar3;
  iVar3 = (*(code *)PTR_FUN_42000e7c)(0x32,0x44,0);
  iVar5 = *piVar1;
  *DAT_42001204 = iVar3;
  uVar2 = DAT_42000664;
  if ((iVar5 == 0) || (bVar4 = iVar3 == 0 || iVar5 == 0, iVar3 == 0 || iVar5 == 0)) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,PTR_s_uart_events_4200120c,PTR_DAT_42001264,uVar2);
  }
  else {
    (*(code *)PTR_FUN_420004b0)
              (PTR_FUN_4200126c,PTR_s_uart_event_task_42001268,DAT_42000988,0,8,bVar4,DAT_42000664);
    (*(code *)PTR_FUN_420004b0)
              (PTR_LAB_42001274,PTR_s_hid_data_processing_42001270,DAT_42000988,0,7,bVar4,uVar2);
    (*(code *)PTR_FUN_420004b0)
              (PTR_FUN_4200127c,PTR_s_hid_parse_task_42001278,DAT_42000988,0,3,bVar4,uVar2);
    FUN_420152cc(0,PTR_DAT_42001280);
    FUN_4201455c();
    FUN_4200f83c();
  }
  return;
}


