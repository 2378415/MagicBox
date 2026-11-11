// strings: strncmp(src_path, vfs->path_prefix, vfs->path_pr

undefined * FUN_4200bf38(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = (*DAT_42000c68)(param_2,param_1 + 8,iVar3);
  if (iVar1 != 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_vfs_c_3c036314_0x15_42000c64,0x2fc,PTR_s_translate_path_42000c60,
               PTR_s_strncmp_src_path__vfs_>path_pref_42000c5c);
  }
  iVar1 = (*DAT_4200030c)(param_2);
  puVar2 = PTR_DAT_42000c58;
  if (iVar3 != iVar1) {
    puVar2 = (undefined *)(param_2 + iVar3);
  }
  return puVar2;
}