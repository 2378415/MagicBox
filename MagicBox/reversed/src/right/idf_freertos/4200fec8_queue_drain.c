// strings: Db7@8a7@

void queue_drain(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int local_30 [12];
  
  local_30[0] = 0;
  iVar2 = (*(code *)PTR_FUN_42000b6c)(param_1,local_30);
  if ((iVar2 == 1) && (local_30[0] != 0)) {
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      if (local_30[0] == *(int *)((param_2 * 9 + iVar2) * 4 + DAT_42000d68)) {
        bVar1 = true;
        goto LAB_4200ff06;
      }
    }
    bVar1 = false;
LAB_4200ff06:
    if (!bVar1) {
      (*(code *)PTR_FUN_420008b4)();
    }
  }
  return;
}