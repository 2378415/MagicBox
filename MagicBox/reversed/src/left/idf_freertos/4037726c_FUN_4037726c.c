// strings: Unhandled interrupt %d on cpu %d!

void FUN_4037726c(undefined4 param_1)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  (*DAT_40374438)(PTR_s_Unhandled_interrupt__d_on_cpu__d_403747f4,param_1,uVar1 >> 0xd & 1);
  return;
}