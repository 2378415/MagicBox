// 42003b2c  FUN_42003b2c  FUN_42003b2c  size=82
// strings: Memory dump at 0x

void FUN_42003b2c(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(uint *)(param_1 + 4) & 0xfffffffc);
  if ((uint)((int)puVar2 + DAT_420003b0) <= DAT_420003b4) {
    FUN_4200330c(PTR_s_Memory_dump_at_0x_420003b8);
    FUN_42003360(puVar2 + -1);
    FUN_4200330c(PTR_DAT_420003bc);
    memw();
    FUN_42003360(puVar2[-1]);
    puVar1 = PTR_DAT_420003c0;
    FUN_4200330c(PTR_DAT_420003c0);
    memw();
    FUN_42003360(*puVar2);
    FUN_4200330c(puVar1);
    memw();
    FUN_42003360(puVar2[1]);
  }
  return;
}


