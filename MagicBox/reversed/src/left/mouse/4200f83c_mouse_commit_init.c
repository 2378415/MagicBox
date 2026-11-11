void mouse_commit_init(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  (*(code *)PTR_FUN_420004b0)
            (PTR_FUN_42000e60,PTR_s_MouseCommitTask_42000e5c,DAT_42000988,0,8,DAT_42000e08,
             DAT_42000664);
  uVar3 = (*(code *)PTR_FUN_42000e7c)(1,0,3);
  puVar2 = PTR_s_BezierTimer_42000e6c;
  puVar1 = PTR_FUN_42000e68;
  *DAT_42000e64 = uVar3;
  iVar4 = (*(code *)PTR_FUN_42000e80)(puVar2,1,0,0,puVar1);
  *DAT_42000e0c = iVar4;
  if (iVar4 == 0) {
    (*(code *)PTR_FUN_420000a8)
              (PTR_s_Mouse_Commit_c_3c036798_0x20_42000e78,0x10f,
               PTR_s_initialize_mouse_commit_task_42000e74,PTR_s_bezier_timer_42000e70);
  }
  return;
}