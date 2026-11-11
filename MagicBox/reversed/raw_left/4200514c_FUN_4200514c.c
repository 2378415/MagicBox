// 4200514c  FUN_4200514c  FUN_4200514c  size=164

uint * FUN_4200514c(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar1 = DAT_42000654;
  for (puVar2 = (uint *)*DAT_42000654; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[2]) {
    if ((param_2 == (*puVar2 >> 0x10 & 1)) && (param_1 == (*puVar2 >> 0x11 & 0x1f))) {
      return puVar2;
    }
  }
  puVar2 = (uint *)(*(code *)PTR_FUN_42000660)(0xc,DAT_420005d8);
  if (puVar2 != (uint *)0x0) {
    (*DAT_42000094)(puVar2,0,0xc);
    *puVar2 = (*puVar2 & DAT_42000658 | (param_1 & 0x1f) << 0x11) & DAT_4200065c |
              (param_2 & 1) << 0x10;
    puVar5 = (uint *)*puVar1;
    if (puVar5 != (uint *)0x0) {
      puVar4 = puVar5;
      puVar6 = (uint *)0x0;
      while( true ) {
        puVar5 = puVar4;
        uVar3 = *puVar5;
        if (((param_2 & 1) < (uVar3 >> 0x10 & 1)) ||
           ((((uVar3 ^ *puVar2) & 0x10000) == 0 && ((param_1 & 0x1f) <= (uVar3 >> 0x11 & 0x1f)))))
        break;
        puVar4 = (uint *)puVar5[2];
        if (puVar4 == (uint *)0x0) goto LAB_420051e9;
        puVar6 = puVar5;
      }
      if (puVar6 != (uint *)0x0) {
        puVar4 = puVar5;
        puVar5 = puVar6;
LAB_420051e9:
        puVar5[2] = (uint)puVar2;
        puVar2[2] = (uint)puVar4;
        return puVar2;
      }
    }
    puVar2[2] = (uint)puVar5;
    *puVar1 = (uint)puVar2;
  }
  return puVar2;
}


