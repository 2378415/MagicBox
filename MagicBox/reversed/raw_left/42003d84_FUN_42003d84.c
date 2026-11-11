// 42003d84  FUN_42003d84  FUN_42003d84  size=101
// strings: Unknown reason

void FUN_42003d84(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = PTR_PTR_4200044c;
  iVar3 = *(int *)(param_1 + 0x50);
  if (iVar3 == 5) {
    uVar2 = 0;
  }
  else {
    if (iVar3 != 6) {
      if (iVar3 == 7) {
        uVar2 = FUN_4200319c();
        iVar3 = *(int *)(param_1 + 0x50);
        *param_2 = uVar2;
      }
      param_2[2] = PTR_s_Unknown_reason_42000448;
      param_2[3] = 0;
      if (7 < iVar3) {
        return;
      }
      param_2[2] = *(undefined4 *)(PTR_PTR_4200044c + iVar3 * 4);
      puVar1 = PTR_FUN_42000450;
      if (iVar3 == 1) {
        param_2[1] = 0;
        param_2[4] = puVar1;
        return;
      }
      if (iVar3 == 7) {
        param_2[4] = PTR_FUN_42000454;
        return;
      }
      return;
    }
    uVar2 = 1;
  }
  *param_2 = uVar2;
  uVar2 = *(undefined4 *)(puVar1 + iVar3 * 4);
  param_2[1] = 1;
  param_2[3] = 0;
  param_2[2] = uVar2;
  return;
}


