void uart0_reply(undefined4 param_1,uint param_2,char param_3)

{
  undefined1 auStack_290 [2];
  undefined2 uStack_28e;
  undefined1 auStack_28c [608];
  int iStack_2c;
  
  if (param_2 < 0x259) {
    if (param_3 == '\0') {
      (*DAT_42000064)(auStack_290,PTR_DAT_42001320,3);
      (*DAT_42000064)((int)&uStack_28e + 1,param_1,param_2);
      (*DAT_42000064)(auStack_28c + (param_2 - 1),PTR_s_>>>_42001324,6);
      iStack_2c = param_2 + 9;
    }
    else {
      (*DAT_42000064)(auStack_290,PTR_DAT_420012b8,2);
      uStack_28e = (undefined2)param_2;
      (*DAT_42000064)(auStack_28c,param_1,param_2);
      iStack_2c = param_2 + 4;
    }
    (*(code *)PTR_FUN_42000488)(*DAT_42001294,auStack_290,0xffffffff,0);
  }
  return;
}