uint FUN_4202d9c4(undefined4 *param_1,char *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  cVar1 = *param_2;
  if (cVar1 == 'r') {
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = 4;
  }
  else if (cVar1 == 'w') {
    uVar4 = 0x600;
    uVar3 = 1;
    uVar2 = 8;
  }
  else {
    if (cVar1 != 'a') {
      *param_1 = 0x16;
      return 0;
    }
    uVar4 = 0x208;
    uVar3 = 1;
    uVar2 = 0x108;
  }
  while( true ) {
    cVar1 = param_2[1];
    param_2 = param_2 + 1;
    if (cVar1 == '\0') break;
    if (cVar1 == '+') {
      uVar2 = uVar2 & 0xffffffe3 | 0x10;
      uVar3 = uVar3 & 0xfffffffc | 2;
    }
    else if (cVar1 == 'x') {
      uVar3 = uVar3 | 0x800;
    }
  }
  *param_3 = uVar3 | uVar4;
  return uVar2;
}