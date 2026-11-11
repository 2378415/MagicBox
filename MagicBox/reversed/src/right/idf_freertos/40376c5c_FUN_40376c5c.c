void FUN_40376c5c(int param_1)

{
  undefined *puVar1;
  
  (*DAT_4037448c)(param_1,0,0xf0);
  puVar1 = PTR_DAT_40374750;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(PTR_DAT_40374750 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(puVar1 + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(puVar1 + 0xc);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(puVar1 + 0x28);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(puVar1 + 0x18);
  return;
}