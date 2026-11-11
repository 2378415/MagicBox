// 42007adc  FUN_42007adc  FUN_42007adc  size=97

void FUN_42007adc(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar1 = PTR_DAT_420008a0;
  if (param_1 == 0) {
    *(undefined4 *)(PTR_DAT_420008a0 + 0x28) = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    FUN_420200c4(puVar1);
    *(undefined **)(puVar1 + 0x28) = PTR_FUN_420008b4;
    *(undefined4 *)(puVar1 + 0x18) = 1;
  }
  else {
    uVar3 = FUN_420201cc(param_1,PTR_s_r_3c03b628_8_420008bc);
    puVar2 = PTR_DAT_420008c0;
    puVar1 = PTR_DAT_420008a0;
    *(undefined4 *)(PTR_DAT_420008a0 + 4) = uVar3;
    uVar3 = FUN_420201cc(param_1,puVar2);
    puVar2 = PTR_DAT_420008c0;
    *(undefined4 *)(puVar1 + 8) = uVar3;
    uVar3 = FUN_420201cc(param_1,puVar2);
    *(undefined4 *)(puVar1 + 0xc) = uVar3;
    FUN_42020708(puVar1,*(undefined4 *)(puVar1 + 4));
    FUN_42020708(puVar1,*(undefined4 *)(puVar1 + 8));
    FUN_42020708(puVar1,*(undefined4 *)(puVar1 + 0xc));
  }
  return;
}


