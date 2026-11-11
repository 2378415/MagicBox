void FUN_4200f7a8(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    (*(code *)PTR_FUN_42000d24)(0,1,0xffffffff);
    iVar1 = (*(code *)PTR_FUN_420008f8)();
    uVar3 = iVar1 + 0x96;
    while (uVar2 = (*(code *)PTR_FUN_420008f8)(), uVar2 < uVar3) {
      iVar1 = (*(code *)PTR_FUN_42000d24)(0,1,10);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_FUN_420008f8)();
        uVar3 = iVar1 + 0x96;
      }
    }
    frame_build_ep0(0);
    (*(code *)PTR_FUN_42000b90)(300);
    frame_build_ep0(1);
  } while( true );
}