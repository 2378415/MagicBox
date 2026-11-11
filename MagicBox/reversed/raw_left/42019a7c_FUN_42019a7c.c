// 42019a7c  FUN_42019a7c  FUN_42019a7c  size=58
// strings: $}7@4>

void FUN_42019a7c(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (*(code *)PTR_FUN_420006fc)();
  if (iVar2 != 0) {
    if (1 < *(uint *)PTR_DAT_42000028) {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_42001804,uVar3,PTR_s_spi_flash_42001800,PTR_DAT_420017fc);
    }
    *(undefined1 *)(param_1 + 0x25) = 1;
    puVar1 = PTR_PTR_42001808;
    *(undefined4 *)(param_1 + 0x28) = 0x10;
    *(undefined4 *)(puVar1 + 0x10) = 0x10;
  }
  return;
}


