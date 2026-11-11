// strings: assert failed:  | <cached disabled>

void FUN_40381d9c(undefined *param_1,undefined4 param_2,undefined *param_3,undefined *param_4)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined auStack_120 [11];
  undefined1 auStack_115 [200];
  undefined1 auStack_4d [5];
  undefined *local_48 [18];
  
  (*DAT_4037448c)(auStack_120,0,0xb);
  (*DAT_403751dc)(param_2,auStack_4d,10);
  iVar1 = FUN_40377b80();
  if (iVar1 == 0) {
    if ((-(DAT_40374808 + -1) & DAT_40374804) != 0) {
      param_1 = PTR_s_<cached_disabled>_403751e4;
    }
    if ((-(DAT_40374808 + -1) & DAT_40374804) != 0) {
      FUN_40381d6c(auStack_120);
      param_3 = auStack_120;
    }
    if ((-(DAT_40374808 + -1) & DAT_40374804) != 0) {
      param_4 = PTR_s_<cached_disabled>_403751e4;
    }
  }
  local_48[0] = PTR_s_assert_failed__403751ec;
  if (param_3 == (undefined *)0x0) {
    param_3 = PTR_DAT_403751e8;
  }
  local_48[1] = param_3;
  local_48[2] = PTR_DAT_403751f0;
  local_48[3] = param_1;
  local_48[4] = PTR_DAT_403751f4;
  local_48[5] = auStack_4d;
  local_48[6] = PTR_DAT_403751f8;
  local_48[7] = param_4;
  local_48[8] = PTR_s___3fc96084_0x30_403751fc;
  iVar1 = 0;
  uVar4 = 199;
  for (uVar5 = 0; uVar5 < 9; uVar5 = uVar5 + 1) {
    puVar3 = local_48[uVar5];
    uVar2 = (*DAT_40375200)(puVar3);
    iVar6 = (uVar4 < uVar2) * uVar4 + (uVar4 >= uVar2) * uVar2;
    (*DAT_403744d4)(auStack_115 + iVar1,puVar3,iVar6);
    uVar4 = uVar4 - iVar6;
    iVar1 = iVar1 + iVar6;
    if (uVar4 == 0) break;
  }
  auStack_115[iVar1] = 0;
  FUN_4037af90();
  return;
}