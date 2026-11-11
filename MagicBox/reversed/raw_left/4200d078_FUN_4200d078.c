// 4200d078  FUN_4200d078  FUN_4200d078  size=54

void FUN_4200d078(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_42018d80(1,3,0);
  puVar2 = DAT_42000cc0;
  if (iVar3 != 0) {
    uVar4 = *(undefined4 *)(iVar3 + 0x10);
    uVar1 = *(undefined1 *)(iVar3 + 0x29);
    *DAT_42000cc0 = *(undefined4 *)(iVar3 + 0xc);
    puVar2[1] = uVar4;
    *(undefined1 *)(puVar2 + 2) = uVar1;
    uVar4 = (*DAT_42000cd4)(0,puVar2,0xc);
    puVar2[3] = uVar4;
    (*(code *)PTR_FUN_42000cc4)();
  }
  return;
}


