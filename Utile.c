#include "main.h"

char * getInputString(char * str, int size){
    int p = 0;
    while(p < size){
        char c = (char)getchar();
        if(c == '\n') break;
        str[p++] = c;
    }
    str[p] = '\0';

    return str;
}

char getInputChar(){
    char input;
    input = (char)getchar();
    //捕获多余字符
    while(input != '\n' && getchar()!='\n');
    
    return input;
}

char * easyHash(char * str, char * hash){
    char abcd[4] = {'a', 'b', 'c', 'd'};
    int i, p = 0;
    while(str[p] != '\0'){
        i = 0;
        for(; i<4;i++){
            char t;
            if(str[p] != '\0'){
                t = (char)(str[p] << 1);
                p++;
            }
            else{
                t = (char)(abcd[i] << 1);
            }
            abcd[i] = abcd[i] ^ t;
        }
    }
    for(i=0; i<4;i++){
        hash[i] = abcd[i];
    }
    hash[4] = '\0';
    return hash;
}