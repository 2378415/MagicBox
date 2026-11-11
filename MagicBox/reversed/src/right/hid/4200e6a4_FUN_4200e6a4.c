// strings: invalid device bLength 0x%02x | unexpected descriptor 0x%02x | Hub Descriptor: | bLength: 0x%02x              | bDescriptorType: 0x%02x      | bNbrPorts: 0x%02x            | wHubCharacteristics: 0x%04x  | bPwrOn2PwrGood: 0x%02x       | bHubContrCurrent: 0x%02x     | DeviceRemovable: 0x%02x      | PortPwrCtrlMask: 0x%02x     

undefined4 FUN_4200e6a4(char *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == '\t') {
    if (param_1[1] == ')') {
      (*DAT_42000634)(PTR_s_Hub_Descriptor__42000c4c);
      (*DAT_42000634)(PTR_s_bLength__0x_02x_42000c30,*param_1);
      (*DAT_42000634)(PTR_s_bDescriptorType__0x_02x_42000c34,param_1[1]);
      (*DAT_42000634)(PTR_s_bNbrPorts__0x_02x_42000c38,param_1[2]);
      (*DAT_42000634)(PTR_s_wHubCharacteristics__0x_04x_42000c3c,*(undefined2 *)(param_1 + 3));
      (*DAT_42000634)(PTR_s_bPwrOn2PwrGood__0x_02x_42000c40,param_1[5]);
      (*DAT_42000634)(PTR_s_bHubContrCurrent__0x_02x_42000c44,param_1[6]);
      (*DAT_42000634)(PTR_s_DeviceRemovable__0x_02x_42000c48,param_1[7]);
      (*DAT_42000634)(PTR_s_PortPwrCtrlMask__0x_02x_42000c50,param_1[8]);
      uVar1 = 0;
    }
    else {
      (*DAT_42000634)(PTR_DAT_42000c1c);
      (*DAT_42000634)(PTR_s_unexpected_descriptor_0x_02x_42000c28,param_1[1]);
      (*DAT_42000634)(PTR_DAT_42000c24);
      uVar1 = 0xfffffffe;
    }
  }
  else {
    (*DAT_42000634)(PTR_DAT_42000c1c);
    (*DAT_42000634)(PTR_s_invalid_device_bLength_0x_02x_42000c20,*param_1);
    (*DAT_42000634)(PTR_DAT_42000c24);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}