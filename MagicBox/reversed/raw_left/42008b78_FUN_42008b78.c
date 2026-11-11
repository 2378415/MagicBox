// 42008b78  FUN_42008b78  FUN_42008b78  size=104

int FUN_42008b78(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  cVar1 = *param_1;
  if (((cVar1 != '/') || (param_1[1] != '0')) || (iVar2 = 0, param_1[2] != '\0')) {
    if (((cVar1 == '/') && (param_1[1] == '1')) && (param_1[2] == '\0')) {
      iVar2 = 1;
    }
    else if (((cVar1 != '/') || (param_1[1] != '2')) || (iVar2 = 2, param_1[2] != '\0')) {
      puVar3 = (undefined4 *)FUN_42020b54();
      *puVar3 = 2;
      return -1;
    }
  }
  *(byte *)(*(int *)(PTR_PTR_42000978 + iVar2 * 4) + 0x10) = (byte)(param_2 >> 0xe) & 1;
  return iVar2;
}


