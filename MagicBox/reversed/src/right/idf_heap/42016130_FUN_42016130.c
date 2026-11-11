// strings: Pe `

int FUN_42016130(int param_1,undefined1 param_2,uint param_3,undefined4 param_4,int param_5,
                uint param_6,undefined1 param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uStack_80;
  undefined1 auStack_7c [2];
  byte bStack_7a;
  ushort auStack_64 [2];
  int iStack_60;
  undefined1 auStack_5c [44];
  int iStack_30;
  
  uVar4 = param_3 & 0xff;
  uStack_80 = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = DAT_420010e0;
  }
  else {
    iStack_30 = param_5;
    iVar1 = FUN_42015dbc(param_1,param_2,uVar4,param_4,&uStack_80,auStack_7c,param_7,param_8);
    if (iVar1 == 0) {
      if ((uVar4 == 0x21 || uVar4 == 0x41) || (uVar4 == 0x42)) {
        uVar4 = (uint)auStack_64[0];
        if (param_6 < uVar4) {
          iVar1 = DAT_42001094;
        }
        else {
          iVar3 = iStack_30;
          uVar6 = uStack_80;
          while (uVar6 = uVar6 + 1, uVar6 < bStack_7a + uStack_80) {
            iVar2 = FUN_42024fd8(param_1,uVar6,auStack_5c);
            if (iVar2 != 0) {
              return iVar2;
            }
            if (uVar4 < 0x20) {
              uVar5 = uVar4;
            }
            else {
              uVar5 = 0x20;
            }
            (*DAT_420002fc)(iVar3,auStack_5c,uVar5);
            uVar4 = uVar4 - uVar5;
            iVar3 = iVar3 + uVar5;
          }
          iVar3 = FUN_42016bc0(iStack_30,auStack_64[0]);
          if ((iVar3 != iStack_60) && (iVar1 = FUN_42015c90(param_1,uStack_80), iVar1 == 0)) {
            iVar1 = DAT_42000cd4;
          }
        }
      }
      else if (param_6 == (param_3 & 0xf)) {
        (*DAT_420002fc)(iStack_30,auStack_64,param_6);
      }
      else {
        iVar1 = DAT_420010ec;
      }
    }
  }
  return iVar1;
}