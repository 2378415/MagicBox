// 4200dc2c  FUN_4200dc2c  FUN_4200dc2c  size=464
// strings: invalid config bLength 0x%02x | unexpected config descriptor 0x%02x

undefined4 FUN_4200dc2c(int param_1,char *param_2,uint param_3)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (*param_2 == '\t') {
    if (param_2[1] == '\x02') {
      if (param_3 < 10) {
        uVar2 = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x1c) = 9;
        *(char *)(param_1 + 0x1d) = param_2[1];
        *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)(param_2 + 2);
        *(char *)(param_1 + 0x20) = param_2[4];
        *(char *)(param_1 + 0x21) = param_2[5];
        *(char *)(param_1 + 0x22) = param_2[6];
        *(char *)(param_1 + 0x23) = param_2[7];
        *(char *)(param_1 + 0x24) = param_2[8];
        pbVar3 = (byte *)(param_2 + 9);
        (*DAT_42000240)(param_1 + 0x28,0,DAT_42000bb8);
        uVar6 = 9;
        uVar7 = 0xff;
        uVar4 = 0xff;
        uVar5 = 0xff;
        while (*pbVar3 != 0) {
          if (param_3 < uVar6) {
            return 0;
          }
          if (pbVar3[1] == 4) {
            uVar4 = (uint)pbVar3[2];
            bVar1 = pbVar3[3];
            uVar5 = (uint)bVar1;
            if (7 < uVar4) {
              (*DAT_42000634)(PTR_DAT_42000ba0);
              (*DAT_42000634)(PTR_s_Interface_num_overflow_42000bbc);
              (*DAT_42000634)(PTR_DAT_42000ba8);
              do {
                    /* WARNING: Do nothing block with infinite loop */
              } while( true );
            }
            if (7 < uVar5) {
              (*DAT_42000634)(PTR_DAT_42000ba0);
              (*DAT_42000634)(PTR_s_Interface_altsetting_num_overflo_42000bc0);
              (*DAT_42000634)(PTR_DAT_42000ba8);
              do {
                    /* WARNING: Do nothing block with infinite loop */
              } while( true );
            }
            if (4 < pbVar3[4]) {
              (*DAT_42000634)(PTR_DAT_42000ba0);
              (*DAT_42000634)(PTR_s_Endpoint_num_overflow_42000bc4);
              (*DAT_42000634)(PTR_DAT_42000ba8);
              do {
                    /* WARNING: Do nothing block with infinite loop */
              } while( true );
            }
            (*DAT_420002fc)(param_1 + uVar4 * 0x144 + uVar5 * 0x25 + 0x40,pbVar3,9);
            *(byte *)(uVar4 * 0x144 + param_1 + 0x168) = bVar1 + 1;
            uVar7 = 0;
          }
          else if (pbVar3[1] == 5) {
            if ((pbVar3[6] == 10) && (pbVar3[3] == 3)) {
              pbVar3[6] = 1;
            }
            (*DAT_420002fc)(param_1 + uVar4 * 0x144 + uVar7 * 7 + uVar5 * 0x25 + 0x49,pbVar3,7);
            uVar7 = uVar7 + 1 & 0xff;
          }
          pbVar3 = pbVar3 + *pbVar3;
          uVar6 = uVar6 + *pbVar3;
        }
        uVar2 = 0;
      }
    }
    else {
      (*DAT_42000634)(PTR_DAT_42000ba0);
      (*DAT_42000634)(PTR_s_unexpected_config_descriptor_0x__42000bb4,param_2[1]);
      (*DAT_42000634)(PTR_DAT_42000ba8);
      uVar2 = 0xfffffffe;
    }
  }
  else {
    (*DAT_42000634)(PTR_DAT_42000ba0);
    (*DAT_42000634)(PTR_s_invalid_config_bLength_0x_02x_42000bb0,*param_2);
    (*DAT_42000634)(PTR_DAT_42000ba8);
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


