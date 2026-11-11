// strings: Lk7@

uint FUN_420099f4(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  (*(code *)PTR_FUN_42000818)(PTR_DAT_42000948);
  uVar1 = 0;
  do {
    if (param_3 <= uVar1) break;
    iVar2 = FUN_42009474(param_1);
    if (iVar2 == 0xd) {
      if (*(int *)(PTR_DAT_42000920 + 0x14) == 1) {
        iVar2 = 10;
      }
      else if (*(int *)(PTR_DAT_42000920 + 0x14) == 0) {
        iVar3 = FUN_42009474(param_1);
        if (iVar3 == -1) {
          FUN_420099d0(param_1,0xd);
          break;
        }
        if (iVar3 == 10) {
          iVar2 = 10;
        }
        else {
          FUN_420099d0(param_1,iVar3);
        }
      }
    }
    else if (iVar2 == -1) break;
    *(char *)(param_2 + uVar1) = (char)iVar2;
    uVar1 = uVar1 + 1;
  } while (iVar2 != 10);
  (*(code *)PTR_FUN_4200081c)(PTR_DAT_42000948);
  if (uVar1 == 0) {
    puVar4 = (undefined4 *)FUN_420180e4();
    *puVar4 = 0xb;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}