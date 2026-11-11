// 4200ab4c  FUN_4200ab4c  FUN_4200ab4c  size=69

undefined4 FUN_4200ab4c(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = (*DAT_420007e8)(param_1,PTR_DAT_420009b0);
  if (iVar1 == 0) {
    (*DAT_42000240)(param_2,0,0x58);
    *(undefined4 *)(param_2 + 4) = DAT_420009b4;
    *(undefined2 *)(param_2 + 8) = 1;
    *(undefined2 *)(param_2 + 10) = 0;
    *(undefined2 *)(param_2 + 0xc) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_420180e4();
    *puVar2 = 2;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


