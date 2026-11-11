// 420078e0  esp_clk_tree_common  FUN_420078e0  size=108
// strings: esp_clk_tree_common

undefined4 FUN_420078e0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 1) {
    uVar1 = FUN_4201a75c();
  }
  else if (param_1 == 2) {
    iVar2 = (*(code *)PTR_FUN_420001b0)(0,0x400);
    if (iVar2 != 0) {
      if (3 < *(uint *)PTR_DAT_42000028) {
        uVar1 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42000870,uVar1,PTR_s_esp_clk_tree_common_4200086c,iVar2);
      }
      FUN_4200509c(iVar2);
    }
    uVar1 = (*(code *)PTR_FUN_42000868)(iVar2);
  }
  else {
    uVar1 = 0;
    if (param_1 == 0) {
      memw();
      uVar1 = (*(code *)PTR_FUN_42000868)(*DAT_42000634);
    }
  }
  return uVar1;
}


