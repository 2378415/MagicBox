// 4037c768  FUN_4037c768  FUN_4037c768  size=71

void FUN_4037c768(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_4037bf44(PTR_DAT_40374e74,0xffffffff);
  uVar2 = DAT_40374e7c;
  piVar1 = DAT_40374e78;
  if (*DAT_40374e78 == 0) {
    FUN_4037cbbc(DAT_40374e7c);
    uVar3 = DAT_40374e80;
    FUN_4037cbbc(DAT_40374e80);
    uVar4 = DAT_40374e8c;
    *DAT_40374e84 = uVar2;
    uVar2 = DAT_40374e90;
    *DAT_40374e88 = uVar3;
    iVar5 = FUN_4037b55c(10,0x10,uVar2,uVar4,0);
    *piVar1 = iVar5;
  }
  FUN_4037c094(PTR_DAT_40374e74);
  return;
}


