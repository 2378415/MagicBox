// 4200bf74  FUN_4200bf74  FUN_4200bf74  size=348

int FUN_4200bf74(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x102;
  }
  uStack_40 = param_4;
  if ((param_3 & 8) != 0) {
    uVar1 = (*DAT_4200030c)(param_1);
    iVar2 = FUN_4200be64(param_1,uVar1,param_2,param_3,param_4,0);
    return iVar2;
  }
  iVar2 = 0;
  if (param_2[0xb] != 0) {
    iVar2 = (*(code *)PTR_FUN_42000660)(0x40,DAT_42000988);
    if (iVar2 == 0) {
      iVar4 = 0;
      iVar3 = 0;
      goto LAB_4200c08e;
    }
    (*DAT_42000064)(iVar2,param_2[0xb],0x40);
  }
  iVar3 = 0;
  if (param_2[0xc] != 0) {
    iVar3 = (*(code *)PTR_FUN_42000660)(0x1c,DAT_42000988);
    if (iVar3 == 0) {
      iVar4 = 0;
      goto LAB_4200c08e;
    }
    (*DAT_42000064)(iVar3,param_2[0xc],0x1c);
  }
  iVar4 = 0;
  if (param_2[0xd] != 0) {
    iVar4 = (*(code *)PTR_FUN_42000660)(0x18,DAT_42000988);
    if (iVar4 == 0) goto LAB_4200c08e;
    (*DAT_42000064)(iVar4,param_2[0xd],0x18);
  }
  uStack_70 = param_2[4];
  uStack_74 = param_2[3];
  uStack_6c = param_2[5];
  uStack_68 = param_2[6];
  uStack_64 = param_2[7];
  uStack_7c = param_2[1];
  uStack_78 = param_2[2];
  uStack_60 = param_2[8];
  uStack_5c = param_2[9];
  uStack_58 = param_2[10];
  local_80 = *param_2;
  iStack_54 = iVar2;
  iStack_50 = iVar3;
  iStack_4c = iVar4;
  uStack_3c = uStack_68;
  uStack_38 = uStack_6c;
  uStack_34 = uStack_70;
  uStack_30 = uStack_64;
  iVar5 = (*(code *)PTR_FUN_42000660)(0x38,DAT_42000988);
  if (iVar5 != 0) {
    (*DAT_42000064)(iVar5,&local_80,0x38);
    uVar1 = (*DAT_4200030c)(param_1);
    iVar2 = FUN_4200be64(param_1,uVar1,iVar5,param_3,uStack_40,0);
    if (iVar2 == 0) {
      return 0;
    }
    (*(code *)PTR_FUN_42000570)(*(undefined4 *)(iVar5 + 0x30));
    (*(code *)PTR_FUN_42000570)(*(undefined4 *)(iVar5 + 0x2c));
    (*(code *)PTR_FUN_42000570)(*(undefined4 *)(iVar5 + 0x34));
    (*(code *)PTR_FUN_42000570)(iVar5);
    return iVar2;
  }
LAB_4200c08e:
  (*(code *)PTR_FUN_42000570)(iVar2);
  (*(code *)PTR_FUN_42000570)(iVar3);
  (*(code *)PTR_FUN_42000570)(iVar4);
  return 0x101;
}


