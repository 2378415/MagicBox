int FUN_42012ec4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    iVar2 = 0x102;
  }
  else if (*(uint *)(param_1 + 4) < 4) {
    if (*DAT_42000f78 == 0) {
      iVar1 = (*(code *)PTR_FUN_42000738)(1,0x10);
      if (iVar1 == 0) {
        iVar2 = 0x101;
      }
      else {
        *(undefined4 *)(iVar1 + 4) = 0;
        *(undefined1 *)(iVar1 + 0xc) = *(undefined1 *)(param_1 + 8);
        iVar2 = FUN_420130b8(param_1,PTR_FUN_42000fb8,iVar1);
        if (iVar2 == 0) {
          *DAT_42000f78 = iVar1;
          iVar2 = *(int *)(param_1 + 4);
          *(int *)(iVar1 + 8) = iVar2;
          if (iVar2 != 0) {
            FUN_42012e5c();
          }
          puVar3 = (undefined4 *)*DAT_42000f78;
          if (puVar3[1] == 0) {
            *(undefined1 *)((int)puVar3 + 0xd) = 1;
            return 0;
          }
          *(undefined1 *)((int)puVar3 + 0xd) = 0;
          FUN_420131e8(*puVar3);
          return 0;
        }
      }
      (*(code *)PTR_FUN_420004c0)(iVar1);
    }
    else {
      iVar2 = 0x103;
    }
  }
  else {
    iVar2 = 0x102;
  }
  return iVar2;
}