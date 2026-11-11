// strings: xResult == ( ( BaseType_t ) 1 ) | Db7@8a7@

void FUN_42026388(undefined4 param_1)

{
  int iVar1;
  undefined4 local_30 [12];
  
  iVar1 = (*(code *)PTR_FUN_4200148c)(param_1,0,local_30);
  if (iVar1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_idf_additions_c_3c035f34_0x28_42001488,0x145,
               PTR_s_vSemaphoreDeleteWithCaps_42001494,
               PTR_s_xResult________BaseType_t___1___42001480);
  }
  (*(code *)PTR_FUN_42000b60)(param_1);
  (*(code *)PTR_FUN_420008b4)(local_30[0]);
  return;
}