/*************************************************************************
	> File Name: change_code.h
	> Author: ZHJ
	> Remarks: 代码混淆器类change_code的声明 
	> Created Time: Wed 15 Sep 2021 09:24:19 PM CST
 ************************************************************************/

#ifndef _CHANGE_CODE_H_
#define _CHANGE_CODE_H_

#include<iostream>

using namespace std;

class change_code
{
public:
    change_code(int argc, char* argv[]);
    virtual ~change_code();

public:
    bool help_judge(int argc) { return argc == 3; } //判定参数数量
    void help_print(); //当参数有误时输出提示信息
    
private:

};

#endif
