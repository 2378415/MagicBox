// strings: ***ERROR*** A stack overflow in task  |  has been detected.

void FUN_4037c13c(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  undefined1 auStack_80 [76];
  undefined *local_34 [3];
  undefined *apuStack_28 [10];
  
  puVar1 = auStack_80;
  local_34[0] = PTR_s____ERROR____A_stack_overflow_in_t_40374dfc;
  local_34[2] = PTR_s_has_been_detected__40374e00;
  local_34[1] = (undefined *)param_2;
  (*DAT_403744c4)(auStack_80,0,0x4b);
  ppuVar2 = local_34;
  do {
    puVar3 = *ppuVar2;
    ppuVar2 = ppuVar2 + 1;
    puVar1 = (undefined1 *)(*DAT_40374e04)(puVar1,puVar3);
  } while (ppuVar2 != apuStack_28);
  FUN_4037b3a8(auStack_80);
  do {
    ill();
  } while( true );
}