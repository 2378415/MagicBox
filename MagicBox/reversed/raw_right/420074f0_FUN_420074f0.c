// 420074f0  FUN_420074f0  FUN_420074f0  size=112

void FUN_420074f0(int param_1,uint param_2)

{
  if (param_1 == 1) {
    memw();
    memw();
    *(uint *)(DAT_4200015c + 0x18) =
         *(uint *)(DAT_4200015c + 0x18) & 0xffffffdf | (param_2 & 1) << 5;
  }
  else if (param_1 == 2) {
    memw();
    memw();
    *(uint *)(DAT_4200015c + 0x1c) =
         *(uint *)(DAT_4200015c + 0x1c) & 0xfffffdff | (param_2 & 1) << 9;
  }
  else if (param_1 == 0) {
    memw();
    memw();
    *(uint *)(DAT_4200015c + 0x18) =
         *(uint *)(DAT_4200015c + 0x18) & 0xfffffffb | (param_2 & 1) << 2;
  }
  else {
    (*(code *)PTR_FUN_4200006c)();
  }
  return;
}


