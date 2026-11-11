// 42002ce4  FUN_42002ce4  FUN_42002ce4  size=170

void FUN_42002ce4(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar1 = PTR_DAT_42000028;
  iVar5 = 1;
  iVar6 = param_1;
  do {
    iVar4 = iVar5;
    if (iVar6 == 1) {
      while( true ) {
        if (3 < *(uint *)puVar1) {
          uVar2 = (*(code *)PTR_FUN_4200005c)();
          (*DAT_42000060)(PTR_DAT_420001a0,uVar2,PTR_DAT_4200019c);
        }
        if (param_1 == 1) {
          (*(code *)PTR_FUN_420001ac)(1);
        }
        iVar3 = (*(code *)PTR_FUN_420001b0)(2,0x400);
        iVar4 = iVar5;
        if (iVar3 != 0) goto LAB_42002d55;
        iVar4 = iVar5 + -1;
        if (iVar5 < 1) break;
        iVar5 = iVar4;
      }
      if (1 < *(uint *)puVar1) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_420001a4,uVar2,PTR_DAT_4200019c);
      }
      iVar6 = 0;
    }
LAB_42002d55:
    (*(code *)PTR_FUN_420001b4)(iVar6);
    iVar3 = (*(code *)PTR_FUN_420001b0)(0,0x400);
    iVar5 = iVar4;
    if (iVar3 != 0) {
      if (3 < *(uint *)puVar1) {
        uVar2 = (*(code *)PTR_FUN_4200005c)();
        (*DAT_42000060)(PTR_DAT_420001a8,uVar2,PTR_DAT_4200019c,iVar3);
      }
      FUN_4200509c(iVar3);
      return;
    }
  } while( true );
}


