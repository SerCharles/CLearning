将命题公式转换为真值表
输入数据：
输入：命题公式：（命题必须是单个大小写字母）（长度不要超过100，命题数量不要超过15）
输出：第一行：各个命题的名称（按ASCII码排序），以及“RS”
      第2-2*n+1行：真值表（按二进制顺序）
样例：
输入：A&(!A|B）
输出：
A  B  RS
0  0  0
0  1  0
1  0  0
1  1  1