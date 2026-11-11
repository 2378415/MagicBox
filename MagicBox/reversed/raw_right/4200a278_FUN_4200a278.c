// 4200a278  FUN_4200a278  FUN_4200a278  size=191
// strings: <k7@

undefined4 FUN_4200a278(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  code *pcVar5;
  uint uVar6;
  
  puVar2 = (uint *)FUN_42009f90(param_2);
  if (puVar2 == (uint *)0x0) {
    uVar6 = 0xffffffff;
  }
  else if (param_2 < 0x40) {
    uVar6 = (uint)(byte)PTR_DAT_420009a0[param_2 * 3 + 2];
  }
  else {
    uVar6 = 0xffffffff;
  }
  if (puVar2 == (uint *)0x0 || (int)uVar6 < 0) {
    *param_1 = 9;
    uVar3 = 0xffffffff;
  }
  else {
    pcVar5 = *(code **)(puVar2[1] + 0x18);
    if (pcVar5 == (code *)0x0) {
      *param_1 = 0x58;
      uVar3 = 0xffffffff;
    }
    else {
      if ((*puVar2 & 2) == 0) {
        uVar3 = (*pcVar5)();
      }
      else {
        uVar3 = (*pcVar5)(puVar2[7],uVar6);
      }
      (*(code *)PTR_FUN_42000700)(DAT_420009a8);
      iVar1 = param_2 * 3;
      if ((PTR_DAT_420009a0[iVar1] & 1) == 0) {
        if ((PTR_DAT_420009a0[iVar1] & 4) == 0) {
          puVar4 = PTR_DAT_420009a0 + param_2 * 3;
          (*DAT_42000240)(puVar4,0,3);
          puVar4[1] = 0xff;
          puVar4[2] = 0xff;
        }
        else {
          PTR_DAT_420009a0[iVar1] = PTR_DAT_420009a0[iVar1] | 2;
        }
      }
      (*(code *)PTR_FUN_42000704)(DAT_420009a8);
    }
  }
  return uVar3;
}


