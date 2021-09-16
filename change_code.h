/*************************************************************************
	> File Name: change_code.h
	> Author: ZHJ
	> Remarks: 代码混淆器类change_code的声明 
	> Created Time: Wed 15 Sep 2021 09:24:19 PM CST
 ************************************************************************/

#ifndef _CHANGE_CODE_H_
#define _CHANGE_CODE_H_

#include<iostream>
#include<fstream>
#include"change_code_base.h"

using namespace std;

class change_code : public _change_code_base
{
public:
    change_code(int argc, char* argv[]);
    virtual ~change_code();
    //公有方法 开始转换
    bool change();

protected:
    //读取文件至缓冲区
    virtual bool _read_content_to_map();
    //处理缓冲区内的内容
    virtual bool _handle_content_from_map();
    //将处理后的内容输出至文件
    virtual bool _write_content_to_file();

protected:
    //判定参数数量
    bool _argument_number_judge(int argc) { return argc == 3; }
    //当参数有误时输出提示信息
    virtual void _argument_number_error_print();
    //输入文件打开读取出现问题的提示
    virtual void _input_file_error_print();

private:
    //当此值为false时 说明初始化失败
    bool _state = true;

};

#endif
