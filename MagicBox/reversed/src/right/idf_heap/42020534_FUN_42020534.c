// strings: pk7@

int FUN_42020534(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_120 [128];
  undefined1 *apuStack_a0 [2];
  undefined4 uStack_98;
  ushort uStack_94;
  undefined2 uStack_92;
  undefined1 *puStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_78;
  undefined4 auStack_48 [3];
  undefined4 uStack_3c;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  apuStack_a0[0] = auStack_120;
  puStack_90 = auStack_120;
  uStack_94 = *(ushort *)(param_2 + 0xc) & 0xfffd;
  uStack_3c = *(undefined4 *)(param_2 + 100);
  uStack_92 = *(undefined2 *)(param_2 + 0xe);
  uStack_80 = *(undefined4 *)(param_2 + 0x20);
  uStack_98 = 0x80;
  uStack_78 = *(undefined4 *)(param_2 + 0x28);
  uStack_8c = 0x80;
  uStack_88 = 0;
  local_30 = param_4;
  uStack_2c = param_5;
  uStack_28 = param_6;
  (*(code *)PTR_FUN_42001188)(auStack_48);
  iVar1 = FUN_4201e8ac(param_1,apuStack_a0,param_3,local_30,uStack_2c,uStack_28);
  if ((-1 < iVar1) && (iVar2 = FUN_4201742c(param_1,apuStack_a0), iVar2 != 0)) {
    iVar1 = -1;
  }
  if ((uStack_94 & 0x40) != 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x40;
  }
  (*(code *)PTR_FUN_42001160)(auStack_48[0]);
  return iVar1;
}