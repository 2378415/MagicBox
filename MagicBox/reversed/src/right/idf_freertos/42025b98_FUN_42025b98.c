void FUN_42025b98(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  memw();
  memw();
  *DAT_420013c8 = *DAT_420013c8 & DAT_420003c0;
  memw();
  memw();
  *DAT_420013cc = *DAT_420013cc & DAT_420003c8;
  (*(code *)PTR_FUN_420003c4)(0x6d,1,0xd,2,2,0);
  (*(code *)PTR_FUN_420003c4)(0x6d,1,0xd,3,3,0);
  memw();
  memw();
  *DAT_420013d0 = *DAT_420013d0 & DAT_420003dc;
  puVar2 = DAT_420013d4;
  memw();
  memw();
  *DAT_420013d4 = *DAT_420013d4 & 0xffffff | (param_1 >> 0x10) << 0x18;
  memw();
  memw();
  *puVar2 = *puVar2 & DAT_420013d8 | (param_1 & 0xff) << 6;
  memw();
  memw();
  *DAT_420013dc = *DAT_420013dc & DAT_420013e0 | 0x200;
  uVar4 = DAT_420013ec;
  puVar2 = DAT_420013e8;
  uVar6 = *(uint *)PTR_DAT_420013e4;
  uVar8 = *(uint *)(PTR_DAT_420013e4 + 4);
  uVar7 = *(uint *)(PTR_DAT_420013e4 + 8);
  memw();
  memw();
  *DAT_420013e8 = *DAT_420013e8 & DAT_420013ec | (uVar6 & 0x7f) << 9;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffe00 | uVar6 >> 7 & 0x1ff;
  uVar1 = DAT_4200021c;
  memw();
  memw();
  *puVar2 = *puVar2 & DAT_4200021c | (uVar6 >> 0x10) << 0x19;
  uVar5 = DAT_420013f0;
  memw();
  memw();
  *puVar2 = *puVar2 & DAT_420013f0 | (uVar6 >> 0x17) << 0x10;
  puVar2 = DAT_420013f4;
  memw();
  memw();
  *DAT_420013f4 = *DAT_420013f4 & uVar4 | (uVar8 >> 0x10 & 0x7f) << 9;
  memw();
  memw();
  *puVar2 = *puVar2 & 0xfffffe00 | uVar8 >> 0x17;
  puVar3 = DAT_420013f8;
  memw();
  memw();
  *DAT_420013f8 = *DAT_420013f8 & uVar4 | (uVar8 & 0x7f) << 9;
  memw();
  memw();
  *puVar3 = *puVar3 & 0xfffffe00 | uVar8 >> 7 & 0x1ff;
  memw();
  memw();
  *puVar3 = *puVar3 & uVar1 | uVar7 << 0x19;
  memw();
  memw();
  *puVar3 = *puVar3 & uVar5 | (uVar7 >> 7 & 0x1ff) << 0x10;
  memw();
  memw();
  *puVar2 = *puVar2 & uVar1 | (uVar7 >> 0x10) << 0x19;
  memw();
  memw();
  *puVar2 = *puVar2 & uVar5 | (uVar7 >> 0x17) << 0x10;
  (*(code *)PTR_FUN_420003c4)(0x6d,1,5,4,0,0x17);
  (*(code *)PTR_FUN_420003c4)(0x6d,1,4,4,0,0x17);
  memw();
  memw();
  *DAT_420013fc = *DAT_420013fc & DAT_42001400 | DAT_42000894;
  if ((param_1 & 0x40000000) != 0) {
    memw();
    if ((*(uint *)(DAT_42001384 + 0x6c) & 3) == 1) {
      FUN_420258a0();
    }
    else {
      FUN_42025ac4();
    }
  }
  FUN_42025a48();
  (*(code *)PTR_FUN_420003c4)(0x6d,1,4,4,0,*PTR_DAT_420013b0);
  (*(code *)PTR_FUN_420003c4)(0x6d,1,6,4,0,*PTR_DAT_420013a8);
  if ((param_1 & 0x1000000) != 0) {
    memw();
    memw();
    *DAT_42001404 = *DAT_42001404 & 0xfffffffe;
    memw();
    *DAT_42001408 = 0;
    memw();
    memw();
    *DAT_4200140c = *DAT_4200140c & 0xfffffffe;
    memw();
    memw();
    *DAT_42001410 = *DAT_42001410 & 0xfffffffe;
    memw();
    memw();
    *DAT_42001414 = *DAT_42001414 & 0xfffffffe;
    memw();
    memw();
    *DAT_42001418 = *DAT_42001418 & 0xfffffffe;
  }
  if ((param_1 & 0x2000000) != 0) {
    memw();
    memw();
    *DAT_42000694 = *DAT_42000694 & DAT_420003dc;
    if ((param_1 >> 0x1b & 1) == 0 && (param_1 >> 0x1c & 1) == 0) {
      memw();
      memw();
      *DAT_4200141c = *DAT_4200141c & DAT_4200088c;
    }
    else {
      memw();
      memw();
      *DAT_4200141c = *DAT_4200141c | DAT_42000804;
    }
    memw();
    memw();
    *DAT_420013d0 = *DAT_420013d0 & DAT_420003b8;
    puVar2 = DAT_4200141c;
    if ((param_1 & 0x10000000) == 0) {
      memw();
      memw();
      *DAT_4200141c = *DAT_4200141c & DAT_42000df0;
      memw();
      memw();
      *puVar2 = *puVar2 & 0xfffffdff;
      memw();
      memw();
      *puVar2 = *puVar2 & 0xffffff7f;
    }
    else {
      memw();
      memw();
      *DAT_4200141c = *DAT_4200141c | DAT_420004fc;
      memw();
      memw();
      *puVar2 = *puVar2 | 0x200;
      memw();
      memw();
      *puVar2 = *puVar2 | 0x80;
    }
    puVar2 = DAT_42001420;
    memw();
    memw();
    *DAT_42001420 = *DAT_42001420 & DAT_4200104c;
    puVar3 = DAT_42001424;
    memw();
    memw();
    *DAT_42001424 = *DAT_42001424 & 0x7fffffff;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_420003d4;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffffa;
    if ((param_1 & 0x4000000) == 0) {
      memw();
      memw();
      *DAT_42001424 = *DAT_42001424 & DAT_420003c8;
    }
    else {
      memw();
      memw();
      *DAT_42001424 = *DAT_42001424 | DAT_42001344;
    }
    uVar1 = DAT_420003b8;
    memw();
    memw();
    *DAT_420013d0 = *DAT_420013d0 & DAT_420003b8;
    memw();
    memw();
    *DAT_42001428 = *DAT_42001428 & 0xfffffffe;
    (*(code *)PTR_FUN_42001440)(0);
    puVar2 = DAT_420013c8;
    memw();
    memw();
    *DAT_420013c8 = *DAT_420013c8 & DAT_4200142c;
    puVar3 = DAT_420013cc;
    memw();
    memw();
    *DAT_420013cc = *DAT_420013cc & 0x3fffffff;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_42001430;
    memw();
    memw();
    *puVar2 = *puVar2 & uVar1;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_42001434;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_42000888;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_42001438;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_4200103c;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_4200143c;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_4200016c;
    puVar2 = DAT_42001420;
    memw();
    memw();
    *DAT_42001420 = *DAT_42001420 & 0xffffffdf;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xffffffef;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_4200104c;
    if ((param_1 & 0x20000000) == 0) {
      memw();
      memw();
      *DAT_42001024 = *DAT_42001024 | 8;
    }
    else {
      memw();
      memw();
      *DAT_42001024 = *DAT_42001024 & 0xfffffff7;
    }
    puVar2 = DAT_420013cc;
    memw();
    memw();
    *DAT_420013cc = *DAT_420013cc & DAT_4200016c;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_42000888;
  }
  memw();
  memw();
  *DAT_420013cc = *DAT_420013cc | DAT_42001344;
  memw();
  memw();
  *DAT_420013c8 = *DAT_420013c8 | DAT_420003bc;
  memw();
  *DAT_420004ec = 0;
  memw();
  *DAT_420004f0 = 0xffffffff;
  FUN_42026140();
  return;
}