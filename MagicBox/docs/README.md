# 文档索引（docs/）

> 这份文件只解决一件事：**先读哪份、哪份是权威、哪份只是历史**。
> 状态：2026-11-14 更新（HANDOVER 重写，旧版存档 `HANDOVER-2026-11-13-archive.md`）。仓库已瘦身为「只保留可编译固件工程」，逆向侧文档不再存在于本仓库。

## 1. 阅读顺序

| 顺序 | 文档 | 什么时候读 |
|---|---|---|
| 0 | [../README.md](../README.md) | 第一次进仓库：目录、构建、刷写、边界（5 分钟） |
| 1 | [HANDOVER.md](HANDOVER.md) | 接手必读：现状、架构、构建/刷写、测试、坑位清单（1,180 行；§14 为历史运行手册，按需跳读） |
| 2 | [API-control-port.md](API-control-port.md) | 要对接上位机 / 改协议时：控制口命令、二进制帧、`mx.*` 探针、故障对照 |
| 3 | [40-status.md](40-status.md) | 想知道「到哪了 / 还差什么」：构建状态、handler、待办（自动生成） |
| 4 | [30-decisions.md](30-decisions.md) | 想改设计时：D1–D48 的结论、理由、证据与推翻条件 |
| 5 | [50-vendor-channel.md](50-vendor-channel.md) | 要改厂商通道（HECATE / G3M PRO）或排查"卡/DPI 不对"：架构、五个根因、探针判据、刷机与已知限制 |
| 6 | [00-facts.md](00-facts.md) · [10-abi.md](10-abi.md) · [20-types.md](20-types.md) | 需要原始事实（镜像身份、分区表、调用约定、数据结构） |
| 7 | [00-plan.md](00-plan.md) | 只想看立项时的验收判据（T1/T2/T3）——**立项期口径** |\n| 8 | [HANDOVER-2026-11-13-archive.md](HANDOVER-2026-11-13-archive.md) | 需要 11-13 及更早的细节（旧版交接文档全文） |

## 2. 权威边界（同一主题只认一处）

| 主题 | 权威文档 | 其余地方只留索引/摘要 |
|---|---|---|
| 协议与命令（文本 + 二进制 + `mx.*`） | [API-control-port.md](API-control-port.md) | HANDOVER §14.6 是探针速查摘要 |
| 构建 / 刷写 / 回滚命令 | [HANDOVER.md](HANDOVER.md) §5–§6 | 根 README 只留最小命令 |
| 厂商通道（HECATE / G3M PRO） | [50-vendor-channel.md](50-vendor-channel.md) | `mouse/README.md` 只留组件内约定与已知限制 |
| 决策与取舍 | [30-decisions.md](30-decisions.md) | HANDOVER §9 是摘要 |
| 当前进度与遗留 | [40-status.md](40-status.md)（机器生成） | 手工补充写在 [40-status-appendix.md](40-status-appendix.md) |
| 某轮改动的过程与证据 | `verification/report/`（按日期） | 方案性长文在 `verification/plan-*.md` |

## 3. 生成物与手工区

- [40-status.md](40-status.md) 由 `python tools/status.py` **整体重写**：尺寸取自 `app_left|app_right/build`，
  报告清单取自 `verification/report/*.md`。因此：
  - 先 `tools/build_app.ps1` 再跑脚本，否则构建列显示「未构建」；
  - 不要直接手改它——要补内容就写 [40-status-appendix.md](40-status-appendix.md)，脚本会原样附在末尾。
- `verification/fingerprints/*.json`、`verification/*.json` 是工具产物，不建议手改。

## 4. 目录速查

```
docs/                    方案 / 事实 / 决策 / 状态 / 协议（本目录）
verification/plan-*.md   4 份方案的完整执行记录（右片固件、HECATE、身份、性能）
verification/report/     32 份上机报告（按日期；批次号见各文件首行）
verification/logs/       台架原始日志（bench-cycle / finish / regress；本地产物，`*.log` 不入库）
verification/model/      纯模型回归（6 个 pytest 文件 / 46 例，无需硬件；含按键队列/守卫/事件调度模型）
verification/regress/    真机协议回归（conftest 夹具 + 12 个用例文件，128 例；含按键完整性、按键×SUMV 并发、按键事件×点击）
tools/                   构建、刷写、台架、分析脚本，见 ../tools/README.md
```

## 5. 维护约定

1. 每轮上机 → 新增 `verification/report/YYYY-MM-DD-<主题>.md`，**不要**把日志塞进 report；
2. 每个不可回退的取舍 → 记一条 `D##` 到 30-decisions；
3. 改协议/命令 → 只改 API-control-port，并在其「变更记录」补一行；
4. 跑完 `status.py` 后检查 `git diff docs/40-status.md`，异常数字说明构建缺失或报告未归档；
5. 引用旧仓库（`reversed/`、`work/*.dump`）的历史文档已在原处标注「已清理」，不要试图修复这些链接。
