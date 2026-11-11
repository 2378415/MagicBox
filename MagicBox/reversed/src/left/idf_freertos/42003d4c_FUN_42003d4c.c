// strings: Exception was unhandled. | Unknown

void FUN_42003d4c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  if (uVar1 < 0x28) {
    uVar2 = *(undefined4 *)(PTR_PTR_42000438 + uVar1 * 4);
    *(undefined **)(param_2 + 0xc) = PTR_s_Exception_was_unhandled__4200043c;
    *(undefined4 *)(param_2 + 8) = uVar2;
    if (uVar1 == 0) {
      *(undefined **)(param_2 + 0x10) = PTR_FUN_42000444;
    }
  }
  else {
    *(undefined **)(param_2 + 8) = PTR_s_Unknown_42000440;
    *(undefined **)(param_2 + 0xc) = PTR_s_Exception_was_unhandled__4200043c;
  }
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 4);
  return;
}