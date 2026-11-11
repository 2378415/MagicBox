// 4200bd20  FUN_4200bd20  FUN_4200bd20  size=38
// strings: /dev/uart/0 | /dev/secondary

undefined4 FUN_4200bd20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_42020bac(PTR_s__dev_uart_0_42000c34,param_2,param_3);
  puVar2 = PTR_s__dev_secondary_42000c3c;
  puVar1 = DAT_42000c38;
  *DAT_42000c38 = uVar3;
  uVar3 = FUN_42020bac(puVar2,param_2,param_3);
  puVar1[1] = uVar3;
  return 0;
}


