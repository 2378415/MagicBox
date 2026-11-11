// 4202d844  FUN_4202d844  FUN_4202d844  size=48

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_4202d844(undefined4 param_1,int param_2,uint param_3)

{
  char unaff_a8;
  undefined4 uVar1;
  
  if ((unaff_a8 == '\x01') && (param_3 < 0x7f)) {
    if (param_2 <= (int)(param_3 - 1)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


