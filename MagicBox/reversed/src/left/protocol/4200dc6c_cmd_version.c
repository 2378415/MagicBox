void cmd_version(void)

{
  undefined1 auStack_50 [32];
  undefined4 local_30 [12];
  
  version_get(auStack_50,local_30);
  uart0_reply(auStack_50,local_30[0],0);
  return;
}