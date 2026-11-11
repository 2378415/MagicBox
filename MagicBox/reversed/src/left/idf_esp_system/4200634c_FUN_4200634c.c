/* WARNING: Type propagation algorithm not settling */

int FUN_4200634c(uint param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == (uint *)0x0) {
    return 0x102;
  }
  if (param_1 == 0x40) {
    memw();
    uVar3 = *DAT_42000780;
    *param_2 = 0;
    uVar2 = uVar3 >> 5;
    uVar3 = uVar3 & 0x10;
  }
  else {
    if (0x40 < param_1) {
      if (param_1 == 0x200) {
        if (*(int *)(PTR_DAT_4200075c + 0xc) == 0) {
          return DAT_4200072c;
        }
        if (param_3 != *(uint *)(PTR_DAT_4200075c + 0x10)) {
          if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
            return DAT_4200072c;
          }
          if (param_3 != *(uint *)(PTR_DAT_4200075c + 0x14)) {
            return DAT_4200072c;
          }
        }
        if (1 < param_3) {
LAB_420064eb:
          iVar1 = FUN_4200775c(7);
          if (iVar1 == 0) {
            *param_2 = 0;
            return 0;
          }
          return iVar1;
        }
        if (param_3 == 0) {
          memw();
          uVar3 = *DAT_42000770 >> 3 & 7;
        }
        else {
          memw();
          uVar3 = *DAT_42000774 >> 3 & 7;
        }
      }
      else {
        if (0x200 < param_1) {
          if (param_1 == 0x400) {
            memw();
            uVar4 = *DAT_42000778;
            uVar3 = uVar4 >> 0xc & 1;
            uVar2 = uVar4 >> 0xd & 1;
            uVar4 = uVar4 >> 0xe & 1;
          }
          else {
            if (param_1 != DAT_420006dc) {
              return DAT_42000728;
            }
            memw();
            uVar4 = *DAT_42000778;
            uVar3 = uVar4 >> 0xf & 1;
            uVar2 = uVar4 >> 0x10 & 1;
            uVar4 = uVar4 >> 0x11 & 1;
          }
          goto code_r0x4200652b;
        }
        if (param_1 == 0x80) {
          memw();
          uVar3 = *DAT_42000780;
          *param_2 = 0;
          uVar2 = uVar3 >> 7;
          uVar3 = uVar3 & 0x40;
          goto joined_r0x42006474;
        }
        if (param_1 != 0x100) {
          return DAT_42000728;
        }
        if (*(int *)(PTR_DAT_4200075c + 0xc) == 0) {
          return DAT_4200072c;
        }
        if (param_3 != *(uint *)(PTR_DAT_4200075c + 0x10)) {
          if (*(int *)(PTR_DAT_4200075c + 0xc) == 1) {
            return DAT_4200072c;
          }
          if (param_3 != *(uint *)(PTR_DAT_4200075c + 0x14)) {
            return DAT_4200072c;
          }
        }
        if (1 < param_3) goto LAB_420064eb;
        if (param_3 == 0) {
          memw();
          uVar3 = *DAT_42000770 & 7;
        }
        else {
          memw();
          uVar3 = *DAT_42000774 >> 6 & 7;
        }
      }
      iVar1 = FUN_4200775c(0);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = uVar3 & 1;
      uVar4 = uVar3 >> 2;
      uVar3 = uVar3 & 2;
code_r0x4200652b:
      uVar3 = uVar2 * 2 | (uint)(uVar3 != 0);
      if (uVar4 != 0) {
        uVar3 = uVar3 | 4;
      }
      *param_2 = uVar3;
      return 0;
    }
    if (param_1 == 8) {
      memw();
      uVar4 = *DAT_42000778;
      uVar3 = uVar4 >> 9 & 1;
      uVar2 = uVar4 >> 10 & 1;
      uVar4 = uVar4 >> 0xb & 1;
      goto code_r0x4200652b;
    }
    if (param_1 < 9) {
      if (param_1 == 2) {
        memw();
        uVar4 = *DAT_42000778;
        uVar3 = uVar4 >> 3 & 1;
        uVar2 = uVar4 >> 4 & 1;
        uVar4 = uVar4 >> 5 & 1;
      }
      else if (param_1 == 4) {
        memw();
        uVar4 = *DAT_42000778;
        uVar3 = uVar4 >> 6 & 1;
        uVar2 = uVar4 >> 7 & 1;
        uVar4 = uVar4 >> 8 & 1;
      }
      else {
        if (param_1 != 1) {
          return DAT_42000728;
        }
        memw();
        uVar4 = *DAT_42000778;
        uVar3 = uVar4 & 1;
        uVar2 = uVar4 >> 1 & 1;
        uVar4 = uVar4 >> 2 & 1;
      }
      goto code_r0x4200652b;
    }
    if (param_1 == 0x10) {
      memw();
      uVar3 = *DAT_42000780;
      *param_2 = 0;
      uVar2 = uVar3 & 2;
      uVar3 = uVar3 & 1;
      goto joined_r0x42006474;
    }
    if (param_1 != 0x20) {
      return DAT_42000728;
    }
    memw();
    uVar3 = *DAT_42000780;
    *param_2 = 0;
    uVar2 = uVar3 >> 3;
    uVar3 = uVar3 & 4;
  }
joined_r0x42006474:
  uVar2 = (uVar2 & 1) * 2;
joined_r0x42006474:
  if (uVar3 == 0) {
    if (uVar2 == 0) {
      return 0;
    }
    *param_2 = 2;
    return 0;
  }
  *param_2 = 1;
  if (uVar2 == 0) {
    return 0;
  }
  *param_2 = 3;
  return 0;
}