// 4200d2a4  ESP_PANIC_DETAILS  FUN_4200d2a4  size=881
// strings: CORE | ESP_EXTRA_INFO

int FUN_4200d2a4(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined1 in_PRID;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  undefined4 *local_80;
  int iStack_7c;
  uint uStack_78;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined4 uStack_50;
  int local_4c [7];
  int iStack_30;
  
  uVar11 = (uint)*(ushort *)(param_1 + 0x12);
  if (uVar11 == 1) {
    uVar1 = *(undefined2 *)(param_1 + 0x14);
    (*DAT_42000094)(&local_80,0,0x34);
    local_80 = DAT_42000ce8;
    iStack_7c = DAT_42000cec;
    uStack_78 = uStack_78 & 0xffffff00;
    uStack_70 = 4;
    uStack_6e = FUN_4202d080();
    uStack_58 = DAT_42000cf0;
    uStack_5c = 0;
    uStack_68 = 0;
    uStack_64 = 0x34;
    uStack_60 = 0;
    uStack_52 = 0x28;
    uStack_50 = 0;
    uStack_6c = uVar11;
    uStack_54 = uVar1;
    iVar3 = FUN_4200ceb4(param_1 + 0x15,&local_80);
    if (iVar3 != 0) {
      return -2;
    }
    uVar11 = (uint)*(ushort *)(param_1 + 0x12);
  }
  iStack_30 = 0x34;
  if (uVar11 == 2) {
    iStack_30 = 0;
  }
  local_4c[0] = 0;
  local_4c[1] = 0;
  local_4c[2] = 0;
  FUN_4200cc6c();
  uVar11 = rsr(in_PRID);
  uVar4 = (*(code *)PTR_FUN_42000c90)(uVar11 >> 0xd & 1);
  uVar14 = FUN_4200cc74(uVar4,local_4c,0);
  uVar15 = uVar14 & 0xffffffff00000000;
  if ((int)uVar14 != 0) {
    iVar3 = FUN_4200d908(local_4c,&local_80);
    if (iVar3 == 0) {
      return -3;
    }
    if (local_80 == (undefined4 *)0x0) {
      return -3;
    }
    uVar15 = FUN_4200d12c(param_1,PTR_s_CORE_3c03b0a0_4_42000cf4,1,local_80,iVar3);
    iVar3 = (int)uVar15;
    if (*(short *)(param_1 + 0x12) == 1) {
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    else if (iVar3 < 1) {
      return iVar3;
    }
  }
  puVar2 = PTR_s_CORE_3c03b0a0_4_42000cf4;
  local_80 = (undefined4 *)0x0;
  iStack_7c = 0;
  uStack_78 = 0;
  while( true ) {
    iVar3 = (int)uVar15;
    uVar16 = FUN_4202ea38(&local_80,(int)(uVar15 >> 0x20));
    uVar11 = uStack_78;
    uVar15 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),iVar3);
    if ((int)uVar16 == -1) break;
    if (uStack_78 != 0) {
      uVar13 = rsr(in_PRID);
      iVar12 = (*(code *)PTR_FUN_42000c90)(uVar13 >> 0xd & 1);
      uVar15 = CONCAT44(local_4c,iVar3);
      if (uVar11 != iVar12) {
        uVar16 = FUN_4200cc74(uVar11,local_4c,0);
        uVar15 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),iVar3);
        if ((int)uVar16 != 0) {
          iVar12 = FUN_4200d908(local_4c,local_4c + 3);
          if (iVar12 == 0) {
            return -3;
          }
          if (local_4c[3] == 0) {
            return -3;
          }
          uVar16 = FUN_4200d12c(param_1,puVar2,1);
          iVar12 = (int)uVar16;
          if (*(short *)(param_1 + 0x12) == 1) {
            if (iVar12 < 0) {
              return iVar12;
            }
          }
          else if (iVar12 < 1) {
            return iVar12;
          }
          uVar15 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),iVar3 + iVar12);
        }
      }
    }
  }
  iVar3 = FUN_4200d23c(param_1,iVar3);
  if (iVar3 < 1) {
    return iVar3;
  }
  local_4c[0] = 0;
  local_4c[1] = 0;
  local_4c[2] = 0;
  local_4c[3] = 0;
  local_4c[4] = 0;
  FUN_4200cc6c();
  iVar12 = 0;
  local_80 = (undefined4 *)0x0;
  iStack_7c = 0;
  uStack_78 = 0;
  while( true ) {
    iVar6 = FUN_4202ea38(&local_80);
    if (iVar6 == -1) break;
    iVar6 = FUN_4200cc74(uStack_78,local_4c,local_4c + 3);
    if (iVar6 != 0) {
      iVar6 = FUN_4200d1b4(param_1,local_4c[0],local_4c[0],0x154);
      if (iVar6 < 1) {
        return iVar6;
      }
      local_4c[5] = 0;
      uVar4 = FUN_4200d898(local_4c,local_4c + 6,local_4c + 5);
      iVar5 = FUN_4200d1b4(param_1,local_4c[6],local_4c[5],uVar4);
      iVar6 = iVar6 + iVar5;
      if (iVar5 == -2) {
        return -2;
      }
      if (iVar6 < 1) {
        return iVar6;
      }
      iVar12 = iVar12 + iVar6;
      if (local_4c[4] != 0) {
        iVar6 = FUN_4200d1b4(param_1,local_4c[3],local_4c[3]);
        if (iVar6 < 1) {
          return iVar6;
        }
        iVar12 = iVar12 + iVar6;
      }
    }
  }
  if (iVar12 < 1) {
    return iVar12;
  }
  local_80 = (undefined4 *)0x0;
  iVar5 = 0;
  iVar6 = 0;
  do {
    iVar7 = FUN_4200cd18(iVar5,&local_80);
    if (iVar7 < 0) {
      return -3;
    }
    iVar8 = iVar6;
    if (iVar7 != 0) {
      iVar8 = FUN_4200d1b4(param_1,local_80,local_80,iVar7);
      if (iVar8 < 1) break;
      iVar8 = iVar6 + iVar8;
    }
    iVar5 = iVar5 + 1;
    iVar6 = iVar8;
  } while (iVar5 != 4);
  if (iVar8 < 0) {
    return iVar8;
  }
  local_4c[0] = 0;
  (*DAT_42000ce4)(param_1 + 1,DAT_42000024,0x42);
  uVar9 = FUN_4200d700();
  puVar2 = PTR_s_ESP_CORE_DUMP_INFO_42000cfc;
  uVar4 = DAT_42000cf8;
  *param_1 = uVar9;
  iVar6 = FUN_4200d12c(param_1,puVar2,uVar4,param_1,0x48);
  if (iVar6 < 1) {
    return iVar6;
  }
  iVar5 = FUN_4200da90(local_4c);
  if ((iVar5 == 0) || (local_4c[0] == 0)) {
    return -3;
  }
  iVar5 = FUN_4200d12c(param_1,PTR_s_ESP_EXTRA_INFO_42000d00,0x2a5,local_4c[0],iVar5);
  if (iVar5 < 1) {
    return iVar5;
  }
  iVar5 = iVar5 + iVar6;
  if (*DAT_42000c84 != '\0') {
    iStack_7c = 0;
    uVar11 = uStack_78 >> 8;
    uStack_78 = uStack_78 & 0xffffff00;
    local_80 = param_1;
    if (*(short *)(param_1 + 0x12) == 0) {
      uStack_78 = CONCAT31((int3)uVar11,1);
      FUN_4201a168(PTR_FUN_42000d04,&local_80);
      if (iStack_7c == 0) {
        return -3;
      }
      param_1[0x21] = iStack_7c;
      uVar11 = iStack_7c + 3U & 0xfffffffc;
    }
    else if (*(short *)(param_1 + 0x12) == 2) {
      iVar6 = FUN_4200d0dc(param_1,PTR_s_ESP_PANIC_DETAILS_42000d08,param_1[0x21],0x2a7);
      if ((iVar6 != 0) || (FUN_4201a168(PTR_FUN_42000d04,&local_80,0), iStack_7c == 0)) {
        return -2;
      }
      uVar11 = param_1[0x21] + 3 & 0xfffffffc;
      if (0 < (int)(uVar11 - param_1[0x21])) {
        local_4c[3] = local_4c[3] & 0xff000000;
        iVar6 = FUN_4200ceb4(param_1 + 0x15,local_4c + 3);
        if (iVar6 != 0) {
          return -2;
        }
        uVar11 = param_1[0x21] + 3 & 0xfffffffc;
      }
    }
    else {
      uVar11 = param_1[0x21] + 3 & 0xfffffffc;
    }
    iVar6 = uVar11 + 0x20;
    iVar5 = iVar5 + iVar6;
    if (iVar6 < 1) {
      return iVar6;
    }
  }
  pcVar10 = (char *)*DAT_420002c0;
  if ((pcVar10 != (char *)0x0) && (*pcVar10 != '\0')) {
    uVar4 = (*DAT_4200030c)(pcVar10);
    iVar6 = FUN_4200d12c(param_1,PTR_s_ESP_PANIC_DETAILS_42000d08,0x2a7,pcVar10,uVar4);
    iVar5 = iVar5 + iVar6;
    if (iVar6 < 1) {
      return iVar6;
    }
  }
  iVar6 = FUN_4200d23c(param_1,iVar5);
  if (iVar6 < 1) {
    return iVar6;
  }
  return iVar3 + iVar12 + iStack_30 + iVar8 + iVar6;
}


