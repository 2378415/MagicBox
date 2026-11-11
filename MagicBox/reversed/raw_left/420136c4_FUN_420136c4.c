// 420136c4  FUN_420136c4  FUN_420136c4  size=109

void FUN_420136c4(int param_1,undefined1 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = (param_4 < 0x201) * param_4 + (uint)(param_4 >= 0x201) * 0x201;
  (*DAT_42000064)(param_2 + 7,param_3,iVar1);
  *(int *)(param_2 + 0x208) = iVar1;
  if ((((param_4 < 4) || (param_2[7] != '\x05')) || (param_2[8] != '\x01')) ||
     ((param_2[9] != '\t' || (uVar2 = 1, param_2[10] != '\x02')))) {
    uVar2 = 0;
  }
  param_2[1] = 0;
  *param_2 = uVar2;
  *(char *)(param_1 + 0x164c) = *(char *)(param_1 + 0x164c) + '\x01';
  return;
}


