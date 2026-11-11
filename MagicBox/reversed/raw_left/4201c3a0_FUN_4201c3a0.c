// 4201c3a0  FUN_4201c3a0  FUN_4201c3a0  size=82

undefined4 FUN_4201c3a0(int param_1,undefined1 param_2,undefined4 param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined4 auStack_30 [12];
  
  uVar3 = DAT_42001a70;
  if (*(int *)(param_1 + 100) == 1) {
    uVar3 = DAT_420011bc;
    for (iVar2 = *(int *)(param_1 + 0x10); DAT_420011bc = uVar3, iVar2 != 0;
        iVar2 = *(int *)(iVar2 + 4)) {
      auStack_30[0] = 0;
      iVar1 = FUN_4201d244(iVar2,param_2,0xff,param_3,auStack_30,&uStack_50,0xff,0xff);
      if (iVar1 == 0) {
        if (param_4 == (undefined1 *)0x0) {
          return 0;
        }
        *param_4 = uStack_4f;
        return 0;
      }
      uVar3 = DAT_420011bc;
    }
  }
  return uVar3;
}


