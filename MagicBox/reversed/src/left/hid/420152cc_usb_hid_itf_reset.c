void usb_hid_itf_reset(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  
  uVar1 = DAT_42001360;
  iVar3 = DAT_4200135c;
  (*DAT_42000094)(DAT_4200135c + (param_1 & 0xff) * (DAT_42001360 & 0xffff),0,DAT_42001360);
  iVar3 = iVar3 + (param_1 & 0xff) * uVar1;
  puVar8 = (undefined1 *)(iVar3 + DAT_42001364);
  puVar7 = (undefined1 *)(iVar3 + DAT_420013cc);
  puVar6 = (undefined4 *)(iVar3 + DAT_420013c4);
  puVar5 = (undefined1 *)(iVar3 + DAT_420013d4);
  puVar4 = (undefined4 *)(iVar3 + DAT_420013c8);
  *(undefined4 *)(iVar3 + 0x18) = param_2;
  *puVar7 = 0x80;
  *puVar6 = PTR_FUN_420013d0;
  puVar2 = PTR_FUN_420013d8;
  *puVar8 = 0;
  *puVar5 = 0;
  *puVar4 = puVar2;
  return;
}