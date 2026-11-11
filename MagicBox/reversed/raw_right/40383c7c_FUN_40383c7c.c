// 40383c7c  FUN_40383c7c  FUN_40383c7c  size=65
// strings: K3G3

void FUN_40383c7c(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_SCOMPARE1;
  undefined1 in_PRID;
  
  puVar2 = PTR_DAT_40374790;
  piVar3 = (int *)(PTR_DAT_4037478c + param_2 * 0x10);
  piVar4 = piVar3 + 4;
  uVar5 = rsil(3);
  do {
    wsr((char)in_SCOMPARE1,0);
    rsync();
    uVar6 = rsr(in_PRID);
    iVar1 = *(int *)puVar2;
    if (iVar1 == in_SCOMPARE1) {
      *(undefined4 *)puVar2 = uVar6;
    }
  } while (iVar1 != 0);
  do {
    if (param_1 == *piVar3) {
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
  } while (piVar3 < piVar4);
  *(undefined4 *)PTR_DAT_40374790 = 0;
  wsr(0,uVar5);
  return;
}


