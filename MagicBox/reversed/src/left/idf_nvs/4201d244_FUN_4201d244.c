// strings: 76\F | IDLEipc0ipc1\

/* WARNING: Control flow encountered bad instruction data */

int FUN_4201d244(int param_1,uint param_2,uint param_3,int param_4,uint *param_5,byte *param_6,
                byte param_7,byte param_8)

{
  int unaff_retaddr;
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  ushort *puVar7;
  ushort local_70;
  undefined1 uStack_6e;
  byte bStack_6d;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  uint uStack_4c;
  byte *pbStack_48;
  uint uStack_44;
  uint *puStack_40;
  byte *pbStack_3c;
  byte *pbStack_38;
  uint uStack_34;
  byte *pbStack_30;
  uint *puStack_2c;
  
  puVar7 = &local_70;
  iVar5 = *(int *)(param_1 + 0xc);
  uStack_44 = (uint)param_8;
  uStack_4c = (uint)param_7;
  param_2 = param_2 & 0xff;
  pbStack_48 = (byte *)(param_3 & 0xff);
  if (iVar5 == -0x10 || iVar5 == 0) {
    return DAT_420011bc;
  }
  if (iVar5 == -1) {
    return DAT_420011bc;
  }
  uVar4 = *param_5;
  if (0x7d < uVar4) {
    return DAT_420011bc;
  }
  uVar3 = *(uint *)(param_1 + 0x3c);
  uVar1 = *(uint *)(param_1 + 0x38);
  uVar4 = (uVar4 < uVar3) * uVar3 + (uVar4 >= uVar3) * uVar4;
  uVar1 = (uint)(0x7e < uVar1) * 0x7e + (0x7e >= uVar1) * uVar1;
  iVar5 = 0;
  puVar6 = (undefined1 *)0x0;
  iStack_50 = param_4;
  if ((param_2 != 0xff) && (puVar6 = (undefined1 *)0x0, param_4 != 0)) {
    if (pbStack_48 == (byte *)0x42) {
      iVar5 = 0;
      puVar6 = (undefined1 *)0x0;
      if (uStack_4c == 0xff) goto LAB_4201d2bc;
    }
    local_70 = (ushort)param_2 | (ushort)((int)pbStack_48 << 8);
    bStack_6d = param_7;
    uStack_68 = 0xffffffff;
    uStack_64 = 0xffffffff;
    uStack_60 = 0xffffffff;
    uStack_5c = 0xffffffff;
    uStack_58 = 0xffffffff;
    uStack_54 = 0xffffffff;
    uStack_6e = 0;
    puStack_40 = param_5;
    pbStack_3c = param_6;
    (*DAT_42000da8)(&uStack_68,param_4,0xf);
    uStack_5c = uStack_5c & 0xffffff;
    uVar4 = FUN_4201cc84(param_1 + 0x44,uVar4);
    iVar5 = 0x7d;
    param_6 = pbStack_3c;
    puVar6 = (undefined1 *)puVar7;
    param_5 = puStack_40;
    if (0x7d < uVar4) {
      return DAT_420011bc;
    }
  }
LAB_4201d2bc:
  if (uVar4 < uVar1) {
    if (unaff_retaddr == 0) {
      flix();
    }
    uStack_34 = (uint)(puVar6 == (undefined1 *)0x0);
    pbStack_38 = param_6 + 8;
    pbStack_48 = (byte *)(uint)(puVar6 == (undefined1 *)0x0 && iVar5 != 0);
    puStack_40 = (uint *)uStack_4c;
    pbStack_30 = pbStack_48;
    puStack_2c = param_5;
    do {
      uStack_4c = param_2;
      uVar3 = uVar4 + 1;
      if ((*(uint *)((uVar4 >> 4) * 4 + param_1 + 0x18) >> (uVar4 & 0xf) * 2 & 3) == 2) {
        iVar5 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                          (*(int **)(param_1 + 0x50),
                           *(int *)(param_1 + 8) + 0x40 + (uVar4 & 0xffff) * 0x20,param_6,0x20);
        if (iVar5 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return iVar5;
        }
        pbVar2 = (byte *)FUN_4201e2d4(param_6,uVar4);
        if (pbVar2 == (byte *)0x0) {
          pbStack_3c = pbVar2;
          iVar5 = FUN_4201d0e8(param_1,uVar4);
          if (iVar5 != 0) {
            *(byte **)(param_1 + 0xc) = pbStack_3c;
            return iVar5;
          }
        }
        else {
          pbVar2 = (byte *)(uint)param_6[1];
          if (((-(((uint)(pbVar2 + -0x41) & 0xff) - 1) & 0xff) != 0) || (pbVar2 == (byte *)0x21)) {
            uVar3 = param_6[2] + uVar4;
          }
          if (((uStack_4c == 0xff) || (*param_6 == uStack_4c)) &&
             ((iStack_50 == 0 ||
              (pbStack_3c = pbVar2, iVar5 = (*DAT_42000c68)(iStack_50,pbStack_38,0xf),
              pbVar2 = pbStack_3c, iVar5 == 0)))) {
            if (pbStack_48 == (byte *)0x0) {
              if ((uStack_34 == 0) || (puStack_40 != (uint *)0xff)) {
                if ((pbStack_30 != (byte *)0x41) || (puStack_40 != (uint *)0xff)) {
                  if (pbStack_30 != (byte *)0x48) goto LAB_4201d455;
                  if ((param_6[3] == 0xff) && ((uStack_44 == 0xff || (param_6[0x1d] == uStack_44))))
                  goto LAB_4201d469;
                }
                else {
                  if (pbVar2 == (byte *)0x48) {
                    return DAT_42001aa0;
                  }
                  if (pbVar2 != (byte *)0x42) goto LAB_4201d469;
                }
              }
              else if (pbVar2 == (byte *)0x42) {
LAB_4201d455:
                if (pbStack_30 == (byte *)0xff) goto LAB_4201d48c;
LAB_4201d469:
                if (pbVar2 == pbStack_30) {
LAB_4201d48c:
                  *puStack_2c = uVar4;
                  return 0;
                }
                if (((uStack_4c & (uint)puStack_40) != 0xff) || (iStack_50 != 0)) {
                  *puStack_2c = uVar4;
                  return DAT_42001aa0;
                }
              }
            }
            else if ((uint *)(uint)param_6[3] == puStack_40) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
          }
        }
      }
      uVar4 = uVar3;
      param_2 = uStack_4c;
    } while (uVar3 < uVar1);
  }
  return DAT_420011bc;
}