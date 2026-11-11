// 42006058  FUN_42006058  FUN_42006058  size=748

undefined4 FUN_42006058(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_2 & 2;
  uVar5 = param_2 & 4;
  if (param_1 == 0x40) {
    memw();
    uVar5 = param_2 & 1;
    if (uVar4 != 0) {
      uVar5 = param_2 & 1 | 2;
    }
    memw();
    *DAT_42000780 = uVar5 << 4 | *DAT_42000780 & 0xffffffcf;
  }
  else if (param_1 < 0x41) {
    if (param_1 == 8) {
      uVar1 = param_2 & 1;
      if (uVar4 != 0) {
        uVar1 = param_2 & 1 | 2;
      }
      memw();
      if (uVar5 != 0) {
        uVar1 = uVar1 | 4;
      }
      memw();
      *DAT_42000778 = uVar1 << 9 | *DAT_42000778 & DAT_4200077c;
    }
    else if (param_1 < 9) {
      if (param_1 == 2) {
        uVar1 = param_2 & 1;
        if (uVar4 != 0) {
          uVar1 = param_2 & 1 | 2;
        }
        memw();
        if (uVar5 != 0) {
          uVar1 = uVar1 | 4;
        }
        memw();
        *DAT_42000778 = uVar1 << 3 | *DAT_42000778 & 0xffffffc7;
      }
      else if (param_1 == 4) {
        uVar1 = param_2 & 1;
        if (uVar4 != 0) {
          uVar1 = param_2 & 1 | 2;
        }
        memw();
        if (uVar5 != 0) {
          uVar1 = uVar1 | 4;
        }
        memw();
        *DAT_42000778 = uVar1 << 6 | *DAT_42000778 & 0xfffffe3f;
      }
      else {
        if (param_1 != 1) {
          return 0x106;
        }
        uVar1 = param_2 & 1;
        if (uVar4 != 0) {
          uVar1 = param_2 & 1 | 2;
        }
        memw();
        if (uVar5 != 0) {
          uVar1 = uVar1 | 4;
        }
        memw();
        *DAT_42000778 = *DAT_42000778 & 0xfffffff8 | uVar1;
      }
    }
    else if (param_1 == 0x10) {
      memw();
      uVar5 = param_2 & 1;
      if (uVar4 != 0) {
        uVar5 = param_2 & 1 | 2;
      }
      memw();
      *DAT_42000780 = *DAT_42000780 & 0xfffffffc | uVar5;
    }
    else {
      if (param_1 != 0x20) {
        return 0x106;
      }
      memw();
      uVar5 = param_2 & 1;
      if (uVar4 != 0) {
        uVar5 = param_2 & 1 | 2;
      }
      memw();
      *DAT_42000780 = uVar5 << 2 | *DAT_42000780 & 0xfffffff3;
    }
  }
  else {
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
      uVar3 = 7;
      if (param_3 < 2) {
        puVar2 = DAT_42000770;
        if (param_3 != 0) {
          puVar2 = DAT_42000774;
        }
        memw();
        uVar4 = (uint)(uVar4 != 0) | (param_2 & 1) * 2;
        memw();
        *puVar2 = *puVar2 & 0xffffffc7;
        memw();
        if (uVar5 != 0) {
          uVar4 = uVar4 | 4;
        }
        memw();
        *puVar2 = (uVar4 << 3 ^ *puVar2) & 0x38 ^ *puVar2;
        uVar3 = 0;
      }
LAB_420062e4:
      uVar3 = FUN_4200775c(uVar3);
      return uVar3;
    }
    if (param_1 < 0x201) {
      if (param_1 != 0x80) {
        if (param_1 != 0x100) {
          return 0x106;
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
        uVar3 = 7;
        if (param_3 < 2) {
          puVar2 = DAT_42000770;
          if (param_3 != 0) {
            puVar2 = DAT_42000774;
          }
          memw();
          uVar4 = (uint)(uVar4 != 0) | (param_2 & 1) * 2;
          memw();
          *puVar2 = *puVar2 & 0xfffffff8;
          memw();
          if (uVar5 != 0) {
            uVar4 = uVar4 | 4;
          }
          memw();
          *puVar2 = (*puVar2 ^ uVar4) & 7 ^ *puVar2;
          uVar3 = 0;
        }
        goto LAB_420062e4;
      }
      memw();
      uVar5 = param_2 & 1;
      if (uVar4 != 0) {
        uVar5 = param_2 & 1 | 2;
      }
      memw();
      *DAT_42000780 = uVar5 << 6 | *DAT_42000780 & 0xffffff3f;
    }
    else if (param_1 == 0x400) {
      uVar1 = param_2 & 1;
      if (uVar4 != 0) {
        uVar1 = param_2 & 1 | 2;
      }
      memw();
      if (uVar5 != 0) {
        uVar1 = uVar1 | 4;
      }
      memw();
      *DAT_42000778 = uVar1 << 0xc | *DAT_42000778 & DAT_42000784;
    }
    else {
      if (param_1 != DAT_420006dc) {
        return 0x106;
      }
      uVar1 = param_2 & 1;
      if (uVar4 != 0) {
        uVar1 = param_2 & 1 | 2;
      }
      memw();
      if (uVar5 != 0) {
        uVar1 = uVar1 | 4;
      }
      memw();
      *DAT_42000778 = uVar1 << 0xf | *DAT_42000778 & DAT_42000788;
    }
  }
  return 0;
}


