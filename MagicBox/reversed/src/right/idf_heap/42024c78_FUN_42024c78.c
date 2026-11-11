undefined4 FUN_42024c78(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 < 0x100) {
    puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
    uVar3 = *puVar1;
    *puVar1 = 1 << 0x20 - (0x20 - (param_2 & 0x1f)) & uVar3 ^ uVar3 |
              (param_3 & 0xff) << 0x20 - (0x20 - (param_2 & 0x1f));
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}