# 仓库清理方案与执行记录（2026-11-11）

工作区：`D:\GitHub\MagicBox`（git 仓库，仅 1 次 `Initial commit`，两个子项目此前全部处于 untracked 状态）
原始工程：`D:\JinPeng\MagicBox`、`D:\JinPeng\MagicBullet`（除 `.git` 外与本仓库逐字节一致，已按目录比对文件数与总体积）

| 指标 | 清理前 | 清理后 |
|---|---|---|
| 文件数 | 22,596 | 7,600（含本轮新增的 `.gitignore`、`CLEANUP.md`、重写的根 `README.md`、`scripts/clean-repo.ps1`） |
| 体积 | 2,945.8 MB | 42.6 MB |
| 最大单文件 | 543 MB（`ghidra_12.2_PUBLIC_20261016.zip`） | 9.2 MB（`models/ort-qnn-v79.aar`） |
| 能否 git push | 不能（单文件超 100 MB 硬限，总量超 1 GB 建议线） | 可以 |

结论：仓库里真正需要版本管理的是 **源码 + 文档 + 构建必需的少量二进制**，其余 2.9 GB 全部是构建产物、第三方工具链、一次性脚本和重复大文件。本轮已按分类删除，删除项都可由 `D:\JinPeng` 原目录复制回来。

---

## 1. 审计方法

1. 全量文件清单（含隐藏目录），按二级目录汇总文件数与体积，锁定体量来源。
2. 对被引用的可疑项做引用核验：Gradle `implementation files(...)`、`idf_component_register(SRCS ...)`、`settings.gradle include`、源码 `import`/全仓 grep。
3. 按大小分组 + SHA-256 做重复文件检测（同体积文件哈希比对），确认重复大文件。
4. 与 `D:\JinPeng` 同路径目录做「文件数 + 总体积」比对，确认本仓库是可再生副本，删除不会丢失唯一数据。

引用核验的关键结论：

- `MagicBullet/build.gradle:62` → `implementation files("$rootDir/models/ort-qnn-v79.aar")`，**唯一**必需的大二进制，保留。
- `settings.gradle` → `include ':app'`、`include ':libuvc'`，libuvc 从源码编译（`libuvc/build.gradle`），仓库里的 `libuvc/aar/libuvc-3.2.9.aar` 无人引用。
- QNN 运行时来自 maven（`com.qualcomm.qti:qnn-runtime:2.42.0`），`models/qnn-aar/` 只是本地解包副本，构建不读它。
- `app/src/main/assets/yolov8n_int8_qdq.onnx` 是 `ModelStore.BUILTIN_ASSET` 的运行时资源，保留；`models/` 与 `模型/` 下的同名文件都是副本。
- `MagicBox/tools/rizin/` 只被 `MagicBox/tools/func.py` 一处引用（反汇编辅助），不影响重建流水线主体。

---

## 2. 已删除清单（按类，共 14,997 个文件 / 2,903.2 MB）

### 2.1 build：构建产物与缓存（可再生，762.0 MB）

| 路径 | 文件 | 体积 | 说明 |
|---|---|---|---|
| `MagicBullet/app/build` | 974 | 552.5 MB | Gradle 产物，含 99 MB debug APK、native 中间库 |
| `MagicBox/AMagicBox-Rebuild/app_left/build` | 2,026 | 132.1 MB | `idf.py build` 输出 |
| `MagicBox/AMagicBox-Rebuild/app_right/build` | 957 | 65.3 MB | 同上 |
| `MagicBox/AMagicBox-Rebuild/app_left/managed_components` | 2,069 | 14.1 MB | ESP-IDF 组件管理器按 `idf_component.yml` 拉取 |
| `MagicBullet/libuvc/build` | 225 | 18.2 MB | |
| `MagicBullet/.gradle` | 15 | 3.9 MB | Gradle 缓存/探针 |
| `MagicBullet/build` | 19 | 2.1 MB | 调试期 uiautomator dump、截图、`aim_config_*.xml` |
| `MagicBullet/app/.cxx` | 72 | 0.9 MB | NDK 构建缓存 |
| `MagicBox/AMagicBox-Rebuild/work`、`btn_trace.log`、`.pytest_cache` | 46 | 1.0 MB | 台架跑批 JSON、日志 |
| 全仓 `__pycache__` / `*.pyc` | ~1,100 | ~7 MB | 含 `models/venv-tflite` 内嵌缓存 |

### 2.2 vendor：第三方工具链与安装包（841.5 MB）

| 路径 | 体积 | 说明 |
|---|---|---|
| `MagicBox/tools/rizin/` | 708.6 MB | rizin win 静态包解压（每个 exe 52.7 MB 重复一份） |
| `MagicBox/tools/rizin-static.zip` | 110.0 MB | 上面的压缩包本体 |
| `MagicBox/官方固件/烧录工具1_7.exe` | 22.2 MB | 官方烧录工具，外部可再获取 |
| `MagicBullet/libuvc/aar/libuvc-3.2.9.aar` | 0.7 MB | 未被任何 gradle 脚本引用（模块走源码编译） |

### 2.3 scratch：一次性脚本 / 日志 / 中间转储（1,040.3 MB）

| 路径 | 文件 | 体积 | 说明 |
|---|---|---|---|
| `MagicBox/work/` | 5,199 | 713.4 MB | 反编译工程中间产物：306 个一次性 patch 脚本、`raw_nop_*` dump、`.gdb` 脚本、抓包、镜像切片、`ghidra_*.zip`、`Wireshark-*.exe`、`zadig-2.9.exe` |
| `MagicBullet/.research/` | 356 | 299.7 MB | 克隆的参考仓库（MAKCM/AIO_Tool 109 MB）、QNN/ORT aar 解包、设备截图 |
| `MagicBox/ghidra-projects/` | 13 | 27.2 MB | Ghidra 工程库，可由 `work/*.elf` 重新 `analyzeHeadless` 生成 |
| `MagicBullet/extract_pdf.py` | 1 | 0.3 KB | 一次性脚本，硬编码绝对路径 |

### 2.4 dup：重复大文件（252.6 MB）

| 路径 | 体积 | 与谁重复 |
|---|---|---|
| `MagicBullet/models/qnn-aar/` | 180.4 MB | maven `qnn-runtime` 的本地解包 |
| `MagicBullet/models/venv-tflite/` | 30.5 MB | Python 虚拟环境（Windows 版），重建代价低 |
| `MagicBullet/models/ort-aar/` | 22.9 MB | `models/ort-qnn-v79.aar` 解包，`libonnxruntime.so` 三份同哈希 |
| `MagicBullet/models/calib/` | 13.3 MB | 量化校准图集（`quantize.py` 输入） |
| `MagicBullet/models/yolov8n.onnx` | 12.2 MB | 训练导出中间件 |
| `MagicBullet/models/aar/ort.aar` | 9.1 MB | 与 `.research/ort-qnn.zip` 同哈希，且无脚本引用 |
| `MagicBullet/models/yolov8n.pt` | 6.2 MB | 训练权重 |
| `MagicBullet/models/yolov8n_int8_qdq.onnx` | 3.6 MB | 与 `app/src/main/assets/` 内资源同哈希 |
| `MagicBullet/模型/det_10g_640_int8_qdq.onnx` | 4.2 MB | 与 `models/imported/m.onnx` 同哈希 |

### 2.5 junk：空壳与占位文件

| 路径 | 说明 |
|---|---|
| `MagicBox/rea-docs/` | `firmware-analysis.md` 内容为 `404: Not Found`；`README_zh.md` 是外部 REA 技能说明，与工程无关 |

`models/` 下的研究脚本（`check_model.py`、`quantize.py`、`compare.py`、`debug_out.py`、`export_onnx.py`、`tail.py`）已保留——它们记录了 int8 量化流程，但引用的是绝对路径，见 §5。

---

## 3. 保留清单（7,600 个文件 / 42.6 MB）与理由

| 内容 | 体积 | 为什么留 |
|---|---|---|
| `MagicBox/官方固件/*.bin` | 0.7 MB | 全部逆向结论的唯一事实来源，不可再生 |
| `MagicBox/官方固件/*.strings.json`、`*.xref.json` | 0.6 MB | 文档直接引用，体积小，保留便于阅读 |
| `MagicBox/reversed/` | 6.7 MB | 逆向交付物（3,071 函数源码树 + 26 模块头 + 11 篇 docs） |
| `MagicBox/tools/`（脚本部分，58 个） | 0.2 MB | 重建流水线脚本（`patch_excw.py` → `merge_patched.py` → `build_project.py` → `fill_gaps.py`） |
| `MagicBox/backups/probe/*.bin` | <0.1 MB | 真机读写回证，小 |
| `MagicBox/AMagicBox-Rebuild/**` 源码 + docs + verification | 1.5 MB | 固件工程本体（12 个组件、40 余条命令 handler、回归用例与逐轮报告） |
| `MagicBullet/app/src`（76 个源文件） | 4.1 MB | App 源码 + 79 条单测 + assets 内置模型 |
| `MagicBullet/libuvc/src` | 15.4 MB | vendored UVC 库源码与 4 个 ABI 的预编译 `.so`（模块从源码编译，缺了无法构建） |
| `MagicBullet/models/ort-qnn-v79.aar` | 9.2 MB | `build.gradle:62` 硬引用 |
| `MagicBullet/models/imported/m.onnx` | 4.2 MB | 现场生效的 8 类 e2e 模型归档 |
| `MagicBullet/docs/`、`README.md`、gradle 包装器 | 0.2 MB | 文档 + 构建入口 |

---

## 4. 校验

- 构建关键文件全部在位：`models/ort-qnn-v79.aar`、`app/src/main/assets/yolov8n_int8_qdq.onnx`、`gradle/wrapper/gradle-wrapper.jar`、`libuvc/.../libUVCCamera.so`、`app_left/main/app_main.c`、`app_left/dependencies.lock`、`components/makcu_proto/handlers.def`、`官方固件/V3.2_LEFT.bin`、`reversed/src/`。
- 清理脚本重跑幂等：`目标 0 项 / 0 MB`。
- 重复文件复查：剩余文件中同哈希的体积重复项为 0（`libuvc` 的 4 个 ABI `.so` 属正常多架构产物）。

---

## 5. 尚未动手、建议后续处理的项

1. **一次性补丁脚本归档**：`MagicBox/AMagicBox-Rebuild/tools/` 有约 84 个、`MagicBox/tools/` 有约 31 个未被文档/源码引用的 `fix_*` / `upd_*` / `regen_cmake*` / `wire_*` 脚本。建议移到 `tools/_archive/`，只留 `build_app.ps1`、`flash_*.ps1`、`aim_stress.py`、`aim_move.py`、`boxbench*`、`link_probe.py`、`diff_insn.py`、`lib_fingerprint.py`、`px_cal.py` 等仍在用的工具。本轮未删，避免误伤仍在使用的 `wire_*`。
2. **孤儿 stub 源码**：`components/makcu_hiddev/src/makcu_hiddev_stub.c`（4 条待移植函数）、`components/makcu_hidhost/src/makcu_hidhost_stub.c`（23 条）**没有出现在任何 `CMakeLists.txt` 的 SRCS 里**，不参与编译。保留原因：它们是待移植函数地址清单（`diff_insn.py` 的对照表）。若确认移植计划已废弃，删这两个文件即可（共 2.5 KB）。
3. **`components/makcu_board/`**：只有一个 `const unsigned makcu_board_port_surface = 6;`，但被 `app_left/main/CMakeLists.txt` 的 `REQUIRES` 引用，删除需同步改 CMake，不建议本轮动。
4. **研究脚本硬编码路径**：`MagicBullet/models/*.py` 全部写死 `D:\JinPeng\MagicBullet\...`。若这些脚本要跟着仓库走，改成相对路径；否则移到 `tools/research/` 并加进 `.gitignore`。
5. **`libuvc/src` 里的上游文档**：`libjpeg-turbo-1.5.0/doc`、`testimages`、`libusb/doc`、`rapidjson/doc|test|thirdparty` 约 2 MB，属 vendored 第三方，裁剪不影响构建，但会让「vendored 上游」与官方 tag 不再一致，建议保留。
6. **`MagicBox/README.md` 的「快速复现」段落**现在指向已删除的 `work/` 与 `tools/rizin/`：需要时先 `python tools\patch_excw.py both` 重新生成 `work/*.nop.bin`，rizin 从 `D:\JinPeng\MagicBox\tools\rizin` 复制或重新下载。
7. **入库策略**：`ort-qnn-v79.aar`（9.2 MB）与 `官方固件/*.bin` 直接提交即可；若以后还要放 >50 MB 的模型/固件，用 Git LFS，不要塞进普通提交。

---

## 6. 回滚

删除项全部来自 copy，回滚就是反向复制：

```powershell
Copy-Item -Recurse -Force D:\JinPeng\MagicBox\work            D:\GitHub\MagicBox\MagicBox\
Copy-Item -Recurse -Force D:\JinPeng\MagicBox\tools\rizin     D:\GitHub\MagicBox\MagicBox\tools\
Copy-Item -Recurse -Force D:\JinPeng\MagicBullet\.research    D:\GitHub\MagicBox\MagicBullet\
# 其余按 §2 表中路径同样复制
```

本次新增的两个文件：`.gitignore`（防回归）与 `scripts/clean-repo.ps1`（分类清理脚本，默认预演，`-Apply` 才删）。
