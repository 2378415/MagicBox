// 420115c8  FUN_420115c8  FUN_420115c8  size=342
// strings: PARSE

void FUN_420115c8(undefined4 param_1,int *param_2,int *param_3,int *param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  bVar1 = *(byte *)((int)param_3 + 9);
  bVar2 = *(byte *)((int)param_3 + 10);
  uVar9 = (uint)bVar2;
  piVar5 = (int *)((uint)*(byte *)(param_3 + 2) * 4 + DAT_42000f50);
  *piVar5 = *piVar5 + (int)(short)(ushort)bVar1 * (int)(short)(ushort)bVar2;
  if ((param_5 & 1) == 0) {
    if ((*param_3 == 7) && (*(byte *)(param_3 + 0x57) != 0)) {
      iVar6 = *(byte *)(param_3 + 0x57) - 1;
      uVar7 = param_5 & 2;
      if ((param_5 & 2) == 0) {
        if ((uint)param_3[iVar6 * 5 + 0xe] < 0xa5) {
          uVar4 = (uVar9 < 0x10) * uVar9 + (uint)(uVar9 >= 0x10) * 0x10;
          piVar5 = param_2 + 2;
          uVar10 = (1 < uVar4) * uVar4 + (uint)(1 >= uVar4);
          uVar8 = uVar7;
          while (uVar9 != 0) {
            *piVar5 = *param_4 + uVar8;
            *(byte *)((int)param_2 + uVar7 + 0x48) = bVar1;
            uVar7 = uVar7 + 1;
            uVar8 = uVar8 + bVar1;
            piVar5 = piVar5 + 1;
            uVar10 = uVar10 - 1;
            uVar9 = uVar10;
          }
          *(char *)(param_2 + 0x16) = (char)uVar4;
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (3,PTR_s_PARSE_42000efc,PTR_DAT_42000f5c,uVar3,PTR_s_PARSE_42000efc,uVar4,
                     param_2[2],*(undefined1 *)((int)param_3 + 9));
        }
        else {
          uVar3 = (*(code *)PTR_FUN_4200005c)();
          (*(code *)PTR_FUN_42000118)
                    (2,PTR_s_PARSE_42000efc,PTR_DAT_42000f60,uVar3,PTR_s_PARSE_42000efc,
                     param_3[iVar6 * 5 + 0xe],param_3[iVar6 * 5 + 0xf]);
        }
      }
      else if ((0xdf < (uint)param_3[iVar6 * 5 + 0xe]) && ((uint)param_3[iVar6 * 5 + 0xf] < 0xe8)) {
        *param_2 = *param_4;
        *(byte *)(param_2 + 1) = bVar1 * bVar2;
        uVar3 = (*(code *)PTR_FUN_4200005c)();
        (*(code *)PTR_FUN_42000118)
                  (3,PTR_s_PARSE_42000efc,PTR_DAT_42000f58,uVar3,PTR_s_PARSE_42000efc,*param_4,
                   (int)(short)(ushort)*(byte *)((int)param_3 + 9) *
                   (int)(short)(ushort)*(byte *)((int)param_3 + 10));
      }
    }
    else {
      uVar3 = (*(code *)PTR_FUN_4200005c)();
      (*(code *)PTR_FUN_42000118)
                (2,PTR_s_PARSE_42000efc,PTR_DAT_42000f64,uVar3,PTR_s_PARSE_42000efc,*param_3,
                 (char)param_3[0x57]);
    }
    *param_4 = *param_4 +
               (int)(short)(ushort)*(byte *)((int)param_3 + 9) *
               (int)(short)(ushort)*(byte *)((int)param_3 + 10);
  }
  else {
    *param_4 = *param_4 + (int)(short)(ushort)bVar1 * (int)(short)(ushort)bVar2;
    uVar3 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(3,PTR_s_PARSE_42000efc,PTR_DAT_42000f54,uVar3,PTR_s_PARSE_42000efc);
  }
  return;
}


