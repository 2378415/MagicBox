void FUN_42007df0(void)

{
  int *piVar1;
  int in_t0;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = FUN_42004fb4();
  uVar3 = (*(code *)PTR_FUN_420008e4)();
  piVar1 = DAT_420008e0;
  *DAT_420008e0 = (int)uVar2 - (int)uVar3;
  piVar1[1] = ((int)((ulonglong)uVar2 >> 0x20) - (int)((ulonglong)uVar3 >> 0x20)) - in_t0;
  return;
}