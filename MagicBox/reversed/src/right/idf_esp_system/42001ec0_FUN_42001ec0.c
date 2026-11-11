void FUN_42001ec0(int param_1)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = *(undefined4 *)PTR_DAT_42000194;
  uStack_2c = *(undefined4 *)(PTR_DAT_42000194 + 4);
  uStack_28 = *(undefined4 *)PTR_DAT_42000198;
  uStack_24 = *(undefined4 *)(PTR_DAT_42000198 + 4);
  (*DAT_4200017c)(&local_30,1,DAT_42000170,0);
  (*DAT_42000050)(&local_30);
  (*DAT_420000d8)(&local_30,0,
                  (uint)((ulonglong)(uint)(param_1 * 1000) * (ulonglong)DAT_420001a4 >> 0x25),3);
  (*DAT_42000180)(&local_30);
  (*DAT_42000058)(&local_30);
  (*DAT_42000050)(&uStack_28);
  (*DAT_42000054)(&uStack_28);
  (*DAT_42000058)(&uStack_28);
  return;
}