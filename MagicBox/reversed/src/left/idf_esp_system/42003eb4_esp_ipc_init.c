// strings: ipcX | esp_ipc_init | res == pdTRUE | (a7@

void FUN_42003eb4(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  
  uStack_30 = *(undefined4 *)PTR_DAT_4200048c;
  uStack_2c = PTR_DAT_4200048c[4];
  puVar4 = PTR_DAT_42000490;
  puVar5 = DAT_42000460;
  puVar6 = PTR_DAT_42000494;
  puVar7 = DAT_42000470;
  iVar8 = DAT_4200045c;
  iVar9 = 0;
  while( true ) {
    uStack_30 = CONCAT13((char)iVar9 + '0',(undefined3)uStack_30);
    uVar1 = (*(code *)PTR_FUN_420004a8)(1,puVar4);
    *puVar5 = uVar1;
    uVar1 = (*(code *)PTR_FUN_420004ac)(1,0,0,puVar6,3);
    *puVar7 = uVar1;
    iVar2 = (*(code *)PTR_FUN_420004b0)(PTR_FUN_42000498,&uStack_30,0x500,iVar9,0x18,iVar8,iVar9);
    iVar3 = 1;
    if (iVar2 != 1) {
      iVar3 = (*(code *)PTR_FUN_420000a8)
                        (PTR_s_esp_ipc_c_3c031674_0x1c_420004a4,0x7a,PTR_s_esp_ipc_init_420004a0,
                         PTR_s_res____pdTRUE_4200049c);
    }
    puVar4 = puVar4 + 0x54;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 0x54;
    puVar7 = puVar7 + 1;
    iVar8 = iVar8 + 4;
    if (iVar9 != 0) break;
    iVar9 = iVar3;
  }
  return;
}