// 40381ce0  FUN_40381ce0  FUN_40381ce0  size=139
// strings: abort() was called at PC 0x |  on core 

void FUN_40381ce0(undefined1 *param_1)

{
  uint unaff_retaddr;
  uint uVar1;
  undefined1 in_PRID;
  undefined1 auStack_70 [9];
  undefined1 auStack_67 [2];
  undefined1 auStack_65 [53];
  undefined1 *apuStack_30 [12];
  
  (*DAT_4037448c)(auStack_70,0,9);
  (*DAT_4037448c)(auStack_67,0,2);
  (*DAT_4037448c)(auStack_65,0,0x32);
  (*DAT_403751dc)((unaff_retaddr & 0x3fffffff | DAT_403751d0 & 0xc0000000) - 3,auStack_70,0x10);
  uVar1 = rsr(in_PRID);
  (*DAT_403751dc)(uVar1 >> 0xd & 1,auStack_67,10);
  apuStack_30[0] = PTR_s_abort___was_called_at_PC_0x_403751d4;
  apuStack_30[1] = auStack_70;
  apuStack_30[2] = PTR_s_on_core_403751d8;
  apuStack_30[3] = auStack_67;
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
    (*DAT_40374d5c)(auStack_65,apuStack_30[uVar1]);
  }
  FUN_4037af90(auStack_65);
  *param_1 = 0x30;
  param_1[1] = 0x78;
  (*DAT_403751dc)((unaff_retaddr & 0x3fffffff | DAT_403751e0 & 0xc0000000) - 3,param_1 + 2,0x10);
  return;
}


