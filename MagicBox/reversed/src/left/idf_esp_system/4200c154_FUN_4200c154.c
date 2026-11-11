undefined4 FUN_4200c154(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 extraout_a3;
  undefined4 uVar7;
  code *pcVar8;
  
  puVar3 = (uint *)FUN_4200c0d8(param_2);
  if (puVar3 == (uint *)0x0) {
    uVar7 = 2;
  }
  else {
    uVar4 = *puVar3;
    if (((param_3 & 3) == 0) || (uVar7 = 0x1e, (uVar4 & 4) == 0)) {
      uVar7 = FUN_4200bf38(puVar3,param_2);
      pcVar8 = *(code **)(puVar3[1] + 0x14);
      if (pcVar8 != (code *)0x0) {
        if ((uVar4 & 2) == 0) {
          iVar5 = (*pcVar8)(uVar7,param_3,param_4);
        }
        else {
          iVar5 = (*pcVar8)(puVar3[7],uVar7,param_3,param_4);
        }
        if (iVar5 < 0) {
          puVar6 = (undefined4 *)FUN_42020b54();
          uVar7 = *puVar6;
          goto LAB_4200c174;
        }
        (*(code *)PTR_FUN_420008d8)(DAT_42000c6c);
        puVar2 = PTR_DAT_42000c70;
        if (PTR_DAT_42000c70[1] == -1) {
          bVar1 = *PTR_DAT_42000c70;
          PTR_DAT_42000c70[1] = (char)puVar3[8];
          uVar7 = DAT_42000c6c;
          *puVar2 = bVar1 & 0xfe;
          puVar2[2] = (char)iVar5;
          (*(code *)PTR_FUN_420008dc)(uVar7);
          return 0;
        }
        (*(code *)PTR_FUN_420008dc)(DAT_42000c6c,extraout_a3,0x40);
        pcVar8 = *(code **)(puVar3[1] + 0x18);
        if (pcVar8 != (code *)0x0) {
          if ((*puVar3 & 2) == 0) {
            (*pcVar8)(iVar5);
          }
          else {
            (*pcVar8)(puVar3[7],iVar5);
          }
          uVar7 = 0xc;
          goto LAB_4200c174;
        }
      }
      uVar7 = 0x58;
    }
  }
LAB_4200c174:
  *param_1 = uVar7;
  return 0xffffffff;
}