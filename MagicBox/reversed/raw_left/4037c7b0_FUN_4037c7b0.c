// 4037c7b0  FUN_4037c7b0  FUN_4037c7b0  size=120

void FUN_4037c7b0(uint param_1,uint param_2)

{
  int *piVar1;
  int unaff_retaddr;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint in_t0;
  
  piVar1 = DAT_40374e84;
  memw();
  iVar4 = *(int *)(*(int *)(*DAT_40374e84 + 0xc) + 0xc);
  iVar3 = iVar4 + 4;
  FUN_4037cc94(iVar3);
  uVar5 = (uint)*(byte *)(iVar4 + 0x24);
  if ((*(byte *)(iVar4 + 0x24) & 4) != 0) {
    do {
      *(int *)(iVar4 + 0x10) = iVar4;
      uVar2 = param_1 + *(uint *)(iVar4 + 0x18);
      memw();
      *(uint *)(iVar4 + 4) = uVar2;
      if (param_2 < uVar2) {
        if ((param_1 <= param_2) || ((-(uVar5 - 1) & 0xff) == 0)) {
          FUN_4037cc28(*piVar1,iVar3);
          goto LAB_4037c821;
        }
      }
      else if (param_2 - param_1 < *(uint *)(iVar4 + 0x18)) goto code_r0x4037c7fa;
      uVar5 = in_t0;
      (**(code **)(iVar4 + 0x20))(iVar4);
      param_1 = uVar2;
      in_t0 = uVar5;
    } while( true );
  }
  if (unaff_retaddr == iVar4) {
    return;
  }
  *(char *)(iVar4 + 0x24) = (char)*(undefined4 *)(unaff_retaddr + 4);
LAB_4037c821:
  (**(code **)(iVar4 + 0x20))(iVar4);
  return;
code_r0x4037c7fa:
  FUN_4037cc28(*DAT_40374e88,iVar3);
  goto LAB_4037c821;
}


