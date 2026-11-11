// 4200fccc  reenumTask  FUN_4200fccc  size=85

void FUN_4200fccc(void)

{
  int iVar1;
  
  if ((*DAT_42000d50 == 0) &&
     (iVar1 = (*(code *)PTR_FUN_42000380)
                        (PTR_FUN_42000d5c,PTR_s_reenumTask_42000d58,DAT_42000d54,0,5,DAT_42000d50,
                         DAT_4200049c), iVar1 != 1)) {
    FUN_420102a8(0);
    (*(code *)PTR_FUN_42000b90)(300);
    FUN_420102a8(1);
    return;
  }
  (*(code *)PTR_FUN_42000354)(*DAT_42000d50,0,0,2);
  return;
}


