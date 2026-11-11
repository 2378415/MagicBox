// strings: %02X 

void frame_echo_hex(undefined4 param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 auStack_120 [288];
  
  puVar1 = PTR_DAT_42000d80;
  puVar2 = auStack_120;
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      puVar4 = (undefined1 *)(param_2 + uVar3);
      uVar3 = uVar3 + 1;
      FUN_4202058c(puVar2,4,puVar1,*puVar4);
      puVar2 = puVar2 + 3;
    } while (uVar3 < (param_3 < 0xff) * param_3 + (uint)(param_3 >= 0xff) * 0xff);
  }
  return;
}