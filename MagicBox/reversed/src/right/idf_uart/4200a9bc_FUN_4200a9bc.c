int FUN_4200a9bc(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = (*DAT_420007e8)(param_1,PTR_DAT_420009b0);
  if (iVar2 == 0) {
    iVar2 = FUN_4200a90c();
    puVar1 = DAT_420009ac;
    if (iVar2 == -1) {
      puVar3 = (undefined4 *)FUN_420180e4();
      *puVar3 = 0x18;
    }
    else {
      param_2 = param_2 & 3;
      if (param_2 == 2) {
        uVar4 = 1 << 0x20 - (0x20 - (iVar2 * 2 & 0x1fU)) | *DAT_420009ac;
        *DAT_420009ac = uVar4;
        *puVar1 = uVar4 | 2 << 0x20 - (0x20 - (iVar2 * 2 & 0x1fU));
      }
      else if (param_2 == 1) {
        *DAT_420009ac = *DAT_420009ac | 2 << 0x20 - (0x20 - (iVar2 * 2 & 0x1fU));
      }
      else if (param_2 == 0) {
        *DAT_420009ac = *DAT_420009ac | 1 << 0x20 - (0x20 - (iVar2 * 2 & 0x1fU));
      }
      else {
        puVar3 = (undefined4 *)FUN_420180e4();
        *puVar3 = 0x16;
        iVar2 = -1;
      }
    }
  }
  else {
    puVar3 = (undefined4 *)FUN_420180e4();
    *puVar3 = 2;
    iVar2 = -1;
  }
  return iVar2;
}