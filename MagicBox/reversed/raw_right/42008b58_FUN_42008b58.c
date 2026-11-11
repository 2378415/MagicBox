// 42008b58  FUN_42008b58  FUN_42008b58  size=473

int FUN_42008b58(uint param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_40;
  uint uStack_3c;
  undefined *puStack_30;
  
  if (param_1 < 3) {
    if (param_2 == (uint *)0x0) {
      iVar1 = -1;
    }
    else if ((char)param_2[5] < '\0') {
      iVar1 = -1;
    }
    else if (param_2[4] < 4) {
      if (param_2[1] < 4) {
        if ((param_2[7] & 3) == 0) {
          FUN_42007718(param_1);
          uVar3 = param_2[6];
          if (uVar3 == 0) {
            uVar3 = 4;
          }
          else if (uVar3 == 9) {
            FUN_42013904();
          }
          iVar1 = FUN_42013a38(uVar3,0,&local_40);
          puVar4 = PTR_DAT_42000848;
          if (iVar1 == 0) {
            puStack_30 = PTR_DAT_42000848 + param_1 * 0x18 + 0xc;
            (*(code *)PTR_FUN_420003a8)(puStack_30,0xffffffff);
            puVar4 = puVar4 + param_1 * 0x18 + 8;
            FUN_420136f0(puVar4,param_1);
            FUN_42024ba8(uVar3,1);
            iVar2 = *(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8);
            if (uVar3 == 9) {
              memw();
              memw();
              *(uint *)(iVar2 + 0x78) = *(uint *)(iVar2 + 0x78) & DAT_420008d8 | DAT_420008e0;
            }
            else if (uVar3 == 0xb) {
              memw();
              memw();
              *(uint *)(iVar2 + 0x78) = *(uint *)(iVar2 + 0x78) | DAT_420008e4;
            }
            else if (uVar3 == 4) {
              memw();
              memw();
              *(uint *)(iVar2 + 0x78) = *(uint *)(iVar2 + 0x78) & DAT_420008d8 | DAT_420008dc;
            }
            else {
              (*(code *)PTR_FUN_4200006c)();
            }
            uVar3 = *param_2;
            iVar8 = (int)((ulonglong)uVar3 * (ulonglong)DAT_420008c0 >> 0x20);
            uVar5 = local_40 + uVar3 * DAT_420008c0;
            if (uVar5 < local_40) {
              iVar8 = iVar8 + 1;
            }
            iVar6 = uVar5 - 1;
            iVar7 = iVar8 + -1;
            if (iVar6 != -1) {
              iVar7 = iVar8;
            }
            iVar8 = (*DAT_420000d0)(iVar6,iVar7);
            if (iVar8 == 0) {
              iVar8 = (*(code *)PTR_FUN_4200006c)();
            }
            uVar3 = (local_40 << 4) / (uVar3 * iVar8);
            memw();
            memw();
            *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffff000 | uVar3 >> 4 & 0xfff;
            memw();
            memw();
            *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & DAT_420008c4 | (uVar3 & 0xf) << 0x14
            ;
            memw();
            memw();
            memw();
            uStack_3c = *(uint *)(iVar2 + 0x78) & DAT_420008c8 | (iVar8 - 1U & 0xff) << 0xc;
            memw();
            memw();
            memw();
            *(uint *)(iVar2 + 0x78) = uStack_3c;
            FUN_42024adc(puVar4,param_2[2]);
            FUN_42024aa8(puVar4,param_2[1]);
            FUN_42024a74(puVar4,param_2[3]);
            FUN_420136ac(puVar4,0);
            FUN_42013638(puVar4,param_2[4],(char)param_2[5]);
            (*(code *)PTR_FUN_420003ac)(puStack_30);
            FUN_42002b78(puVar4);
            FUN_42002b50(puVar4);
          }
        }
        else {
          iVar1 = 0x106;
        }
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


