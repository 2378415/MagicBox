// 4202d7ec  FUN_4202d7ec  FUN_4202d7ec  size=88

int FUN_4202d7ec(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint local_30 [12];
  
  if (param_2 < 0x7e) {
    uVar1 = param_2 >> 4 & 0xffff;
    iVar4 = uVar1 * 4 + param_1;
    uVar2 = *(uint *)(iVar4 + 0x18);
    piVar3 = *(int **)(param_1 + 0x50);
    local_30[0] = 3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20) & uVar2 ^ uVar2 |
                  param_3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20);
    *(uint *)(iVar4 + 0x18) = local_30[0];
    iVar4 = (**(code **)(*piVar3 + 0x14))
                      (piVar3,uVar1 * 4 + *(int *)(param_1 + 8) + 0x20,local_30,4);
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


