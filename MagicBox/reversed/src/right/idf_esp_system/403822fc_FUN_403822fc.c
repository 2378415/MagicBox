// strings: P'8@ | \*8@

undefined4 FUN_403822fc(int param_1)

{
  undefined4 uVar1;
  
  if (((*(uint *)(param_1 + 0x18) >> 8 & 0xff) << 8 == DAT_4037523c) ||
     ((*(uint *)(param_1 + 0x18) & 0xff) < 0x16)) {
    uVar1 = FUN_40382dac(param_1,PTR_FUN_40375244,PTR_FUN_40375240,0x200);
  }
  else {
    uVar1 = FUN_40382dac(param_1,PTR_FUN_4037524c,PTR_FUN_40375248,2);
  }
  return uVar1;
}