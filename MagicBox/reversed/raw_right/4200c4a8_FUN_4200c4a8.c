// 4200c4a8  FUN_4200c4a8  FUN_4200c4a8  size=777

void FUN_4200c4a8(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)(param_1 + 0xc);
  cVar1 = *(char *)(DAT_42000af8 + param_2 * 0x18 + uVar4 * 0xc4 + 4);
  if (cVar1 == '\0') {
    iVar3 = param_2 * 0x18 + uVar4 * 0xc4 + DAT_42000af8;
    uVar2 = FUN_420247a4(8,0,*(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,iVar3 + 8);
    *(undefined2 *)(iVar3 + 6) = uVar2;
    FUN_4200c448(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 8) + 2),0,0,
                 *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,
                 *(undefined1 *)(*(int *)(param_3 + 8) + 3));
    FUN_4200c204(param_1,param_2,0,param_4,
                 *(undefined4 *)(DAT_42000af8 + param_2 * 0x18 + uVar4 * 0xc4 + 8),
                 *(undefined1 *)(iVar3 + 6),3);
  }
  else if (cVar1 == '\x01') {
    iVar3 = param_2 * 0x18 + uVar4 * 0xc4 + DAT_42000af8;
    uVar2 = FUN_420247a4(*(undefined2 *)(param_4 + 6),0x80,
                         *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,iVar3 + 8);
    *(undefined2 *)(iVar3 + 6) = uVar2;
    FUN_4200c448(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 8) + 2),0x80,0,
                 *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,
                 *(undefined1 *)(*(int *)(param_3 + 8) + 3));
    FUN_4200c204(param_1,param_2,0x80,param_5,
                 *(undefined4 *)(DAT_42000af8 + param_2 * 0x18 + uVar4 * 0xc4 + 8),
                 *(undefined1 *)(iVar3 + 6),2);
  }
  else if (cVar1 == '\x02') {
    iVar3 = param_2 * 0x18 + uVar4 * 0xc4 + DAT_42000af8;
    uVar2 = FUN_420247a4(*(undefined2 *)(param_4 + 6),0,
                         *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,iVar3 + 8);
    *(undefined2 *)(iVar3 + 6) = uVar2;
    FUN_4200c448(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 8) + 2),0,0,
                 *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,
                 *(undefined1 *)(*(int *)(param_3 + 8) + 3));
    FUN_4200c204(param_1,param_2,0,param_5,
                 *(undefined4 *)(DAT_42000af8 + param_2 * 0x18 + uVar4 * 0xc4 + 8),
                 *(undefined1 *)(iVar3 + 6),2);
  }
  else if (cVar1 == '\x03') {
    iVar3 = param_2 * 0x18 + uVar4 * 0xc4 + DAT_42000af8;
    uVar2 = FUN_420247a4(0,0x80,*(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,iVar3 + 8);
    *(undefined2 *)(iVar3 + 6) = uVar2;
    FUN_4200c448(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 8) + 2),0x80,0,
                 *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,
                 *(undefined1 *)(*(int *)(param_3 + 8) + 3));
    FUN_4200c204(param_1,param_2,0x80,0,
                 *(undefined4 *)(DAT_42000af8 + param_2 * 0x18 + uVar4 * 0xc4 + 8),
                 *(undefined1 *)(iVar3 + 6),2);
  }
  else if (cVar1 == '\x04') {
    iVar3 = param_2 * 0x18 + uVar4 * 0xc4 + DAT_42000af8;
    uVar2 = FUN_420247a4(0,0,*(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,iVar3 + 8);
    *(undefined2 *)(iVar3 + 6) = uVar2;
    FUN_4200c448(param_1,param_2,*(undefined1 *)(*(int *)(param_3 + 8) + 2),0,0,
                 *(ushort *)(*(int *)(param_3 + 0xc) + 4) & 0x7ff,
                 *(undefined1 *)(*(int *)(param_3 + 8) + 3));
    FUN_4200c204(param_1,param_2,0,0,
                 *(undefined4 *)(DAT_42000af8 + param_2 * 0x18 + uVar4 * 0xc4 + 8),
                 *(undefined1 *)(iVar3 + 6),2);
  }
  return;
}


