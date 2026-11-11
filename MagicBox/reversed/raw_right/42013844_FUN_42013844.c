// 42013844  FUN_42013844  FUN_42013844  size=143

void FUN_42013844(undefined4 *param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    memw();
    memw();
    *(uint *)*param_1 = *(uint *)*param_1 & 0xfffffffb;
    iVar1 = DAT_4200004c;
    memw();
    memw();
    *(uint *)(DAT_4200004c + 0x120) = *(uint *)(DAT_4200004c + 0x120) | DAT_420008dc;
    memw();
    memw();
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) | DAT_42000894;
    memw();
    memw();
    *(uint *)*param_1 = *(uint *)*param_1 | DAT_420003b4;
  }
  else {
    memw();
    memw();
    *(uint *)*param_1 = *(uint *)*param_1 | 4;
    iVar1 = DAT_4200004c;
    memw();
    memw();
    *(uint *)(DAT_4200004c + 0x120) = *(uint *)(DAT_4200004c + 0x120) | DAT_420008dc;
    memw();
    memw();
    *(uint *)(iVar1 + 0x120) = *(uint *)(iVar1 + 0x120) & DAT_4200104c;
  }
  return;
}


