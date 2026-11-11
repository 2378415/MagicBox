// 420098c0  FUN_420098c0  FUN_420098c0  size=25

undefined4 FUN_420098c0(undefined4 param_1,int param_2)

{
  (*DAT_42000240)(param_2,0,0x58);
  *(undefined4 *)(param_2 + 4) = DAT_42000804;
  return 0;
}


