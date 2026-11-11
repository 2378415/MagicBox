// strings: ***ERROR*** A stack overflow in task  |  has been detected.

void FUN_4037bde0(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined *local_80 [3];
  undefined1 auStack_74 [116];
  
  local_80[0] = PTR_s____ERROR____A_stack_overflow_in_t_40374d54;
  local_80[2] = PTR_s_has_been_detected__40374d58;
  puVar1 = auStack_74;
  local_80[1] = (undefined *)param_2;
  (*DAT_4037448c)(puVar1,0,0x4b);
  for (uVar2 = 0; uVar2 < 3; uVar2 = uVar2 + 1) {
    puVar1 = (undefined1 *)(*DAT_40374d5c)(puVar1,local_80[uVar2]);
  }
  FUN_4037af90(auStack_74);
  do {
    ill();
  } while( true );
}