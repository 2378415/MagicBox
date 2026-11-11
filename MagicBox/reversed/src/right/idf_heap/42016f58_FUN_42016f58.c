int FUN_42016f58(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  
  while( true ) {
    iVar5 = (*(code *)PTR_FUN_420006e0)((uint)(param_1 == 0) + (uint)(param_1 != 0) * param_1);
    if (iVar5 != 0) break;
    pcVar3 = (code *)FUN_42016d68();
    if (pcVar3 == (code *)0x0) {
      puVar4 = (undefined4 *)FUN_42017204(4);
      puVar2 = PTR_PTR_42001144;
      puVar1 = PTR_FUN_42001140;
      *puVar4 = PTR_PTR_4200113c;
      pcVar3 = (code *)FUN_42017210(puVar4,puVar2,puVar1);
    }
    (*pcVar3)();
  }
  return iVar5;
}