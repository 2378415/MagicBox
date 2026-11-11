// strings: chip_generic

undefined4 FUN_4038262c(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_50 [3];
  uint *puStack_44;
  undefined2 uStack_3c;
  undefined1 uStack_3a;
  uint uStack_30;
  uint uStack_2c;
  
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_3a = 0x20;
  local_50[0] = 0x80000;
  puStack_44 = &uStack_30;
  uStack_3c = 0x4b;
  uVar2 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,local_50);
  uVar3 = uStack_2c - 1;
  if (uStack_30 != 0) {
    uVar3 = uStack_2c;
  }
  if ((uVar3 == 0xffffffff) && (0xfffffffd < uStack_30 - 1)) {
    if (*(int *)PTR_DAT_40374414 != 0) {
      uVar2 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_40375330,uVar2,PTR_s_chip_generic_40375328);
    }
    uVar2 = 0x106;
    uVar3 = uStack_2c;
  }
  else {
    uVar1 = (undefined4)(CONCAT44(uStack_30 >> 0x10,uStack_30) >> 8);
    uVar3 = (uint)(CONCAT44(uStack_30,(int)(CONCAT44(uVar1,uVar1) >> 8)) >> 8);
    uVar1 = (undefined4)(CONCAT44(uStack_2c >> 0x10,uStack_2c) >> 8);
    uStack_30 = (uint)(CONCAT44(uStack_2c,(int)(CONCAT44(uVar1,uVar1) >> 8)) >> 8);
  }
  *param_2 = uStack_30;
  param_2[1] = uVar3;
  return uVar2;
}