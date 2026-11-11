undefined4 FUN_42025004(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2 < 0x7e) {
    puVar1 = (uint *)((param_2 >> 4) * 4 + param_1);
    uVar3 = *puVar1;
    *puVar1 = 3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20) & uVar3 ^ uVar3 |
              param_3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}