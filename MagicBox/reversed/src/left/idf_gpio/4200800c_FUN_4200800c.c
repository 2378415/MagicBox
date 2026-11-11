// strings: system_time

void FUN_4200800c(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar6 = FUN_42004fb4();
  iVar4 = *DAT_42000918;
  iVar5 = DAT_42000918[1];
  uVar7 = (*(code *)PTR_FUN_4200092c)();
  puVar2 = PTR_FUN_42000920;
  piVar1 = DAT_4200091c;
  DAT_4200091c[1] =
       (int)((ulonglong)uVar6 >> 0x20) + iVar5 * -2 + (int)((ulonglong)uVar7 >> 0x20) * -2;
  *piVar1 = ((int)uVar6 - iVar4) - (int)uVar7;
  iVar4 = FUN_42002b74(puVar2);
  if (iVar4 != 0) {
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (2,PTR_s_system_time_42000924,PTR_DAT_42000928,uVar3,PTR_s_system_time_42000924,iVar4)
    ;
  }
  return;
}