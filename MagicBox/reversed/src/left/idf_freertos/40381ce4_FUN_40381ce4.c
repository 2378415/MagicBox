// strings: assert failed:  | <cached disabled>

void FUN_40381ce4(undefined *param_1,undefined4 param_2,undefined4 *param_3,undefined *param_4)

{
  int unaff_retaddr;
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined **ppuVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  undefined1 auStack_120 [200];
  undefined *local_58 [9];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 auStack_29 [41];
  
  local_34 = (undefined *)0x0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_2a = 0;
  (*DAT_40375298)(param_2,auStack_29,10);
  iVar1 = FUN_403780cc();
  puVar2 = DAT_40374614;
  if (iVar1 == 0) {
    if (param_1 + DAT_403750dc <= DAT_40374614) {
      param_1 = PTR_s_<cached_disabled>_4037529c;
    }
    puVar6 = param_4 + DAT_403750dc;
    if ((undefined *)((int)param_3 + DAT_403750dc) <= DAT_40374614) {
      param_3 = &local_34;
      local_34 = (undefined *)CONCAT22(local_34._2_2_,(short)DAT_403752bc);
      (*DAT_40375298)((int)(CONCAT44(DAT_403752a4 >> 0x1e,unaff_retaddr << 2) >> 2) + -3,
                      (int)&local_34 + 2,0x10);
      if (puVar6 <= puVar2) {
        param_4 = PTR_s_<cached_disabled>_4037529c;
      }
      goto LAB_40381d67;
    }
    if (puVar6 <= DAT_40374614) {
      param_4 = PTR_s_<cached_disabled>_4037529c;
    }
  }
  if (param_3 == (undefined4 *)0x0) {
    param_3 = (undefined4 *)PTR_DAT_403752a0;
  }
LAB_40381d67:
  ppuVar4 = local_58;
  local_58[0] = PTR_s_assert_failed__403752a8;
  local_58[5] = auStack_29;
  local_58[2] = PTR_DAT_403752ac;
  local_58[6] = PTR_DAT_403752b4;
  local_58[1] = (undefined *)param_3;
  local_58[7] = param_4;
  local_58[3] = param_1;
  local_58[4] = PTR_DAT_403752b0;
  local_58[8] = PTR_s___3fc964dc_0x30_403752b8;
  iVar1 = 0;
  uVar5 = 199;
  do {
    puVar2 = *ppuVar4;
    uVar3 = (*DAT_403752c0)(puVar2);
    iVar7 = (uVar5 < uVar3) * uVar5 + (uVar5 >= uVar3) * uVar3;
    uVar5 = uVar5 - iVar7;
    (*DAT_4037450c)(auStack_120 + iVar1,puVar2,iVar7);
    iVar1 = iVar1 + iVar7;
    if (uVar5 == 0) break;
    ppuVar4 = ppuVar4 + 1;
  } while ((undefined **)&local_34 != ppuVar4);
  auStack_120[iVar1] = 0;
  FUN_4037b3a8(auStack_120);
  return;
}