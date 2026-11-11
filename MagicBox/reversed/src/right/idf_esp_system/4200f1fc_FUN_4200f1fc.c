int FUN_4200f1fc(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_40;
  undefined1 auStack_3c [16];
  undefined4 auStack_2c [11];
  
  iVar1 = FUN_42013da4(PTR_s_storage_42000ccc,PTR_s_usb_devices_42000cc8,0,&local_40);
  if (iVar1 == 0) {
    *param_2 = 0;
    for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
      FUN_42017b5c(auStack_3c,0x10,PTR_s_device__d_42000cd0,uVar3);
      auStack_2c[0] = 0x46;
      iVar2 = FUN_42013cc4(local_40,auStack_3c,*param_2 * 0x46 + param_1,auStack_2c);
      if (iVar2 != 0) {
        if (iVar2 != DAT_42000cd4) {
          FUN_42013d60(local_40);
          return iVar2;
        }
        break;
      }
      *param_2 = *param_2 + 1;
    }
    FUN_42013d60(local_40);
  }
  return iVar1;
}