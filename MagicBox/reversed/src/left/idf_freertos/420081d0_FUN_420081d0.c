void FUN_420081d0(int param_1,uint param_2)

{
  do {
    memw();
  } while (-((((uint *)**(undefined4 **)(PTR_PTR_42000978 + param_1 * 4))[7] >> 0x10 & 0x3ff) - 0x80
            ) < 2);
  memw();
  *(uint *)**(undefined4 **)(PTR_PTR_42000978 + param_1 * 4) = param_2 & 0xff;
  return;
}