// 42019660  esp_mmu_unmap  FUN_42019660  size=236
// strings: esp_mmu_unmap | mmap

undefined4 FUN_42019660(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  undefined4 uVar12;
  
  puVar11 = PTR_PTR_4200175c;
  piVar1 = DAT_4200174c;
  if (param_1 == 0) {
    uVar3 = *(undefined4 *)PTR_PTR_4200175c;
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)
              (1,uVar3,PTR_DAT_42001764,uVar2,*(undefined4 *)puVar11,PTR_s_esp_mmu_unmap_42001794,
               0x273);
    uVar2 = 0x102;
  }
  else {
    if (((*DAT_4200174c == 0) || (param_1 = param_1 & 0x1ffffff, param_1 < (uint)DAT_4200174c[5]))
       || ((uint)DAT_4200174c[3] <= param_1)) {
      uVar3 = *(undefined4 *)PTR_PTR_4200175c;
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      uVar12 = *(undefined4 *)puVar11;
      uVar6 = 0x281;
      puVar11 = PTR_DAT_42001798;
    }
    else {
      puVar8 = (uint *)DAT_4200174c[9];
      if (puVar8 != (uint *)0x0) {
        puVar4 = puVar8;
        while (puVar4 = (uint *)puVar4[9], puVar4 != (uint *)0x0) {
          if (((puVar4 != puVar8) && (puVar4 != (uint *)**(int **)(DAT_4200174c[10] + 4))) &&
             (param_1 == *puVar4)) {
            uVar7 = DAT_4200174c[6];
            uVar10 = puVar4[4];
            uVar5 = *(int *)puVar4[9] - *(int *)(**(int **)(puVar4[10] + 4) + 4);
            uVar9 = puVar4[2];
            DAT_4200174c[6] = (uVar5 < uVar7) * uVar7 + (uVar5 >= uVar7) * uVar5;
            (*(code *)PTR_FUN_420017a0)(uVar9,uVar10);
            uVar5 = puVar4[9];
            puVar8 = (uint *)puVar4[10];
            if (uVar5 == 0) {
              piVar1[10] = (int)puVar8;
            }
            else {
              *(uint **)(uVar5 + 0x28) = puVar8;
            }
            *puVar8 = uVar5;
            (*(code *)PTR_FUN_42000570)(puVar4);
            return 0;
          }
        }
      }
      uVar3 = *(undefined4 *)PTR_PTR_4200175c;
      uVar2 = (*(code *)PTR_FUN_4200005c)();
      uVar12 = *(undefined4 *)puVar11;
      uVar6 = 0x296;
      puVar11 = PTR_DAT_4200179c;
    }
    (*(code *)PTR_FUN_42000118)(1,uVar3,puVar11,uVar2,uVar12,PTR_s_esp_mmu_unmap_42001794,uVar6);
    uVar2 = 0x105;
  }
  return uVar2;
}


