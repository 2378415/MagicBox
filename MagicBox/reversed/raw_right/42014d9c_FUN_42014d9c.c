// 42014d9c  FUN_42014d9c  FUN_42014d9c  size=203

int FUN_42014d9c(int param_1,undefined4 param_2,char param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  byte local_30 [48];
  
  if (*(int *)(param_1 + 100) == 1) {
    iVar2 = FUN_42013fcc(*(undefined4 *)(param_1 + 0x38),0,param_2);
    if (iVar2 == 0) {
      if (param_3 == '\0') {
        iVar2 = DAT_42000cd4;
      }
      else {
        local_30[0] = 1;
        while( true ) {
          if ((local_30[0] == 0xff) ||
             ((*(uint *)((uint)(local_30[0] >> 5) * 4 + param_1 + 0x44) & 1 << (local_30[0] & 0x1f))
              == 0)) break;
          local_30[0] = local_30[0] + 1;
        }
        if (local_30[0] == 0xff) {
          iVar2 = DAT_420010a4;
        }
        else {
          iVar2 = FUN_42014b48(param_1,0,1,param_2,local_30);
          if (iVar2 == 0) {
            iVar2 = FUN_42024c78(param_1 + 0x44,local_30[0],1);
            bVar1 = local_30[0];
            if (iVar2 == 0) {
              *param_4 = local_30[0];
              puVar3 = (undefined4 *)(*(code *)PTR_FUN_420006e0)(0x1c);
              if (puVar3 == (undefined4 *)0x0) {
                iVar2 = 0x101;
              }
              else {
                *puVar3 = 0;
                puVar3[1] = 0;
                *(byte *)(puVar3 + 6) = bVar1;
                (*DAT_42000cfc)(puVar3 + 2,param_2,0xf);
                *(undefined1 *)((int)puVar3 + 0x17) = 0;
                FUN_42024cb0(param_1 + 0x38,puVar3);
                iVar2 = 0;
              }
            }
            else {
              iVar2 = -1;
            }
          }
        }
      }
    }
    else {
      *param_4 = *(byte *)(iVar2 + 0x18);
      iVar2 = 0;
    }
  }
  else {
    iVar2 = DAT_420010a0;
  }
  return iVar2;
}


