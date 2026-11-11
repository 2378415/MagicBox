undefined4
FUN_4200be64(char *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  undefined4 *puVar1;
  
  if (param_3 == 0) {
    return 0x102;
  }
  if (param_2 != 0xffffffff) {
    if (param_2 == 1) {
      return 0x102;
    }
    if (0xf < param_2) {
      return 0x102;
    }
    if (1 < param_2) {
      if (*param_1 != '/') {
        return 0x102;
      }
      if (param_1[param_2 - 1] == '/') {
        return 0x102;
      }
    }
  }
  if (*DAT_42000c48 == 0) {
    if (*DAT_42000c48 != 0) {
      return 0x103;
    }
    if (*DAT_42000c4c == 0) {
      *DAT_42000c4c = 1;
    }
    puVar1 = (undefined4 *)(*(code *)PTR_FUN_42000660)(0x24,DAT_42000988);
    if (puVar1 != (undefined4 *)0x0) {
      *DAT_42000c48 = (int)puVar1;
      if (param_2 == 0xffffffff) {
        (*DAT_42000c54)(puVar1 + 2,0xf);
      }
      else {
        (*DAT_42000c50)(puVar1 + 2,param_1);
      }
      puVar1[6] = param_2;
      puVar1[1] = param_3;
      puVar1[7] = param_5;
      puVar1[8] = 0;
      *puVar1 = param_4;
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = 0;
      }
      return 0;
    }
  }
  return 0x101;
}