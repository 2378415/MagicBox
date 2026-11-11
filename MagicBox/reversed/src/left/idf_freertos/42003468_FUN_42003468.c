void FUN_42003468(int param_1)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = *(undefined4 *)PTR_DAT_420002c8;
  uStack_24 = *(undefined4 *)(PTR_DAT_420002c8 + 4);
  local_30 = *(undefined4 *)PTR_DAT_420002cc;
  uStack_2c = *(undefined4 *)(PTR_DAT_420002cc + 4);
  (*DAT_420002a4)(&uStack_28,1,DAT_42000298,0);
  (*DAT_42000174)(&uStack_28);
  (*DAT_420001f4)(&uStack_28,0,
                  (uint)((ulonglong)(uint)(param_1 * 1000) * (ulonglong)DAT_420002d0 >> 0x25),3);
  (*DAT_420002a8)(&uStack_28);
  (*DAT_4200017c)(&uStack_28);
  (*DAT_42000174)(&local_30);
  (*DAT_42000178)(&local_30);
  (*DAT_4200017c)(&local_30);
  return;
}