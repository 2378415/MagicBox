// strings: ''!;'|

int FUN_4200b6fc(int param_1)

{
  int iVar1;
  int local_30;
  int iStack_2c;
  undefined1 uStack_28;
  undefined1 auStack_24 [36];
  
  iStack_2c = 0;
  uStack_28 = 0;
  local_30 = param_1;
  if (*(short *)(param_1 + 0x48) == 0) {
    uStack_28 = 1;
    FUN_42012fb8(PTR_FUN_42000a3c,&local_30,0);
    if (iStack_2c == 0) {
      return -3;
    }
    *(int *)(param_1 + 0x84) = iStack_2c;
  }
  else if (*(short *)(param_1 + 0x48) == 2) {
    iVar1 = FUN_4200b40c(param_1,PTR_s_ESP_PANIC_DETAILS_42000a40,*(undefined4 *)(param_1 + 0x84),
                         0x2a7);
    if (iVar1 != 0) {
      return iVar1;
    }
    FUN_42012fb8(PTR_FUN_42000a3c,&local_30,0);
    if (iStack_2c == 0) {
      return -2;
    }
    iVar1 = (*(int *)(param_1 + 0x84) + 3U & 0xfffffffc) - *(int *)(param_1 + 0x84);
    if (0 < iVar1) {
      (*DAT_42000240)(auStack_24,0,3);
      iVar1 = FUN_4200aed4(param_1 + 0x54,auStack_24,iVar1);
      if (iVar1 != 0) {
        return -2;
      }
    }
  }
  return (*(int *)(param_1 + 0x84) + 3U & 0xfffffffc) + 0x20;
}