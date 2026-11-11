// 4201cf28  FUN_4201cf28  FUN_4201cf28  size=395

/* WARNING: Control flow encountered bad instruction data */

int FUN_4201cf28(int param_1,uint param_2,uint param_3,undefined4 param_4,int param_5,uint param_6,
                byte param_7)

{
  int unaff_retaddr;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_a15;
  uint in_stack_00000110;
  uint local_70 [2];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  uStack_2c = (uint)param_7;
  iVar2 = *(int *)(param_1 + 0xc);
  param_3 = param_3 & 0xff;
  if (iVar2 == 0) {
    return DAT_42001a94;
  }
  uStack_30 = param_6;
  if (iVar2 == -1) {
    iVar2 = FUN_4201ccf8(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = *(int *)(param_1 + 0xc);
  }
  if (iVar2 != -4) {
    uVar1 = (*DAT_4200030c)(param_4);
    if (0xf < uVar1) {
      return DAT_42001a98;
    }
    uVar1 = uStack_30;
    uStack_28 = DAT_42001a9c;
    do {
      if (uStack_28 < uVar1) {
        return DAT_42001a58;
      }
      uStack_28 = -((param_3 - 0x41 & 0xff) - 1) & 0xff | (uint)(param_3 - 0x21 == 0);
      iVar2 = 1;
      if (uStack_28 == 0) {
        uVar3 = 0x20;
        if (8 < uVar1) {
          return 0x102;
        }
        goto LAB_4201cfc2;
      }
      uVar1 = in_stack_00000110;
    } while (unaff_retaddr != 1);
    uVar1 = *(uint *)(in_a15 + 4) & param_3 - 0x21;
    uVar3 = uVar1 + 0x20;
    if (uVar1 != 0) {
      iVar2 = (*(uint *)(in_a15 + 4) >> 5) + 1;
    }
LAB_4201cfc2:
    if (*(int *)(param_1 + 0x38) != -1) {
      if (0x7e < (uint)(*(int *)(param_1 + 0x38) + iVar2)) {
        return DAT_42001a60;
      }
      local_70[0] = param_2 & 0xff | param_3 << 8 | (uVar3 >> 5 & 0xff) << 0x10 | uStack_2c << 0x18;
      uStack_68 = 0xffffffff;
      uStack_64 = 0xffffffff;
      uStack_60 = 0xffffffff;
      uStack_5c = 0xffffffff;
      uStack_58 = 0xffffffff;
      uStack_54 = 0xffffffff;
      (*DAT_42000da8)(&uStack_68,param_4,0xf);
      uStack_5c = uStack_5c & 0xffffff;
      (*DAT_42000064)(&local_50,local_70);
      iVar2 = FUN_4201cb6c(param_1 + 0x44,&local_50,*(undefined4 *)(param_1 + 0x38));
      uVar1 = uStack_30;
      if (iVar2 != 0) {
        return iVar2;
      }
      if (uStack_28 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      uStack_34 = FUN_4201e2c0(param_5,uStack_30);
      uStack_38 = (undefined2)uVar1;
      uStack_36 = 0xffff;
      uStack_4c = FUN_4201e26c(&local_50);
      iVar2 = FUN_4201cd64(param_1,&local_50);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar1 = uStack_30 & 0x1f;
      if (uStack_30 != uVar1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (uVar1 == 0) {
        return 0;
      }
      local_50 = 0xffffffff;
      (*DAT_42000064)(&local_50,param_5 + (uStack_30 - uVar1),uVar1);
      iVar2 = FUN_4201cd64(param_1,&local_50);
      return iVar2;
    }
  }
  return DAT_42001a60;
}


