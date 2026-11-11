// 42026248  FUN_42026248  FUN_42026248  size=47

int FUN_42026248(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint unaff_retaddr;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  uVar4 = rsr(in_PRID);
  if (1 < (uVar4 >> 0xd & 1)) {
    (*(code *)PTR_FUN_4200006c)();
  }
  do {
    memw();
  } while (*DAT_42001478 == 0);
  FUN_42001cf8();
  FUN_42012b94();
  (*(code *)PTR_FUN_4200147c)();
  (*(code *)PTR_FUN_4200006c)();
  uVar4 = unaff_retaddr >> 6;
  iVar1 = (*(code *)PTR_FUN_42000484)(0x54,unaff_retaddr >> 0xd & 1);
  if (uVar4 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_FUN_42000484)(uVar4 * param_1,param_3);
  }
  if (((iVar1 == 0) || (uVar4 != 0 && iVar2 == 0)) ||
     (iVar3 = (*(code *)PTR_FUN_4200037c)(param_1,uVar4,iVar2,iVar1,0), iVar3 == 0)) {
    (*(code *)PTR_FUN_420008b4)(iVar2);
    (*(code *)PTR_FUN_420008b4)(iVar1);
    iVar3 = 0;
  }
  return iVar3;
}


