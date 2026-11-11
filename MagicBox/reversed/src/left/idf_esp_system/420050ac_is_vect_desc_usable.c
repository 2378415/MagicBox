// strings: !((vd->flags & VECDESC_FL_SHARED) && (vd->flags  | intr_alloc.c | is_vect_desc_usable

uint FUN_420050ac(uint *param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_t0;
  undefined1 in_PRID;
  byte local_30 [4];
  int iStack_2c;
  uint uStack_28;
  
  uVar2 = *param_1 >> 0x11 & 0x1f;
  FUN_4200779c(param_3,uVar2,local_30);
  if ((uStack_28 & 2) == 0) {
    uVar1 = param_4 == -1 & uStack_28;
    if ((param_4 == -1 & uStack_28) == 0) {
      if ((param_2 & 1 << (local_30[0] & 0x1f)) != 0) {
        if ((param_2 & 0x200) == 0) {
          if (iStack_2c == 1) {
            return uVar1;
          }
        }
        else if (iStack_2c == 0) {
          return uVar1;
        }
        uVar3 = (uint)(short)*param_1;
        if ((uVar3 & 1) == 0) {
          if ((~uVar3 & 0xc) == 0) {
            uVar3 = in_t0;
            (*(code *)PTR_FUN_420000a8)
                      (PTR_s_intr_alloc_c_3c033c58_0x20_42000650,0x12d,
                       PTR_s_is_vect_desc_usable_4200064c,
                       PTR_s____vd_>flags___VECDESC_FL_SHARED_42000648);
          }
          if ((uVar3 & 8) == 0) {
            if ((uVar3 & 4) == 0) {
              uVar1 = rsr(in_PRID);
              uVar2 = FUN_4202eff8(uVar2,uVar1 >> 0xd & 1);
              uVar1 = (uVar2 ^ 1) & 0xff;
            }
            else if (((param_2 & 0x100) != 0) &&
                    (uVar1 = 1, (param_2 >> 10 & 1) != (uVar3 >> 1 & 1))) {
              uVar1 = uVar3 & 8;
            }
          }
        }
      }
    }
    else {
      uVar1 = uStack_28 & 2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}