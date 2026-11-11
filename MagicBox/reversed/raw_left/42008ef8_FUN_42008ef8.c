// 42008ef8  FUN_42008ef8  FUN_42008ef8  size=78

undefined4 FUN_42008ef8(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(PTR_DAT_42000a30 + (param_1 * 5 + param_3) * 4);
  uVar1 = 0;
  if ((((~uVar3 & DAT_42000a34) != 0) && ((uVar3 & 0x7fff) != DAT_42000a38)) &&
     (uVar2 = (uint)(short)((int)(uVar3 << 0x11) >> 0x11), uVar2 == param_2)) {
    if ((param_1 < 3) &&
       (FUN_42018570(uVar2 & 0xff,(int)(uVar3 << 0xd) >> 0x1c,0), (uVar3 & 0x80000) != 0)) {
      FUN_42018538(uVar2,uVar3 >> 0x14);
    }
    uVar1 = 1;
  }
  return uVar1;
}


