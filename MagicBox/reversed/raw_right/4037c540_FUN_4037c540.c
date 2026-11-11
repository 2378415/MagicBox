// 4037c540  FUN_4037c540  FUN_4037c540  size=118

void FUN_4037c540(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined1 in_PRID;
  int local_30 [12];
  
  FUN_4037bbe8(PTR_DAT_40374dcc,0xffffffff);
  iVar1 = FUN_4037c514(local_30);
  if (local_30[0] == 0) {
    if (param_2 == 0) {
      FUN_4037bd38(PTR_DAT_40374dcc);
      FUN_4037c4a4(param_1,iVar1);
    }
    else {
      bVar2 = false;
      if (param_2 != 0) {
        memw();
        bVar2 = *(int *)*DAT_40374dc4 == 0;
      }
      FUN_4037ba38(*DAT_40374dd0,param_1 - iVar1,bVar2);
      FUN_4037bd38(PTR_DAT_40374dcc);
      uVar3 = rsr(in_PRID);
      FUN_403787f4(uVar3 >> 0xd & 1);
    }
  }
  else {
    FUN_4037bd38(PTR_DAT_40374dcc);
  }
  return;
}


