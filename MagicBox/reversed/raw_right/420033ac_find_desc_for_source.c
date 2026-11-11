// 420033ac  find_desc_for_source  FUN_420033ac  size=114
// strings: svd != NULL

void FUN_420033ac(int param_1,uint param_2)

{
  bool bVar1;
  uint *puVar2;
  int *piVar3;
  int *in_t0;
  
  puVar2 = (uint *)*DAT_42000478;
  do {
    if (puVar2 == (uint *)0x0) {
      return;
    }
    if ((*puVar2 & 4) == 0) {
      if (((int)(*puVar2 << 2) >> 0x18 == param_1) && ((*puVar2 >> 0x10 & 1) == param_2)) {
        return;
      }
    }
    else if ((*puVar2 >> 0x10 & 1) == param_2) {
      piVar3 = (int *)puVar2[1];
      if (piVar3 != (int *)0x0) goto LAB_4200340a;
      piVar3 = in_t0;
      param_1 = (*(code *)PTR_FUN_42000044)
                          (PTR_s_intr_alloc_c_3c031654_0x20_42000490,0xc0,
                           PTR_s_find_desc_for_source_4200048c,PTR_s_svd____NULL_42000488);
      in_t0 = piVar3;
      do {
        if ((int)(short)(*piVar3 << 7) >> 8 == param_1) {
          bVar1 = true;
          goto LAB_42003414;
        }
        piVar3 = (int *)piVar3[5];
LAB_4200340a:
      } while (piVar3 != (int *)0x0);
      bVar1 = false;
LAB_42003414:
      if (bVar1) {
        return;
      }
    }
    puVar2 = (uint *)puVar2[2];
  } while( true );
}


