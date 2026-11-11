undefined4 FUN_42012140(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_42011e44(0xff,0xff,0);
  do {
    if (iVar1 == 0) {
      return 1;
    }
    iVar2 = FUN_42011e80(iVar1);
    if (*(char *)(iVar2 + 0x2a) != '\0') {
      uVar3 = *(uint *)(iVar2 + 0xc);
      if ((uVar3 <= param_1) && (param_1 < uVar3 + *(int *)(iVar2 + 0x10))) {
        return 0;
      }
      if ((param_1 < uVar3) && (uVar3 < param_1 + param_2)) {
        return 0;
      }
    }
    iVar1 = FUN_42011db8(iVar1);
  } while( true );
}