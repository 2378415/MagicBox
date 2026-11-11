// 42013734  FUN_42013734  FUN_42013734  size=328

void FUN_42013734(void)

{
  int iVar1;
  
  if (*(char *)(DAT_42001220 + 1) == -0x60) {
    if (*(short *)(DAT_42001220 + 2) == 1) {
      if (*(char *)(DAT_42001220 + 4) == '\0') {
        iVar1 = FUN_420153a0(0,DAT_42001228,PTR_LAB_42001224);
        if (iVar1 == 0) {
          memw();
          *DAT_4200122c = '\x01';
          (*(code *)PTR_FUN_42001238)();
          return;
        }
        memw();
        *DAT_4200122c = '\0';
        (*(code *)PTR_FUN_4200123c)();
        return;
      }
      if (*(char *)(DAT_42001220 + 4) != -1) {
        return;
      }
    }
    else if (*(short *)(DAT_42001220 + 2) != 0) {
      return;
    }
    memw();
    if (*DAT_4200122c == '\0') {
      return;
    }
    memw();
    *DAT_4200122c = '\0';
    (*(code *)PTR_FUN_4200123c)();
    FUN_42015470(0);
    FUN_420145cc();
    return;
  }
  if (*(char *)(DAT_42001220 + 1) != -0x5e) {
    (*(code *)PTR_FUN_42000488)(*DAT_42001230,0,0);
    return;
  }
  if ((*DAT_42001208 == *(char *)(DAT_42001220 + 5)) && (DAT_42000e84[0x635] != '\0')) {
    if (*DAT_42000e84 == '\0') {
      if (((DAT_42000e84[1] != '\0') && (DAT_42000e84[0x20c] != '\0')) &&
         (*(char *)(DAT_42001220 + 6) != '\0')) {
        if ((*(int *)(DAT_42000e84 + 0x214) == 0) ||
           (*(char *)(*(int *)(DAT_42000e84 + 0x214) + 0x62) != *(char *)(DAT_42001220 + 8)))
        goto LAB_420137f6;
      }
    }
    else if ((DAT_42000e84[0x20c] != '\0') &&
            ((*(char *)(DAT_42001220 + 6) != '\0' &&
             (*(char *)(DAT_42001220 + 8) != *(char *)(*(int *)(DAT_42000e84 + 0x210) + 0x1d5)))))
    goto LAB_420137f6;
    (*(code *)PTR_FUN_42000488)(*DAT_42001204,DAT_42001234,0xffffffff,0);
  }
  else {
LAB_420137f6:
    FUN_42014610(DAT_42001234,6,*DAT_42001208,0x738);
  }
  return;
}


