// 420100fc  FUN_420100fc  FUN_420100fc  size=148

void FUN_420100fc(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_4201037c();
  for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
    uVar1 = (*(code *)PTR_FUN_42000b64)(8,4,0);
    *(undefined4 *)(iVar3 * 4 + DAT_42000d64) = uVar1;
  }
  for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
    *(undefined1 *)(iVar3 * 0x24 + DAT_42000d68 + 0x20) = 0;
    for (iVar4 = 0; iVar4 < 8; iVar4 = iVar4 + 1) {
      iVar2 = (*(code *)PTR_FUN_42000484)(DAT_42000424,8);
      *(int *)((iVar3 * 9 + iVar4) * 4 + DAT_42000d68) = iVar2;
      if (iVar2 != 0) {
        (*DAT_42000240)(iVar2,0,DAT_42000424);
      }
    }
  }
  for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
    (*(code *)PTR_FUN_42000380)
              (PTR_FUN_42000d80,PTR_s_hid_uart_42000d7c,DAT_4200077c,iVar3,7,0,DAT_4200049c);
  }
  return;
}


