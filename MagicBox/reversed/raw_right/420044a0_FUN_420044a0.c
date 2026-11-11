// 420044a0  FUN_420044a0  FUN_420044a0  size=153

void FUN_420044a0(uint param_1,uint *param_2)

{
  uint uVar1;
  int local_60 [7];
  uint auStack_44 [17];
  
  (*DAT_420002fc)(auStack_44,PTR_DAT_42000534);
  uVar1 = 0;
  do {
    if (6 < uVar1) {
LAB_420044e5:
      *param_2 = auStack_44[0] & 3 | (auStack_44[1] & 3) << 2 | (auStack_44[2] & 3) << 4 |
                 (auStack_44[3] & 3) << 6 | (auStack_44[4] & 3) << 8 | (auStack_44[5] & 3) << 10 |
                 (auStack_44[6] & 3) << 0xc | (param_1 >> 8 & 0xff) << 0xe;
      return;
    }
    (*DAT_420002fc)(local_60,PTR_PTR_42000538,0x1c);
    if (param_1 <= (uint)(local_60[uVar1] + DAT_42000588)) {
      auStack_44[uVar1] = 2;
      goto LAB_420044e5;
    }
    auStack_44[uVar1] = 0;
    uVar1 = uVar1 + 1;
  } while( true );
}


