void cmd_keys_up(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  undefined1 auStack_30 [48];
  
  if ((param_6 != 0) && (iVar1 = parse_list6(param_5,param_6,auStack_30), iVar1 != 0)) {
    hid_keys_up(param_3,auStack_30,iVar1);
    uart0_reply(param_1,param_2,0);
  }
  return;
}