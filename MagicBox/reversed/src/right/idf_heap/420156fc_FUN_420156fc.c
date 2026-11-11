int FUN_420156fc(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined4 local_37 [4];
  undefined4 auStack_24 [9];
  
  if (*(int *)(param_1 + 0xc) == -1) {
    *(undefined4 *)(param_1 + 0xc) = 0xfffffffe;
    for (puVar2 = local_37; puVar2 != auStack_24; puVar2 = (undefined4 *)((int)puVar2 + 1)) {
      *(undefined1 *)puVar2 = 0xff;
    }
    local_40 = *(undefined4 *)(param_1 + 0xc);
    uStack_3c = *(undefined4 *)(param_1 + 0x10);
    uStack_38 = *(undefined1 *)(param_1 + 0x14);
    auStack_24[0] = FUN_420156e8(&local_40);
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),&local_40,0x20);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x38) = 0;
      for (puVar2 = (undefined4 *)(param_1 + 0x18); (undefined4 *)(param_1 + 0x38) != puVar2;
          puVar2 = puVar2 + 1) {
        *puVar2 = 0xffffffff;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}