undefined4 FUN_42012b6c(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_42000f54;
  uVar2 = *(undefined4 *)PTR_DAT_42000f50;
  (*DAT_42000240)(PTR_DAT_42000f54,0,0x10);
  *(undefined4 *)puVar1 = uVar2;
  *(undefined **)(param_1 + 8) = PTR_PTR_42000f58;
  *(undefined **)(param_1 + 0xc) = puVar1;
  return 0;
}