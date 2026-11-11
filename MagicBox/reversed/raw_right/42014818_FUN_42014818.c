// 42014818  FUN_42014818  FUN_42014818  size=298

int FUN_42014818(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  char cStack_43;
  byte bStack_42;
  undefined1 uStack_2c;
  int aiStack_24 [9];
  
  iVar1 = FUN_420168fc(param_1 + 0x10,*(undefined4 *)(param_1 + 8),param_2,param_3);
  if (iVar1 == 0) {
    FUN_420147fc(param_1);
    for (puVar3 = (undefined4 *)(param_1 + 0x44); (undefined4 *)(param_1 + 100) != puVar3;
        puVar3 = puVar3 + 1) {
      *puVar3 = 0;
    }
    for (iVar1 = *(int *)(param_1 + 0x10); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
      aiStack_24[0] = 0;
      while (iVar2 = FUN_42015dbc(iVar1,0,1,0,aiStack_24,&uStack_44,0xff,0xff), iVar2 == 0) {
        puVar3 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x1c);
        if (puVar3 == (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 100) = 0;
          return 0x101;
        }
        *puVar3 = 0;
        puVar3[1] = 0;
        FUN_42013fe4(&uStack_44,puVar3 + 2,0x10);
        if (cStack_43 != '\x01') {
          (*(code *)PTR_FUN_420004c0)(puVar3);
          return -1;
        }
        *(undefined1 *)(puVar3 + 6) = uStack_2c;
        iVar2 = FUN_42024c78(param_1 + 0x44,uStack_2c,1);
        if (iVar2 != 0) {
          (*(code *)PTR_FUN_420004c0)(puVar3);
          return -1;
        }
        FUN_42024cb0(param_1 + 0x38,puVar3);
        aiStack_24[0] = aiStack_24[0] + (uint)bStack_42;
      }
    }
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 1;
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | DAT_42000afc;
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    iVar1 = FUN_42014610(param_1,&uStack_50);
    if (iVar1 == 0) {
      FUN_42014698(param_1,&uStack_50);
      FUN_4201400c(param_1,&uStack_50);
      FUN_42014770(&uStack_50);
      *(undefined4 *)(param_1 + 100) = 1;
      iVar1 = 0;
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0;
      iVar1 = 0x101;
    }
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return iVar1;
}


