// 42009ed0  translate_path  FUN_42009ed0  size=58
// strings: strncmp(src_path, vfs->path_prefix, vfs->path_pr

undefined * FUN_42009ed0(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = (*DAT_4200099c)(param_2,param_1 + 8,iVar3);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_42000044)
              (PTR_s_vfs_c_3c0331b8_0x15_42000998,0x2fc,PTR_s_translate_path_42000994,
               PTR_s_strncmp_src_path__vfs_>path_pref_42000990);
  }
  iVar1 = (*DAT_420001e4)(param_2);
  if (iVar3 == iVar1) {
    puVar2 = PTR_DAT_4200098c;
  }
  else {
    puVar2 = (undefined *)(param_2 + iVar3);
  }
  return puVar2;
}


