#include"main.h"

extern List * students;

int saveStudentsData(){
    int num = 0;
    FILE * file = fopen(STUDENTS_DATA_FILE, "w");
    ListNode *p = students->first;
    while(p != NULL){
        char * dp = (char *) p->data;
        for(unsigned int i=0; i < (unsigned int)sizeof(struct student); i++){
            fputc(dp[i], file);
        }
        p = p->next;
        num++;
    }
    fclose(file);
    return num;
}

int loadStudentsData(){
    int num = 0;
    FILE * file = fopen(STUDENTS_DATA_FILE, "rb");
    if(file == NULL){
        printf("Open students data file ERROR\n");
        return -1;
    }
    while(1){
        {
            fgetc(file);
            if(feof(file)) break;
            fseek(file, -1, 1);
        }
        struct student * stud = malloc(sizeof(struct student));
        unsigned char * dp = (char *) stud;
        for(unsigned int i=0; i < (unsigned int)sizeof(struct student); i++){
            dp[i] = fgetc(file);
        }
        insertList(students, stud);
        num++;
    }
    fclose(file);
    return num;
}