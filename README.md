# Change_code_underline
这是一个简单的混淆器，通过#define来实现简单的混淆

# 思路
通过#define宏定义对代码内容进行批量替换，将原文替换为多段下划线，从而达到混淆的目的

# v1.0
1. 混淆功能已经初步实现 参数格式为: ./line [原文件] [混淆后文件] 
2. 核心操作在_change_content()与_change_word_to_underline()中
3. 目前仅会对数字、字母、下划线进行进行混淆
