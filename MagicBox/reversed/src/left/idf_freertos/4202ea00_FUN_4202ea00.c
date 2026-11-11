// strings: xResult == ( ( BaseType_t ) 1 ) | \d7@L

void FUN_4202ea00(undefined4 param_1)

{
  int iVar1;
  undefined4 local_30 [12];
  
  iVar1 = (*(code *)PTR_FUN_42001f3c)(param_1,0,local_30);
  if (iVar1 != 1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_idf_additions_c_3c03b594_0x28_42001f38,0x145,
               PTR_s_vSemaphoreDeleteWithCaps_42001f44,
               PTR_s_xResult________BaseType_t___1___42001f30);
  }
  (*(code *)PTR_FUN_42001120)(param_1);
  (*(code *)PTR_FUN_42000a4c)(local_30[0]);
  return;
}