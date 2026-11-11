/* WARNING: Control flow encountered bad instruction data */

int FUN_4201d748(int param_1,undefined4 param_2)

{
  int unaff_retaddr;
  undefined4 *puVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_90 [16];
  undefined4 uStack_80;
  int iStack_30;
  
  puVar1 = (undefined4 *)local_90;
  uVar6 = *(uint *)(param_1 + 0xc);
  if ((uVar6 + 8 < 7) && ((1 << ((byte)(uVar6 + 8) & 0x1f) & 0x51U) != 0)) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                      (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x20,param_1 + 0x18);
    if (iVar2 != 0) {
LAB_4201da70:
      *(undefined4 *)(param_1 + 0xc) = 0;
      return iVar2;
    }
    uVar6 = *(uint *)(param_1 + 0xc);
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  uVar4 = *(uint *)(param_1 + 0x18) & 3;
  sVar3 = (short)uVar4;
  if (uVar4 == 2) {
    if (*(int *)(param_1 + 0x3c) == -1) {
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
  }
  else {
    if (unaff_retaddr == 0) {
      sVar3 = *(short *)(param_1 + 0x42);
    }
    *(short *)(param_1 + 0x42) = sVar3 + 1;
  }
  uVar4 = 1;
  if (uVar6 == 0xfffffffe) {
    uVar6 = 0;
    if ((~*(uint *)(param_1 + 0x18) & 3) != 0) {
      uVar6 = *(uint *)(param_1 + 0x38);
      goto joined_r0x4201d7ec;
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
    do {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                        (*(int **)(param_1 + 0x50),
                         *(int *)(param_1 + 8) + 0x40 + (uVar6 & 0xffff) * 0x20,&uStack_80,4);
      if (iVar2 != 0) goto LAB_4201da70;
      uVar7 = *(uint *)(param_1 + 0x38);
      if (uStack_80 == -1) {
        uVar4 = (uVar7 < 0x7e) * uVar7 + (uint)(uVar7 >= 0x7e) * 0x7e;
        if (uVar7 == 0) {
          return 0;
        }
        break;
      }
      if (0x7d < uVar7) {
        return -1;
      }
      uVar5 = *(uint *)((uVar7 >> 4) * 4 + param_1 + 0x18);
      iVar2 = FUN_4202d7ec(param_1,uVar7,0);
      if (iVar2 != 0) goto LAB_4201da70;
      uVar6 = *(int *)(param_1 + 0x38) + 1;
      *(uint *)(param_1 + 0x38) = uVar6;
      if ((uVar5 >> (uVar7 & 0xf) * 2 & 3) == 2) {
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
      }
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
joined_r0x4201d7ec:
    } while (uVar6 < 0x7e);
    uVar6 = 0;
    do {
      uVar7 = *(uint *)((uVar6 >> 4) * 4 + param_1 + 0x18) >> (uVar6 & 0xf) * 2 & 3;
      if (uVar7 == 0) {
        uVar7 = 0xffffffff;
      }
      else {
        if (uVar7 == 1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                          (*(int **)(param_1 + 0x50),
                           *(int *)(param_1 + 8) + 0x40 + (uVar6 & 0xffff) * 0x20,
                           (undefined1 *)((int)puVar1 + 0x30),0x20);
        if (iVar2 != 0) goto LAB_4201da70;
        puVar1 = (undefined4 *)((int)puVar1 + unaff_retaddr + -0x60);
        iVar2 = FUN_4201d0e8(param_1,uVar6);
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 0xc) = param_2;
          return iVar2;
        }
        uVar7 = uVar6;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
    if (uVar7 != 0xffffffff) {
      puVar1[1] = 0xff;
      *puVar1 = 0xff;
      puVar1[0x14] = 0;
      iVar2 = FUN_4201d244(param_1,*(undefined1 *)(puVar1 + 0xc),*(undefined1 *)((int)puVar1 + 0x31)
                           ,puVar1 + 0xe,puVar1 + 0x14,puVar1 + 4);
      if (((iVar2 == 0) && ((uint)puVar1[0x14] < uVar7)) &&
         (iVar2 = FUN_4201d0e8(param_1), iVar2 != 0)) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        return iVar2;
      }
    }
  }
  else if (((uVar6 & 0xfffffffb) == 0xfffffff8) && (uVar6 = *(uint *)(param_1 + 0x3c), uVar6 < 0x7e)
          ) {
    do {
      if ((*(uint *)((uVar6 >> 4) * 4 + param_1 + 0x18) >> (uVar6 & 0xf) * 2 & 3) == 2) {
        iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                          (*(int **)(param_1 + 0x50),
                           *(int *)(param_1 + 8) + 0x40 + (uVar6 & 0xffff) * 0x20,&uStack_80,0x20);
        if (iVar2 != 0) goto LAB_4201da70;
        iVar2 = FUN_4201e2d4(&uStack_80,uVar6);
        if (iVar2 != 0) {
          if (uStack_80._2_1_ == '\0') {
            return -1;
          }
          iVar2 = FUN_4201cb6c(param_1 + 0x44,&uStack_80,uVar6);
          if (iVar2 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          goto LAB_4201da70;
        }
        iStack_30 = iVar2;
        iVar2 = FUN_4201d0e8(param_1,uVar6);
        if (iVar2 != 0) {
          *(int *)(param_1 + 0xc) = iStack_30;
          return iVar2;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x7e);
  }
  return 0;
}