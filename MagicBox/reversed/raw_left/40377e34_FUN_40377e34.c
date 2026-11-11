// 40377e34  FUN_40377e34  FUN_40377e34  size=73

undefined4 FUN_40377e34(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x102;
  }
  else {
    uVar1 = 0x105;
    if ((*DAT_40374898 != 0) && (iVar3 = DAT_40374898[9], iVar3 != 0)) {
      iVar2 = iVar3;
      do {
        iVar2 = *(int *)(iVar2 + 0x24);
        if (iVar2 == 0) {
          return 0x105;
        }
      } while ((((iVar3 == iVar2) || (**(int **)(DAT_40374898[10] + 4) == iVar2)) ||
               (param_1 < *(uint *)(iVar2 + 0x18))) || (*(uint *)(iVar2 + 0x1c) <= param_1));
      uVar1 = 0;
      *param_2 = *(undefined4 *)(iVar2 + 0x14);
    }
  }
  return uVar1;
}


