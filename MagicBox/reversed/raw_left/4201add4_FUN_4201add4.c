// 4201add4  FUN_4201add4  size=231
// strings: (p7@

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x4201ae1c) */

void FUN_4201add4(void)

{
  bool bVar1;
  undefined4 *puVar2;
  code *pcVar3;
  ulonglong *puVar4;
  undefined4 uVar5;
  int iVar6;
  ulonglong uVar7;
  
  puVar2 = DAT_420019fc;
  do {
    (*(code *)PTR_ulTaskGenericNotifyTake_42000eb8)(0,1,0xffffffff);
    (*(code *)PTR_FUN_420004c8)();
    (*(code *)PTR_spinlock_acquire_420004dc)(PTR_DAT_420019f8,0xffffffff);
    bVar1 = false;
    while( true ) {
      puVar4 = (ulonglong *)*puVar2;
      uVar7 = (*(code *)PTR_FUN_4200092c)();
      if (puVar4 == (ulonglong *)0x0) break;
      if (uVar7 < *puVar4) {
        (*(code *)PTR_FUN_42001a08)((int)*puVar4,*(undefined4 *)((int)puVar4 + 4),0);
        goto LAB_4201aef9;
      }
      iVar6 = (int)puVar4[3];
      if (iVar6 != 0) {
        *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)((int)puVar4 + 0x1c);
      }
      uVar7 = puVar4[2];
      **(int **)((int)puVar4 + 0x1c) = iVar6;
      bVar1 = true;
      if ((int)uVar7 == DAT_42001a00) {
        (*(code *)PTR_FUN_42000570)(puVar4);
      }
      else {
        if ((int)puVar4[1] != 0 || (*(uint *)((int)puVar4 + 0xc) & 0xffffff) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        *(undefined4 *)puVar4 = 0;
        *(undefined4 *)((int)puVar4 + 4) = 0;
        pcVar3 = *(code **)(puVar4 + 2);
        uVar5 = *(undefined4 *)((int)puVar4 + 0x14);
        (*(code *)PTR_FUN_420004c8)();
        (*(code *)PTR_vPortExitCritical_420004e0)(PTR_DAT_420019f8);
        (*pcVar3)(uVar5);
        (*(code *)PTR_FUN_420004c8)();
        (*(code *)PTR_spinlock_acquire_420004dc)(PTR_DAT_420019f8,0xffffffff);
      }
    }
    if (bVar1) {
      (*(code *)PTR_FUN_42001a08)(0xffffffff,0xffffffff,0);
    }
LAB_4201aef9:
    (*(code *)PTR_FUN_420004c8)();
    (*(code *)PTR_vPortExitCritical_420004e0)(PTR_DAT_420019f8);
  } while( true );
}


