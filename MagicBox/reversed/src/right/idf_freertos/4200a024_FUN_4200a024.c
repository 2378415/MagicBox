// strings: <k7@

int FUN_4200a024(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  code *pcVar7;
  byte *pbVar8;
  
  puVar1 = (uint *)FUN_42009fb8(param_2);
  if (puVar1 == (uint *)0x0) {
    *param_1 = 2;
  }
  else {
    uVar2 = *puVar1;
    if (((uint)((param_3 & 3) != 0) & uVar2 >> 2 & 1) == 0) {
      uVar3 = FUN_42009ed0(puVar1,param_2);
      pcVar7 = *(code **)(puVar1[1] + 0x14);
      if (pcVar7 == (code *)0x0) {
        *param_1 = 0x58;
      }
      else {
        if ((uVar2 & 2) == 0) {
          iVar4 = (*pcVar7)(uVar3,param_3,param_4);
        }
        else {
          iVar4 = (*pcVar7)(puVar1[7],uVar3,param_3,param_4);
        }
        if (iVar4 < 0) {
          puVar6 = (undefined4 *)FUN_420180e4();
          *param_1 = *puVar6;
        }
        else {
          (*(code *)PTR_FUN_42000700)(DAT_420009a8);
          for (iVar5 = 0; iVar5 < 0x40; iVar5 = iVar5 + 1) {
            if (PTR_DAT_420009a0[iVar5 * 3 + 1] == -1) {
              pbVar8 = PTR_DAT_420009a0 + iVar5 * 3;
              *pbVar8 = *pbVar8 & 0xfe;
              pbVar8[1] = (byte)puVar1[8];
              pbVar8[2] = (byte)iVar4;
              (*(code *)PTR_FUN_42000704)(DAT_420009a8);
              return iVar5;
            }
          }
          (*(code *)PTR_FUN_42000704)(DAT_420009a8);
          pcVar7 = *(code **)(puVar1[1] + 0x18);
          if (pcVar7 == (code *)0x0) {
            *param_1 = 0x58;
          }
          else {
            if ((*puVar1 & 2) == 0) {
              (*pcVar7)(iVar4);
            }
            else {
              (*pcVar7)(puVar1[7],iVar4);
            }
            *param_1 = 0xc;
          }
        }
      }
    }
    else {
      *param_1 = 0x1e;
    }
  }
  return -1;
}