void FUN_420048f8(int *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int local_40;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  (*DAT_42000094)(param_1,0,0x1c);
  for (puVar1 = (uint *)*DAT_42000598; puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[8]) {
    if ((puVar1[7] != 0) && ((~(*puVar1 | puVar1[1] | puVar1[2]) & param_2) == 0)) {
      FUN_4202ebe0(puVar1[7],&local_40);
      uVar2 = param_1[2];
      *param_1 = *param_1 + local_40;
      param_1[1] = param_1[1] + iStack_3c;
      param_1[2] = (uVar2 < uStack_38) * uStack_38 + (uVar2 >= uStack_38) * uVar2;
      param_1[3] = param_1[3] + iStack_34;
      param_1[4] = param_1[4] + iStack_30;
      param_1[5] = param_1[5] + iStack_2c;
      param_1[6] = param_1[6] + iStack_28;
    }
  }
  return;
}