void FUN_4200c7b8(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)(param_1 + 0xc);
  iVar3 = param_2 * 0x18 + (uint)bVar1 * 0xc4 + DAT_42000af8;
  uVar2 = FUN_420247a4(param_5,*(undefined1 *)(*(int *)(param_3 + 0xc) + 2),
                       *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,iVar3 + 8);
  *(undefined2 *)(iVar3 + 6) = uVar2;
  iVar4 = *(int *)(param_3 + 0xc);
  FUN_4200c448(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 8) + 2),*(undefined1 *)(iVar4 + 2)
               ,*(byte *)(iVar4 + 3) & 3,*(ushort *)(iVar4 + 4) & 0x7ff,
               *(undefined1 *)(*(int *)(param_3 + 8) + 3));
  uVar5 = 0;
  if (*(char *)(param_3 + 0x10) != '\0') {
    uVar5 = 2;
  }
  FUN_4200c204(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 0xc) + 2),param_4,
               *(undefined4 *)(iVar3 + 8),
               *(undefined1 *)(DAT_42000af8 + param_2 * 0x18 + (uint)bVar1 * 0xc4 + 6),uVar5);
  return;
}