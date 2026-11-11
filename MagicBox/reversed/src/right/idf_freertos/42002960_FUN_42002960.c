undefined4 FUN_42002960(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 in_PRID;
  
  if (param_1 < 2) {
    if (*(int *)(param_1 * 4 + DAT_42000328) == 0) {
      uVar3 = 0x102;
    }
    else {
      uVar4 = rsr(in_PRID);
      if ((param_1 == (uVar4 >> 0xd & 1)) && (iVar1 = (*(code *)PTR_FUN_42000340)(), iVar1 != 2)) {
        uVar3 = 0x103;
      }
      else {
        iVar1 = (*(code *)PTR_FUN_42000390)(param_1 * 4 + DAT_42000384,0,param_2);
        if (iVar1 == 0) {
          uVar3 = 0xffffffff;
        }
        else {
          memw();
          *(undefined4 *)(param_1 * 4 + DAT_42000388) = param_3;
          memw();
          *(undefined1 *)(DAT_4200038c + param_1) = 1;
          iVar1 = (*(code *)PTR_FUN_42000394)();
          if (iVar1 == 0) {
            puVar2 = (undefined4 *)(param_1 * 4 + DAT_42000328);
            (*(code *)PTR_FUN_4200034c)(*puVar2,0x18);
            (*(code *)PTR_FUN_42000354)(*puVar2,0,0,2);
          }
          else {
            (*(code *)PTR_FUN_42000398)(*(undefined4 *)(param_1 * 4 + DAT_42000328),0);
          }
          uVar3 = 0;
        }
      }
    }
  }
  else {
    uVar3 = 0x102;
  }
  return uVar3;
}