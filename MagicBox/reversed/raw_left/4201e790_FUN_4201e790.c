// 4201e790  FUN_4201e790  FUN_4201e790  size=62

int FUN_4201e790(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  
  while( true ) {
    iVar5 = (*(code *)PTR_FUN_4200056c)((uint)(param_1 == 0) + (uint)(param_1 != 0) * param_1);
    if (iVar5 != 0) break;
    pcVar3 = (code *)FUN_4201e5a0();
    if (pcVar3 == (code *)0x0) {
      puVar4 = (undefined4 *)FUN_4201ea34(4);
      puVar2 = PTR_PTR_42001b28;
      puVar1 = PTR_FUN_42001b24;
      *puVar4 = PTR_PTR_42001b20;
      pcVar3 = (code *)FUN_4201ea40(puVar4,puVar2,puVar1);
    }
    (*pcVar3)();
  }
  return iVar5;
}


