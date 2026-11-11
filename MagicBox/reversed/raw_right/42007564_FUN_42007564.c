// 42007564  FUN_42007564  FUN_42007564  size=251

void FUN_42007564(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_4200085c;
  iVar1 = DAT_42000858;
  iVar2 = DAT_4200084c;
  if (param_1 == 1) {
    memw();
    memw();
    *(uint *)(DAT_42000858 + 0x78) = *(uint *)(DAT_42000858 + 0x78) | DAT_42000850;
    iVar2 = DAT_4200015c;
    memw();
    memw();
    *(uint *)(DAT_4200015c + 0x20) = *(uint *)(DAT_4200015c + 0x20) | 0x20;
    memw();
    memw();
    *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xffffffdf;
    memw();
    memw();
    *(uint *)(iVar1 + 0x78) = *(uint *)(iVar1 + 0x78) & DAT_42000854;
  }
  else if (param_1 == 2) {
    memw();
    memw();
    *(uint *)(DAT_4200085c + 0x78) = *(uint *)(DAT_4200085c + 0x78) | DAT_42000850;
    iVar2 = DAT_4200015c;
    memw();
    memw();
    *(uint *)(DAT_4200015c + 0x24) = *(uint *)(DAT_4200015c + 0x24) | 0x200;
    memw();
    memw();
    *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & 0xfffffdff;
    memw();
    memw();
    *(uint *)(iVar3 + 0x78) = *(uint *)(iVar3 + 0x78) & DAT_42000854;
  }
  else if (param_1 == 0) {
    memw();
    memw();
    *(uint *)(DAT_4200084c + 0x78) = *(uint *)(DAT_4200084c + 0x78) | DAT_42000850;
    iVar1 = DAT_4200015c;
    memw();
    memw();
    *(uint *)(DAT_4200015c + 0x20) = *(uint *)(DAT_4200015c + 0x20) | 4;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffb;
    memw();
    memw();
    *(uint *)(iVar2 + 0x78) = *(uint *)(iVar2 + 0x78) & DAT_42000854;
  }
  else {
    (*(code *)PTR_FUN_4200006c)();
  }
  return;
}


