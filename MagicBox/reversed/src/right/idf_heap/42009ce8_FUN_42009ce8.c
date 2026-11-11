int FUN_42009ce8(undefined4 *param_1)

{
  int iVar1;
  int local_70;
  int iStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  
  (*DAT_42000240)(&local_70,0,0xc);
  if (param_1[0xb] != 0) {
    local_70 = (*(code *)PTR_FUN_42000484)(0x40,DAT_4200077c);
    if (local_70 == 0) goto LAB_42009daf;
    (*DAT_420002fc)(local_70,param_1[0xb],0x40);
  }
  if (param_1[0xc] != 0) {
    iStack_6c = (*(code *)PTR_FUN_42000484)(0x1c,DAT_4200077c);
    if (iStack_6c == 0) goto LAB_42009daf;
    (*DAT_420002fc)(iStack_6c,param_1[0xc],0x1c);
  }
  if (param_1[0xd] != 0) {
    iStack_68 = (*(code *)PTR_FUN_42000484)(0x18,DAT_4200077c);
    if (iStack_68 == 0) goto LAB_42009daf;
    (*DAT_420002fc)(iStack_68,param_1[0xd],0x18);
  }
  uStack_64 = *param_1;
  uStack_60 = param_1[1];
  uStack_5c = param_1[2];
  uStack_58 = param_1[3];
  uStack_54 = param_1[4];
  uStack_50 = param_1[5];
  uStack_4c = param_1[6];
  uStack_48 = param_1[7];
  uStack_44 = param_1[8];
  uStack_40 = param_1[9];
  uStack_3c = param_1[10];
  iStack_38 = local_70;
  iStack_34 = iStack_6c;
  iStack_30 = iStack_68;
  iVar1 = (*(code *)PTR_FUN_42000484)(0x38,DAT_4200077c);
  if (iVar1 != 0) {
    (*DAT_420002fc)(iVar1,&uStack_64,0x38);
    return iVar1;
  }
LAB_42009daf:
  FUN_42009cc8(&local_70);
  return 0;
}