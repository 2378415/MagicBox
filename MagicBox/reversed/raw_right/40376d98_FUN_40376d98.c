// 40376d98  FUN_40376d98  FUN_40376d98  size=22
// strings: Unhandled interrupt %d on cpu %d!

void FUN_40376d98(undefined4 param_1)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  (*DAT_403745cc)(PTR_s_Unhandled_interrupt__d_on_cpu__d_40374774,param_1,uVar1 >> 0xd & 1);
  return;
}


