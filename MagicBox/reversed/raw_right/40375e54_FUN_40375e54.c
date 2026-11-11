// 40375e54  FUN_40375e54  FUN_40375e54  size=230
// strings: cpuid == xPortGetCoreID()

void FUN_40375e54(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined1 in_PRID;
  
  uVar5 = rsr(in_PRID);
  if (param_1 != (uVar5 >> 0xd & 1)) {
    FUN_40381d9c(PTR_s_esp_ipc_c_3c030adc_0x1c_40374618,0x38,PTR_s_ipc_task_40374614,
                 PTR_s_cpuid____xPortGetCoreID___40374610);
  }
  (*(code *)PTR_FUN_40374638)();
  while( true ) {
    while( true ) {
      do {
        FUN_4037e19c(0,1,0xffffffff);
        memw();
        if ((*(char *)(DAT_4037461c + param_1) != '\0') &&
           (memw(), *(int *)(param_1 * 4 + DAT_40374620) != 0)) {
          puVar3 = (undefined4 *)(param_1 * 4 + DAT_40374620);
          memw();
          memw();
          (*(code *)*puVar3)(*(undefined4 *)(param_1 * 4 + DAT_40374624));
          memw();
          *(undefined1 *)(DAT_4037461c + param_1) = 0;
          memw();
          *puVar3 = 0;
        }
        memw();
      } while (*(int *)(param_1 * 4 + DAT_40374628) == 0);
      puVar3 = (undefined4 *)(param_1 * 4 + DAT_40374628);
      memw();
      pcVar4 = (code *)*puVar3;
      memw();
      uVar2 = *(undefined4 *)(param_1 * 4 + DAT_4037462c);
      memw();
      iVar6 = *(int *)(param_1 * 4 + DAT_40374630);
      uVar1 = *(undefined4 *)(param_1 * 4 + DAT_40374634);
      memw();
      *puVar3 = 0;
      if (iVar6 != 1) break;
      FUN_4037b39c(uVar1,0,0,0);
      (*pcVar4)(uVar2);
    }
    if (iVar6 != 2) break;
    (*pcVar4)(uVar2);
    FUN_4037b39c(uVar1,0,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40381ce0();
}


