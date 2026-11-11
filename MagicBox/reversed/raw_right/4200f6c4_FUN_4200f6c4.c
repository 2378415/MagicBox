// 4200f6c4  FUN_4200f6c4  FUN_4200f6c4  size=217

void FUN_4200f6c4(int param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = DAT_42000d20;
  if (param_1 == 0) {
    return;
  }
  if (DAT_420004fc < *(ushort *)(param_1 + 2)) {
    *DAT_42000d20 = 0x5a;
    puVar2[1] = *(undefined1 *)(param_1 + 1);
    *(undefined2 *)(puVar2 + 2) = 1;
    puVar2[4] = 0xff;
    FUN_4200f6b0(puVar2,5);
    return;
  }
  (*DAT_42000240)(DAT_42000d20,0,DAT_42000424);
  *puVar2 = 0x5a;
  bVar1 = *(byte *)(param_1 + 1);
  puVar2[1] = bVar1;
  puVar2 = DAT_42000d20;
  if (bVar1 == 0xa3) {
    FUN_4200fae0(DAT_42000d20);
    goto LAB_4200f795;
  }
  if (bVar1 < 0xa4) {
    if (bVar1 == 0xa0) {
      FUN_4200fac0(DAT_42000d20);
      goto LAB_4200f795;
    }
    if (bVar1 == 0xa1) {
      if (*(ushort *)(param_1 + 2) < 8) {
        *(undefined2 *)(DAT_42000d20 + 2) = 1;
        puVar2[4] = 0xff;
      }
      else {
        FUN_4200fc74(param_1,DAT_42000d20);
      }
      goto LAB_4200f795;
    }
    if (bVar1 == 0x1a) {
      FUN_4200f854(DAT_42000d20);
      goto LAB_4200f795;
    }
  }
  else {
    if (bVar1 == 0xa4) {
      FUN_4200fe44(param_1,DAT_42000d20);
      goto LAB_4200f795;
    }
    if (bVar1 == 0xb1) goto LAB_4200f795;
  }
  FUN_420248e4(DAT_42000d20);
LAB_4200f795:
  FUN_4200f6b0(DAT_42000d20,*(short *)(DAT_42000d20 + 2) + 4);
  return;
}


