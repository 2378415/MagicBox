// strings: xResult == ( ( BaseType_t ) 1 ) | \d7@L

void FUN_4202e948(undefined4 param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  iVar1 = (*(code *)PTR_FUN_42001f3c)(param_1,&local_30,auStack_2c);
  if (iVar1 != 1) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_idf_additions_c_3c03b594_0x28_42001f38,0xfc,PTR_s_vQueueDeleteWithCaps_42001f34
               ,PTR_s_xResult________BaseType_t___1___42001f30);
  }
  (*(code *)PTR_FUN_42001120)(param_1);
  (*(code *)PTR_FUN_42000a4c)(auStack_2c[0]);
  (*(code *)PTR_FUN_42000a4c)(local_30);
  return;
}