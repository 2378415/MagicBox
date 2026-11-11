// 403827ac  FUN_403827ac  FUN_403827ac  size=190
// strings: chip_generic

int FUN_403827ac(int param_1,code *param_2,code *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint local_30 [12];
  
  if (*(int *)(param_1 + 0x10) - 4U < 2) {
    iVar1 = (*param_3)(param_1,local_30);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (3 < *(uint *)PTR_DAT_40374414) {
      uVar2 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_40375344,uVar2,PTR_s_chip_generic_40375328,local_30[0]);
    }
    uVar3 = local_30[0] | param_4;
    if ((~local_30[0] & param_4) != 0) {
      (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,0);
      iVar1 = (*param_2)(param_1,uVar3);
      iVar4 = *(int *)(param_1 + 4);
      if (iVar1 != 0) {
        (**(code **)(iVar4 + 0x2c))(param_1,1);
        return iVar1;
      }
      iVar1 = (**(code **)(iVar4 + 0x54))(param_1,**(undefined4 **)(iVar4 + 4));
      if (iVar1 == 0x106) {
        (**(code **)(*(int *)(param_1 + 4) + 0x2c))(param_1,1);
      }
      else if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*param_3)(param_1,local_30);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (3 < *(uint *)PTR_DAT_40374414) {
        uVar2 = FUN_40381bb0();
        (*DAT_40374438)(PTR_DAT_40375348,uVar2,PTR_s_chip_generic_40375328,local_30[0]);
      }
      if (local_30[0] == uVar3) {
        return 0;
      }
      return 0x108;
    }
  }
  return 0;
}


