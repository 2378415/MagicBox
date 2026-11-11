// strings: ESP_EXTRA_INFO

int FUN_4200b79c(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_30 [12];
  
  local_30[0] = 0;
  (*DAT_42000a34)(param_1 + 1,DAT_42000020,0x42);
  uVar1 = FUN_4200b988();
  *param_1 = uVar1;
  iVar2 = FUN_4200b4e4(param_1,PTR_s_ESP_CORE_DUMP_INFO_42000a48,DAT_42000a44,param_1,0x48);
  iVar3 = iVar2;
  if (0 < iVar2) {
    iVar3 = FUN_4200be0c(local_30);
    if (iVar3 == 0) {
      iVar3 = -3;
    }
    else {
      iVar3 = FUN_4200b4e4(param_1,PTR_s_ESP_EXTRA_INFO_42000a4c,0x2a5,local_30[0],iVar3);
      if (0 < iVar3) {
        iVar3 = iVar3 + iVar2;
        if (*DAT_420009d4 != '\0') {
          iVar2 = FUN_4200b6fc(param_1);
          if (iVar2 < 1) {
            return iVar2;
          }
          iVar3 = iVar3 + iVar2;
        }
        pcVar4 = (char *)*DAT_4200019c;
        if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
          uVar1 = (*DAT_420001e4)(pcVar4);
          iVar2 = FUN_4200b4e4(param_1,PTR_s_ESP_PANIC_DETAILS_42000a40,0x2a7,pcVar4,uVar1);
          if (iVar2 < 1) {
            return iVar2;
          }
          iVar3 = iVar3 + iVar2;
        }
        iVar3 = FUN_4200b220(param_1,iVar3);
      }
    }
  }
  return iVar3;
}