#ifndef __UTILE_H__
#define __UTILE_H__

#include "main.h"

/*
    从键盘输入一个字符串, 保存在str中
*/
char * getInputString(char * str, int size);


/*
    捕获一个用户输入的字符
*/
char getInputChar();

/*
    对一个字符转进行简单的(16位)加密
    参数: 
        str:    需要加密的字符串
        hash:   保存加密后的字符串
*/
char * easyHash(char * str, char * hash);




#endif