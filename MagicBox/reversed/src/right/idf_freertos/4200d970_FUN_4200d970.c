undefined4 *
FUN_4200d970(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5
            )

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)PTR_FUN_42000b78)(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    (*DAT_42000240)(puVar1,0,0x14);
    *puVar1 = param_3;
    puVar1[1] = param_4;
    iVar2 = (*(code *)PTR_FUN_42000b7c)
                      (PTR_s_usb_tim_42000b74,
                       (uint)((ulonglong)(uint)(param_2 * 1000) * (ulonglong)DAT_420001a4 >> 0x26),
                       param_5,puVar1,PTR_FUN_42000b70);
    puVar1[4] = iVar2;
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}