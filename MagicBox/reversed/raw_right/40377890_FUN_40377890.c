// 40377890  FUN_40377890  FUN_40377890  size=106

undefined4 FUN_40377890(uint param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x102;
  }
  else {
    uVar5 = 0;
    bVar1 = false;
    for (uVar4 = 0; uVar4 < *DAT_40374818; uVar4 = uVar4 + 1) {
      for (uVar3 = DAT_40374818[uVar4 * 10 + 9]; uVar3 != 0; uVar3 = *(uint *)(uVar3 + 0x24)) {
        if ((((uVar3 != DAT_40374818[uVar4 * 10 + 9]) &&
             (**(uint **)(DAT_40374818[uVar4 * 10 + 10] + 4) != uVar3)) &&
            (*(uint *)(uVar3 + 0x18) <= param_1)) && (param_1 < *(uint *)(uVar3 + 0x1c))) {
          bVar1 = true;
          uVar5 = uVar3;
          break;
        }
      }
    }
    if (bVar1) {
      *param_2 = *(undefined4 *)(uVar5 + 0x14);
      uVar2 = 0;
    }
    else {
      uVar2 = 0x105;
    }
  }
  return uVar2;
}


