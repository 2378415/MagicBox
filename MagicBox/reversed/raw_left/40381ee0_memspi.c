// 40381ee0  memspi  FUN_40381ee0  size=130
// strings: memspi

undefined4 FUN_40381ee0(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 local_40 [3];
  uint *puStack_34;
  undefined2 uStack_2c;
  uint auStack_24 [9];
  
  auStack_24[0] = 0;
  local_40[0] = 0x30000;
  puStack_34 = auStack_24;
  uStack_2c = 0x9f;
  (**(code **)(*param_1 + 4))(param_1,local_40);
  if ((auStack_24[0] == DAT_403752d4) || (auStack_24[0] == 0 || auStack_24[0] == DAT_403752d4)) {
    if (*(int *)PTR_DAT_40374414 != 0) {
      uVar1 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_403752dc,uVar1,PTR_s_memspi_403752d8);
    }
    uVar1 = 0x108;
  }
  else {
    *param_2 = (auStack_24[0] >> 8 & 0xff) << 8 | auStack_24[0] >> 0x10 |
               (auStack_24[0] & 0xff) << 0x10;
    uVar1 = 0;
  }
  return uVar1;
}


