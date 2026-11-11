// 4200271c  FUN_4200271c  FUN_4200271c  size=50
// strings: Unknown | Exception was unhandled.

void FUN_4200271c(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 0x50) < 0x28) {
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(PTR_PTR_42000304 + *(uint *)(param_1 + 0x50) * 4)
    ;
  }
  else {
    *(undefined **)(param_2 + 8) = PTR_s_Unknown_42000308;
  }
  *(undefined **)(param_2 + 0xc) = PTR_s_Exception_was_unhandled__4200030c;
  if (*(int *)(param_1 + 0x50) == 0) {
    *(undefined **)(param_2 + 0x10) = PTR_FUN_42000310;
  }
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 4);
  return;
}


