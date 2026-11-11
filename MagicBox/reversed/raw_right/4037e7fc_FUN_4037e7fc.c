// 4037e7fc  FUN_4037e7fc  FUN_4037e7fc  size=140
// strings: IDLE

void FUN_4037e7fc(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char local_40 [16];
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [10];
  
  iVar3 = 0;
  bVar2 = true;
  while ((iVar3 < 2 && (bVar2))) {
    for (iVar4 = 0;
        (iVar4 < 0x10 && (cVar1 = PTR_DAT_40374fa8[iVar4], local_40[iVar4] = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
    if (iVar4 < 0x10) {
      local_40[iVar4] = (char)iVar3 + '0';
      if (iVar4 + 1 < 0x10) {
        local_40[iVar4 + 1] = '\0';
      }
    }
    auStack_28[0] = 0;
    uStack_2c = 0;
    FUN_4037c17c(auStack_28,&uStack_2c,&local_30);
    iVar4 = FUN_4037e718(PTR_FUN_40374fac,local_40,local_30,0,0,uStack_2c,auStack_28[0],iVar3);
    *(int *)(iVar3 * 4 + DAT_40374fb0) = iVar4;
    if (iVar4 == 0) {
      bVar2 = false;
    }
    iVar3 = iVar3 + 1;
  }
  return;
}


