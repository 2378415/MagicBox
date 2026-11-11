// 42003f74  FUN_42003f74  FUN_42003f74  size=158

undefined4 FUN_42003f74(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 in_PRID;
  
  iVar1 = DAT_4200045c;
  uVar2 = 0x102;
  if ((param_1 < 2) && (iVar4 = param_1 * 4, *(int *)(param_1 * 4 + DAT_4200045c) != 0)) {
    uVar5 = rsr(in_PRID);
    if ((param_1 == (uVar5 >> 0xd & 1)) && (iVar3 = (*(code *)PTR_FUN_420004b4)(), iVar3 != 2)) {
      return 0x103;
    }
    iVar3 = (*(code *)PTR_FUN_420004c4)(DAT_420004b8 + iVar4,0,param_2);
    uVar2 = 0xffffffff;
    if (iVar3 != 0) {
      memw();
      *(undefined4 *)(DAT_420004bc + iVar4) = param_3;
      memw();
      *(undefined1 *)(DAT_420004c0 + param_1) = 1;
      iVar3 = (*(code *)PTR_FUN_420004c8)();
      uVar2 = *(undefined4 *)(iVar1 + iVar4);
      if (iVar3 == 0) {
        (*(code *)PTR_FUN_4200047c)(uVar2,0x18);
        (*(code *)PTR_FUN_42000484)(*(undefined4 *)(iVar1 + iVar4),0,0,2,0);
      }
      else {
        (*(code *)PTR_FUN_420004cc)(uVar2,0);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


