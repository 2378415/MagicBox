// strings: xHandle

int FUN_4037b320(int param_1,undefined4 param_2,undefined4 param_3)

{
  char unaff_a8;
  
  if ((-(unaff_a8 + -1) & param_1 != 0) == 0) {
    FUN_40381d9c(PTR_s_queue_c_3c032220_0x2a_40374c30,0x372,
                 PTR_s_xQueueCreateCountingSemaphoreSta_40374c70,PTR_s_xHandle_40374c6c);
  }
  else {
    param_1 = FUN_4037b1c0(param_1,0,0,param_3,2);
    if (param_1 != 0) {
      memw();
      *(undefined4 *)(param_1 + 0x38) = param_2;
    }
  }
  return param_1;
}