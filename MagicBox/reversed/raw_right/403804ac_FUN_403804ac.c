// 403804ac  FUN_403804ac  FUN_403804ac  size=32

uint FUN_403804ac(int param_1)

{
  memw();
  memw();
  return (uint)(**(int **)(param_1 + 4) == 0) | ((*(int **)(param_1 + 4))[0x29] & 1U) * 2;
}


