bool serial_read(int param_1,undefined *param_2,int param_3,uint param_4,int *param_5,
                 undefined1 *param_6)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined1 local_50;
  undefined1 auStack_4f [23];
  uint auStack_38 [2];
  undefined1 *puStack_30;
  
  memw();
  cVar1 = *DAT_42000ec4;
  if (cVar1 == '\0') {
    local_50 = 0xff;
    uart0_reply(&local_50,1,0);
  }
  else {
    if (param_1 == 1) {
      iVar2 = FUN_42013bec(0);
      return iVar2 == 0;
    }
    if (param_1 == 2) {
      puVar4 = PTR_DAT_42000ec0;
      if (param_2 != (undefined *)0x0) {
        puVar4 = param_2;
      }
      iVar2 = FUN_42013bec(puVar4);
      return iVar2 == 0;
    }
    if ((((param_1 == 0) && (param_3 != 0)) && (param_4 != 0 && param_3 != 0)) &&
       (((param_5 != (int *)0x0 &&
         (auStack_38[0] = (uint)(param_6 == (undefined1 *)0x0), auStack_38[0] == 0)) &&
        ((puStack_30 = param_6, iVar2 = uart0_read_string(&local_50,0x16,auStack_38), iVar2 == 0 &&
         (auStack_38[0] != 0)))))) {
      *puStack_30 = local_50;
      if (auStack_38[0] == 1) {
        *param_5 = 0;
        return (bool)cVar1;
      }
      uVar3 = auStack_38[0] - 1;
      iVar2 = (uVar3 < param_4) * uVar3 + (uVar3 >= param_4) * param_4;
      (*DAT_42000064)(param_3,auStack_4f,iVar2);
      *param_5 = iVar2;
      return (bool)cVar1;
    }
  }
  return false;
}