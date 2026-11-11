// 42002ba8  FUN_42002ba8  FUN_42002ba8  size=113
// strings: cpu_start

/* WARNING: Control flow encountered bad instruction data */

int FUN_42002ba8(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint unaff_retaddr;
  undefined4 uVar1;
  undefined4 uVar2;
  int extraout_a3;
  uint *puVar3;
  uint *puVar4;
  int in_t0;
  
  puVar3 = DAT_42000154 + -5;
  puVar4 = DAT_42000154;
  do {
    if ((code *)puVar4[4] != (code *)0x0) {
      (*(code *)puVar4[4])();
    }
    puVar4 = puVar4 + -1;
  } while (puVar4 != puVar3);
  (*(code *)PTR_FUN_42000158)();
  (*(code *)PTR_FUN_4200015c)();
  if (param_4 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((unaff_retaddr & param_1) == 0) {
    *(uint *)(extraout_a3 * 4 + in_t0) = param_1;
    return in_t0;
  }
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  (*DAT_42000060)(PTR_DAT_42000164,uVar1,PTR_s_cpu_start_42000160);
  uVar1 = (*(code *)PTR_FUN_4200016c)();
  if (2 < *puVar4) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*DAT_42000060)(PTR_DAT_42000168,uVar2,PTR_s_cpu_start_42000160,uVar1);
  }
  return 0;
}


