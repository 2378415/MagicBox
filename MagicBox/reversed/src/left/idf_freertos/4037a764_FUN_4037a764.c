void FUN_4037a764(uint param_1,uint param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  puVar3 = PTR_FUN_40374bd0;
  puVar4 = PTR_FUN_40374bcc;
  puVar6 = PTR_FUN_40374bc4;
  if (param_2 == 0) {
    uVar1 = ((param_1 >> 1) + 3 & 0xfffffffc) - 8;
    puVar2 = PTR_FUN_40374bd4;
    puVar5 = PTR_FUN_40374bc8;
  }
  else if (param_2 == 1) {
    uVar1 = param_1 - 0x10;
    puVar2 = PTR_FUN_40374bdc;
    puVar5 = PTR_FUN_40374bd8;
  }
  else {
    param_2 = 2;
    uVar1 = param_1;
    puVar2 = PTR_FUN_40374bf0;
    puVar3 = PTR_FUN_40374bec;
    puVar4 = PTR_FUN_40374be8;
    puVar5 = PTR_FUN_40374be4;
    puVar6 = PTR_FUN_40374be0;
  }
  param_3[1] = uVar1;
  param_3[0xd] = param_4 + param_1;
  param_3[3] = (uint)puVar6;
  param_3[4] = (uint)puVar5;
  param_3[5] = (uint)puVar4;
  param_3[6] = (uint)puVar3;
  param_3[7] = (uint)puVar2;
  *param_3 = param_1;
  param_3[0xc] = param_4;
  param_3[0xb] = param_4;
  param_3[10] = param_4;
  param_3[9] = param_4;
  param_3[8] = param_4;
  param_3[0xe] = 0;
  param_3[2] = param_2;
  FUN_4037cbbc(param_3 + 0xf);
  FUN_4037cbbc(param_3 + 0x14);
  uVar1 = DAT_40374bf4;
  param_3[0x19] = 0;
  param_3[0x1a] = uVar1;
  param_3[0x1b] = 0;
  return;
}