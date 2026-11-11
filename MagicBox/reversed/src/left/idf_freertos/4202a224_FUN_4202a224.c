// strings: Balloc succeeded

undefined4 FUN_4202a224(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = 0;
  for (iVar3 = 1;
      iVar3 < (int)((longlong)(param_4 + 8) * (longlong)DAT_42001dc4 >> 0x21) -
              (param_4 + 8 >> 0x1f); iVar3 = iVar3 * 2) {
    iVar4 = iVar4 + 1;
  }
  iVar3 = FUN_4202a0d4(param_1,iVar4);
  uVar5 = CONCAT44(iVar3,iVar3);
  if (iVar3 == 0) {
    uVar5 = (*(code *)PTR_FUN_420000a8)
                      (PTR_s__builds_idf_crosstool_NG__build__42001db8,0xd3,0,
                       PTR_s_Balloc_succeeded_42001dc0);
  }
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  *(undefined4 *)((int)uVar5 + 0x10) = 1;
  *(undefined4 *)((int)uVar5 + 0x14) = param_5;
  if (param_3 < 10) {
    pbVar2 = (byte *)(param_2 + 10);
    param_3 = 9;
  }
  else {
    pbVar2 = (byte *)(param_2 + 9);
    do {
      uVar1 = FUN_4202a19c(param_1,uVar1,10,*pbVar2 - 0x30);
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != (byte *)(param_2 + param_3));
    pbVar2 = (byte *)(param_2 + 9) + param_3 + -8;
  }
  for (iVar3 = param_3; iVar3 < param_4; iVar3 = iVar3 + 1) {
    uVar1 = FUN_4202a19c(param_1,uVar1,10,pbVar2[iVar3 - param_3] - 0x30);
  }
  return uVar1;
}