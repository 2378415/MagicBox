/* (1 unreachable decompiler blocks omitted) */

int FUN_4201c110(int param_1,undefined4 param_2,int param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  byte local_30 [48];
  
  iVar4 = *(int *)(param_1 + 0x38);
  do {
    if (iVar4 == 0) {
      iVar4 = DAT_420011bc;
      if (param_3 != 0) {
        local_30[0] = 1;
        if ((*(uint *)(param_1 + 0x44) >> 1 & 1) == 0) {
          iVar4 = FUN_4201be2c(param_1,0,1,param_2,local_30);
          bVar1 = local_30[0];
          if (iVar4 == 0) {
            iVar4 = (uint)(local_30[0] >> 5) * 4 + param_1;
            *(uint *)(iVar4 + 0x44) =
                 *(uint *)(iVar4 + 0x44) | 1 << 0x20 - (0x20 - (local_30[0] & 0x1f));
            *param_4 = local_30[0];
            puVar3 = (undefined4 *)(*(code *)PTR_FUN_4200056c)(0x1c);
            if (puVar3 == (undefined4 *)0x0) {
              iVar4 = 0x101;
            }
            else {
              *puVar3 = 0;
              puVar3[1] = 0;
              *(byte *)(puVar3 + 6) = bVar1;
              (*DAT_42000da8)(puVar3 + 2,param_2,0xf);
              iVar4 = *(int *)(param_1 + 0x3c);
              *(undefined1 *)((int)puVar3 + 0x17) = 0;
              uVar5 = 0;
              if (iVar4 != 0) {
                *(undefined4 **)(iVar4 + 4) = puVar3;
                uVar5 = *(undefined4 *)(param_1 + 0x3c);
              }
              *puVar3 = uVar5;
              iVar4 = *(int *)(param_1 + 0x38);
              puVar3[1] = 0;
              *(undefined4 **)(param_1 + 0x3c) = puVar3;
              if (iVar4 == 0) {
                *(undefined4 **)(param_1 + 0x38) = puVar3;
              }
              *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
LAB_4201c1f3:
              iVar4 = 0;
            }
          }
        }
        else {
          iVar4 = DAT_42001a5c;
        }
      }
      return iVar4;
    }
    iVar2 = (*DAT_42000c68)(param_2,iVar4 + 8,0xf);
    if (iVar2 == 0) {
      *param_4 = *(byte *)(iVar4 + 0x18);
      goto LAB_4201c1f3;
    }
    iVar4 = *(int *)(iVar4 + 4);
  } while( true );
}