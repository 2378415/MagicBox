// strings: X,8@ | h-8@

undefined4 FUN_40382264(int param_1)

{
  undefined4 uVar1;
  
  if (((*(uint *)(param_1 + 0x18) >> 8 & 0xff) << 8 == DAT_40374a3c) ||
     ((*(uint *)(param_1 + 0x18) & 0xff) < 0x16)) {
    uVar1 = FUN_403827ac(param_1,PTR_FUN_40375310,PTR_FUN_4037530c,0x200);
  }
  else {
    uVar1 = FUN_403827ac(param_1,PTR_FUN_40375318,PTR_FUN_40375314,2);
  }
  return uVar1;
}