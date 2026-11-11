// strings: Fail to alloc hub_class | Hub depth(%d) is overflow | Unable to set hub depth  | /dev/hub%d | hubint_tim

int FUN_4200ea90(int param_1,uint param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  ushort uVar6;
  undefined1 auStack_30 [48];
  
  param_2 = param_2 & 0xff;
  puVar2 = (undefined1 *)FUN_4200e93c();
  if (puVar2 == (undefined1 *)0x0) {
    (*DAT_42000634)(PTR_DAT_42000c1c);
    (*DAT_42000634)(PTR_s_Fail_to_alloc_hub_class_42000c70);
    (*DAT_42000634)(PTR_DAT_42000c24);
    return -1;
  }
  puVar2[3] = *(undefined1 *)(param_1 + 2);
  *(int *)(puVar2 + 0x2af0) = param_1;
  *(undefined4 *)(puVar2 + 0x2af4) = *(undefined4 *)(param_1 + 0xa64);
  cVar1 = *(char *)(param_1 + 3);
  puVar2[4] = cVar1;
  *(undefined1 **)(param_1 + 0xa60) = puVar2;
  *(undefined1 **)(param_2 * 0x144 + param_1 + 0x3c) = puVar2;
  uVar6 = (ushort)*(byte *)(param_1 + 4);
  if (5 < uVar6) {
    (*DAT_42000634)(PTR_DAT_42000c1c);
    (*DAT_42000634)(PTR_s_Hub_depth__d__is_overflow_42000c74,*(undefined1 *)(param_1 + 4));
    (*DAT_42000634)(PTR_DAT_42000c24);
    return -2;
  }
  if (((uVar6 != 0) && (cVar1 == '\x05')) && (iVar3 = FUN_4200e59c(puVar2,uVar6 - 1), iVar3 < 0)) {
    (*DAT_42000634)(PTR_DAT_42000c1c);
    (*DAT_42000634)(PTR_s_Unable_to_set_hub_depth_42000c78);
    (*DAT_42000634)(PTR_DAT_42000c24);
    return iVar3;
  }
  if (*(char *)(param_1 + 3) == '\x05') {
    iVar3 = FUN_4200e824(puVar2,puVar2 + 0x12);
    if (iVar3 < 0) {
      return iVar3;
    }
    FUN_4200e5dc(puVar2 + 0x12,0xb);
    puVar2[5] = puVar2[0x14];
    puVar2[6] = puVar2[0x17] * '\x02';
    puVar2[7] = 0;
  }
  else {
    iVar3 = FUN_4200e894(puVar2,puVar2 + 9);
    if (iVar3 < 0) {
      return iVar3;
    }
    FUN_4200e6a4(puVar2 + 9,9);
    puVar2[5] = puVar2[0xb];
    puVar2[6] = puVar2[0xe] * '\x02';
    puVar2[7] = (byte)(*(ushort *)(puVar2 + 0xc) >> 5) & 3;
  }
  for (uVar5 = 0; uVar5 < (byte)puVar2[5]; uVar5 = uVar5 + 1 & 0xff) {
    iVar3 = uVar5 * DAT_42000bcc;
    puVar2[iVar3 + 0x21] = (char)(uVar5 + 1);
    *(undefined1 **)(puVar2 + DAT_42000c68 + iVar3) = puVar2;
    *(undefined4 *)(puVar2 + DAT_42000c7c + iVar3) = *(undefined4 *)(param_1 + 0xa64);
  }
  if (*(char *)(param_1 + 0xd) == '\x02') {
    puVar2[8] = 1;
  }
  else {
    puVar2[8] = 0;
  }
  if (-1 < *(char *)(param_2 * 0x144 + param_1 + 0x4b)) {
    return -1;
  }
  *(uint *)(puVar2 + 11000) = param_1 + param_2 * 0x144 + 0x49;
  bVar4 = 0;
  while (bVar4 < (byte)puVar2[5]) {
    bVar4 = bVar4 + 1;
    iVar3 = FUN_4200ea4c(puVar2,bVar4,8);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  FUN_4200da94(puVar2[6]);
  bVar4 = 0;
  while (bVar4 < (byte)puVar2[5]) {
    bVar4 = bVar4 + 1;
    iVar3 = FUN_4200e7e4(puVar2,bVar4,auStack_30);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  *puVar2 = 1;
  FUN_42017b5c(param_1 + param_2 * 0x144 + 0x28,0x10,PTR_s__dev_hub_d_42000c80,puVar2[2]);
  *(uint *)(puVar2 + 0x2b3c) =
       ((uint)*(byte *)(*(int *)(puVar2 + 0x2af4) + 4) * 2 + ((byte)puVar2[2] - 1)) * 4 +
       DAT_42000c84;
  if (*(byte *)(param_1 + 3) < 3) {
    uVar5 = (uint)*(byte *)(*(int *)(puVar2 + 11000) + 6);
  }
  else {
    uVar5 = 1 << 0x20 - (0x20 - (*(byte *)(*(int *)(puVar2 + 11000) + 6) - 1 & 0x1f));
  }
  iVar3 = FUN_4200d970(PTR_s_hubint_tim_42000c8c,uVar5,PTR_FUN_42000c88,puVar2,0);
  *(int *)(puVar2 + 0x2b40) = iVar3;
  if (iVar3 == 0) {
    (*DAT_42000634)(PTR_DAT_42000c1c);
    (*DAT_42000634)(PTR_s_No_memory_to_alloc_int_timer_42000c90);
    (*DAT_42000634)(PTR_DAT_42000c24);
    return -1;
  }
  FUN_4200d9f0();
  return 0;
}