void FUN_42005e84(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_420006c4;
  if (param_1 == 0) {
    *(undefined4 *)(PTR_DAT_420006c4 + 0x28) = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    FUN_42017694(puVar1);
    *(undefined **)(puVar1 + 0x28) = PTR_FUN_420006d8;
    *(undefined4 *)(puVar1 + 0x18) = 1;
  }
  else {
    uVar2 = FUN_4201779c(param_1,PTR_DAT_420006e4);
    puVar1 = PTR_DAT_420006c4;
    *(undefined4 *)(PTR_DAT_420006c4 + 4) = uVar2;
    uVar2 = FUN_4201779c(param_1,PTR_DAT_420006e8);
    *(undefined4 *)(puVar1 + 8) = uVar2;
    uVar2 = FUN_4201779c(param_1,PTR_DAT_420006e8);
    *(undefined4 *)(puVar1 + 0xc) = uVar2;
    FUN_42017c98(puVar1,*(undefined4 *)(puVar1 + 4));
    FUN_42017c98(puVar1,*(undefined4 *)(puVar1 + 8));
    FUN_42017c98(puVar1,*(undefined4 *)(puVar1 + 0xc));
  }
  return;
}