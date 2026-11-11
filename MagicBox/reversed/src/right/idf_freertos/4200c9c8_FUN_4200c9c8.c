void FUN_4200c9c8(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_2 * 0x20;
  iVar3 = *(int *)(param_1 + 8) + iVar7;
  memw();
  uVar6 = *(uint *)(iVar3 + 0x508);
  uVar5 = (uint)*(byte *)(param_1 + 0xc);
  iVar4 = *(int *)(DAT_42000af8 + param_2 * 0x18 + uVar5 * 0xc4 + 0x14);
  if ((uVar6 & 2) != 0) {
    memw();
    *(uint *)(iVar3 + 0x508) = uVar6;
    if ((uVar6 & 1) == 0) {
      if ((uVar6 & 4) == 0) {
        if ((uVar6 & 8) == 0) {
          if ((uVar6 & 0x10) == 0) {
            if ((uVar6 & 0x40) == 0) {
              if ((uVar6 & 0x80) == 0) {
                if ((uVar6 & 0x100) == 0) {
                  if ((uVar6 & 0x400) == 0) {
                    if ((uVar6 & 0x200) != 0) {
                      *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff4;
                      FUN_4200c98c();
                    }
                  }
                  else {
                    *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff5;
                    FUN_4200c98c();
                  }
                }
                else {
                  *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff7;
                  FUN_4200c98c();
                }
              }
              else {
                *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff4;
                FUN_4200c98c();
              }
            }
            else {
              *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff6;
              FUN_4200c98c();
            }
          }
          else {
            *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff6;
            FUN_4200c98c();
          }
        }
        else {
          *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff8;
          FUN_4200c98c();
        }
      }
      else {
        *(undefined4 *)(iVar4 + 0x2c) = 0xfffffff4;
        FUN_4200c98c();
      }
    }
    else {
      *(undefined4 *)(iVar4 + 0x2c) = 0;
      memw();
      *(uint *)(iVar4 + 0x24) =
           *(int *)(iVar4 + 0x24) +
           (*(int *)(DAT_42000af8 + param_2 * 0x18 + uVar5 * 0xc4 + 8) -
           (*(uint *)(iVar7 + *(int *)(param_1 + 8) + 0x510) & 0x7ffff));
      memw();
      if ((*(uint *)(iVar7 + *(int *)(param_1 + 8) + 0x510) >> 0x1d & 3) == 0) {
        *(undefined1 *)(iVar4 + 0x10) = 0;
      }
      else {
        *(undefined1 *)(iVar4 + 0x10) = 1;
      }
      bVar1 = *(byte *)(*(int *)(iVar4 + 0xc) + 3);
      if ((bVar1 & 3) == 0) {
        cVar2 = *(char *)(DAT_42000af8 + param_2 * 0x18 + uVar5 * 0xc4 + 4);
        if (cVar2 == '\x01') {
          *(undefined1 *)(DAT_42000af8 + param_2 * 0x18 + uVar5 * 0xc4 + 4) = 4;
          FUN_4200c4a8(param_1,param_2,iVar4,*(undefined4 *)(iVar4 + 0x14),
                       *(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar4 + 0x1c));
        }
        else if (cVar2 == '\x03') {
          *(undefined1 *)(DAT_42000af8 + param_2 * 0x18 + uVar5 * 0xc4 + 4) = 0;
          FUN_4200c98c();
        }
      }
      else if ((bVar1 & 3) != 1) {
        FUN_4200c98c();
      }
    }
  }
  return;
}