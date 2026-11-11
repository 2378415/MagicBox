// 42014610  FUN_42014610  FUN_42014610  size=133

undefined4 FUN_42014610(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_50 [2];
  byte bStack_4e;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  int aiStack_30 [12];
  
  iVar3 = *(int *)(param_1 + 0x10);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    aiStack_30[0] = 0;
    while (iVar2 = FUN_42015dbc(iVar3,0xff,0x48,0,aiStack_30,auStack_50,0xff,0xff), iVar2 == 0) {
      puVar1 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x28);
      if (puVar1 == (undefined4 *)0x0) {
        return 0x101;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      FUN_42013fe4(auStack_50,puVar1 + 2);
      *(undefined1 *)(puVar1 + 6) = auStack_50[0];
      *(undefined1 *)((int)puVar1 + 0x1a) = uStack_33;
      *(undefined1 *)((int)puVar1 + 0x19) = uStack_34;
      puVar1[7] = uStack_38;
      puVar1[8] = 0;
      puVar1[9] = 0;
      FUN_42024c30(param_2,puVar1);
      aiStack_30[0] = aiStack_30[0] + (uint)bStack_4e;
    }
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}


