// 4202dfd8  FUN_4202dfd8  FUN_4202dfd8  size=1866
// strings: Pk7@@

/* WARNING: Removing unreachable block (ram,0x4202e386) */
/* WARNING: Removing unreachable block (ram,0x4202e391) */
/* WARNING: Removing unreachable block (ram,0x4202e3c0) */
/* WARNING: Removing unreachable block (ram,0x4202e3c8) */

void FUN_4202dfd8(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  int unaff_retaddr;
  int iVar15;
  int iVar14;
  int iVar13;
  int iVar12;
  int iVar11;
  int iVar10;
  int iVar9;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  
  puVar4 = DAT_42001e2c;
  puVar3 = DAT_42001e28;
  memw();
  memw();
  *DAT_42001e28 = *DAT_42001e28 & DAT_42000534;
  memw();
  memw();
  *puVar4 = *puVar4 & DAT_42000538;
  (*(code *)PTR_FUN_42000554)(0x6d,1,0xd,2,2,0);
  (*(code *)PTR_FUN_42000554)(0x6d,1,0xd,3,3,0);
  puVar5 = DAT_42001e34;
  memw();
  memw();
  *DAT_42001e30 = *DAT_42001e30 & DAT_4200054c;
  memw();
  memw();
  *puVar5 = (uint)(CONCAT44(((uint)param_1 & 0xffffff) >> 0x10,*puVar5 << 8) >> 8);
  puVar2 = DAT_42001e3c;
  memw();
  memw();
  *puVar5 = ((uint)param_1 & 0xff) << 6 | *puVar5 & DAT_42001e38;
  puVar5 = DAT_42001e44;
  memw();
  memw();
  *puVar2 = *puVar2 & DAT_42001e40 | 0x200;
  uVar17 = DAT_42001e48;
  memw();
  memw();
  *puVar5 = *puVar5 & DAT_42001e48 | 0x200;
  memw();
  memw();
  *puVar5 = *puVar5 & 0xfffffe00 | 1;
  memw();
  memw();
  *puVar5 = *puVar5 & 0x1ffffff | DAT_4200059c;
  puVar2 = DAT_42001e50;
  memw();
  memw();
  *puVar5 = *puVar5 & DAT_42001e4c | DAT_42000d30;
  memw();
  memw();
  *puVar2 = *puVar2 & uVar17 | 0x200;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffe00 | 1;
  puVar5 = DAT_42001e54;
  memw();
  memw();
  *DAT_42001e54 = *DAT_42001e54 & uVar17 | 0x200;
  uVar17 = DAT_4200059c;
  memw();
  memw();
  *puVar5 = *puVar5 & 0xfffffe00 | 1;
  memw();
  memw();
  *puVar5 = *puVar5 & 0x1ffffff | uVar17;
  uVar17 = DAT_42000d30;
  memw();
  memw();
  *puVar5 = *puVar5 & DAT_42001e4c | DAT_42000d30;
  memw();
  memw();
  *puVar2 = *puVar2 & 0x1ffffff | DAT_4200059c;
  memw();
  memw();
  *puVar2 = *puVar2 & DAT_42001e4c | uVar17;
  (*(code *)PTR_FUN_42000554)(0x6d,1,5,4,0,0x17);
  (*(code *)PTR_FUN_42000554)(0x6d,1,4,4,0,0x17);
  uVar21 = DAT_42000a7c;
  iVar1 = DAT_420004f0;
  iVar16 = 1;
  memw();
  memw();
  *DAT_42001e58 = *DAT_42001e58 & DAT_42001e5c | DAT_42000a7c;
  if (((uint)param_1 & 0x40000000) != 0) {
    memw();
    if ((*(uint *)(iVar1 + 0x6c) & 3) == 1) {
      memw();
      (*(code *)PTR_FUN_42000554)(0x61,1,6,7,0,*(uint *)(iVar1 + 0x6c) >> 0xd & 0xff);
      (*(code *)PTR_FUN_42000554)(0x61,1,5,6,6,1);
      iVar16 = 1;
      uVar17 = 1;
    }
    else {
      iVar9 = unaff_retaddr + uVar21;
      iVar10 = unaff_retaddr + uVar21;
      iVar11 = unaff_retaddr + uVar21;
      iVar12 = unaff_retaddr + uVar21;
      iVar13 = unaff_retaddr + uVar21;
      iVar14 = unaff_retaddr + uVar21;
      iVar15 = unaff_retaddr + uVar21;
      (*(code *)PTR_FUN_42001ec0)();
      iVar16 = (*(code *)PTR_FUN_42001ec4)();
      uVar18 = 2;
      if ((iVar16 != 1) && (uVar18 = 0, iVar16 == 2)) {
        uVar18 = 1;
      }
      uVar18 = (*(code *)PTR_FUN_420001b0)(uVar18,100);
      uVar22 = (*(code *)PTR_FUN_42001ec8)(DAT_420002a0,0,uVar18);
      uVar23 = (*(code *)PTR_FUN_42000644)();
      iVar16 = (int)uVar22 + (int)uVar23;
      *(int *)(iVar9 + 0x14) = iVar16;
      uVar21 = (int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar23 >> 0x20) + iVar16;
      (*(code *)PTR_FUN_420001f8)(iVar14);
      (*(code *)PTR_FUN_42001ecc)();
      (*(code *)PTR_FUN_42000554)(0x61,1,0,0,0);
      (*(code *)PTR_FUN_42000554)(0x61,1,0,0);
      *(int **)(iVar10 + 0x10) = param_1;
      do {
        uVar17 = (*(code *)PTR_FUN_42001ed0)(0x61,1,3,0);
        iVar16 = (*(code *)PTR_FUN_42001ed0)(0x61,1,3,3);
        uVar22 = (*(code *)PTR_FUN_42000644)();
        uVar20 = (uint)((ulonglong)uVar22 >> 0x20);
        if ((uVar17 != 0) && (iVar16 != 0)) {
          param_1 = *(int **)(iVar11 + 0x10);
          goto LAB_4202e2ea;
        }
      } while ((uVar20 < uVar21) ||
              ((uVar21 == uVar20 && ((uint)uVar22 < *(uint *)(iVar12 + 0x14)))));
      param_1 = *(int **)(iVar13 + 0x10);
      if (1 < *(uint *)PTR_DAT_42000028) {
        uVar18 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_42001e64,uVar18);
      }
LAB_4202e2ea:
      (*(code *)PTR_FUN_42000204)(iVar15);
      (*(code *)PTR_FUN_42001ec0)(0);
    }
  }
  memw();
  memw();
  uVar21 = *(uint *)(iVar1 + 0x50) >> 0x18 & 7;
  if (((uVar21 == 1) || (1 < (*(uint *)(iVar1 + 0x6c) & 3))) ||
     ((1 < uVar21 && ((*(uint *)(iVar1 + 0x6c) & 1) != 0)))) {
    memw();
    rsync();
    uVar20 = *(uint *)(unaff_retaddr + 4);
    for (uVar21 = 10; param_1 = param_1 + 1, uVar21 < uVar20; uVar21 = uVar21 + 1 & 0xff) {
      iVar19 = *param_1;
      if (((iVar19 != 0) && (*(code **)(iVar19 + 0xc) != (code *)0x0)) &&
         (*(char *)(iVar1 + 2) == *(char *)(iVar19 + 0x18))) {
        (**(code **)(iVar19 + 0xc))(uVar17,iVar16,iVar1);
      }
      uVar20 = (uint)(byte)*puVar3;
    }
    return;
  }
  if (3 < *(uint *)PTR_DAT_42000028) {
    uVar18 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42001e80,uVar18,PTR_s_rtcinit_42001e60);
  }
  puVar6 = PTR_DAT_42001e74;
  (*(code *)PTR_FUN_42000554)(0x6d,1,4,4,0,*PTR_DAT_42001e68);
  (*(code *)PTR_FUN_42000554)(0x6d,1,6,4,0,*puVar6);
  puVar5 = DAT_42001e8c;
  if (((uint)param_1 & 0x1000000) != 0) {
    memw();
    memw();
    *DAT_42001e84 = *DAT_42001e84 & 0xfffffffe;
    memw();
    *DAT_42001e88 = 0;
    puVar2 = DAT_42001e90;
    memw();
    memw();
    *puVar5 = *puVar5 & 0xfffffffe;
    puVar5 = DAT_42001e94;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffffe;
    puVar2 = DAT_42001e98;
    memw();
    memw();
    *puVar5 = *puVar5 & 0xfffffffe;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffffe;
  }
  uVar17 = DAT_4200143c;
  if (((uint)param_1 & 0x2000000) != 0) {
    memw();
    memw();
    *DAT_42000878 = *DAT_42000878 & DAT_4200054c;
    puVar5 = DAT_42001e9c;
    if (((uint)param_1 >> 0x1b & 1) == 0 && ((uint)param_1 >> 0x1c & 1) == 0) {
      memw();
      memw();
      *DAT_42001e9c = *DAT_42001e9c & DAT_42000a74;
    }
    else {
      memw();
      memw();
      *DAT_42001e9c = *DAT_42001e9c | DAT_420009f8;
    }
    uVar21 = DAT_4200052c;
    memw();
    memw();
    *DAT_42001e30 = *DAT_42001e30 & DAT_4200052c;
    memw();
    if (((uint)param_1 & 0x10000000) == 0) {
      memw();
      *puVar5 = *puVar5 & DAT_4200164c;
      memw();
      memw();
      *puVar5 = *puVar5 & 0xfffffdff;
      memw();
      memw();
      *puVar5 = *puVar5 & 0xffffff7f;
    }
    else {
      memw();
      *puVar5 = *puVar5 | DAT_420006dc;
      memw();
      memw();
      *puVar5 = *puVar5 | 0x200;
      memw();
      memw();
      *puVar5 = *puVar5 | 0x80;
    }
    puVar2 = DAT_42001ea4;
    puVar5 = DAT_42001ea0;
    memw();
    memw();
    *DAT_42001ea0 = *DAT_42001ea0 & DAT_420019a4;
    uVar20 = DAT_42000544;
    memw();
    memw();
    *puVar2 = *puVar2 & 0x7fffffff;
    uVar17 = DAT_4200143c;
    memw();
    memw();
    *puVar2 = *puVar2 & uVar20;
    memw();
    memw();
    *puVar5 = *puVar5 & 0xfffffffa;
    memw();
    if (((uint)param_1 & 0x4000000) == 0) {
      memw();
      *puVar2 = *puVar2 & DAT_42000538;
    }
    else {
      memw();
      *puVar2 = *puVar2 | uVar17;
    }
    puVar2 = DAT_42001ea8;
    memw();
    memw();
    *DAT_42001e30 = *DAT_42001e30 & uVar21;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffffe;
    (*(code *)PTR_FUN_42001ed4)(0);
    uVar7 = DAT_42001eb0;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_42001eac;
    uVar20 = DAT_42000a70;
    memw();
    memw();
    *puVar4 = *puVar4 & 0x3fffffff;
    uVar8 = DAT_42001eb8;
    memw();
    memw();
    *puVar4 = *puVar4 & uVar7;
    uVar7 = DAT_42001eb4;
    memw();
    memw();
    *puVar3 = *puVar3 & uVar21;
    memw();
    memw();
    *puVar4 = *puVar4 & uVar7;
    uVar21 = DAT_42000294;
    memw();
    memw();
    *puVar3 = *puVar3 & uVar20;
    memw();
    memw();
    *puVar4 = *puVar4 & uVar8;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_42001994;
    memw();
    memw();
    *puVar4 = *puVar4 & DAT_42001ebc;
    memw();
    memw();
    *puVar3 = *puVar3 & uVar21;
    memw();
    memw();
    *puVar5 = *puVar5 & 0xffffffdf;
    memw();
    memw();
    *puVar5 = *puVar5 & 0xffffffef;
    puVar2 = DAT_42001984;
    memw();
    memw();
    *puVar5 = *puVar5 & DAT_420019a4;
    memw();
    if (((uint)param_1 & 0x20000000) == 0) {
      memw();
      *puVar2 = *puVar2 | 8;
    }
    else {
      memw();
      *puVar2 = *puVar2 & 0xfffffff7;
    }
    memw();
    memw();
    *puVar4 = *puVar4 & uVar21;
    memw();
    memw();
    *puVar4 = *puVar4 & uVar20;
  }
  uVar21 = DAT_42000530;
  memw();
  memw();
  *puVar4 = *puVar4 | uVar17;
  memw();
  memw();
  *puVar3 = *puVar3 | uVar21;
  memw();
  *DAT_420006cc = 0;
  memw();
  *DAT_420006d0 = 0xffffffff;
  FUN_4202e730();
  return;
}


