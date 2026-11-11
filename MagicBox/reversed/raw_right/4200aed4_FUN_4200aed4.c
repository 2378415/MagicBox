// 4200aed4  FUN_4200aed4  FUN_4200aed4  size=143
// strings: zUpD

int FUN_4200aed4(int *param_1,int param_2,uint param_3,int param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (*param_1 + (uint)*(byte *)(param_1 + 9) + param_3 < (uint)DAT_420009f8[1]) {
    param_4 = 0;
    goto LAB_4200af5b;
  }
  (*(code *)PTR_FUN_4200006c)();
  do {
    uVar4 = -(*(byte *)(param_1 + 9) - 0x20);
    iVar5 = (uVar4 < param_3) * uVar4 + (uVar4 >= param_3) * param_3;
    (*DAT_420002fc)((int)param_1 + *(byte *)(param_1 + 9) + 4,param_2 + param_4,iVar5);
    bVar1 = *(byte *)(param_1 + 9);
    *(char *)(param_1 + 9) = (char)((uint)bVar1 + iVar5);
    if (((uint)bVar1 + iVar5 & 0xff) == 0x20) {
      piVar2 = param_1 + 1;
      iVar3 = FUN_4200ae14(*DAT_420009f8 + *param_1,piVar2,0x20);
      if (iVar3 != 0) {
        return iVar3;
      }
      *param_1 = *param_1 + 0x20;
      FUN_4200b990(param_1 + 10,piVar2,0x20);
      *(undefined1 *)(param_1 + 9) = 0;
      (*DAT_42000240)(piVar2,0,0x20);
    }
    param_4 = param_4 + iVar5;
    param_3 = param_3 - iVar5;
LAB_4200af5b:
  } while (param_3 != 0);
  return 0;
}


