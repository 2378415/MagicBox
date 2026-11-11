undefined4 FUN_4200b504(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30 [12];
  
  iVar1 = FUN_4200bdb0(param_2,local_30);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffd;
  }
  else {
    uVar2 = FUN_4200b4e4(param_1,PTR_DAT_42000a38,1,local_30[0],iVar1);
  }
  return uVar2;
}