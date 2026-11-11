void cmd_key_tap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c [11];
  
  if (param_6 != 0) {
    iVar1 = parse_int_or_char(param_5,param_6);
    parse_range(param_5,param_6,local_2c,&local_30);
    if (iVar1 != 0) {
      hid_key_tap(param_3,iVar1,local_2c[0],local_30);
      uart0_reply(param_1,param_2,0);
    }
  }
  return;
}