// 42003420  is_vect_desc_usable  FUN_42003420  size=191
// strings: !((vd->flags & VECDESC_FL_SHARED) && (vd->flags  | intr_alloc.c | is_vect_desc_usable

undefined4 FUN_42003420(uint *param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint in_t0;
  undefined1 in_PRID;
  byte local_30 [4];
  int iStack_2c;
  uint uStack_28;
  
  uVar3 = *param_1 >> 0x11 & 0x1f;
  FUN_42005af8(param_3,uVar3,local_30);
  if ((uStack_28 & 2) == 0) {
    if (((uStack_28 & 1) == 0) || (param_4 != -1)) {
      if ((param_2 & 1 << (local_30[0] & 0x1f)) == 0) {
        uVar1 = 0;
      }
      else {
        if ((param_2 & 0x200) == 0) {
          if (iStack_2c == 1) {
            return 0;
          }
        }
        else if (iStack_2c == 0) {
          return 0;
        }
        uVar4 = (uint)(short)(ushort)*param_1;
        if ((uVar4 & 1) == 0) {
          if (((ushort)*param_1 & 0xc) == 0xc) {
            uVar4 = in_t0;
            (*(code *)PTR_FUN_42000044)
                      (PTR_s_intr_alloc_c_3c031654_0x20_42000490,0x12d,
                       PTR_s_is_vect_desc_usable_42000498,
                       PTR_s____vd_>flags___VECDESC_FL_SHARED_42000494);
          }
          if ((uVar4 & 8) == 0) {
            if ((uVar4 & 4) == 0) {
              uVar4 = rsr(in_PRID);
              iVar2 = FUN_42026a70(uVar3,uVar4 >> 0xd & 1);
              if (iVar2 == 0) {
                uVar1 = 1;
              }
              else {
                uVar1 = 0;
              }
            }
            else if ((param_2 & 0x100) == 0) {
              uVar1 = 0;
            }
            else if ((param_2 >> 10 & 1) == (uVar4 >> 1 & 1)) {
              uVar1 = 1;
            }
            else {
              uVar1 = 0;
            }
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


