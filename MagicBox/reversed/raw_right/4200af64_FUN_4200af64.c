// 4200af64  FUN_4200af64  FUN_4200af64  size=107

undefined4 FUN_4200af64(undefined4 param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = FUN_420246b8();
  uVar4 = *param_2;
  iVar3 = 0;
  if ((uVar4 & 0x1f) != 0) {
    iVar3 = -((uVar4 & 0x1f) - 0x20);
  }
  if ((uint)DAT_420009f8[1] < uVar4 + iVar3 + iVar1) {
    uVar2 = 0x101;
  }
  else {
    *param_2 = uVar4 + iVar3 + iVar1;
    (*DAT_42000240)(param_1,0,0x30);
    uVar4 = *param_2 >> 0xc;
    if ((*param_2 & 0xfff) != 0) {
      uVar4 = uVar4 + 1;
    }
    if ((uint)DAT_420009f8[1] < uVar4 << 0xc) {
      (*(code *)PTR_FUN_4200006c)();
    }
    uVar2 = (*(code *)PTR_FUN_42000a18)(*DAT_420009fc,*DAT_420009f8);
  }
  return uVar2;
}


