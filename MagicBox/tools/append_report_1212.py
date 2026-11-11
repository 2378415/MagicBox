import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
p = os.path.join(ROOT, '官方固件逆向分析报告.md')
t = open(p, encoding='utf-8').read()
t += '''

### 12.12 UART1 帧格式定版 + lock 族重写

**（1）片间帧格式已完整**：右片三个帧构造器（`0x420102A8`、`0x4200FAC0`、`0x4200FAE0`）写法一致：

```
5A <cmd> <len:u16> <payload…>
```

- `+0` 魔数 `0x5A`（'Z'）；
- `+1` 命令：`0xA0` EP0 隧道、`0xA1`、`0xA2` 数据/事件、`0xA3`；
- `+2..3` 负载长度（不是类型）；
- `+4` 起是负载，左片读到的 `+4/+5/+6/+8` 其实是 `payload[0..4]`。

这推翻了上一轮记录的两处“不一致”：`0xA0` 分支的 `==1` 是**负载长度为 1**；`+8` 属于负载而非头部溢出。

**（2）`lock_*` 四兄弟重写**：`cmd_lock_query` / `cmd_lock_axis` / `cmd_lock_param0` / `cmd_lock_param2` 分别对应「查询状态 / 查询轴向 / 设开关 / 设轴向参数」，且 `lock_m*(0)` 会连带 `catch_set(...,0)` 并清 dirty 标志。四者共用 `ctx+0x210` 的两张子表（`+0x54` 按键、`+0x9C` 轴向）。
'''
open(p, 'w', encoding='utf-8').write(t)
print('report updated')
