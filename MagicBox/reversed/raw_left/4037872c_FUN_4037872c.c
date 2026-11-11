// 4037872c  FUN_4037872c  FUN_4037872c  size=304

/* WARNING: Control flow encountered bad instruction data */

int FUN_4037872c(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  undefined4 *unaff_retaddr;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint in_t0;
  undefined1 local_40 [16];
  undefined4 *apuStack_30 [12];
  
  puVar1 = PTR_PTR_403748f8;
  puVar3 = (undefined4 *)local_40;
  apuStack_30[0] = param_1;
  iVar4 = (**(code **)(*(int *)PTR_PTR_403748f8 + 8))(apuStack_30);
  if (iVar4 == 0) {
    if (*(int *)(apuStack_30[0][1] + 0x40) == 0) {
      iVar4 = DAT_40374914;
    }
    else if (((param_2 == 0) || ((uint)apuStack_30[0][5] < param_3)) ||
            ((uint)apuStack_30[0][5] < param_3 + param_4)) {
      iVar4 = 0x102;
    }
    else if (param_4 != 0) {
      iVar4 = (**(code **)(*(int *)*apuStack_30[0] + 0x30))((int *)*apuStack_30[0],param_2);
      uVar6 = -(DAT_403748b0 + -1);
      uVar9 = (param_4 < DAT_40374460) * param_4 + (param_4 >= DAT_40374460) * DAT_40374460;
      do {
        puVar3[6] = uVar9;
        puVar2 = unaff_retaddr;
        if (((uVar6 & 0xff) == 0) && (iVar4 == 0)) {
          *puVar3 = 0;
          if (*(code **)(*(int *)(puVar3[4] + 8) + 0x10) == (code *)0x0) {
            return 0x101;
          }
          iVar4 = (**(code **)(*(int *)(puVar3[4] + 8) + 0x10))(0,unaff_retaddr[6],unaff_retaddr);
          unaff_retaddr[5] = iVar4;
          unaff_retaddr[6] = *unaff_retaddr;
          puVar3 = unaff_retaddr;
          uVar6 = in_t0;
          if (iVar4 == 0) {
            return 0x101;
          }
        }
        else {
          puVar3[5] = 0;
          uVar6 = in_t0;
        }
        unaff_retaddr = puVar2;
        iVar4 = (*(code *)**(undefined4 **)puVar1)(puVar3[4]);
        iVar8 = puVar3[4];
        if (iVar4 != 0) goto LAB_40378802;
        uVar9 = puVar3[6];
        iVar5 = (param_4 < uVar9) * param_4 + (param_4 >= uVar9) * uVar9;
        pcVar7 = *(code **)(*(int *)(iVar8 + 4) + 0x40);
        if (puVar3[5] == 0) {
          iVar4 = (*pcVar7)(iVar8,param_2);
          if (iVar4 != 0) {
LAB_403787df:
            (**(code **)(*(int *)puVar1 + 4))(puVar3[4],iVar4);
            iVar8 = puVar3[4];
LAB_40378802:
            pcVar7 = *(code **)(*(int *)(iVar8 + 8) + 0x14);
            if (pcVar7 == (code *)0x0) {
              return iVar4;
            }
            (*pcVar7)(*(undefined4 *)(iVar8 + 0xc),puVar3[5]);
            return iVar4;
          }
          iVar4 = (**(code **)(*(int *)puVar1 + 4))(puVar3[4],puVar3[5]);
        }
        else {
          iVar4 = (*pcVar7)(iVar8,puVar3[5],param_3,iVar5);
          if (iVar4 != 0) goto LAB_403787df;
          (**(code **)(*(int *)puVar1 + 4))(puVar3[4],0);
          iVar4 = (*DAT_4037450c)(param_2,puVar3[5],iVar5);
        }
        param_4 = param_4 - iVar5;
        uVar9 = uVar6;
        in_t0 = uVar6;
        if (unaff_retaddr == (undefined4 *)0x1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      } while( true );
    }
  }
  return iVar4;
}


