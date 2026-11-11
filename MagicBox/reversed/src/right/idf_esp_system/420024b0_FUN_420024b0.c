// strings: Memory dump at 0x

void FUN_420024b0(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(uint *)(param_1 + 4) & 0xfffffffc);
  if ((uint)((int)puVar2 + DAT_42000278) <= DAT_4200027c) {
    FUN_42001e2c(PTR_s_Memory_dump_at_0x_42000280);
    FUN_42001e58(puVar2 + -1);
    FUN_42001e2c(PTR_DAT_42000284);
    memw();
    FUN_42001e58(puVar2[-1]);
    puVar1 = PTR_DAT_42000288;
    FUN_42001e2c(PTR_DAT_42000288);
    memw();
    FUN_42001e58(*puVar2);
    FUN_42001e2c(puVar1);
    memw();
    FUN_42001e58(puVar2[1]);
  }
  return;
}