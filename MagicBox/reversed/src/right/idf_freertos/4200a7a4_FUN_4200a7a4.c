undefined4 FUN_4200a7a4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  puVar1 = (uint *)FUN_42009f90(param_1);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0xffffffff;
  }
  else if (param_1 < 0x40) {
    uVar2 = (uint)(byte)PTR_DAT_420009a0[param_1 * 3 + 2];
  }
  else {
    uVar2 = 0xffffffff;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_FUN_420006f0)();
  if (puVar1 == (uint *)0x0 || (int)uVar2 < 0) {
    *puVar3 = 9;
    uVar4 = 0xffffffff;
  }
  else if ((*(undefined4 **)(puVar1[1] + 0x30) == (undefined4 *)0x0) ||
          (pcVar5 = (code *)**(undefined4 **)(puVar1[1] + 0x30), pcVar5 == (code *)0x0)) {
    *puVar3 = 0x58;
    uVar4 = 0xffffffff;
  }
  else if ((*puVar1 & 2) == 0) {
    uVar4 = (*pcVar5)(uVar2,param_2,param_3);
  }
  else {
    uVar4 = (*pcVar5)(puVar1[7],uVar2,param_2,param_3);
  }
  return uVar4;
}