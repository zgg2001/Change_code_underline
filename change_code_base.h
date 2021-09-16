/*************************************************************************
	> File Name: change_code_base.h
	> Author: ZHJ
	> Remarks: 基类 定义了基础方法和处理接口
	> Created Time: Thu 16 Sep 2021 11:25:45 AM CST
 ************************************************************************/

#ifndef _CHANGE_CODE_UNDERLINE_H_
#define _CHANGE_CODE_UNDERLINE_H_

#include<string>

class _change_code_base
{
public:
    void set_input_file(char* filename)
    {
        _input_file = filename;
    }
    std::string get_input_file()
    {
        return _input_file;
    }

    void set_output_file(char* filename)
    {
        _output_file = filename;
    }
    std::string get_output_file()
    {
        return _output_file;
    }

protected:
    //读取文件至缓冲区
    virtual bool _read_content_to_map() = 0;
    //处理缓冲区内的内容
    virtual bool _handle_content_from_map() = 0;
    //将处理后的内容输出至文件
    virtual bool _write_content_to_file() = 0;

private:
    std::string _input_file;
    std::string _output_file;

};

#endif
