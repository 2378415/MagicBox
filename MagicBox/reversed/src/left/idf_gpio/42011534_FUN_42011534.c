// strings: PARSE

void FUN_42011534(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_FUN_4200056c)(DAT_42000f44);
  if (iVar1 == 0) {
    uVar2 = (*(code *)PTR_FUN_4200005c)();
    (*(code *)PTR_FUN_42000118)(1,PTR_s_PARSE_42000efc,PTR_DAT_42000f48,uVar2,PTR_s_PARSE_42000efc);
  }
  else {
    (*DAT_42000094)(iVar1,0,DAT_42000f44);
    *(undefined1 *)(iVar1 + 0xc) = 0;
  }
  return;
}