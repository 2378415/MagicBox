int FUN_4201be2c(int param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  undefined1 uStack_70;
  byte bStack_6f;
  byte bStack_53;
  undefined1 *apuStack_50 [4];
  undefined1 *puStack_40;
  int iStack_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  
  iVar7 = *(int *)(param_1 + 0x10);
  iStack_3c = param_1;
  iStack_38 = param_5;
  uStack_34 = param_6;
  if (param_3 == (undefined1 *)0x41) {
    puStack_40 = &uStack_70;
joined_r0x4201be4f:
    if (iVar7 == 0) {
      bVar4 = false;
      iVar7 = 0;
      uVar8 = 0;
      bVar5 = 0;
    }
    else {
      apuStack_50[0] = (undefined1 *)0x0;
      puVar1 = (undefined1 *)
               FUN_4201d244(iVar7,param_2,0x48,param_4,apuStack_50,puStack_40,0xff,0xff);
      if (puVar1 != (undefined1 *)0x0) goto LAB_4201be92;
      puStack_30 = puVar1;
      iVar2 = FUN_4201bd2c(iStack_3c,param_2,param_4,iStack_38,uStack_34);
      puVar1 = puStack_30;
      if (iVar2 == 0) {
        return 0;
      }
      if (0xfffffffd < *(int *)(iVar7 + 0xc) - 1U) {
        iVar7 = *(int *)(iStack_3c + 0x10);
        while( true ) {
          if (iVar7 == 0) {
            return DAT_420011bc;
          }
          apuStack_50[0] = puVar1;
          iVar2 = FUN_4201d244(iVar7,param_2,0x41,param_4,apuStack_50,puStack_40,0xff,0xff);
          if (iVar2 == 0) break;
          iVar7 = *(int *)(iVar7 + 4);
        }
      }
      bVar5 = bStack_53 & 0x7f;
      if ((bStack_53 & 0x7f) != 0) {
        return -1;
      }
      uVar8 = 0x80;
      if (bStack_53 == 0x80) {
        uVar8 = 0;
      }
      bVar4 = true;
      if (bStack_53 == 0x80) {
        bVar5 = 0x80;
      }
    }
    iVar2 = FUN_4201b9b8(iStack_3c,param_2,param_4,iStack_38,uStack_34,uVar8);
    if (iVar2 == DAT_42001a60) {
      return DAT_42001a5c;
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (bVar4) {
      if (*(int *)(iStack_3c + 100) != 1) {
        return DAT_42001a70;
      }
      iVar7 = FUN_4201b2ec(iStack_3c,param_2,param_4,bVar5);
      if (iVar7 == DAT_42001a74) {
        return DAT_42001a6c;
      }
      return iVar7;
    }
    iVar2 = *(int *)(iStack_3c + 0x10);
    if (iVar2 != 0) {
      puStack_40 = (undefined1 *)0x0;
      iStack_38 = iVar7;
      do {
        apuStack_50[0] = puStack_40;
        iVar7 = FUN_4201d244(iVar2,param_2,0x41,param_4,apuStack_50,&uStack_70,0xff,0xff);
        if (iVar7 == 0) goto LAB_4201c07e;
        iVar2 = *(int *)(iVar2 + 4);
      } while (iVar2 != 0);
      iVar7 = iStack_38;
    }
  }
  else {
    puStack_40 = param_3;
    if (iVar7 != 0) {
      puStack_40 = &uStack_70;
      puStack_30 = param_3;
      do {
        apuStack_50[0] = (undefined1 *)0x0;
        iVar2 = FUN_4201d244(iVar7,param_2,0xff,param_4,apuStack_50,puStack_40,0xff,0xff);
        if (iVar2 == 0) {
          puStack_40 = puStack_30;
          if ((undefined1 *)(uint)bStack_6f == puStack_30) {
            iVar2 = FUN_4201d5e0(iVar7,param_2,puStack_30,param_4,iStack_38,uStack_34,0xff,0xff);
            if (iVar2 == 0) {
              return 0;
            }
          }
          goto LAB_4201bff4;
        }
        iVar7 = *(int *)(iVar7 + 4);
      } while (iVar7 != 0);
      puStack_40 = puStack_30;
    }
    iVar7 = 0;
LAB_4201bff4:
    iVar6 = *(int *)(iStack_3c + 0x14);
    iVar3 = FUN_4201cf28(iVar6,param_2,puStack_40,param_4,iStack_38,uStack_34,0xff);
    iVar2 = DAT_42001a60;
    if (iVar3 == DAT_42001a60) {
      if ((*(int *)(iVar6 + 0xc) != -4) && (iVar3 = FUN_4201dcf0(iVar6), iVar3 != 0)) {
        return iVar3;
      }
      iVar3 = FUN_4201ddd0(iStack_3c + 0x10);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = FUN_4201cf28(*(undefined4 *)(iStack_3c + 0x14),param_2,puStack_40,param_4,iStack_38,
                           uStack_34,0xff);
      if (iVar3 == iVar2) {
        return DAT_42001a5c;
      }
    }
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  iVar2 = iVar7;
  if (iVar7 == 0) {
    return 0;
  }
LAB_4201c07e:
  if (0xfffffffd < *(int *)(iVar2 + 0xc) - 1U) {
    iVar2 = *(int *)(iStack_3c + 0x10);
    puStack_40 = &uStack_70;
    while( true ) {
      if (iVar2 == 0) {
        return DAT_420011bc;
      }
      apuStack_50[0] = (undefined1 *)0x0;
      iVar7 = FUN_4201d244(iVar2,param_2,0xff,param_4,apuStack_50,puStack_40,0xff,0xff);
      if (iVar7 == 0) break;
      iVar2 = *(int *)(iVar2 + 4);
    }
  }
  iVar7 = FUN_4201d70c(iVar2,param_2,0xff,param_4,0xff);
  if (iVar7 == DAT_42001a74) {
    return DAT_42001a6c;
  }
  return iVar7;
LAB_4201be92:
  iVar7 = *(int *)(iVar7 + 4);
  goto joined_r0x4201be4f;
}