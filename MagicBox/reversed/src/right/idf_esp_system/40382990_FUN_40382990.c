undefined4 FUN_40382990(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  int local_50;
  int iStack_4c;
  undefined1 auStack_48 [2];
  undefined1 uStack_46;
  undefined1 *puStack_3c;
  undefined2 uStack_34;
  undefined1 uStack_32;
  
  local_50 = 0;
  iStack_4c = 0;
  (*DAT_4037448c)(auStack_48,0,0x1c);
  uStack_46 = 8;
  uStack_34 = 0x4b;
  uStack_32 = 0x20;
  puStack_3c = (undefined1 *)&local_50;
  uVar1 = (**(code **)(*(int *)*param_1 + 4))((int *)*param_1,auStack_48);
  iVar2 = iStack_4c + -1;
  if (local_50 - 1U != 0xffffffff) {
    iVar2 = iStack_4c;
  }
  if ((iVar2 == -1) && (0xfffffffd < local_50 - 1U)) {
    *param_2 = local_50;
    param_2[1] = iStack_4c;
    uVar1 = 0x106;
  }
  else {
    uVar3 = (*DAT_40375268)();
    *(undefined8 *)param_2 = uVar3;
  }
  return uVar1;
}