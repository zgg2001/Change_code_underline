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
    if(_argument_number_judge(argc) == false)
    {
        _state = false;
        _argument_number_error_print();
    }
    else
    {
        //确定输入输出文件
        set_input_file(argv[1]);
        set_output_file(argv[2]);
    }
}

change_code::~change_code()
{
    
}

bool change_code::change()
{
    //初始化失败
    if(_state == false)
    {
        cout << "初始化失败，无法转换" << endl;
        return false;
    }
    //读取文件至缓冲区
    if(_read_content_to_map() == false)
    {
        _input_file_error_print();
        return false;
    }
    //处理缓冲区内的内容
    if(_handle_content_from_map() == false)
    {
        return false;
    }
    //将处理后的内容输出至文件
    if(_write_content_to_file() == false)
    {
        return false;
    }
    return true;
}

bool change_code::_read_content_to_map()
{
    ifstream infile;
    infile.open(get_input_file(), ios::binary);
    
    if(infile.is_open())
    {
        //获取文件内容
        string temp;
        while(getline(infile, temp))
        {
            cout << temp << endl;
        }
        infile.close();
    }
    else
    {
        return false;
    }
    
    return true;
}

bool change_code::_handle_content_from_map()
{
    return true;
}

bool change_code::_write_content_to_file()
{
    return true;
}

void change_code::_argument_number_error_print()
{
    cout << endl;
    cout << "欢迎使用本代码混淆器" << endl;
    cout << "by ZHJ" << endl << endl;
    cout << "请确认参数格式是否正确:" << endl;
    cout << "./line [原文件] [混淆后文件]" << endl;
    cout << endl;
}

void change_code::_input_file_error_print()
{
    cout << endl;
    cout << "原文件读取失败" << endl;
    cout << "请确认原文件路径是否正确" << endl << endl;
    cout << "参数格式如下:" << endl;
    cout << "./line [原文件] [混淆后文件]" << endl;
    cout << endl;    
}

