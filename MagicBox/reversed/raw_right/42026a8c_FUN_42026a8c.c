// 42026a8c  FUN_42026a8c  FUN_42026a8c  size=76

undefined * FUN_42026a8c(uint param_1,int param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 in_PRID;
  
  if (param_1 < 0x20) {
    if ((byte)PTR_DAT_4200153c[param_1] < 4) {
      uVar2 = rsr(in_PRID);
      iVar3 = param_1 * 2 + (uVar2 >> 0xd & 1);
      piVar4 = (int *)(PTR_PTR_42001534 + iVar3 * 8);
      puVar1 = (undefined *)*piVar4;
      if (param_2 == 0) {
        *piVar4 = (int)PTR_FUN_42001538;
        piVar4[1] = iVar3;
      }
      else {
        *piVar4 = param_2;
        piVar4[1] = param_3;
      }
      if (puVar1 == PTR_FUN_42001538) {
        puVar1 = (undefined *)0x0;
      }
    }
    else {
      puVar1 = (undefined *)0x0;
    }
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}


