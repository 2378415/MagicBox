// strings: Db7@8a7@

void frame_build_ep0(char param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 *local_30 [12];
  
  memw();
  memw();
  *DAT_42000d88 = param_1;
  memw();
  memw();
  *DAT_42000d8c = param_1;
  FUN_420103b8(param_1);
  local_30[0] = (undefined1 *)(*(code *)PTR_FUN_42000484)(DAT_42000424,8);
  if (local_30[0] != (undefined1 *)0x0) {
    (*DAT_42000240)(local_30[0],0,DAT_42000424);
    *local_30[0] = 0x5a;
    local_30[0][1] = 0xa0;
    *(undefined2 *)(local_30[0] + 2) = 1;
    if (param_1 == '\0') {
      uVar3 = 0xff;
    }
    else {
      uVar3 = 0;
    }
    local_30[0][4] = uVar3;
    iVar2 = *DAT_42000d64;
    if (iVar2 == 0) {
      (*(code *)PTR_FUN_420008b4)();
    }
    else {
      while (iVar1 = (*(code *)PTR_FUN_42000d78)(iVar2), iVar1 == 0) {
        queue_drain(iVar2,0);
      }
      (*(code *)PTR_FUN_42000358)(iVar2,local_30,0);
    }
    if (param_1 == '\0') {
      memw();
      memw();
      *DAT_42000d48 = 0;
      FUN_4200fb00();
      FUN_4200fb1c();
      FUN_42024984();
    }
  }
  return;
}