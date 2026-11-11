// strings: abort() was called at PC 0x |  on core 

void FUN_40381c60(void)

{
  int unaff_retaddr;
  undefined1 **ppuVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  undefined1 auStack_70 [52];
  undefined1 *local_3c [4];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_22 = 0;
  uStack_2c = 0;
  uStack_23 = 0;
  (*DAT_403744c4)(auStack_70,0,0x32);
  (*DAT_40375298)((int)(CONCAT44((uint)PTR_FUN_4037528c >> 0x1e,unaff_retaddr << 2) >> 2) + -3,
                  &uStack_2c,0x10);
  uVar3 = rsr(in_PRID);
  (*DAT_40375298)(uVar3 >> 0xd & 1,&uStack_23,10);
  local_3c[1] = (undefined1 *)&uStack_2c;
  local_3c[0] = PTR_s_abort___was_called_at_PC_0x_40375290;
  local_3c[3] = &uStack_23;
  local_3c[2] = PTR_s_on_core_40375294;
  ppuVar1 = local_3c;
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 1;
    (*DAT_40374e04)(auStack_70,*ppuVar1);
    ppuVar1 = ppuVar1 + 1;
  } while (iVar2 != 4);
  FUN_4037b3a8(auStack_70);
  do {
    ill();
  } while( true );
}