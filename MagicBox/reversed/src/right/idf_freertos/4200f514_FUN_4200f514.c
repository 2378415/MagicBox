// strings: &6@&Fi

void FUN_4200f514(void)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_40;
  uint uStack_3c;
  uint uStack_30;
  
  uVar3 = 0;
  uVar5 = 0;
  uVar7 = 0;
  do {
    while( true ) {
      do {
        iVar4 = (*(code *)PTR_FUN_42000b6c)(*DAT_42000d00,&local_40,0xffffffff);
      } while (iVar4 == 0);
      if (local_40 == 0) break;
      if (local_40 - 2U < 2) {
        FUN_420090ec(1);
        (*(code *)PTR_FUN_42000d10)(*DAT_42000d00,0);
        uVar3 = 0;
        uVar5 = 0;
        uVar7 = 0;
      }
    }
    uVar6 = uStack_3c;
    if ((int)DAT_420004fc < (int)uStack_3c) {
      uVar6 = DAT_420004fc;
    }
    iVar4 = FUN_42008fb4(1,DAT_42000d04,uVar6,0xffffffff);
    for (iVar8 = 0; pbVar2 = DAT_42000d08, iVar8 < iVar4; iVar8 = iVar8 + 1) {
      bVar1 = *(byte *)(DAT_42000d04 + iVar8);
      uVar6 = (uint)bVar1;
      if (uVar7 == 2) {
        uVar7 = 3;
        uVar5 = uVar6;
      }
      else if (uVar7 < 3) {
        if (uVar7 == 0) {
          if (uVar6 == 0x5a) {
            (*DAT_42000240)(DAT_42000d08,0,DAT_42000424);
            *pbVar2 = bVar1;
            uVar7 = 1;
            uVar3 = 0;
            uVar5 = 0;
          }
        }
        else if (uVar7 == 1) {
          DAT_42000d08[1] = bVar1;
          uVar7 = 2;
        }
        else {
          uVar7 = 0;
        }
      }
      else if (uVar7 == 3) {
        uVar5 = uVar5 | uVar6 << 8;
        *(short *)(DAT_42000d08 + 2) = (short)uVar5;
        if (uVar5 == 0) {
          frame_forward(pbVar2);
          uVar7 = 0;
        }
        else if (DAT_420004fc < uVar5) {
          uVar7 = 0;
        }
        else {
          uVar3 = 0;
          uVar7 = 4;
        }
      }
      else if (uVar7 == 4) {
        if (uVar3 < 0x800) {
          uStack_30 = uVar3 + 1 & 0xffff;
          *(byte *)(uVar3 + DAT_42000d0c) = bVar1;
          if (uVar5 == uStack_30) {
            frame_forward(DAT_42000d08);
            uVar7 = 0;
            uVar3 = uStack_30;
          }
          else {
            uVar3 = uStack_30;
          }
        }
        else {
          uVar7 = 0;
        }
      }
      else {
        uVar7 = 0;
      }
    }
  } while( true );
}