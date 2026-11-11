void cmd_keys_combo(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  undefined1 auStack_40 [12];
  undefined4 uStack_34;
  undefined4 auStack_30 [12];
  
  if (param_6 != 0) {
    iVar1 = parse_list6(param_5,param_6,auStack_40);
    parse_range(param_5,param_6,auStack_30,&uStack_34);
    if (iVar1 != 0) {
      hid_keys_combo(param_3,auStack_40,iVar1,auStack_30[0],uStack_34);
      uart0_reply(param_1,param_2,0);
    }
  }
  return;
}