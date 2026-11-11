// 420106bc  FUN_420106bc  size=702

/* WARNING: Control flow encountered bad instruction data */

void FUN_420106bc(undefined4 param_1,uint param_2,int param_3,char *param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_190;
  undefined4 local_90;
  undefined1 auStack_8c [76];
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  uStack_40 = param_2 & 0xff;
  if (param_3 == 0) {
    return;
  }
  iVar7 = *(int *)(param_3 + 0x210);
  if (iVar7 == 0) {
    return;
  }
  local_190 = 0;
  uStack_3c = iVar7 + 0x100;
  bVar1 = *(byte *)(iVar7 + 0x1d6);
  uVar8 = (uint)bVar1;
  bVar3 = param_5 != 0;
  if ((uVar8 != param_5) && (bVar3)) {
    return;
  }
  bVar2 = *(byte *)(param_3 + 0x52c);
  if (*(char *)(param_3 + 0x20c) == '\0') {
    if (!bVar3 || param_4 == (char *)0x0) {
      param_4 = (char *)(param_3 + 0x219);
    }
  }
  else {
    if (!bVar3 || param_4 == (char *)0x0) {
      param_4 = (char *)(param_3 + 0x219);
    }
    else if (*param_4 != *(char *)(iVar7 + 0x1d5)) {
      return;
    }
    if (uVar8 != 0) {
      memw();
      memw();
      memw();
      local_190 = (uint)*(byte *)(*(int *)(param_3 + 0x210) + 0x1d5);
      (*DAT_42000064)((int)&local_190 + 1,param_4 + 1,uVar8 - 1);
      goto LAB_42010768;
    }
  }
  (*DAT_42000064)(&local_190,param_4,uVar8);
LAB_42010768:
  memw();
  memw();
  memw();
  if (*(char *)(param_3 + 0x52d) == '\0') {
    uVar12 = (uint)*(byte *)(param_3 + 0x20c) * 8;
    uVar9 = uStack_3c;
    if (*(byte *)(uStack_3c + 0xb4) != 0) {
      uVar11 = uVar8 * 8;
      uVar10 = uVar12 + *(int *)(iVar7 + 0x1b0);
      if (uVar10 < uVar11) {
        uVar13 = *(byte *)(uStack_3c + 0xb4) + uVar10;
        uVar13 = (uVar13 < uVar11) * uVar13 + (uVar13 >= uVar11) * uVar11;
        uVar11 = uVar13 + 7;
        uVar10 = uVar10 >> 3;
        uVar14 = uVar11 >> 3;
        if (uVar10 < uVar14) {
          uStack_2c = uStack_3c;
          uStack_3c = uVar14;
          uStack_38 = uVar12;
          uStack_34 = uVar13;
          uStack_30 = uVar11;
          (*DAT_42000094)((int)&local_190 + uVar10,0,uVar14 - uVar10);
          uVar11 = uStack_30;
          uVar9 = uStack_2c;
          uVar12 = uStack_38;
          uVar13 = uStack_34;
        }
        if ((uVar11 & 0xfffffff8) != uVar13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
    if (*(byte *)(uVar9 + 0xbc) != 0) {
      uVar11 = uVar8 * 8;
      uVar10 = uVar12 + *(int *)(iVar7 + 0x1b8);
      if (uVar10 < uVar11) {
        uVar13 = *(byte *)(uVar9 + 0xbc) + uVar10;
        uVar13 = (uVar13 < uVar11) * uVar13 + (uVar13 >= uVar11) * uVar11;
        uVar11 = uVar13 + 7;
        uVar10 = uVar10 >> 3;
        uVar14 = uVar11 >> 3;
        if (uVar10 < uVar14) {
          uStack_3c = uVar14;
          uStack_38 = uVar12;
          uStack_34 = uVar13;
          uStack_30 = uVar11;
          uStack_2c = uVar9;
          (*DAT_42000094)((int)&local_190 + uVar10,0,uVar14 - uVar10);
          uVar11 = uStack_30;
          uVar9 = uStack_2c;
          uVar12 = uStack_38;
          uVar13 = uStack_34;
        }
        if ((uVar11 & 0xfffffff8) != uVar13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
    if (*(byte *)(uVar9 + 0xc4) != 0) {
      uVar10 = uVar8 * 8;
      uVar12 = uVar12 + *(int *)(iVar7 + 0x1c0);
      if (uVar12 < uVar10) {
        uVar9 = *(byte *)(uVar9 + 0xc4) + uVar12;
        uVar9 = (uVar9 < uVar10) * uVar9 + (uVar9 >= uVar10) * uVar10;
        uVar10 = uVar9 + 7;
        uVar12 = uVar12 >> 3;
        uVar11 = uVar10 >> 3;
        if (uVar12 < uVar11) {
          uStack_3c = uVar11;
          uStack_38 = uVar9;
          uStack_34 = uVar10;
          (*DAT_42000094)((int)&local_190 + uVar12,0,uVar11 - uVar12);
          uVar9 = uStack_38;
          uVar10 = uStack_34;
        }
        if ((uVar10 & 0xfffffff8) != uVar9) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
  }
  FUN_4200fe10(param_3,&local_190,uVar8);
  iVar5 = FUN_4200fcb4(param_3,&local_190,uVar8);
  if (iVar5 == 0) {
    memw();
    memw();
    *DAT_42000e04 = 0;
    memw();
  }
  else {
    uVar6 = FUN_4202d108(&local_190,uVar8,*(undefined1 *)(param_3 + 0x20c),
                         *(undefined4 *)(param_3 + 0x210));
    (*(code *)PTR_spinlock_acquire_420004dc)(PTR_DAT_42000ea0,0xffffffff);
    uVar9 = -(bVar2 - 1);
    (*DAT_42000064)(param_3 + (uVar9 & 0xff) * 0x100 + 0x321,&local_190,uVar8);
    puVar4 = PTR_DAT_42000ea4;
    *(uint *)(param_3 + (uVar9 & 0xff) * 4 + 0x524) = uVar8;
    iVar5 = (*DAT_42000114)(&local_190,puVar4,uVar8);
    *(bool *)(param_3 + 800) = iVar5 == 0;
    (*DAT_42000064)(param_3 + 0x219,&local_190,uVar8);
    puVar4 = PTR_DAT_42000ea0;
    *(uint *)(param_3 + 0x31c) = uVar8;
    *(undefined4 *)(iVar7 + 0x1e4) = uVar6;
    (*(code *)PTR_vPortExitCritical_420004e0)(puVar4);
    *(char *)(param_3 + 0x52c) = -(*(char *)(param_3 + 0x52c) + -1);
    local_90 = (uStack_40 & 0xff) << 8;
    local_90 = (uint)CONCAT12(bVar1,(undefined2)local_90);
    (*DAT_42000064)(auStack_8c,&local_190,uVar8);
    FUN_42014610(&local_90);
    if (*DAT_42000e64 != 0) {
      (*(code *)PTR_xQueueGenericSend_42000488)(*DAT_42000e64,0,0);
    }
    memw();
    memw();
    *DAT_42000e04 = 0;
    memw();
  }
  return;
}


