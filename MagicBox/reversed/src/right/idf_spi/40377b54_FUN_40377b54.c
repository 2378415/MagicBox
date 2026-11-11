void FUN_40377b54(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  FUN_40377a78(uVar1,*(undefined4 *)(uVar1 * 4 + DAT_4037484c));
  FUN_4037660c();
  return;
}