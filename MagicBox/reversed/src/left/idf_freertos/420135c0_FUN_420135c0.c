/* WARNING: Control flow encountered bad instruction data */

void FUN_420135c0(int param_1,uint param_2)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar4 = (param_2 < 0x100) * param_2 + (uint)(param_2 >= 0x100) * 0x100;
  (*DAT_42000064)(DAT_42001218,param_1,uVar4);
  iVar3 = DAT_4200121c;
  *(uint *)(DAT_4200121c + 0x40) = uVar4;
  uVar1 = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)(iVar3 + 0x4e) = 0;
  *(undefined1 *)(iVar3 + 0x4d) = uVar1;
  uVar6 = 0;
  if (param_2 != 0) {
    do {
      pbVar5 = (byte *)(param_1 + uVar6);
      bVar2 = *pbVar5;
      if (pbVar5[1] != 4) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((7 < bVar2) && (pbVar5[7] == 1)) {
        *(undefined1 *)((uint)pbVar5[2] * 0x738 + DAT_42000e84 + 2) = 1;
      }
      uVar6 = uVar6 + bVar2;
    } while (uVar6 < uVar4);
  }
  return;
}