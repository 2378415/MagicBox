// 4200f12c  FUN_4200f12c  FUN_4200f12c  size=166
// strings: usbh_hub%u

undefined4 FUN_4200f12c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_40 [64];
  
  (*DAT_42000240)(auStack_40,0,0x20);
  *(undefined1 *)(param_1 + 0x10) = 1;
  *(undefined1 *)(param_1 + 0x12) = 1;
  *(undefined1 *)(param_1 + 0x11) = 1;
  *(undefined4 *)(param_1 + 0x2b00) = 0;
  *(undefined1 *)(param_1 + 0x13) = 1;
  *(undefined1 *)(param_1 + 0x15) = 1;
  *(int *)(param_1 + 0x2b4c) = param_1 + 0xd;
  *(int *)(param_1 + 0x2b04) = param_1;
  iVar1 = FUN_4200d880(7);
  *(int *)(param_1 + 0x2b6c) = iVar1;
  if (iVar1 == 0) {
    (*DAT_42000634)(PTR_DAT_42000c1c);
    (*DAT_42000634)(PTR_s_Failed_to_create_hub_mq_42000cb0);
    (*DAT_42000634)(PTR_DAT_42000c24);
    uVar2 = 0xffffffff;
  }
  else {
    FUN_42017b5c(auStack_40,0x20,PTR_s_usbh_hub_u_42000cb4,*(undefined1 *)(param_1 + 4));
    iVar1 = FUN_4200d754(auStack_40,DAT_420004fc,0,PTR_FUN_42000cb8,param_1);
    *(int *)(param_1 + 0x2b68) = iVar1;
    if (iVar1 == 0) {
      (*DAT_42000634)(PTR_DAT_42000c1c);
      (*DAT_42000634)(PTR_s_Failed_to_create_hub_thread_42000cbc);
      (*DAT_42000634)(PTR_DAT_42000c24);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


