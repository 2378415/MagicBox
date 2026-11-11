// 40375ee8  FUN_40375ee8  size=420
// strings:  0x%08lX:0x%08lX |  |<-CORRUPTED |  |<-CONTINUES

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_40375ee8(int param_1,undefined4 param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_40;
  uint uStack_3c;
  int iStack_38;
  int iStack_30;
  
  if (param_1 < 1) {
    return 0x102;
  }
  (*DAT_4037450c)(&local_40,param_2,0x10);
  if (param_3 == '\0') {
    (*DAT_40374438)(PTR_s_Backtrace__4037462c);
    uVar4 = local_40;
    if ((int)local_40 < 0) {
      uVar4 = local_40 & 0x3fffffff | DAT_4037460c;
    }
    (*DAT_40374438)(PTR_s_0x_08lX_0x_08lX_40374638,uVar4 - 3,uStack_3c);
  }
  else {
    (*(code *)PTR_FUN_40374648)();
    uVar4 = uStack_3c;
    uVar3 = local_40;
    if ((int)local_40 < 0) {
      uVar3 = local_40 & 0x3fffffff | DAT_4037460c;
    }
    (*(code *)PTR_FUN_40374648)(PTR_s_0x_3c030f7c_0x48_40374630);
    (*(code *)PTR_FUN_4037464c)(uVar3 - 3);
    (*(code *)PTR_FUN_40374648)(PTR_DAT_40374634);
    (*(code *)PTR_FUN_4037464c)(uVar4);
  }
  uVar4 = DAT_4037460c;
  if (DAT_40374600 < uStack_3c + DAT_403745fc) {
    if (uStack_3c + DAT_40374604 <= DAT_40374608) {
      halt_baddata();
    }
  }
  else if ((uStack_3c & 0xf) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  bVar1 = 1;
  do {
    if (iStack_38 == 0) {
      if (bVar1 != 0) goto LAB_4037607c;
      goto LAB_403760b5;
    }
    if (bVar1 != 0) goto LAB_4037607c;
    bVar1 = FUN_40375e54(&local_40);
    uVar3 = uStack_3c;
    uVar5 = local_40;
    if ((int)local_40 < 0) {
      uVar5 = local_40 & 0x3fffffff | uVar4;
    }
    iStack_30 = uVar5 - 3;
    bVar1 = bVar1 ^ 1;
    if (param_3 == '\0') {
      (*DAT_40374438)(PTR_s_0x_08lX_0x_08lX_40374638,iStack_30,uStack_3c);
    }
    else {
      (*(code *)PTR_FUN_40374648)(PTR_s_0x_3c030f7c_0x48_40374630);
      (*(code *)PTR_FUN_4037464c)(iStack_30);
      (*(code *)PTR_FUN_40374648)(PTR_DAT_40374634);
      (*(code *)PTR_FUN_4037464c)(uVar3);
    }
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  if (bVar1 != 0) {
LAB_4037607c:
    if (param_3 == '\0') {
      (*DAT_40374438)(PTR_s__<_CORRUPTED_4037463c);
      uVar2 = 0xffffffff;
      goto LAB_403760cb;
    }
    (*(code *)PTR_FUN_40374648)();
    uVar2 = 0xffffffff;
    goto LAB_403760bb;
  }
  if (iStack_38 == 0) {
LAB_403760b5:
    if (param_3 == '\0') goto LAB_403760c9;
  }
  else {
    if (param_3 == '\0') {
      (*DAT_40374438)(PTR_s__<_CONTINUES_40374640);
LAB_403760c9:
      uVar2 = 0;
LAB_403760cb:
      (*DAT_40374438)(PTR_DAT_40374644);
      return uVar2;
    }
    (*(code *)PTR_FUN_40374648)();
  }
  uVar2 = 0;
LAB_403760bb:
  (*(code *)PTR_FUN_40374648)(PTR_DAT_40374644);
  return uVar2;
}


