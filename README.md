# Conquer-English-Text
- 一个小工具，可以对比目标文本和词库，找出对应词汇，本版本适用于四六级(CET4/6)。

---

# 四六级大纲词汇照妖镜
## 原理描述
- 通过对比目标文章与大纲词汇表，对目标文章的单词分析，寻找在四/六级大纲词汇出现的单词，进行标记或筛选出相应的大纲词汇，以帮助使用者有针对性地进行笔记。
## 设计与实现(C语言)
### 参考：
* 《C Primer Plus》6th edition
    * Chapter 11 String and String Function
    * Chapter 13 Files I/O
* 《Data structure and algorithm analysis》2nd edition
* 中国大学Mooc—浙江大学—C语言进阶习题
### 如何使用?
* 1.点击 “Clone or download” 按钮
    * a.选择 “Download Zip”
    * b.解压文件到你能找到的地方。
* 2.使用一些可以编译c源代码的工具,如IDE(Devc++)等,编译main.c,使其生成main.exe
* 3.将你要查找的文章以.txt 文件形式复制到同一文件夹并使用终端软件 (Windows CMD)
    * 输入以下命令
        * ./main.exe NAME.txt
        * 注意 :把你的文件名替换到NAME的位置上
