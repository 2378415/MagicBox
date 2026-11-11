import os
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

p = os.path.join(ROOT, 'reversed', 'README.md')
t = open(p, encoding='utf-8').read()
t = t.replace('| 代码行 | 142,551 |', '| 代码行 | 145,363（含 153 个兜底反汇编块） |')
t = t.replace('| 反编译失败后补反汇编 | **153 / 153**（每个文件末尾附 objdump 块） |',
              '| 反编译失败后补反汇编 | **153 / 153**（objdump 块带 2,812 个基本块标签、1,081 行符号/字符串注释） |')
t = t.replace('4. 遇到 `halt_baddata()`：同一文件末尾有 `objdump fallback` 块，是权威反汇编。',
              '4. 遇到 `halt_baddata()`：同一文件末尾有 `objdump fallback` 块，带 `L_xxxxxxxx:` 基本块标签、调用目标符号名与字符串常量注释。')
open(p, 'w', encoding='utf-8').write(t)

p2 = os.path.join(ROOT, '官方固件逆向分析报告.md')
t2 = open(p2, encoding='utf-8').read()
t2 = t2.replace('阅读 `halt_baddata` 函数时不必再手工查地址表。',
                '阅读 `halt_baddata` 函数时不必再手工查地址表。153 个块合计 **2,812 个基本块标签**（`L_4200e04a:` 之类）与 **1,081 行**符号/字符串注释。')
open(p2, 'w', encoding='utf-8').write(t2)
print('numbers updated')
