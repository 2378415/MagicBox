// 42001c44  FUN_42001c44  FUN_42001c44  size=180

void FUN_42001c44(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  
  for (cVar6 = '\x01'; uVar3 = DAT_42000174, cVar6 != '\0'; cVar6 = cVar6 + -1) {
    iVar5 = FUN_420257f8(0xb);
    uVar2 = DAT_42000160;
    iVar1 = DAT_4200015c;
    if (iVar5 == 0) {
      memw();
      memw();
      *(uint *)(DAT_4200015c + 0x18) = *(uint *)(DAT_4200015c + 0x18) | DAT_42000160;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | uVar2;
      memw();
      memw();
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_42000164;
      memw();
      memw();
      *(uint *)(DAT_42000168 + 0x48) = *(uint *)(DAT_42000168 + 0x48) & DAT_4200016c;
    }
    FUN_4202580c(0xb,iVar5);
  }
  (*DAT_4200017c)(DAT_42000174,2,DAT_42000170,1);
  (*DAT_42000050)(uVar3);
  uVar4 = DAT_42000178;
  (*DAT_420000d8)(uVar3,0,DAT_42000178,1);
  (*DAT_420000d8)(uVar3,1,uVar4,3);
  (*DAT_42000180)(uVar3);
  (*DAT_42000058)(uVar3);
  return;
}


