// 4201a7d8  FUN_4201a7d8  FUN_4201a7d8  size=157
// strings: clk_hal

uint FUN_4201a7d8(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar1 = DAT_42001980;
  memw();
  uVar4 = *DAT_42001980 >> 10 & 3;
  if (uVar4 == 1) {
    memw();
    memw();
    uVar4 = *DAT_42001984 & 4;
    if ((*DAT_42001984 & 4) == 0) {
      uVar5 = *DAT_42001984 & 3;
      if (uVar5 == 1) {
        uVar4 = DAT_42001978;
      }
      else if (uVar5 == 2) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (1,PTR_s_clk_hal_4200196c,PTR_DAT_42001988,uVar2,PTR_s_clk_hal_4200196c);
      }
      else if (uVar5 == 0) {
        uVar4 = DAT_4200194c;
      }
    }
    else {
      uVar5 = *DAT_42001984 & 3;
      uVar4 = DAT_42001978;
      if (((uVar5 != 1) && (uVar4 = DAT_42001974, uVar5 != 2)) && (uVar4 = DAT_4200194c, uVar5 != 0)
         ) {
        uVar4 = 0;
      }
    }
  }
  else {
    if (uVar4 == 2) {
      uVar4 = DAT_4200197c;
    }
    else {
      if (uVar4 != 0) {
        FUN_4201a748();
      }
      iVar3 = FUN_4201a798();
      uVar4 = iVar3 * DAT_4200087c;
    }
    memw();
    uVar4 = uVar4 / ((*puVar1 & 0x3ff) + 1);
  }
  return uVar4;
}


