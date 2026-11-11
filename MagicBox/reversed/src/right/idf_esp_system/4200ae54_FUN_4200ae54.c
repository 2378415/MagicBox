void FUN_4200ae54(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_42011e9c(1,3,0);
  puVar1 = DAT_420009f8;
  if (iVar2 != 0) {
    *DAT_420009f8 = *(undefined4 *)(iVar2 + 0xc);
    puVar1[1] = *(undefined4 *)(iVar2 + 0x10);
    *(undefined1 *)(puVar1 + 2) = *(undefined1 *)(iVar2 + 0x29);
    uVar3 = (*DAT_42000a0c)(0,puVar1,0xc);
    puVar1[3] = uVar3;
    (*(code *)PTR_FUN_42000a00)();
  }
  return;
}