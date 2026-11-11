// strings: device_%d

int FUN_4200f3ec(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined4 local_40;
  undefined1 auStack_3c [60];
  
  iVar1 = FUN_42013da4(PTR_s_storage_42000ccc,PTR_s_usb_devices_42000cc8,1,&local_40);
  if (iVar1 == 0) {
    uVar2 = FUN_4200f3ac(param_1,param_2);
    if (uVar2 == 0xffffffff) {
      uVar2 = *DAT_42000ce8;
      if (0xe < uVar2) {
        FUN_42013d60(local_40);
        return 0x101;
      }
      puVar3 = (undefined2 *)(uVar2 * 0x46 + DAT_42000cec);
      *puVar3 = (short)param_1;
      puVar3[1] = (short)param_2;
      *(undefined1 *)(puVar3 + 2) = param_3;
      (*DAT_42000cfc)((int)puVar3 + 5,param_4,0x3f);
      *(undefined1 *)(puVar3 + 0x22) = 0;
      *DAT_42000ce8 = *DAT_42000ce8 + 1;
    }
    else {
      iVar1 = uVar2 * 0x46 + DAT_42000cec;
      *(undefined1 *)(iVar1 + 4) = param_3;
      (*DAT_42000cfc)(iVar1 + 5,param_4,0x3f);
      *(undefined1 *)(iVar1 + 0x44) = 0;
    }
    FUN_42017b5c(auStack_3c,0x10,PTR_s_device__d_42000cd0,uVar2);
    iVar1 = FUN_42013c98(local_40,auStack_3c,uVar2 * 0x46 + DAT_42000cec,0x46);
    if (iVar1 == 0) {
      iVar1 = FUN_42013c70(local_40);
    }
    FUN_42013d60(local_40);
  }
  return iVar1;
}