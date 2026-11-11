// 4200ab94  FUN_4200ab94  FUN_4200ab94  size=59

undefined4 FUN_4200ab94(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 < 0x10) {
    (*DAT_42000240)(param_2,0,0x58);
    *(undefined4 *)(param_2 + 4) = DAT_420009b4;
    *(undefined2 *)(param_2 + 8) = 1;
    *(undefined2 *)(param_2 + 10) = 0;
    *(undefined2 *)(param_2 + 0xc) = 0;
    uVar2 = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    puVar1 = (undefined4 *)FUN_420180e4();
    *puVar1 = 9;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


