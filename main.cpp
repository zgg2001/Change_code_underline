/*************************************************************************
	> File Name: main.cpp
	> Author: ZHJ
	> Remarks: 简单混淆器
	> Created Time: Wed 15 Sep 2021 09:13:38 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include"change_code.h"

using namespace std;

int main(int argc, char* argv[])
{
    change_code *object = new change_code(argc, argv);
    return 0;
}

