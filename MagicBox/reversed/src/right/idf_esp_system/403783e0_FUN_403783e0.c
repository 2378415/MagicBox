// strings: ||7@0Z

int FUN_403783e0(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  undefined1 auStack_70 [64];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  iStack_30 = param_1;
  iStack_28 = param_3;
  iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 8))(&iStack_30);
  if (iVar2 == 0) {
    if (*(int *)(*(int *)(iStack_30 + 4) + 0x44) == 0) {
      iVar2 = DAT_4037488c;
    }
    else if (iStack_30 == *DAT_40374884) {
      if ((iStack_30 != 0) &&
         (pcVar7 = *(code **)(*(int *)(iStack_30 + 8) + 8), pcVar7 != (code *)0x0)) {
        iVar3 = (*pcVar7)(*(undefined4 *)(iStack_30 + 0xc),param_2,param_4);
        if (iVar3 == 0x10d) {
          return 0x10d;
        }
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381ce0();
        }
      }
      if (iStack_28 == 0) {
        iVar2 = 0x102;
      }
      else if (*(uint *)(iStack_30 + 0x14) < param_2 + param_4) {
        iVar2 = 0x102;
      }
      else if ((param_2 & 0xf) == 0) {
        if (param_4 != 0) {
          if ((param_4 & 0xf) == 0) {
            uVar4 = iStack_28 + DAT_4037466c;
            uVar6 = 0;
            if ((DAT_40374828 < uVar4) ||
               (iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(), iVar2 == 0)) {
              for (; uVar6 < param_4; uVar6 = uVar6 + iStack_2c) {
                uVar5 = uVar6 + param_2;
                if (((uVar5 & 0x3f) == 0) && (0x3f < param_4 - uVar6)) {
                  (*DAT_403744d4)(auStack_70,iStack_28 + uVar6,0x40);
                  iStack_2c = 0x40;
                }
                else if (((uVar5 & 0x1f) == 0) && (0x1f < param_4 - uVar6)) {
                  (*DAT_403744d4)(auStack_70,iStack_28 + uVar6,0x20);
                  iStack_2c = 0x20;
                }
                else {
                  (*DAT_403744d4)(auStack_70,iStack_28 + uVar6,0x10);
                  iStack_2c = 0x10;
                }
                if ((((DAT_40374828 < uVar4) &&
                     (iVar2 = (*(code *)**(undefined4 **)PTR_PTR_4037487c)(iStack_30), iVar2 != 0))
                    || (iVar2 = (**(code **)(*(int *)(iStack_30 + 4) + 0x50))
                                          (iStack_30,auStack_70,uVar5,iStack_2c), iVar2 != 0)) ||
                   ((DAT_40374828 < uVar4 &&
                    (iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30,0), iVar2 != 0)))
                   ) goto LAB_40378559;
              }
              if ((DAT_40374828 < uVar4) ||
                 (iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30,0), iVar2 == 0)) {
                iVar2 = (**(code **)(*(int *)PTR_PTR_4037487c + 0xc))(iStack_30,0,0,param_2,param_4)
                ;
              }
              else {
LAB_40378559:
                puVar1 = PTR_PTR_4037487c;
                (**(code **)(*(int *)PTR_PTR_4037487c + 4))(iStack_30,0);
                (**(code **)(*(int *)puVar1 + 0xc))(iStack_30,iVar2,0,param_2,param_4);
              }
            }
          }
          else {
            iVar2 = 0x104;
          }
        }
      }
      else {
        iVar2 = 0x102;
      }
    }
    else {
      iVar2 = 0x106;
    }
  }
  return iVar2;
}