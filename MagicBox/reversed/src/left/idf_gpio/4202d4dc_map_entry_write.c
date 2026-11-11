void map_entry_write(int param_1,uint param_2,uint param_3)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x214) != 0)) &&
     ((param_2 & 0xffff | param_3 & 0xffff) < 0x100)) {
    *(char *)(*(int *)(param_1 + 0x214) + (param_2 & 0xffff) + 99) = (char)(param_3 & 0xffff);
  }
  return;
}