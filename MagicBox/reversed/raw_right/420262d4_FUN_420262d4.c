// 420262d4  FUN_420262d4  FUN_420262d4  size=63
// strings: xResult == ( ( BaseType_t ) 1 ) | Db7@8a7@

void FUN_420262d4(undefined4 param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  iVar1 = (*(code *)PTR_FUN_4200148c)(param_1,auStack_2c,&local_30);
  if (iVar1 != 1) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_idf_additions_c_3c035f34_0x28_42001488,0xfc,PTR_s_vQueueDeleteWithCaps_42001484
               ,PTR_s_xResult________BaseType_t___1___42001480);
  }
  (*(code *)PTR_FUN_42000b60)(param_1);
  (*(code *)PTR_FUN_420008b4)(local_30);
  (*(code *)PTR_FUN_420008b4)(auStack_2c[0]);
  return;
}


