// 4037af64  ESP_ERROR_CHECK  FUN_4037af64  size=42
// strings: ESP_ERROR_CHECK

void FUN_4037af64(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint unaff_retaddr;
  
  FUN_4037af18(PTR_s_ESP_ERROR_CHECK_40374c20,param_1,param_2,param_3,param_4,param_5,
               unaff_retaddr & 0x3fffffff | DAT_40374c1c & 0xc0000000);
                    /* WARNING: Subroutine does not return */
  FUN_40381ce0();
}


