// 420049f8  heap_caps_init  FUN_420049f8  size=647
// strings: heap_init | heap_idx <= num_heaps | heap_idx == num_heaps | SLIST_EMPTY(&registered_heaps) | heap_caps_init.c | heap_caps_init | heaps_array != NULL

void FUN_420049f8(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *in_t0;
  int in_WindowStart;
  undefined1 auStack_50 [16];
  uint *puStack_40;
  uint *puStack_3c;
  uint *puStack_38;
  uint *puStack_34;
  uint *puStack_30;
  uint *puStack_2c;
  int iStack_28;
  
  iVar2 = FUN_42004c98();
  iVar6 = (uint)(in_WindowStart == 0) * (int)auStack_50;
  iVar2 = (uint)(in_WindowStart != 0) * (int)(auStack_50 + -(iVar2 * 0x14 + 0xfU & 0xfffffff0));
  puVar8 = (uint *)(iVar6 + iVar2 + 0x10);
  puVar3 = (uint *)FUN_42004cb4(puVar8);
  puVar4 = puVar3;
  if (puVar3 < (uint *)0x2) {
    iStack_28 = (int)puVar3 * 0x24;
    iVar11 = (uint)(in_WindowStart == 0) * (iVar6 + iVar2);
    iVar6 = (uint)(in_WindowStart != 0) * ((iVar6 + iVar2) - (iStack_28 + 0xfU & 0xfffffff0));
    puVar1 = (undefined4 *)(iVar11 + iVar6);
    puStack_40 = (uint *)(iVar11 + iVar6 + 0x10);
    puVar9 = (uint *)PTR_DAT_42000028;
    if (2 < *(uint *)PTR_DAT_42000028) {
      puStack_38 = (uint *)PTR_DAT_42000028;
      puStack_3c = puVar3;
      uVar5 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_420005b8,uVar5,PTR_s_heap_init_420005ac);
      puVar9 = puStack_38;
      puVar4 = puStack_3c;
    }
    if (puVar4 != (uint *)0x0) {
      puStack_30 = puVar4;
      goto LAB_42004add;
    }
    if (*DAT_42000598 == 0) goto LAB_42004c1d;
LAB_42004be0:
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_heap_caps_init_c_3c032fe4_0x16_420005a8,0x83,PTR_s_heap_caps_init_420005c0,
               PTR_s_SLIST_EMPTY__registered_heaps__420005d4);
  }
  else {
    iVar11 = *(int *)(iVar6 + iVar2 + 0x14);
    if (((*(int *)(iVar6 + iVar2 + 0x24) == *puVar8 + iVar11) &&
        (*(int *)(iVar6 + iVar2 + 0x2c) == *(int *)(iVar6 + iVar2 + 0x18))) &&
       (*(char *)(iVar6 + iVar2 + 0x34) == *(char *)(iVar6 + iVar2 + 0x20))) {
      *(uint *)(iVar6 + iVar2 + 0x24) = *puVar8;
      *(undefined4 *)(iVar6 + iVar2 + 0x18) = 0xffffffff;
      *(int *)(iVar6 + iVar2 + 0x28) = *(int *)(iVar6 + iVar2 + 0x28) + iVar11;
      puVar4 = (uint *)((int)puVar3 + -1);
    }
    iStack_28 = (int)puVar4 * 0x24;
    iVar11 = (uint)(in_WindowStart == 0) * (iVar6 + iVar2);
    iVar6 = (uint)(in_WindowStart != 0) * ((iVar6 + iVar2) - (iStack_28 + 0xfU & 0xfffffff0));
    puStack_40 = (uint *)(iVar11 + iVar6 + 0x10);
    puVar1 = (undefined4 *)(iVar11 + iVar6);
    puVar9 = (uint *)PTR_DAT_42000028;
    puStack_30 = puVar3;
    if (2 < *(uint *)PTR_DAT_42000028) {
      puStack_38 = (uint *)PTR_DAT_42000028;
      puStack_3c = puVar3;
      uVar5 = (*(code *)PTR_FUN_4200005c)();
      (*DAT_42000060)(PTR_DAT_420005b8,uVar5,PTR_s_heap_init_420005ac);
      puVar1 = (undefined4 *)(iVar11 + iVar6);
      puVar9 = puStack_38;
      puStack_30 = puStack_3c;
    }
LAB_42004add:
    param_2 = (uint *)0x0;
    param_3 = puVar8;
    puVar8 = (uint *)0x0;
    puStack_34 = puVar4;
    puStack_2c = puVar9;
    do {
      uVar7 = param_3[2];
      puVar4 = puStack_40 + (int)puVar8 * 9;
      if (uVar7 == 0xffffffff) {
        (*DAT_42000094)(puVar4,0,0x24);
      }
      else {
        puStack_38 = (uint *)((int)puVar8 + 1);
        if (puStack_34 < puStack_38) {
          puVar4 = in_t0;
          (*(code *)PTR_FUN_420000a8)
                    (PTR_s_heap_caps_init_c_3c032fe4_0x16_420005a8,0x6c,
                     PTR_s_heap_caps_init_420005c0,PTR_s_heap_idx_<__num_heaps_420005bc);
          in_t0 = puVar4;
        }
        iVar6 = uVar7 * 0x10;
        puStack_3c = puVar4;
        (*DAT_42000064)(puVar4,PTR_PTR_420005c4 + iVar6 + 4,0xc);
        uVar12 = *param_3;
        uVar10 = param_3[1];
        puStack_3c[5] = DAT_420005c8;
        uVar7 = param_3[4];
        puStack_3c[3] = uVar12;
        puStack_3c[4] = uVar10 + uVar12;
        puStack_3c[6] = 0;
        if ((char)uVar7 == '\0') {
          FUN_42004980(puStack_3c);
        }
        else {
          puStack_3c[7] = 0;
        }
        uVar7 = *puStack_2c;
        puStack_40[(int)puVar8 * 9 + 8] = 0;
        if (2 < uVar7) {
          uVar5 = (*(code *)PTR_FUN_4200005c)();
          uVar7 = param_3[1];
          *puVar1 = *(undefined4 *)(PTR_PTR_420005c4 + iVar6);
          (*DAT_42000060)(PTR_DAT_420005cc,uVar5,PTR_s_heap_init_420005ac,*param_3,uVar7,uVar7 >> 10
                         );
        }
        puVar8 = puStack_38;
      }
      param_1 = puStack_34;
      param_2 = (uint *)((int)param_2 + 1);
      param_3 = param_3 + 5;
    } while (puStack_30 != param_2);
    if (puStack_34 != puVar8) {
      (*(code *)PTR_FUN_420000a8)
                (PTR_s_heap_caps_init_c_3c032fe4_0x16_420005a8,0x7e,PTR_s_heap_caps_init_420005c0,
                 PTR_s_heap_idx____num_heaps_420005d0);
    }
    param_4 = DAT_42000598;
    if (*DAT_42000598 != 0) goto LAB_42004be0;
    puVar8 = (uint *)0x0;
    param_2 = puStack_40;
    param_3 = DAT_420005d8;
    if (param_1 == (uint *)0x0) {
      puVar8 = (uint *)0x0;
      goto LAB_42004c1d;
    }
  }
  do {
    iVar6 = FUN_4202cf30(param_2,param_3);
    if ((iVar6 != 0) &&
       (puVar3 = (uint *)(*(code *)PTR_FUN_420005e0)(param_2[7],iStack_28), puVar4 = puStack_40,
       puVar3 != (uint *)0x0)) {
      puStack_40 = puVar3;
      (*DAT_42000064)(puVar3,puVar4,iStack_28);
      param_3 = puStack_40 + -1;
      if (puStack_40[7] != 0) {
        (*(code *)PTR_FUN_420005b4)(puStack_40[7],puStack_40 + 5);
      }
      param_2 = (uint *)0x0;
      puStack_40[8] = *param_4;
      *param_4 = (uint)puStack_40;
      goto LAB_42004c5e;
    }
    puVar8 = (uint *)((int)puVar8 + 1);
    param_2 = param_2 + 9;
  } while (param_1 != puVar8);
LAB_42004c1d:
  uVar7 = (*(code *)PTR_FUN_420000a8)
                    (PTR_s_heap_caps_init_c_3c032fe4_0x16_420005a8,0x92,
                     PTR_s_heap_caps_init_420005c0,PTR_s_heaps_array____NULL_420005dc);
  do {
    (*(code *)PTR_FUN_420005b4)(uVar7,param_3 + 0xf);
    puVar4 = param_3;
    do {
      param_3 = puVar8;
      uVar7 = *param_3;
      *param_3 = (uint)(puVar4 + 10);
      param_3[9] = uVar7;
LAB_42004c5e:
      param_2 = (uint *)((int)param_2 + 1);
      puVar8 = param_3 + 9;
      if (param_1 == param_2) {
        return;
      }
      uVar7 = param_3[0x11];
      puVar4 = param_3;
    } while (uVar7 == 0);
  } while( true );
}


