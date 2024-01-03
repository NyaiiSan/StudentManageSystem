#include"main.h"

extern List * students;

int saveStudentsData(){
    int num = 0;
    FILE * file = fopen(STUDENTS_DATA_FILE, "wb");
    ListNode *p = students->first;
    while(p != NULL){
        fwrite(p->data, sizeof(struct student), 1, file);
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
        struct student * stud = malloc(sizeof(struct student));
        if(fread(stud, sizeof(struct student), 1, file) == 1){
            insertList(students, stud);
            num++;
        }
        else{
            free(stud);
            break;
        }
    }
    fclose(file);
    return num;
}