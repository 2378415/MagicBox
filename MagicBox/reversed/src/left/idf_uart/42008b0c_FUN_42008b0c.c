uint FUN_42008b0c(char *param_1,uint param_2)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = *param_1;
  if (((((cVar1 == '/') && (param_1[1] == '0')) && (param_1[2] == '\0')) ||
      (((cVar1 == '/' && (param_1[1] == '1')) && (param_1[2] == '\0')))) ||
     (((cVar1 == '/' && (param_1[1] == '2')) && (param_1[2] == '\0')))) {
    if (param_2 == 0) {
      return 0;
    }
    if (((param_2 >> 1 & 3) != 0) && ((param_2 & 1) == 0)) {
      return param_2 & 1;
    }
    puVar2 = (undefined4 *)FUN_42020b54();
    *puVar2 = 0xd;
  }
  else {
    puVar2 = (undefined4 *)FUN_42020b54();
    *puVar2 = 2;
  }
  return 0xffffffff;
}