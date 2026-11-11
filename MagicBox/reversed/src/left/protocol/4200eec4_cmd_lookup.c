// strings: right() | left() | middle()

undefined * cmd_lookup(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  if ((param_1 != 0) && (param_2 != 0 && param_1 != 0)) {
    uVar2 = 0;
    puVar4 = PTR_PTR_42000dbc;
    puVar5 = PTR_s_left___42000db8;
    do {
      uVar3 = *(uint *)(puVar4 + 4);
      if ((uVar3 <= param_2) && (iVar1 = (*DAT_42000114)(param_1,puVar5,uVar3), iVar1 == 0)) {
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar3;
        }
        return PTR_PTR_42000dbc + (uVar2 & 0xffff) * 0x14;
      }
      puVar5 = *(undefined **)(puVar4 + 0x14);
      uVar2 = uVar2 + 1;
      puVar4 = puVar4 + 0x14;
    } while (puVar5 != (undefined *)0x0);
  }
  return (undefined *)0x0;
}