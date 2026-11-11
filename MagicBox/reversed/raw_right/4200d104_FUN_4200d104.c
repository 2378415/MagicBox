// 4200d104  FUN_4200d104  FUN_4200d104  size=633

undefined4 FUN_4200d104(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint auStack_2c [11];
  
  bVar1 = param_2[4];
  if ((*param_2 & 3) == 0) {
    uVar6 = 0;
  }
  else {
    bVar2 = param_2[1];
    if (bVar2 == 1) {
      if (bVar1 == 1) {
        uVar3 = *(ushort *)(param_2 + 2);
        if (uVar3 == 0x10) {
          memw();
          *(undefined1 *)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8) = 0;
          uVar6 = 0;
        }
        else if (uVar3 < 0x11) {
          if (uVar3 == 2) {
            uVar6 = 0;
          }
          else if (uVar3 == 8) {
            FUN_4200c198(param_1,0);
            uVar6 = 0;
          }
          else if (uVar3 == 1) {
            puVar7 = (uint *)(*(int *)(param_1 + 8) + 0x440);
            memw();
            memw();
            *puVar7 = *puVar7 & 0xfffffffb;
            uVar6 = 0;
          }
          else {
            uVar6 = 0xfffffffb;
          }
        }
        else if (uVar3 == 0x13) {
          memw();
          *(undefined1 *)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8 + 2) = 0;
          uVar6 = 0;
        }
        else if (uVar3 < 0x14) {
          if (uVar3 == 0x11) {
            memw();
            *(undefined1 *)((uint)*(byte *)(param_1 + 0xc) * 0xc4 + DAT_42000af8 + 1) = 0;
            uVar6 = 0;
          }
          else if (uVar3 == 0x12) {
            uVar6 = 0;
          }
          else {
            uVar6 = 0xfffffffb;
          }
        }
        else if (uVar3 == 0x14) {
          uVar6 = 0;
        }
        else {
          uVar6 = 0xfffffffb;
        }
      }
      else {
        uVar6 = 0xfffffffe;
      }
    }
    else if (bVar2 == 3) {
      if (bVar1 == 1) {
        sVar4 = *(short *)(param_2 + 2);
        if (sVar4 == 4) {
          FUN_4200c8a4(param_1,1);
          uVar6 = 0;
        }
        else if (sVar4 == 8) {
          FUN_4200c198(param_1,1);
          uVar6 = 0;
        }
        else if (sVar4 == 2) {
          uVar6 = 0;
        }
        else {
          uVar6 = 0xfffffffb;
        }
      }
      else {
        uVar6 = 0xfffffffe;
      }
    }
    else if (bVar2 == 0) {
      if (bVar1 == 1) {
        memw();
        uVar8 = *(uint *)(*(int *)(param_1 + 8) + 0x440);
        memw();
        auStack_2c[0] = 0;
        uVar9 = (uint)*(byte *)(param_1 + 0xc);
        memw();
        if (*(char *)(uVar9 * 0xc4 + DAT_42000af8) != '\0') {
          auStack_2c[0] = DAT_42000a8c;
        }
        memw();
        if (*(char *)(uVar9 * 0xc4 + DAT_42000af8 + 1) != '\0') {
          auStack_2c[0] = auStack_2c[0] | DAT_420003bc;
        }
        memw();
        if (*(char *)(uVar9 * 0xc4 + DAT_42000af8 + 2) != '\0') {
          auStack_2c[0] = auStack_2c[0] | DAT_42000894;
        }
        memw();
        if ((uVar8 & 1) != 0) {
          auStack_2c[0] = auStack_2c[0] | 1;
        }
        memw();
        if ((uVar8 & 4) != 0) {
          auStack_2c[0] = auStack_2c[0] | 2;
          iVar5 = FUN_42024764(param_1,1);
          if (iVar5 == 1) {
            auStack_2c[0] = auStack_2c[0] | 0x200;
          }
          else {
            iVar5 = FUN_42024764(param_1,1);
            if (iVar5 == 3) {
              auStack_2c[0] = auStack_2c[0] | 0x400;
            }
          }
        }
        memw();
        if ((uVar8 & 0x10) != 0) {
          auStack_2c[0] = auStack_2c[0] | 8;
        }
        memw();
        if ((uVar8 & 0x100) != 0) {
          auStack_2c[0] = auStack_2c[0] | 0x10;
        }
        memw();
        if ((uVar8 & 0x1000) != 0) {
          auStack_2c[0] = auStack_2c[0] | 0x100;
        }
        (*DAT_420002fc)(param_3,auStack_2c);
        uVar6 = 0;
      }
      else {
        uVar6 = 0xfffffffe;
      }
    }
    else {
      uVar6 = 0;
    }
  }
  return uVar6;
}


