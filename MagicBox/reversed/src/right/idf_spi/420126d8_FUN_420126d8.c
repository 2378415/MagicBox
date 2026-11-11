// strings: \x7@

undefined4 FUN_420126d8(uint param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    uVar1 = 0x102;
  }
  else {
    param_1 = param_1 & 0x1ffffff;
    puVar2 = (uint *)0x0;
    for (uVar4 = 0; uVar4 < *DAT_42000ebc; uVar4 = uVar4 + 1) {
      if ((DAT_42000ebc[uVar4 * 10 + 5] <= param_1) && (param_1 < DAT_42000ebc[uVar4 * 10 + 3])) {
        puVar2 = DAT_42000ebc + uVar4 * 10 + 1;
      }
    }
    if (puVar2 == (uint *)0x0) {
      uVar1 = 0x105;
    }
    else {
      for (puVar3 = (uint *)puVar2[8]; puVar3 != (uint *)0x0; puVar3 = (uint *)puVar3[9]) {
        if ((((uint *)puVar2[8] != puVar3) && ((uint *)**(undefined4 **)(puVar2[9] + 4) != puVar3))
           && (*puVar3 == param_1)) {
          uVar4 = *(int *)puVar3[9] - *(int *)(**(int **)(puVar3[10] + 4) + 4);
          uVar5 = puVar2[5];
          puVar2[5] = (uVar4 < uVar5) * uVar5 + (uVar4 >= uVar5) * uVar4;
          (*(code *)PTR_FUN_42000edc)(puVar3[2],puVar3[4]);
          if (puVar3[9] == 0) {
            puVar2[9] = puVar3[10];
          }
          else {
            *(uint *)(puVar3[9] + 0x28) = puVar3[10];
          }
          *(uint *)puVar3[10] = puVar3[9];
          (*(code *)PTR_FUN_420004c0)(puVar3);
          return 0;
        }
      }
      uVar1 = 0x105;
    }
  }
  return uVar1;
}