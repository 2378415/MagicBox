// 42012aa8  FUN_42012aa8  FUN_42012aa8  size=165
// strings: 0~7@

int FUN_42012aa8(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_60 [8];
  undefined1 uStack_58;
  undefined1 uStack_50;
  int iStack_44;
  undefined1 uStack_3a;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  iVar4 = *DAT_42000e68;
  (*DAT_42000240)(auStack_60,0,0x38);
  uStack_58 = 1;
  uStack_50 = 1;
  uStack_34 = 0x50;
  iVar2 = (*DAT_42000f20)();
  uStack_50 = iVar2 == 0;
  FUN_42012a8c(auStack_60);
  iVar2 = (*(code *)PTR_FUN_42000f38)();
  if (iVar2 != 0) {
    uStack_3a = 1;
    (*(code *)PTR_FUN_42000f3c)(auStack_60);
  }
  if (iStack_44 == 0) {
    uStack_30 = FUN_42012a4c();
  }
  else {
    uStack_30 = 0x50;
  }
  iVar2 = (*(code *)PTR_FUN_42000f40)(PTR_DAT_42000f34,auStack_60);
  if (iVar2 == 0) {
    iVar3 = (*(code *)PTR_FUN_42000f44)(PTR_PTR_42000f30);
    iVar2 = iVar3;
    if (iVar3 == 0) {
      uVar5 = *(uint *)(iVar4 + 4);
      if (*(uint *)(PTR_PTR_42000f30 + 0x14) < uVar5) {
        iVar2 = 0x104;
      }
      else if ((uVar5 <= DAT_4200011c) || (iVar2 = (*(code *)PTR_FUN_42000f48)(), iVar2 == 0)) {
        puVar1 = PTR_PTR_42000f30;
        *(undefined4 *)(PTR_PTR_42000f30 + 0x14) = *(undefined4 *)(iVar4 + 4);
        *DAT_420009fc = puVar1;
        iVar2 = iVar3;
      }
    }
  }
  return iVar2;
}


