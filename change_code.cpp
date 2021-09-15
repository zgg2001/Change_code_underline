/*************************************************************************
	> File Name: change_code.cpp
	> Author: ZHJ
	> Remarks: 代码混淆器类change_code的定义 
    > Created Time: Wed 15 Sep 2021 09:25:21 PM CST
 ************************************************************************/

#include"change_code.h"

change_code::change_code(int argc, char* argv[])
{
    //如果参数数量不对则输出help信息
    if(help_judge(argc) == false)
    {
        help_print();
    }
}

change_code::~change_code()
{
    
}

void change_code::help_print()
{
    cout << endl;
    cout << "欢迎使用本代码混淆器" << endl;
    cout << "by ZHJ" << endl;
    cout << "使用格式如下:" << endl;
    cout << "./line [原文件] [混淆后文件]" << endl;
    cout << endl;
}
