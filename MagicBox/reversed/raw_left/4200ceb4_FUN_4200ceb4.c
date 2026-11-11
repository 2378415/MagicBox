// 4200ceb4  FUN_4200ceb4  FUN_4200ceb4  size=154

int FUN_4200ceb4(int *param_1,int param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *local_30;
  int *piStack_2c;
  
  uVar5 = (uint)*(byte *)(param_1 + 9);
  if (param_3 + *param_1 + uVar5 < (uint)DAT_42000cc0[1]) {
    param_4 = 0;
    if (param_3 == 0) {
      return 0;
    }
    local_30 = param_1 + 1;
    piStack_2c = param_1 + 10;
  }
  else {
    uVar5 = (*(code *)PTR_FUN_42000330)();
  }
  while( true ) {
    uVar3 = -(uVar5 - 0x20);
    iVar4 = (uVar3 < param_3) * uVar3 + (uVar3 >= param_3) * param_3;
    (*DAT_42000064)((int)param_1 + uVar5 + 4,param_2 + param_4,iVar4);
    bVar1 = *(byte *)(param_1 + 9);
    *(char *)(param_1 + 9) = (char)(iVar4 + (uint)bVar1);
    if ((iVar4 + (uint)bVar1 & 0xff) == 0x20) {
      iVar2 = FUN_4200ce40(*DAT_42000cc0 + *param_1,local_30,0x20);
      if (iVar2 != 0) {
        return iVar2;
      }
      *param_1 = *param_1 + 0x20;
      FUN_4200d708(piStack_2c,local_30);
      *(undefined1 *)(param_1 + 9) = 0;
      (*DAT_42000094)(local_30,0,0x20);
    }
    param_3 = param_3 - iVar4;
    param_4 = param_4 + iVar4;
    if (param_3 == 0) break;
    uVar5 = (uint)*(byte *)(param_1 + 9);
  }
  return 0;
}


