// 42014970  FUN_42014970  FUN_42014970  size=460
// strings: @4 0D

int FUN_42014970(int param_1,uint param_2,undefined4 param_3,int param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  char cVar11;
  int aiStack_70 [9];
  uint local_4c;
  undefined1 uStack_48;
  undefined1 uStack_47;
  uint uStack_44;
  int iStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  int iStack_30;
  uint uStack_2c;
  
  uStack_3c = param_2 & 0xff;
  uStack_34 = param_6 & 0xff;
  aiStack_70[0] = 0;
  aiStack_70[1] = 0;
  aiStack_70[2] = 0;
  uVar10 = *(int *)(param_1 + 0x30) - 1;
  if (0x7f < uVar10) {
    uVar10 = 0x7f;
  }
  if (uVar10 * 4000 < param_5) {
    iVar5 = DAT_420010a8;
  }
  else {
    iVar2 = 0;
    uVar10 = 0;
    iStack_40 = param_1;
    uStack_38 = param_3;
    iStack_30 = param_4;
    uStack_2c = param_5;
    do {
      while( true ) {
        iVar7 = *(int *)(iStack_40 + 0x14);
        uVar3 = FUN_42015840(iVar7);
        if (uVar10 != 0) break;
        if (uVar3 < uStack_2c) {
          if (399 < uVar3) goto LAB_42014a0c;
        }
        else if (uStack_2c != 0 || uVar3 != 0) break;
        if ((*(int *)(iVar7 + 0xc) != -4) && (iVar7 = FUN_42015820(iVar7), iVar7 != 0)) {
          return iVar7;
        }
        iVar7 = iStack_40;
        iVar5 = FUN_42016820(iStack_40 + 0x10);
        if (iVar5 != 0) {
          return iVar5;
        }
        uVar4 = FUN_42015840(*(undefined4 *)(iVar7 + 0x14));
        if (uVar4 == uVar3) {
          return DAT_420010a4;
        }
      }
      if (uVar3 == 0) {
        iVar5 = DAT_420010a4;
        goto LAB_42014afa;
      }
LAB_42014a0c:
      if (uVar3 < param_5) {
        uVar4 = uVar3;
      }
      else {
        uVar4 = param_5;
      }
      param_5 = param_5 - uVar4;
      iVar5 = FUN_42015ac8(iVar7,uStack_3c,0x42,uStack_38,iStack_30 + iVar2,uVar4,
                           uVar10 + uStack_34 & 0xff);
      uVar8 = uVar10 + 1;
      uVar10 = uVar8 & 0xff;
      if (iVar5 != 0) {
        if (iVar5 == DAT_420010ac) {
          return iVar5;
        }
        goto LAB_42014afa;
      }
      puVar6 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0xc);
      if (puVar6 == (undefined4 *)0x0) {
        iVar5 = 0x101;
        goto LAB_42014afa;
      }
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[2] = iVar7;
      FUN_42024cd4(aiStack_70,puVar6);
      if ((param_5 != 0) || (uVar3 - uVar4 < 0x20)) {
        if ((*(int *)(iVar7 + 0xc) != -4) && (iVar5 = FUN_42015820(iVar7), iVar5 != 0)) {
          goto LAB_42014afa;
        }
        iVar5 = FUN_42016820(iStack_40 + 0x10);
        if (iVar5 != 0) {
          goto LAB_42014afa;
        }
      }
      iVar2 = iVar2 + uVar4;
    } while (param_5 != 0);
    for (puVar9 = &local_4c; puVar9 != &uStack_44; puVar9 = (uint *)((int)puVar9 + 1)) {
      *(undefined1 *)puVar9 = 0xff;
    }
    local_4c = uStack_2c;
    uStack_48 = (undefined1)uVar8;
    uStack_47 = (undefined1)uStack_34;
    iVar5 = FUN_42015ac8(*(undefined4 *)(iStack_40 + 0x14),uStack_3c,0x48,uStack_38,&local_4c,8,0xff
                        );
    if (iVar5 == DAT_420010ac) {
      return iVar5;
    }
LAB_42014afa:
    uVar1 = uStack_38;
    uVar10 = uStack_3c;
    if (iVar5 != 0) {
      cVar11 = '\0';
      for (iVar2 = aiStack_70[0]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
        FUN_42016228(*(undefined4 *)(iVar2 + 8),uVar10,0x42,uVar1,cVar11,0xff);
        cVar11 = cVar11 + '\x01';
      }
    }
    FUN_4201494c(aiStack_70);
  }
  return iVar5;
}


