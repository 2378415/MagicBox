// 4201100c  FUN_4201100c  FUN_4201100c  size=135

byte FUN_4201100c(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int in_a7;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  param_2 = param_2 & 0xffff;
  if ((param_1 != 0) && (iVar2 = *(int *)(param_1 + 0x214), param_2 < 0x100)) {
    if (iVar2 == 0) {
      in_a7 = 1;
    }
    if (in_a7 == 0) {
      uVar6 = (uint)*(byte *)(iVar2 + 0x58);
      piVar3 = (int *)(iVar2 + 8);
      if (uVar6 != 0) {
        uVar4 = 0;
        do {
          if (*piVar3 != 0) {
            uVar6 = FUN_4202d57c(param_1 + 0x219,*piVar3,*(undefined1 *)(iVar2 + uVar4 + 0x48),
                                 *(undefined4 *)(param_1 + 0x31c));
            if ((uVar6 & 0xff) == param_2) {
              bVar5 = 2;
              goto LAB_4201107c;
            }
            uVar6 = (uint)*(byte *)(iVar2 + 0x58);
          }
          bVar1 = uVar4 != 5;
          piVar3 = piVar3 + 1;
        } while ((uVar4 + 1 < uVar6) && (uVar4 = uVar4 + 1, bVar1));
      }
      bVar5 = 0;
LAB_4201107c:
      return bVar5 | *(char *)(param_1 + param_2 + 0x636) == '\x01';
    }
  }
  return 0;
}


