// 4200fd24  FUN_4200fd24  FUN_4200fd24  size=95

void FUN_4200fd24(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined1 uVar3;
  
  puVar1 = DAT_42000d28;
  if ((*(char *)(DAT_42000d28 + 4) == '\0') || (*(char *)((int)DAT_42000d28 + 0xc9) == '\0')) {
    *(undefined2 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 4) = 0;
  }
  else {
    *(undefined1 *)(DAT_42000d28 + 4) = 0;
    *(undefined1 *)((int)puVar1 + 0xc9) = 0;
    iVar2 = FUN_4200f358(*puVar1,puVar1[1],0,DAT_42000d30);
    *(undefined2 *)(param_1 + 2) = 1;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0xff;
    }
    *(undefined1 *)(param_1 + 4) = uVar3;
    *(undefined1 *)((int)DAT_42000d28 + 7) = 0;
    if (iVar2 == 0) {
      FUN_4200fccc();
    }
  }
  return;
}


