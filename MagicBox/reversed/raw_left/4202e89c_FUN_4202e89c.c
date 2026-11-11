// 4202e89c  FUN_4202e89c  FUN_4202e89c  size=167
// strings: app_start | \d7@L

int FUN_4202e89c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined *in_a12;
  undefined1 in_PRID;
  undefined8 uVar6;
  
  uVar5 = rsr(in_PRID);
  if ((uVar5 >> 0xd & 1) < 2) {
    do {
      memw();
    } while (*DAT_42001f24 == 0);
    FUN_4200327c();
    FUN_42019c30();
    if (3 < *(uint *)PTR_DAT_42000028) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar5 = rsr(in_PRID);
      in_a12 = PTR_s_app_start_42001f18;
      (*DAT_42000060)(PTR_DAT_42001f28,uVar1,PTR_s_app_start_42001f18,uVar5 >> 0xd & 1);
    }
    (*(code *)PTR_FUN_42001f2c)();
  }
  uVar6 = (*(code *)PTR_FUN_42000330)();
  uVar1 = FUN_4201dcf0;
  cust0();
  iVar2 = (*(code *)PTR_FUN_42000660)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),in_a12 + 4);
  if (param_2 == 0) {
    iVar4 = 0;
    iVar3 = iVar2;
  }
  else {
    iVar4 = (*(code *)PTR_FUN_42000660)(param_2 * param_1,uVar1);
    iVar3 = iVar4;
    if (iVar2 == 0) goto LAB_4202e934;
  }
  if (iVar3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_FUN_420004ac)(param_1,param_2,iVar4,iVar2,0);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
LAB_4202e934:
  (*(code *)PTR_FUN_42000a4c)(iVar4);
  (*(code *)PTR_FUN_42000a4c)(iVar2);
  return 0;
}


