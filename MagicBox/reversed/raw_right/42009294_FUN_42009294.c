// 42009294  FUN_42009294  FUN_42009294  size=303

int FUN_42009294(uint param_1,int param_2,int param_3,uint param_4,undefined4 *param_5,uint param_6)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  if (param_1 < 3) {
    if (param_2 < 0x81) {
      iVar3 = -1;
    }
    else if (param_3 == 0) {
      if ((param_6 & 0x400) != 0) {
        param_6 = param_6 & 0xfffffbff;
      }
      if (*(int *)(param_1 * 4 + DAT_42000844) == 0) {
        puVar2 = (uint *)FUN_420081ec(param_1,param_4,0,param_2);
        *(uint **)(param_1 * 4 + DAT_42000844) = puVar2;
        if (puVar2 == (uint *)0x0) {
          iVar3 = -1;
        }
        else {
          *puVar2 = param_1;
          puVar2[3] = 0;
          *(undefined1 *)(puVar2 + 4) = 0;
          *(undefined1 *)((int)puVar2 + 0x11) = 0;
          puVar2[1] = param_4;
          puVar2[0x11] = 0;
          puVar2[0x12] = 0;
          puVar2[0x13] = 0;
          *(undefined1 *)(puVar2 + 0x15) = 0;
          *(undefined1 *)((int)puVar2 + 0x55) = 0;
          *(undefined1 *)((int)puVar2 + 0x56) = 0;
          puVar2[5] = 0;
          *(undefined1 *)(puVar2 + 7) = 0;
          *(undefined1 *)(puVar2 + 0x10) = 0;
          puVar2[10] = 0x101;
          puVar2[0xf] = 0;
          puVar2[0x16] = 0;
          (*(code *)PTR_FUN_42000358)(puVar2[0x1c],0,0,0);
          FUN_420085c8(param_1,10);
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = *(undefined4 *)(*(int *)(param_1 * 4 + DAT_42000844) + 0x5c);
          }
          local_30 = *(undefined4 *)PTR_DAT_42000908;
          uStack_2c = *(undefined4 *)(PTR_DAT_42000908 + 4);
          FUN_42007718(param_1);
          puVar1 = PTR_DAT_42000848;
          memw();
          memw();
          *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) =
               *(uint *)(*(int *)(PTR_DAT_42000848 + param_1 * 0x18 + 8) + 0xc) & 0xfff80000;
          memw();
          *(undefined4 *)(*(int *)(puVar1 + param_1 * 0x18 + 8) + 0x10) = DAT_420008e8;
          iVar3 = *(int *)(param_1 * 4 + DAT_42000844);
          iVar3 = FUN_42003938(PTR_DAT_42000860[param_1 * 0x14 + 0x10],param_6,PTR_FUN_4200090c,
                               iVar3,iVar3 + 8);
          if ((iVar3 != 0) || (iVar3 = FUN_42008d38(param_1,&local_30), iVar3 != 0)) {
            FUN_4200922c(param_1);
          }
        }
      }
      else {
        iVar3 = -1;
      }
    }
    else {
      iVar3 = -1;
    }
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}


