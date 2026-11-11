// 42019750  esp_mmu_vaddr_to_paddr  FUN_42019750  size=181
// strings: esp_mmu_vaddr_to_paddr | mmap

undefined4 FUN_42019750(int param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  uint uStack_30;
  uint auStack_2c [11];
  
  puVar6 = PTR_PTR_4200175c;
  uVar4 = (uint)(param_1 == 0);
  if (param_1 != 0) {
    if (param_2 == (uint *)0x0) {
      uVar4 = 1;
    }
    if (uVar4 == 0) {
      iVar2 = (*(code *)PTR_FUN_420017b0)(0,param_1,1,3);
      puVar6 = PTR_PTR_4200175c;
      if (iVar2 != 0) {
        uStack_30 = uVar4;
        auStack_2c[0] = uVar4;
        iVar2 = (*(code *)PTR_FUN_420017b4)(param_1,auStack_2c,&uStack_30);
        puVar6 = PTR_PTR_4200175c;
        if (iVar2 == 0) {
          uVar3 = *(undefined4 *)PTR_PTR_4200175c;
          uVar1 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (1,uVar3,PTR_DAT_420017ac,uVar1,*(undefined4 *)puVar6,
                     PTR_s_esp_mmu_vaddr_to_paddr_420017a4,0x307);
          return 0x105;
        }
        *param_2 = auStack_2c[0];
        *param_3 = uStack_30;
        return 0;
      }
      uVar3 = *(undefined4 *)PTR_PTR_4200175c;
      uVar1 = (*(code *)PTR_FUN_4200005c)();
      uVar7 = *(undefined4 *)puVar6;
      uVar5 = 0x301;
      puVar6 = PTR_DAT_420017a8;
      goto LAB_420197a4;
    }
  }
  uVar3 = *(undefined4 *)PTR_PTR_4200175c;
  uVar1 = (*(code *)PTR_FUN_4200005c)();
  uVar7 = *(undefined4 *)puVar6;
  uVar5 = 0x300;
  puVar6 = PTR_DAT_42001764;
LAB_420197a4:
  (*(code *)PTR_FUN_42000118)
            (1,uVar3,puVar6,uVar1,uVar7,PTR_s_esp_mmu_vaddr_to_paddr_420017a4,uVar5);
  return 0x102;
}


