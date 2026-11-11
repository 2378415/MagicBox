// 4200db58  FUN_4200db58  FUN_4200db58  size=206
// strings: invalid device bLength 0x%02x | unexpected device descriptor 0x%02x

undefined4 FUN_4200db58(int param_1,char *param_2,uint param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_2 == '\x12') {
    if (param_2[1] == '\x01') {
      if (param_3 < 9) {
        uVar2 = 0;
      }
      else {
        *(undefined1 *)(param_1 + 7) = 0x12;
        *(char *)(param_1 + 8) = param_2[1];
        cVar1 = param_2[3];
        *(char *)(param_1 + 9) = param_2[2];
        *(char *)(param_1 + 10) = cVar1;
        *(char *)(param_1 + 0xb) = param_2[4];
        *(char *)(param_1 + 0xc) = param_2[5];
        *(char *)(param_1 + 0xd) = param_2[6];
        *(char *)(param_1 + 0xe) = param_2[7];
        cVar1 = param_2[9];
        *(char *)(param_1 + 0xf) = param_2[8];
        *(char *)(param_1 + 0x10) = cVar1;
        cVar1 = param_2[0xb];
        *(char *)(param_1 + 0x11) = param_2[10];
        *(char *)(param_1 + 0x12) = cVar1;
        cVar1 = param_2[0xd];
        *(char *)(param_1 + 0x13) = param_2[0xc];
        *(char *)(param_1 + 0x14) = cVar1;
        *(char *)(param_1 + 0x15) = param_2[0xe];
        *(char *)(param_1 + 0x16) = param_2[0xf];
        *(char *)(param_1 + 0x17) = param_2[0x10];
        *(char *)(param_1 + 0x18) = param_2[0x11];
        uVar2 = 0;
      }
    }
    else {
      (*DAT_42000634)(PTR_DAT_42000ba0);
      (*DAT_42000634)(PTR_s_unexpected_device_descriptor_0x__42000bac,param_2[1]);
      (*DAT_42000634)(PTR_DAT_42000ba8);
      uVar2 = 0xfffffffe;
    }
  }
  else {
    (*DAT_42000634)(PTR_DAT_42000ba0);
    (*DAT_42000634)(PTR_s_invalid_device_bLength_0x_02x_42000ba4,*param_2);
    (*DAT_42000634)(PTR_DAT_42000ba8);
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


