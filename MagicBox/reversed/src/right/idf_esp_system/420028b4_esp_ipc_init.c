// strings: ipcX | T^7@

void FUN_420028b4(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  
  uStack_30 = *(undefined4 *)PTR_DAT_4200035c;
  uStack_2c = PTR_DAT_4200035c[4];
  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
    uStack_30 = CONCAT13((char)iVar3 + '0',(undefined3)uStack_30);
    uVar1 = (*(code *)PTR_FUN_42000378)(1,PTR_DAT_42000360 + iVar3 * 0x54);
    *(undefined4 *)(iVar3 * 4 + DAT_4200032c) = uVar1;
    uVar1 = (*(code *)PTR_FUN_4200037c)(1,0,0,PTR_DAT_42000364 + iVar3 * 0x54,3);
    *(undefined4 *)(DAT_4200033c + iVar3 * 4) = uVar1;
    iVar2 = (*(code *)PTR_FUN_42000380)
                      (PTR_FUN_42000368,&uStack_30,0x500,iVar3,0x18,DAT_42000328 + iVar3 * 4,iVar3);
    if (iVar2 != 1) {
      (*(code *)PTR_FUN_42000044)
                (PTR_s_esp_ipc_c_3c030adc_0x1c_42000374,0x7a,PTR_s_esp_ipc_init_42000370,
                 PTR_s_res____pdTRUE_4200036c);
    }
  }
  return;
}