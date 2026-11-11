// 420150a0  FUN_420150a0  FUN_420150a0  size=41

int FUN_420150a0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_30 [12];
  
  *param_2 = 0;
  if (*(char *)(param_1 + 0x12) == '\0') {
    iVar1 = DAT_4200108c;
  }
  else {
    iVar1 = FUN_420145b0(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),local_30);
    if (iVar1 == 0) {
      *param_2 = local_30[0];
    }
  }
  return iVar1;
}


