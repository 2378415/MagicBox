// 4200fe68  FUN_4200fe68  FUN_4200fe68  size=95
// strings: Db7@8a7@

void FUN_4200fe68(uint param_1)

{
  bool bVar1;
  int iVar2;
  int local_30 [12];
  
  local_30[0] = 0;
  do {
    do {
      iVar2 = (*(code *)PTR_FUN_42000b6c)
                        (*(undefined4 *)((param_1 & 0xff) * 4 + DAT_42000d64),local_30,0xffffffff);
    } while (iVar2 != 1);
    FUN_4200f6b0(local_30[0],*(short *)(local_30[0] + 2) + 4);
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      if (local_30[0] == *(int *)(((param_1 & 0xff) * 9 + iVar2) * 4 + DAT_42000d68)) {
        bVar1 = true;
        goto LAB_4200febc;
      }
    }
    bVar1 = false;
LAB_4200febc:
    if (!bVar1) {
      (*(code *)PTR_FUN_420008b4)();
    }
  } while( true );
}


