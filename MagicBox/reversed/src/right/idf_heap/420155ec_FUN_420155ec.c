undefined4 FUN_420155ec(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = FUN_42016b98(param_2);
  if (*(int *)(param_1 + 8) != 0) {
    iVar4 = *(int *)(param_1 + 4);
    uVar3 = *(uint *)(iVar4 + 8);
    if (uVar3 < 0x1d) {
      *(uint *)(iVar4 + 8) = uVar3 + 1;
      *(uint *)(uVar3 * 4 + iVar4 + 0xc) = param_3 & 0xff | iVar1 << 8;
      return 0;
    }
  }
  iVar4 = (*(code *)PTR_FUN_420006e0)(0x80);
  if (iVar4 == 0) {
    uVar2 = 0x101;
  }
  else {
    FUN_42024e74();
    FUN_42024ec0(param_1,iVar4);
    *(uint *)(iVar4 + 0xc) = param_3 & 0xff | iVar1 << 8;
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
    uVar2 = 0;
  }
  return uVar2;
}