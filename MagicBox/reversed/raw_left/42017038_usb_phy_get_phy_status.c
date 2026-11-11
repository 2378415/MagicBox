// 42017038  usb_phy_get_phy_status  FUN_42017038  size=133
// strings: usb_phy_get_phy_status

undefined4 FUN_42017038(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (2 < param_1) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001540,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_usb_phy_get_phy_status_4200153c,0x1c5);
    return 0x102;
  }
  piVar2 = (int *)*DAT_42001538;
  if (piVar2 == (int *)0x0) {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,PTR_s_usb_phy_420014ec,PTR_DAT_42001544,uVar1,PTR_s_usb_phy_420014ec,
               PTR_s_usb_phy_get_phy_status_4200153c,0x1c6);
    return 0x103;
  }
  if (param_1 == 2) {
    iVar3 = piVar2[2];
  }
  else if (param_1 == 0) {
    iVar3 = *piVar2;
  }
  else {
    iVar3 = piVar2[1];
  }
  if (iVar3 == 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(iVar3 + 8);
  }
  return 0;
}


