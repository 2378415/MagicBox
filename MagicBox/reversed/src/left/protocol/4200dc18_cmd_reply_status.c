// strings: buttons()

void cmd_reply_status(undefined *param_1,int param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  char acStack_42 [66];
  
  iVar1 = (*DAT_42000c68)(param_1,DAT_42000d90,8);
  if (iVar1 == 0) {
    uVar2 = 0xb;
    iVar1 = 10;
    param_2 = 9;
    param_1 = PTR_s_buttons___42000d8c;
  }
  else {
    uVar2 = param_2 + 2;
    if (0x20 < uVar2) {
      return;
    }
    iVar1 = param_2 + 1;
  }
  (*DAT_42000064)(acStack_42 + 2,param_1,param_2);
  acStack_42[param_2 + 2] = '\n';
  acStack_42[iVar1 + 2] = param_3 + '0';
  uart0_reply(acStack_42 + 2,uVar2,0);
  return;
}