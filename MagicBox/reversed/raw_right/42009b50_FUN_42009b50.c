// 42009b50  FUN_42009b50  FUN_42009b50  size=36
// strings: /dev/uart/0 | /dev/secondary

undefined4 FUN_42009b50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_4201813c(PTR_s__dev_uart_0_42000964,param_2,param_3);
  puVar1 = DAT_42000968;
  *DAT_42000968 = uVar2;
  uVar2 = FUN_4201813c(PTR_s__dev_secondary_4200096c,param_2,param_3);
  puVar1[1] = uVar2;
  return 0;
}


