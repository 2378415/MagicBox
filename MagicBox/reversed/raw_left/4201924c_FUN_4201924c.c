// 4201924c  FUN_4201924c  FUN_4201924c  size=58
// strings: esp_mmu_map

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4201924c(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_a7;
  
  puVar1 = PTR_PTR_4200175c;
  if (in_a7 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar3 = *(undefined4 *)PTR_PTR_4200175c;
  uVar2 = (*(code *)PTR_FUN_4200005c)();
  (*(code *)PTR_FUN_42000118)
            (1,uVar3,PTR_DAT_42001764,uVar2,*(undefined4 *)puVar1,PTR_s_esp_mmu_map_42001760,0x1b7);
  return 0x102;
}


