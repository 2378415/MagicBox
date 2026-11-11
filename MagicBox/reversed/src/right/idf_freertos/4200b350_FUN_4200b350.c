undefined4 FUN_4200b350(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 uStack_59;
  undefined1 uStack_58;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  
  if (*(short *)(param_1 + 0x48) == 1) {
    (*DAT_42000240)(&local_60,0,0x34);
    local_60 = 0x7f;
    uStack_5f = 0x45;
    uStack_5e = 0x4c;
    uStack_5d = 0x46;
    uStack_5c = 1;
    uStack_5b = 1;
    uStack_5a = 1;
    uStack_59 = 0;
    uStack_58 = 0;
    uStack_50 = 4;
    uStack_4e = FUN_42024754();
    uStack_3c = 0;
    uStack_4c = 1;
    uStack_48 = 0;
    uStack_44 = 0x34;
    uStack_36 = 0x20;
    uStack_40 = 0;
    uStack_38 = 0x34;
    uStack_32 = 0x28;
    uStack_30 = 0;
    uStack_2e = 0;
    uStack_34 = param_2;
    iVar1 = FUN_4200aed4(param_1 + 0x54,&local_60);
    if (iVar1 != 0) {
      return 0xfffffffe;
    }
  }
  if (*(short *)(param_1 + 0x48) == 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x34;
  }
  return uVar2;
}