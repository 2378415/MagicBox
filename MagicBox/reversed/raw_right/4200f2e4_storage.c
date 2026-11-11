// 4200f2e4  storage  FUN_4200f2e4  size=116
// strings: storage

void FUN_4200f2e4(void)

{
  int iVar1;
  
  FUN_4200f270();
  iVar1 = FUN_42013c4c(PTR_s_storage_42000ccc);
  if (iVar1 == DAT_42000ce0 || iVar1 == DAT_42000ce4) {
    FUN_42013d14(PTR_s_storage_42000ccc);
    iVar1 = FUN_42013c4c(PTR_s_storage_42000ccc);
  }
  if (iVar1 == 0) {
    FUN_4200f1fc(DAT_42000cec,DAT_42000ce8,0xf);
    iVar1 = (*(code *)PTR_FUN_42000b64)(10,0x46,0);
    *DAT_42000cf0 = iVar1;
    if (iVar1 != 0) {
      (*(code *)PTR_FUN_42000380)
                (PTR_FUN_42000cf8,PTR_s_nvs_store_task_42000cf4,DAT_4200077c,0,2,0,DAT_4200049c);
    }
  }
  return;
}


