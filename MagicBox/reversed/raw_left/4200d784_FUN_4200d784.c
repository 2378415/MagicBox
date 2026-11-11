// 4200d784  FUN_4200d784  FUN_4200d784  size=100

/* WARNING: Control flow encountered bad instruction data */

uint FUN_4200d784(uint *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int unaff_retaddr;
  uint uVar3;
  
  uVar2 = DAT_4200036c;
  iVar1 = DAT_42000368;
  uVar3 = param_1[1];
  if (DAT_42000d28 < uVar3 + DAT_42000d24) {
    if (DAT_4200036c < uVar3 + DAT_42000368) {
      *param_1 = uVar3;
      if (uVar2 != 0) {
        param_1[0x14] = param_1[0x14] + 0x40;
      }
      *(uint *)(iVar1 + 0x94) = param_2 & 0xff;
      return 0;
    }
    *(uint **)(unaff_retaddr + 4) = param_1;
    if ((uint)((int)param_1 + iVar1) <= uVar2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  else if ((uVar3 & 0xf) == 0) {
    if (param_1[2] + DAT_4200074c <= DAT_42000d2c) {
      halt_baddata();
    }
    if (param_1[2] + DAT_42000368 <= DAT_4200036c) {
      return -(DAT_42000d30 + -1) & 0xff;
    }
  }
  return 0;
}


