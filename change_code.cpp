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
        _handle_content_error_print();
        return false;
    }
    //将处理后的内容输出至文件
    if(_write_content_to_file() == false)
    {
        _write_content_error_print();
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
            if(!temp.empty())
                _content.push_back(temp);
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
    for(string& s : _content)
    {   
        _change_content(s);    
    }
    return true;
}

bool change_code::_write_content_to_file()
{
    ofstream outfile;
    outfile.open(get_output_file(), ios::binary);
    
    if(outfile.is_open())
    {
        //输出内容
        for(string s : _defines)
        {
            outfile << s << endl;
        }
        for(string s : _content)
        {
            outfile << s << endl;
        }
        outfile.close();
    }
    else
    {
        return false;
    }
    return true;
}

bool change_code::_change_content(string& temp)
{
    bool state_mark2 = false, state_mark1 = false;//引号标记
    string t = temp;
    string word = "          ";
    temp.clear();
    word.clear();

    for(char c : t)
    {
        //判定是否为数字/字母/下划线
        if(_judge_number_letter_underline(c) == true)
        {
            if(state_mark2 == false && state_mark1 == false)
                word += c;
            else
                temp += c;
        }
        else
        {
            //预编译语句 不要修改
            if(c == '#' && temp.empty())
            {
                temp = t;
                break;
            }
            //双引号内字符串不能修改
            if(c == 34)
            {
                if(state_mark2 == false)
                    state_mark2 = true;
                else
                    state_mark2 = false;
            }
            //单引号
            else if(c == 39)
            {
                if(state_mark1 == false)
                    state_mark1 = true;
                else
                    state_mark1 = false;
            }
            //
            if(!word.empty())
            {
                _change_word_to_underline(word);
                temp += _words[word];
                word.clear();
            }
            //去多空格
            if(c == ' ' && (temp.empty() || temp[temp.size()-1] == ' '))
            {
                continue;
            }
            temp += c;
        }
    }
    if(!word.empty())
    {
        _change_word_to_underline(word);
        temp += _words[word];
    }

    if(temp.empty())
        return false;
    return true;
}

bool change_code::_judge_number_letter_underline(char c)
{
    if(c == '_' || c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'z')
    {
        return true;
    }
    return false;
}

bool change_code::_change_word_to_underline(const string& word)
{
    //如果之前已经碰到过该单词 就不需处理
    if(_words.count(word) == 1)
    {
        return true;
    }

    _underline += '_';
    _words[word] = _underline;

    string define = "#define ";
    define += _underline;
    define += ' ';
    define += word;
    _defines.push_back(define);

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

void change_code::_handle_content_error_print()
{ 
    cout << endl;
    cout << "文件内容处理失败" << endl;
    cout << "请向原作者反应 github: @zgg_2001" << endl << endl;
    cout << "参数格式如下:" << endl;
    cout << "./line [原文件] [混淆后文件]" << endl;
    cout << endl;    
}

void change_code::_write_content_error_print()
{
    cout << endl;
    cout << "混淆后内容输出失败" << endl;
    cout << "请确认混淆后文件路径是否正确" << endl << endl;
    cout << "参数格式如下:" << endl;
    cout << "./line [原文件] [混淆后文件]" << endl;
    cout << endl;    
}
