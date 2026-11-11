// strings: IDLE

void FUN_4037ebd8(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  undefined4 uStack_40;
  char cStack_3c;
  undefined1 uStack_3b;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [10];
  
  uVar2 = DAT_40375078;
  cVar5 = '\0';
  piVar4 = DAT_40375074;
  do {
    cStack_3c = cVar5 + '0';
    uStack_40 = uVar2;
    uStack_3b = 0;
    auStack_28[0] = 0;
    uStack_2c = 0;
    FUN_4037c514(auStack_28,&uStack_2c,&local_30);
    iVar3 = FUN_4037eb00(PTR_FUN_4037507c,&uStack_40,local_30,0,0,uStack_2c,auStack_28[0],cVar5);
    *piVar4 = iVar3;
    if (cVar5 != '\0') {
      if (iVar3 != 0) {
        iVar3 = FUN_4037cab4();
        puVar1 = PTR_DAT_40374ef4;
        if (iVar3 == 1) {
          rsil(3);
          FUN_4037bf44(PTR_DAT_40374ef4,0xffffffff);
          memw();
          *DAT_40374ef0 = 0xffffffff;
          memw();
          *DAT_40374f10 = 1;
          memw();
          *DAT_40374edc = 0;
          FUN_4037c094(puVar1);
          FUN_4037be6c();
        }
        else if (iVar3 == -1) {
          FUN_40381ce4(PTR_s_tasks_c_3c034d7c_0x2a_40374ed4,DAT_40375088,
                       PTR_s_vTaskStartScheduler_40375084,PTR_s_xReturn_______1___40375080);
        }
      }
      break;
    }
    piVar4 = piVar4 + 1;
    cVar5 = '\x01';
  } while (iVar3 != 0);
  memw();
  return;
}