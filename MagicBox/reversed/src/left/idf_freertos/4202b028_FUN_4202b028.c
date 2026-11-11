undefined4 FUN_4202b028(undefined4 *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  
  if (param_3[2] != 0) {
    puVar4 = (undefined4 *)*param_3;
    do {
      do {
        uVar5 = *puVar4;
        uVar3 = puVar4[1];
        puVar4 = puVar4 + 2;
      } while (uVar3 == 0);
      uVar1 = uVar3;
      if (((uint)param_2[2] <= uVar3) &&
         (uVar1 = param_2[2], (*(ushort *)(param_2 + 3) & 0x480) != 0)) {
        iVar6 = *param_2 - param_2[4];
        uVar1 = (param_2[5] * 3) / 2;
        uVar7 = iVar6 + 1 + uVar3;
        if (uVar1 < uVar7) {
          uVar1 = uVar7;
        }
        if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
          iVar2 = (*(code *)PTR_FUN_42001c8c)(param_1);
          if (iVar2 == 0) {
            (*(code *)PTR_FUN_42001c38)(param_1,param_2[4]);
            goto LAB_4202b114;
          }
        }
        else {
          iVar2 = (*(code *)PTR_FUN_42001c78)(param_1,uVar1);
          if (iVar2 == 0) {
LAB_4202b114:
            *param_1 = 0xc;
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
            param_3[2] = 0;
            uVar5 = 0xffffffff;
            goto LAB_4202b12b;
          }
          (*DAT_42000064)(iVar2,param_2[4],iVar6);
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
        }
        param_2[4] = iVar2;
        *param_2 = iVar2 + iVar6;
        param_2[5] = uVar1;
        param_2[2] = uVar1 - iVar6;
        uVar1 = uVar3;
      }
      (*DAT_42001c90)(*param_2,uVar5,uVar1);
      param_2[2] = param_2[2] - uVar1;
      *param_2 = *param_2 + uVar1;
      iVar6 = param_3[2];
      param_3[2] = iVar6 - uVar3;
    } while (iVar6 - uVar3 != 0);
  }
  uVar5 = 0;
LAB_4202b12b:
  param_3[1] = 0;
  return uVar5;
}