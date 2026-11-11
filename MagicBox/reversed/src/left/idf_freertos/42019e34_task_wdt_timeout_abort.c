// strings: task_wdt | pZ7@ | ret == pdTRUE | task_wdt_timeout_abort

void FUN_42019e34(char param_1)

{
  undefined *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 in_PRID;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  puVar1 = PTR_DAT_42000028;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (*(int *)PTR_DAT_42000028 != 0) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42001880,uVar3,PTR_s_task_wdt_42001870);
  }
  (*(code *)PTR_FUN_42000314)(6);
  uVar3 = (*(code *)PTR_FUN_42000474)();
  iVar4 = (*(code *)PTR_FUN_42000c8c)(uVar3,&local_30);
  uVar2 = 1;
  if (iVar4 != 1) {
    uVar2 = (*(code *)PTR_FUN_420000a8)
                      (PTR_s_task_wdt_c_3c03aad8_0x25_4200188c,0x17a,
                       PTR_s_task_wdt_timeout_abort_42001888,PTR_s_ret____pdTRUE_42001884);
  }
  uVar3 = uStack_2c;
  *DAT_420002d8 = uVar2;
  *DAT_42000c84 = uVar2;
  if (param_1 == '\0') {
    if (*(int *)puVar1 != 0) {
      uVar5 = (*(code *)PTR_FUN_4200005c)();
      uVar6 = rsr(in_PRID);
      (*DAT_42000060)(PTR_DAT_42001894,uVar5,PTR_s_task_wdt_42001870,uVar6 >> 0xd & 1);
    }
  }
  else if (*(int *)puVar1 != 0) {
    uVar5 = (*(code *)PTR_FUN_4200005c)();
    uVar6 = rsr(in_PRID);
    (*DAT_42000060)(PTR_DAT_42001890,uVar5,PTR_s_task_wdt_42001870,uVar6 >> 0xd & 1);
  }
  (*(code *)PTR_FUN_42001898)(uVar3);
  return;
}