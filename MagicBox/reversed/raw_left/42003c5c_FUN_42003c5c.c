// 42003c5c  FUN_42003c5c  FUN_42003c5c  size=240

void FUN_42003c5c(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 in_EPC1;
  undefined1 in_EPC2;
  undefined1 in_EPC3;
  undefined1 in_EPC4;
  undefined4 local_90 [24];
  int iStack_30;
  int iStack_2c;
  
  puVar4 = local_90;
  iStack_30 = param_2;
  iStack_2c = param_1;
  (*DAT_42000064)(local_90,PTR_PTR_4200040c,0x60);
  FUN_4200330c(PTR_s_Core_42000410);
  FUN_420033bc(param_2);
  param_1 = param_1 + 0x10;
  FUN_4200330c(PTR_s_register_dump__42000414);
  iVar5 = 0;
  do {
    FUN_4200330c(PTR_s__3c039338_0x14_42000408);
    puVar2 = puVar4;
    iVar1 = param_1 + -0x10;
    do {
      iVar3 = iVar1;
      if (*(char *)*puVar2 != '\0') {
        FUN_4200330c();
        FUN_4200330c(PTR_DAT_42000418);
        FUN_42003360(*(undefined4 *)(iVar3 + 4));
        FUN_4200330c(PTR_DAT_4200041c);
      }
      puVar2 = puVar2 + 1;
      iVar1 = iVar3 + 4;
    } while (iVar3 + 4 != param_1);
    iVar5 = iVar5 + 4;
    param_1 = iVar3 + 0x14;
    puVar4 = puVar4 + 4;
  } while (iVar5 != 0x18);
  iVar5 = (*(code *)PTR_FUN_42000434)();
  if (iVar5 != 0) {
    if (iStack_30 == 0) {
      if (*(int *)(iStack_2c + 0x50) != 5) {
        return;
      }
    }
    else {
      if (iStack_30 != 1) {
        return;
      }
      if (*(int *)(iStack_2c + 0x50) != 6) {
        return;
      }
    }
    uVar6 = rsr(in_EPC1);
    FUN_4200330c(PTR_s__3c039338_0x14_42000408);
    FUN_4200330c(PTR_s_Core_42000410);
    FUN_420033bc(iStack_30);
    FUN_4200330c(PTR_s_was_running_in_ISR_context__42000420);
    FUN_4200330c(PTR_DAT_42000424);
    FUN_42003360(uVar6);
    uVar6 = rsr(in_EPC2);
    FUN_4200330c(PTR_s_EPC2___0x_42000428);
    FUN_42003360(uVar6);
    uVar6 = rsr(in_EPC3);
    FUN_4200330c(PTR_s_EPC3___0x_4200042c);
    FUN_42003360(uVar6);
    uVar6 = rsr(in_EPC4);
    FUN_4200330c(PTR_s_EPC4___0x_42000430);
    FUN_42003360(uVar6);
  }
  return;
}


