undefined4 FUN_42003e0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  (*(code *)PTR_FUN_42000474)();
  uVar1 = (*(code *)PTR_FUN_42000478)();
  puVar3 = (undefined4 *)(param_1 * 4 + DAT_4200045c);
  param_1 = param_1 * 4;
  uVar2 = (*(code *)PTR_FUN_42000478)(*puVar3);
  if (uVar2 < uVar1) {
    (*(code *)PTR_FUN_4200047c)(*puVar3,uVar1);
  }
  puVar4 = (undefined4 *)(DAT_42000460 + param_1);
  (*(code *)PTR_FUN_42000480)(*puVar4,0xffffffff);
  puVar3 = (undefined4 *)(DAT_4200045c + param_1);
  (*(code *)PTR_FUN_4200047c)(*puVar3,uVar1);
  memw();
  *(undefined4 *)(DAT_42000464 + param_1) = param_3;
  uVar5 = *puVar3;
  memw();
  *(undefined4 *)(DAT_42000468 + param_1) = param_4;
  memw();
  *(undefined4 *)(DAT_4200046c + param_1) = param_2;
  (*(code *)PTR_FUN_42000484)(uVar5,0,0,2);
  (*(code *)PTR_FUN_42000480)(*(undefined4 *)(DAT_42000470 + param_1),0xffffffff);
  (*(code *)PTR_FUN_42000488)(*puVar4,0,0);
  return 0;
}