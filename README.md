# Starton
输入一行运算式，不用加=，回车获得结果
注：()使用英文的。
容错机制：除数不能为0，)不能没有，不能有四则运算符之外的数，出现只会计算出最少无错的部分。
整体思路：没有用栈，一个一个字符进行提取。借助运算符的优先级进行运算，借助了迭代的思想，先计算括号的部分，提取出括号的内容再按照高到低依次运算，最终返回结果。
