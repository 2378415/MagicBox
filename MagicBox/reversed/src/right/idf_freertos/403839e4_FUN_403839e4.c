longlong FUN_403839e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     uint param_5,undefined4 param_6)

{
  undefined4 unaff_retaddr;
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 unaff_a8;
  int unaff_a9;
  uint unaff_a10;
  undefined4 unaff_a11;
  int in_a13;
  uint uVar5;
  char in_WindowBase;
  undefined1 in_WindowStart;
  int local_c;
  
  iVar1 = rsr(in_WindowBase);
  uVar5 = iVar1 + 1U & 0x1f;
  uVar2 = rsr(in_WindowStart);
  uVar3 = uVar2 << 0x20 - uVar5;
  if (-1 < (int)uVar3) {
    return CONCAT44(uVar3,1);
  }
  uVar2 = uVar2 >> uVar5 | uVar3 >> 0x10;
  wsr(in_WindowStart,uVar2 >> 0x20 - (LZCOUNT(-uVar2 & uVar2) & 0x1fU));
  iVar1 = rsr(in_WindowBase);
  puVar4 = (undefined4 *)((iVar1 + 0x1f) - LZCOUNT(-uVar2 & uVar2));
  wsr(in_WindowBase,puVar4);
  rsync();
  uVar2 = rsr(in_WindowStart);
  while( true ) {
    while( true ) {
      while( true ) {
        if (uVar2 == 0) {
          uVar2 = rsr(in_WindowBase + '\x01');
          wsr(in_WindowStart,1 << 0x20 - (0x20 - (uVar2 & 0x1f)));
          rsync();
          return ZEXT48(puVar4) << 0x20;
        }
        if ((uVar2 & 1) == 0) break;
        puVar4 = (undefined4 *)(unaff_a9 - 0x10);
        *puVar4 = param_3;
        *(int *)(unaff_a9 + -0xc) = param_4;
        *(uint *)(unaff_a9 + -8) = param_5;
        *(undefined4 *)(unaff_a9 + -4) = param_6;
        param_5 = uVar2 >> 1;
        in_WindowBase = in_WindowBase + '\x01';
      }
      if ((uVar2 & 2) == 0) break;
      *(undefined4 *)(in_a13 + -0x10) = param_3;
      *(int *)(in_a13 + -0xc) = param_4;
      *(uint *)(in_a13 + -8) = param_5;
      *(undefined4 *)(in_a13 + -4) = param_6;
      iVar1 = *(int *)(param_4 + -0xc);
      puVar4 = (undefined4 *)(iVar1 - 0x20);
      *puVar4 = unaff_a8;
      *(int *)(iVar1 + -0x1c) = unaff_a9;
      *(uint *)(iVar1 + -0x18) = unaff_a10;
      *(undefined4 *)(iVar1 + -0x14) = unaff_a11;
      unaff_a10 = uVar2 >> 2;
      in_WindowBase = in_WindowBase + '\x02';
    }
    if ((uVar2 & 4) == 0) break;
    *(undefined4 *)(in_a13 + -0x10) = unaff_retaddr;
    *(BADSPACEBASE **)(in_a13 + -0xc) = register0x00000004;
    *(uint *)(in_a13 + -8) = uVar2;
    *(undefined4 **)(in_a13 + -4) = puVar4;
    puVar4 = (undefined4 *)(local_c - 0x30);
    *puVar4 = param_3;
    *(int *)(local_c + -0x2c) = param_4;
    *(uint *)(local_c + -0x28) = param_5;
    *(undefined4 *)(local_c + -0x24) = param_6;
    *(undefined4 *)(local_c + -0x20) = unaff_a8;
    *(int *)(local_c + -0x1c) = unaff_a9;
    *(uint *)(local_c + -0x18) = unaff_a10;
    *(undefined4 *)(local_c + -0x14) = unaff_a11;
    in_WindowBase = in_WindowBase + '\x03';
  }
  uVar2 = uVar2 * 2 + 1;
  uVar3 = rsr(in_WindowBase);
  if ((uVar2 & 0x8000) == 0) {
    do {
      uVar3 = uVar3 - 1;
      uVar2 = uVar2 << 1;
    } while ((uVar2 & 0x8000) == 0);
    uVar3 = uVar3 & 0xf;
  }
  iVar1 = 0x20 - (uVar3 & 0x1f);
  wsr(in_WindowStart,(uint)(CONCAT44(uVar2,uVar2 << 0x10) >> iVar1) & 0xffff);
  iVar1 = rsr((char)iVar1);
  wsr(in_WindowBase,0x20 - iVar1);
  rsync();
  return CONCAT44(0x20 - iVar1,2);
}