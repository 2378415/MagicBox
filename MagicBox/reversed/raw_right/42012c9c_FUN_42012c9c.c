// 42012c9c  FUN_42012c9c  FUN_42012c9c  size=169

undefined4 FUN_42012c9c(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char local_30 [48];
  
  puVar1 = (undefined4 *)(*(code *)PTR_FUN_42000738)(1,0x10);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x101;
  }
  if (param_1 == 0) {
    puVar1[2] = param_2;
  }
  else {
    puVar1[1] = param_2;
  }
  (*(code *)PTR_FUN_420003a8)(PTR_DAT_42000f7c,0xffffffff);
  if (*DAT_42000f78 == 0) {
    uVar3 = 0x103;
LAB_42012d33:
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000f7c);
    (*(code *)PTR_FUN_420004c0)(puVar1);
  }
  else {
    if (param_1 == 0) {
      iVar2 = FUN_42012c08(puVar1,local_30);
      if (iVar2 != 0) {
        uVar3 = 0x102;
        goto LAB_42012d33;
      }
    }
    else {
      iVar2 = FUN_42012c40(puVar1[1],local_30);
      if (iVar2 != 0) {
        uVar3 = 0x102;
        goto LAB_42012d33;
      }
    }
    puVar4 = (undefined4 *)*DAT_42000f78;
    *puVar1 = puVar4[1];
    puVar4[1] = puVar1;
    if (*(char *)((int)puVar4 + 0xd) != '\0') {
      FUN_420131e8(*puVar4);
      *(undefined1 *)(*DAT_42000f78 + 0xd) = 0;
    }
    if (local_30[0] != '\0') {
      FUN_42012c78();
    }
    (*(code *)PTR_FUN_420003ac)(PTR_DAT_42000f7c);
    *param_3 = (int)puVar1;
    uVar3 = 0;
  }
  return uVar3;
}


