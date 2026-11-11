void cmd_dump_channels(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_30 [48];
  
  if (param_3 != 0) {
    iVar4 = 0;
    if (*(int *)(param_3 + 0x214) != 0) {
      iVar3 = 0x100;
      do {
        iVar2 = *(int *)(param_3 + 0x214) + iVar4;
        if (((*(char *)(iVar2 + 0x269) != '\0') && (*(char *)(iVar2 + 0x369) != '\0')) &&
           (*(char *)(param_3 + iVar4 + 0x636) != '\0')) {
          uVar1 = FUN_4202058c(auStack_30,0x10,PTR_DAT_42000d88);
          uart0_reply(auStack_30,uVar1,0);
          return;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  uart0_reply(PTR_s_0_3c034fa0_0x14_42000d84,1,0);
  return;
}