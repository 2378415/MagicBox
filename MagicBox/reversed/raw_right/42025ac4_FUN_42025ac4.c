// 42025ac4  FUN_42025ac4  FUN_42025ac4  size=210
// strings: dh7@

/* WARNING: Removing unreachable block (ram,0x42025b81) */

void FUN_42025ac4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 auStack_30 [48];
  
  (*(code *)PTR_FUN_420013b4)(1);
  iVar1 = (*(code *)PTR_FUN_420013b8)();
  if (iVar1 == 1) {
    uVar5 = 2;
  }
  else if (iVar1 == 2) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  uVar5 = (*(code *)PTR_FUN_42000090)(uVar5,100);
  uVar6 = (*(code *)PTR_FUN_420013bc)(DAT_42000178,0,uVar5);
  uVar7 = (*(code *)PTR_FUN_42000474)();
  iVar1 = (int)((ulonglong)uVar6 >> 0x20) + (int)((ulonglong)uVar7 >> 0x20);
  uVar4 = (int)uVar6 + (uint)uVar7;
  if (uVar4 < (uint)uVar7) {
    iVar1 = iVar1 + 1;
  }
  (*(code *)PTR_FUN_420000dc)(auStack_30);
  (*(code *)PTR_FUN_420013c0)();
  (*(code *)PTR_FUN_420003c4)(0x61,1,0,0,0);
  (*(code *)PTR_FUN_420003c4)(0x61,1,0,0);
  do {
    iVar2 = (*(code *)PTR_FUN_420013c4)(0x61,1,3,0);
    iVar3 = (*(code *)PTR_FUN_420013c4)(0x61,1,3,3);
    uVar8 = (*(code *)PTR_FUN_42000474)();
    if (iVar2 != 0 && iVar3 != 0) break;
  } while (uVar8 < CONCAT44(iVar1,uVar4));
  (*(code *)PTR_FUN_420000e8)(auStack_30);
  (*(code *)PTR_FUN_420013b4)(0);
  return;
}


