// 42001540  FUN_42001540  FUN_42001540  size=89

void FUN_42001540(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  if (*DAT_42000020 == 0) {
    for (uVar4 = 0; uVar4 < 5; uVar4 = uVar4 + 1) {
      memw();
      uVar1 = (uint)(byte)PTR_DAT_42000024[uVar4];
      for (uVar2 = 0; uVar2 < 2; uVar2 = uVar2 + 1) {
        cVar3 = (char)(uVar1 >> 4);
        if (uVar1 >> 4 < 10) {
          cVar3 = cVar3 + '0';
        }
        else {
          cVar3 = cVar3 + 'W';
        }
        *(char *)((int)DAT_42000020 + uVar4 * 2 + uVar2) = cVar3;
        uVar1 = (uVar1 & 0xf) << 4;
      }
    }
    *(undefined1 *)((int)DAT_42000020 + 9) = 0;
  }
  return;
}


