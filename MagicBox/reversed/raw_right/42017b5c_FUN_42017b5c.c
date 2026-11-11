// 42017b5c  FUN_42017b5c  FUN_42017b5c  size=115

int FUN_42017b5c(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *local_c0 [2];
  int iStack_b8;
  undefined2 uStack_b4;
  undefined2 uStack_b2;
  undefined1 *puStack_b0;
  int iStack_ac;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined4 uStack_50;
  undefined1 auStack_40 [12];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_20 [32];
  
  uStack_34 = param_4;
  uStack_30 = param_5;
  uStack_2c = param_6;
  puVar1 = (undefined4 *)(*(code *)PTR_FUN_420006f0)();
  if (param_2 < 0) {
    *puVar1 = 0x8b;
    iVar2 = -1;
  }
  else {
    uStack_b4 = 0x208;
    iStack_b8 = 0;
    if (param_2 != 0) {
      iStack_b8 = param_2 + -1;
    }
    uStack_b2 = 0xffff;
    puStack_58 = auStack_20;
    puStack_54 = auStack_40;
    uStack_50 = 0xc;
    local_c0[0] = param_1;
    puStack_b0 = param_1;
    iStack_ac = iStack_b8;
    iVar2 = FUN_42018690(puVar1,local_c0,param_3,puStack_58,puStack_54,0xc);
    if (iVar2 < -1) {
      *puVar1 = 0x8b;
    }
    if (param_2 != 0) {
      *local_c0[0] = 0;
    }
  }
  return iVar2;
}


