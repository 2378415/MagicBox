// 42025a48  FUN_42025a48  FUN_42025a48  size=123

void FUN_42025a48(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  memw();
  uVar4 = *(uint *)(DAT_42001384 + 0x6c) & 3;
  if ((1 < uVar4) || (uVar4 == 1)) {
    uVar4 = FUN_420258ec(1);
    iVar2 = FUN_4202595c(1);
    if (iVar2 != 0) {
      uVar5 = iVar2 + 3;
      *(uint *)PTR_DAT_420013a4 = (uVar5 < uVar4) * uVar5 + (uVar5 >= uVar4) * uVar4;
      puVar1 = PTR_DAT_420013a8;
      uVar5 = iVar2 + 2;
      *(uint *)PTR_DAT_420013a8 = (uVar5 < uVar4) * uVar5 + (uVar5 >= uVar4) * uVar4;
      uVar3 = FUN_42025984(1);
      *(undefined4 *)PTR_DAT_420013ac = uVar3;
      uVar3 = FUN_42025984(1,*(undefined4 *)puVar1);
      *(undefined4 *)PTR_DAT_420013b0 = uVar3;
    }
  }
  return;
}


