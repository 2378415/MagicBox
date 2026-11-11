// strings: Unknown

void FUN_42003880(int param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_t0;
  undefined1 in_PRID;
  uint local_50 [2];
  undefined *puStack_48;
  undefined4 uStack_40;
  undefined *puStack_3c;
  int iStack_34;
  undefined1 uStack_30;
  
  local_50[0] = 0;
  uVar4 = rsr(in_PRID);
  uVar4 = uVar4 >> 0xd & 1;
  *(int *)(uVar4 * 4 + DAT_42000344) = param_1;
  if (param_2 == 0) {
LAB_42003905:
    FUN_42003468(1000);
    (*DAT_420002b8)(1);
    if ((uVar4 != 0) && ((*(code *)PTR_FUN_4200037c)(0), uVar4 == 1)) goto LAB_42003929;
  }
  else {
    iVar2 = FUN_4202ce58(param_1);
    if ((iVar2 == 5) && (uVar4 == 1)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar2 = FUN_4202ce58(param_1);
    if ((iVar2 == 6) && (uVar4 == 0)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar2 = FUN_4202ce58(param_1);
    if (iVar2 != 7) goto LAB_42003905;
    iVar2 = FUN_4200319c();
    if (iVar2 != -1) {
      uVar3 = FUN_4200319c();
      if (uVar3 != uVar4) {
        *(undefined4 *)(DAT_42000344 + uVar4 * 4) = 0;
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      goto LAB_42003905;
    }
    if (uVar4 != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    FUN_42003468(1000);
    (*DAT_420002b8)(1);
  }
  (*(code *)PTR_FUN_4200037c)(1);
LAB_42003929:
  (*(code *)PTR_FUN_42000380)();
  if ((DAT_420002ec & 1) != 0) {
    uVar4 = FUN_4202ce50(param_1);
    uVar4 = uVar4 & 0x3fffffff | DAT_4200034c;
    if ((((((-(DAT_42000354 + -1) & 0xffU) == 0) && ((-(DAT_4200035c + -1) & 0xffU) == 0)) &&
         (DAT_42000360 < uVar4 - DAT_4200034c)) && (DAT_4200036c < uVar4 + DAT_42000368)) ||
       (uVar4 = FUN_4202ce50(param_1), uVar4 <= DAT_42000348)) {
      uVar4 = FUN_4202ce60(param_1,PTR_DAT_42000364);
    }
    param_1 = in_t0 + param_3;
    if ((uVar4 == 5) || (iVar2 = FUN_4202ce58(param_1), iVar2 == 6)) {
      puVar1 = PTR_DAT_42000370;
      (*DAT_42000174)(PTR_DAT_42000370);
      (*DAT_42000384)(puVar1);
      (*DAT_4200017c)(puVar1);
    }
  }
  uVar4 = rsr(in_PRID);
  local_50[0] = uVar4 >> 0xd & 1;
  local_50[1] = 4;
  uStack_40 = 0;
  puStack_48 = PTR_s_Unknown_42000374;
  uVar4 = FUN_4202ce48(param_1,local_50);
  uStack_30 = (undefined1)(param_2 | uVar4);
  if (((param_2 | uVar4) & 0xff) == 0) {
    FUN_42003d4c(param_1,local_50);
  }
  else {
    FUN_42003d84();
  }
  puStack_3c = PTR_FUN_42000378;
  iStack_34 = param_1;
  FUN_420034e8(local_50);
  return;
}