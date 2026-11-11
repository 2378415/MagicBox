int FUN_42015ac8(int param_1,undefined1 param_2,char param_3,undefined4 param_4,int param_5,
                uint param_6,byte param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 local_70 [4];
  undefined4 uStack_6c;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined4 uStack_54;
  undefined1 auStack_50 [32];
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  
  puVar5 = local_70;
  uStack_2c = (uint)param_7;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar2 = DAT_420010e0;
  }
  else {
    uStack_30 = param_6;
    iStack_28 = param_5;
    if (*(int *)(param_1 + 0xc) == -1) {
      iVar2 = FUN_420156fc(param_1);
      if (iVar2 != 0) goto LAB_42015c8e;
    }
    if (*(int *)(param_1 + 0xc) == -4) {
      iVar2 = DAT_420010ac;
    }
    else {
      uVar3 = (*DAT_420001e4)(param_4);
      if (uVar3 < 0x10) {
        if (DAT_420010e4 < param_6) {
          iVar2 = DAT_420010a8;
        }
        else {
          bVar1 = param_3 == '!' || param_3 == 'A';
          if (((bVar1) || (param_3 == 'B')) || (param_6 < 9)) {
            if ((bVar1) || (param_3 == 'B')) {
              uVar3 = uStack_30 + 0x1f & 0xffffffe0;
              uVar6 = uVar3 + 0x20;
              iVar4 = (uStack_30 + 0x1f >> 5) + 1;
              if ((uVar3 != 0) && ((param_3 != '!' && param_3 != 'A' && (param_3 != 'B')))) {
                return DAT_420010a8;
              }
            }
            else {
              iVar4 = 1;
              uVar6 = 0x20;
            }
            iVar2 = DAT_420010ac;
            if ((*(int *)(param_1 + 0x38) != -1) &&
               ((uint)(*(int *)(param_1 + 0x38) + iVar4) < 0x7f)) {
              FUN_42015668(auStack_50,param_2,param_3,uVar6 >> 5 & 0xff,param_4,uStack_2c);
              (*DAT_420002fc)(local_70,auStack_50,0x20);
              iVar2 = FUN_420155ec(param_1 + 0x44,local_70,*(undefined4 *)(param_1 + 0x38));
              uVar3 = uStack_30;
              if (iVar2 == 0) {
                if ((bVar1) || (param_3 == 'B')) {
                  uStack_54 = FUN_42016bc0(iStack_28,uStack_30);
                  uStack_58 = (undefined2)uVar3;
                  uStack_56 = 0xffff;
                  uStack_6c = FUN_42016b6c(local_70);
                  iVar2 = FUN_420158c0(param_1,local_70);
                  if (iVar2 == 0) {
                    uVar6 = uVar3 & 0x1f;
                    if ((uVar3 == uVar6) ||
                       (iVar4 = FUN_42015a48(param_1,iStack_28,uVar3 - uVar6), iVar4 == 0)) {
                      if (uVar6 != 0) {
                        for (; puVar5 != auStack_50; puVar5 = puVar5 + 1) {
                          *puVar5 = 0xff;
                        }
                        (*DAT_420002fc)(local_70,iStack_28 + (uVar3 - uVar6),uVar6);
                        iVar2 = FUN_420158c0(param_1,local_70);
                      }
                    }
                    else {
                      iVar2 = iVar4;
                    }
                  }
                }
                else {
                  (*DAT_420002fc)(&uStack_58,iStack_28,uStack_30);
                  uStack_6c = FUN_42016b6c(local_70);
                  iVar2 = FUN_420158c0(param_1,local_70);
                }
              }
            }
          }
          else {
            iVar2 = 0x102;
          }
        }
      }
      else {
        iVar2 = DAT_420010e8;
      }
    }
  }
LAB_42015c8e:
  return iVar2;
}