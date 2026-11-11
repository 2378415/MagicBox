// 403788ac  FUN_403788ac  FUN_403788ac  size=36

int FUN_403788ac(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  
  if ((((undefined4 *)param_1[2] == (undefined4 *)0x0) ||
      (pcVar2 = *(code **)param_1[2], pcVar2 == (code *)0x0)) ||
     (iVar1 = (*pcVar2)(param_1[3]), iVar1 == 0)) {
    (*(code *)**(undefined4 **)*param_1)();
    iVar1 = 0;
  }
  return iVar1;
}


