undefined4 FUN_4200cb3c(char *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((*param_1 == '/') && (param_1[1] == '\0')) {
    (*DAT_42000094)(param_2,0,0x58);
    uVar1 = DAT_42000c78;
    *(undefined2 *)(param_2 + 0xc) = 0;
    *(undefined4 *)(param_2 + 4) = uVar1;
    *(undefined4 *)(param_2 + 8) = 1;
    *(undefined4 *)(param_2 + 0x10) = 0;
    return 0;
  }
  puVar2 = (undefined4 *)FUN_42020b54();
  *puVar2 = 2;
  return 0xffffffff;
}