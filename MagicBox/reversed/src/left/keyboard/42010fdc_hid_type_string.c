void hid_type_string(undefined4 param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3;
    do {
      iVar1 = char_to_usage(*param_2);
      if (iVar1 != 0) {
        hid_key_down(param_1,iVar1);
        (*(code *)PTR_FUN_42000098)(0x32);
        hid_key_up(param_1,iVar1);
      }
      param_2 = param_2 + 1;
    } while (param_2 != puVar2);
  }
  return;
}