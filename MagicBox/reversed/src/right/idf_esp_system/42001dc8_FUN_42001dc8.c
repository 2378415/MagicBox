void FUN_42001dc8(void)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = *(undefined4 *)PTR_DAT_42000194;
  uStack_2c = *(undefined4 *)(PTR_DAT_42000194 + 4);
  uStack_28 = *(undefined4 *)PTR_DAT_42000198;
  uStack_24 = *(undefined4 *)(PTR_DAT_42000198 + 4);
  (*DAT_42000050)(&local_30);
  (*DAT_42000054)(&local_30);
  (*DAT_42000058)(&local_30);
  (*DAT_42000050)(&uStack_28);
  (*DAT_42000054)(&uStack_28);
  (*DAT_42000058)(&uStack_28);
  return;
}