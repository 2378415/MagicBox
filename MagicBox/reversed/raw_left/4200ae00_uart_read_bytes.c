// 4200ae00  uart_read_bytes  FUN_4200ae00  size=285
// strings: uart_read_bytes | uart

int FUN_4200ae00(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int aiStack_40 [4];
  undefined *puStack_30;
  int iStack_2c;
  int iStack_28;
  
  if (param_1 < 3) {
    if (param_2 == 0) {
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar5 = 0x5f1;
      puVar6 = PTR_DAT_42000b80;
    }
    else {
      iStack_28 = param_1 << 2;
      piVar4 = (int *)(param_1 * 4 + DAT_42000a40);
      if (*piVar4 != 0) {
        aiStack_40[0] = 0;
        iVar2 = (*(code *)PTR_FUN_42000480)(*(undefined4 *)(*piVar4 + 0x68),param_4);
        iVar3 = 0;
        if (iVar2 != 1) {
          return -1;
        }
        if (param_3 == 0) {
          iVar3 = 0;
        }
        else {
          puStack_30 = PTR_DAT_42000af4 + param_1 * 0x18;
          do {
            while( true ) {
              iVar2 = (*(code *)PTR_FUN_42000b84)
                                (*(undefined4 *)(*piVar4 + 0x60),aiStack_40,param_4,param_3);
              if (iVar2 != 0) break;
              iVar2 = FUN_4200903c(param_1);
              if (iVar2 == 0) goto LAB_4200af06;
            }
            iStack_2c = iVar2;
            (*DAT_42000064)(param_2 + iVar3,iVar2,aiStack_40[0]);
            (*(code *)PTR_FUN_420004dc)(puStack_30,0xffffffff);
            *(int *)(*piVar4 + 0x14) = *(int *)(*piVar4 + 0x14) - aiStack_40[0];
            FUN_4200910c(param_1);
            (*(code *)PTR_FUN_420004e0)(puStack_30);
            param_3 = param_3 - aiStack_40[0];
            iVar3 = iVar3 + aiStack_40[0];
            (*(code *)PTR_FUN_42000b88)(*(undefined4 *)(*piVar4 + 0x60),iStack_2c);
            FUN_4200903c(param_1);
          } while (param_3 != 0);
        }
LAB_4200af06:
        (*(code *)PTR_FUN_42000488)(*(undefined4 *)(*(int *)(DAT_42000a40 + iStack_28) + 0x68),0,0);
        return iVar3;
      }
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar5 = 0x5f2;
      puVar6 = PTR_DAT_42000af0;
    }
  }
  else {
    uVar1 = (*(code *)PTR_FUN_4200005c)();
    uVar5 = 0x5f0;
    puVar6 = PTR_DAT_42000a58;
  }
  (*(code *)PTR_FUN_42000118)
            (1,PTR_DAT_42000a54,puVar6,uVar1,PTR_DAT_42000a54,PTR_s_uart_read_bytes_42000b7c,uVar5);
  return -1;
}


