// strings:          (((((                  

void FUN_4200fd84(int param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte local_50 [21];
  undefined1 auStack_3b [59];
  
  uVar4 = DAT_42000d30;
  puVar3 = DAT_42000d28;
  uVar8 = (uint)*(ushort *)(param_1 + 2);
  uVar7 = 0;
  for (uVar6 = 0; uVar6 < (uVar8 < 0x14) * uVar8 + (uint)(uVar8 >= 0x14) * 0x14; uVar6 = uVar6 + 1)
  {
    bVar1 = *(byte *)(param_1 + uVar6 + 4);
    if (((PTR_DAT_42000d60[bVar1] & 0xf) != 0) && (uVar7 < 0x14)) {
      local_50[uVar7] = bVar1;
      uVar7 = uVar7 + 1;
    }
  }
  local_50[uVar7] = 0;
  if (uVar7 == 0) {
    FUN_4200fd24(param_2);
  }
  else {
    uVar2 = *(undefined1 *)(DAT_42000d28 + 4);
    (*DAT_42000cfc)(auStack_3b,DAT_42000d30);
    *(undefined1 *)(puVar3 + 4) = 1;
    (*DAT_42000cfc)(uVar4,local_50,0x15);
    *(undefined1 *)((int)puVar3 + 0xdd) = 0;
    iVar5 = FUN_4200f358(*puVar3,puVar3[1],*(undefined1 *)(puVar3 + 4),uVar4);
    if (iVar5 == 0) {
      *(undefined2 *)(param_2 + 2) = 1;
      *(undefined1 *)(param_2 + 4) = 0;
      FUN_4200fccc();
    }
    else {
      *(undefined1 *)(DAT_42000d28 + 4) = uVar2;
      (*DAT_42000cfc)(DAT_42000d30,auStack_3b);
      *(undefined2 *)(param_2 + 2) = 1;
      *(undefined1 *)(param_2 + 4) = 0xff;
    }
    *(undefined1 *)((int)DAT_42000d28 + 7) = 0;
  }
  return;
}