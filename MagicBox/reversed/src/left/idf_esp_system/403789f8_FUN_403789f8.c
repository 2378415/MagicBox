// strings: spi_flash | E %s: flash encrypted write address must be 16 b | J'W2

int FUN_403789f8(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  undefined1 auStack_70 [64];
  int iStack_30;
  uint uStack_2c;
  int iStack_28;
  
  puVar1 = PTR_PTR_403748f8;
  iStack_30 = param_1;
  uVar2 = (**(code **)(*(int *)PTR_PTR_403748f8 + 8))(&iStack_30);
  if (uVar2 == 0) {
    if (*(int *)(*(int *)(iStack_30 + 4) + 0x44) == 0) {
      uVar2 = DAT_40374914;
    }
    else if (iStack_30 == *DAT_40374900) {
      pcVar7 = *(code **)(*(int *)(iStack_30 + 8) + 8);
      if (pcVar7 != (code *)0x0) {
        uStack_2c = uVar2;
        iVar3 = (*pcVar7)(*(undefined4 *)(iStack_30 + 0xc),param_2,param_4);
        if (iVar3 == 0x10d) {
          return 0x10d;
        }
        uVar2 = uStack_2c;
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_40381c60();
        }
      }
      if ((param_3 != 0) && (param_2 + param_4 <= *(uint *)(iStack_30 + 0x14))) {
        if ((param_2 & 0xf) == 0) {
          if (param_4 == 0) {
            return uVar2;
          }
          if ((param_4 & 0xf) != 0) {
            if (*(int *)PTR_DAT_40374414 != 0) {
              (*DAT_40374438)(PTR_s_E__s__flash_encrypted_write_leng_40374958,
                              PTR_s_spi_flash_40374908);
            }
            return 0x104;
          }
          uStack_2c = param_3 + DAT_403746c4;
          if ((uStack_2c <= DAT_403748b0) &&
             (iVar3 = (*(code *)**(undefined4 **)puVar1)(), iVar3 != 0)) {
            if (*(int *)PTR_DAT_40374414 == 0) {
              return iVar3;
            }
            uStack_2c = iVar3;
            (*DAT_40374438)(PTR_s_E__s__flash_acquire_lock_failed_4037495c,PTR_s_spi_flash_40374908)
            ;
            return uStack_2c;
          }
          uVar2 = 0;
          iStack_28 = param_3;
          do {
            uVar5 = uVar2 + param_2;
            iVar3 = iStack_28 + uVar2;
            if ((uVar5 & 0x3f) == 0) {
              uVar6 = param_4 - uVar2;
              if (uVar6 < 0x40) goto LAB_40378b09;
              (*DAT_4037450c)(auStack_70,iVar3,0x40);
              iVar3 = 0x40;
            }
            else {
              if ((uVar5 & 0x1f) == 0) {
                uVar6 = param_4 - uVar2;
LAB_40378b09:
                if (0x1f < uVar6) {
                  (*DAT_4037450c)(auStack_70,iVar3,0x20);
                  iVar3 = 0x20;
                  goto LAB_40378b2a;
                }
              }
              (*DAT_4037450c)(auStack_70,iVar3,0x10);
              iVar3 = 0x10;
            }
LAB_40378b2a:
            if (DAT_403748b0 < uStack_2c) {
              iVar4 = (*(code *)**(undefined4 **)puVar1)();
              if (iVar4 != 0) goto LAB_40378b8f;
              iVar4 = (**(code **)(*(int *)(iStack_30 + 4) + 0x50))
                                (iStack_30,auStack_70,uVar5,iVar3);
              if ((iVar4 != 0) || (iVar4 = (**(code **)(*(int *)puVar1 + 4))(iStack_30), iVar4 != 0)
                 ) goto LAB_40378b8f;
            }
            else {
              iVar4 = (**(code **)(*(int *)(iStack_30 + 4) + 0x50))
                                (iStack_30,auStack_70,uVar5,iVar3);
              if (iVar4 != 0) goto LAB_40378b8f;
            }
            uVar2 = uVar2 + iVar3;
          } while (uVar2 < param_4);
          if ((DAT_403748b0 < uStack_2c) ||
             (iVar4 = (**(code **)(*(int *)puVar1 + 4))(iStack_30,0), iVar4 == 0)) {
            iVar3 = (**(code **)(*(int *)puVar1 + 0xc))(iStack_30,0,0,param_2,param_4);
            return iVar3;
          }
LAB_40378b8f:
          uStack_2c = iVar4;
          (**(code **)(*(int *)puVar1 + 4))(iStack_30,0);
          iVar3 = (**(code **)(*(int *)puVar1 + 0xc))(iStack_30,uStack_2c,0,param_2,param_4);
          if (iVar3 == 0) {
            return uStack_2c;
          }
          if (*(int *)PTR_DAT_40374414 == 0) {
            return uStack_2c;
          }
          (*DAT_40374438)(PTR_s_E__s__restore_cache_fail_3fc959ae_2_40374960,
                          PTR_s_spi_flash_40374908);
          return uStack_2c;
        }
        if (*(int *)PTR_DAT_40374414 != 0) {
          (*DAT_40374438)(PTR_s_E__s__flash_encrypted_write_addr_40374954,PTR_s_spi_flash_40374908);
        }
      }
      uVar2 = 0x102;
    }
    else {
      uVar2 = 0x106;
    }
  }
  return uVar2;
}