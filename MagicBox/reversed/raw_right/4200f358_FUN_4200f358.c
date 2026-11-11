// 4200f358  FUN_4200f358  FUN_4200f358  size=81

undefined4 FUN_4200f358(undefined2 param_1,undefined2 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_70;
  undefined2 uStack_6e;
  undefined1 uStack_6c;
  undefined1 auStack_6b [63];
  undefined1 uStack_2c;
  
  (*DAT_42000240)(&local_70,0,0x46);
  local_70 = param_1;
  uStack_6e = param_2;
  uStack_6c = param_3;
  (*DAT_42000cfc)(auStack_6b,param_4,0x3f);
  uStack_2c = 0;
  iVar1 = (*(code *)PTR_FUN_42000358)(*DAT_42000cf0,&local_70,100,0);
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x101;
  }
  return uVar2;
}


