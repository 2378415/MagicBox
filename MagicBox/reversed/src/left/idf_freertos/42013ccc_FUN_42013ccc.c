void FUN_42013ccc(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  short *local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar3 = DAT_42001288;
  puVar2 = DAT_42001260;
  iVar1 = DAT_4200121c;
  do {
    do {
      iVar4 = (*(code *)PTR_FUN_420010f8)(*puVar2,&local_30,0xffffffff);
    } while (iVar4 != 1);
    if (local_30 != (short *)0x0) {
      FUN_420136c4(uVar3,local_30,uStack_2c,uStack_28);
    }
    if (*local_30 != 0) {
      FUN_42012480(local_30,(int)local_30 + 7,*(undefined4 *)(local_30 + 0x104));
    }
    if ((byte)(*(char *)(iVar1 + 0x4e) - 1U) < *(byte *)(iVar1 + 0x4c)) {
      FUN_42013c8c();
    }
  } while( true );
}