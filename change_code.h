/*************************************************************************
	> File Name: change_code.h
	> Author: ZHJ
	> Remarks: 代码混淆器类change_code的声明 
	> Created Time: Wed 15 Sep 2021 09:24:19 PM CST
 ************************************************************************/

#ifndef _CHANGE_CODE_H_
#define _CHANGE_CODE_H_

#include<cstring>
#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
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
    //改变字符串内容
    virtual bool _change_content(string& temp);
    //判定当前字符是否为字母、数字、下划线
    bool _judge_number_letter_underline(char c);
    //进行单词与下划线之间的转换
    bool _change_word_to_underline(const string& word);

protected:
    //判定参数数量
    virtual bool _argument_number_judge(int argc) 
    { return argc == 3 || argc == 4; }
    //当参数有误时输出提示信息
    virtual void _argument_number_error_print();
    //输入文件打开读取出现问题的提示
    virtual void _input_file_error_print();
    //处理内容时出现问题
    virtual void _handle_content_error_print();
    //输出内容时出现问题
    virtual void _write_content_error_print();

private:
    //当此值为false时 说明初始化失败
    bool _state = true;
    //是否删除注释 -d参数 默认不删除
    bool _delete_notes = false;
    //当前是否属于/**/注释中
    bool _notes_now = false;
    //储存文件中的内容
    vector<string> _content;
    //储存define语句
    vector<string> _defines;
    //储存单词map
    unordered_map<string, string> _words;
    //储存当前下划线长度
    string _underline = "";
};

#endif
