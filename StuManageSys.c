#include"main.h"

extern List * students;

int addStudent(){
    struct student *stud = malloc(sizeof(struct student));

    printf("Add a student.\n");
    // 输入学生名字
    printf("Input Name: ");
    getInputString(stud->name, sizeof(stud->name));
    // 输入学生id
    char inputId[sizeof(stud->id)];
    while(1){
        printf("Input Id: ");
        getInputString(inputId, sizeof(stud->id));
        if(getStudentById(inputId) == NULL) break;;
        printf("\033[1;31mId %s has been used.\nPlease re-enter.\n\033[0m", inputId);
    }
    strcpy(stud->id, inputId);
    // 输入学生年龄
    printf("Input Age: ");
    int age;
    scanf("%d", &age);
    stud->age = age;
    getchar();

    printf("Student %s add Success\n", stud->name);

    // 为学生生成默认登录密码
    char passwdText[32];
    strcpy(passwdText, stud->id);
    strcat(passwdText, "ab");
    easyHash(passwdText, stud->passwd);

    // 设置学生成绩为空值
    for(int i=0; i<SUBJ_NUMS; i++){
        stud->grades[i] = -1;
    }

    insertList(students, stud);
    return 1;
}

void showStudent(struct student * stud){
    p_hr();
    // 输出学生的名字
    printf("Name:\t%s\n", stud->name);
    //输出学生的学号
    printf("ID:\t%s\n", stud->id);
     //输出学生的年龄
    printf("Age:\t%d\n", stud->age);
    //输出学生成绩
    showStudGrade(stud);
}

void showAllStudent(){
    if(students == NULL){
        printf("\033[1;31m No Student \033[0m\n");
        return ;
    }
    ListNode * p = students->first;
    printf("\033[1;36m Number of students: %d \n\033[0m", students->len);
    while(p){
        struct student * stud = p->data;
        showStudent(stud);
        p = p->next;
    }
}

struct student * getStudentById(char * id){
    ListNode * p = students->first;
    struct student * stud = NULL;
    while(p){
        if(strcmp(id, p->data->id) == 0){
            stud = p->data;
            break;
        }
        p = p->next;
    }
    return stud;
}

struct student * studentLogin(char * id, char * passwd){
    struct student *stud;
    stud = getStudentById(id);
    if(stud == NULL){
        printf("\033[1;31mFailed! Id %s is not in System\n\033[0m", id);
        return NULL;
    }
    char passHash[8];
    easyHash(passwd, passHash);
    if(strcmp(passHash, stud->passwd) == 0){
        printf("\033[1;42m Login Success! \n\033[0m");
        return stud;
    }
    printf("\033[1;31m Failed! Wrong Password! \n\033[0m");
    return NULL;
}

int inputStudentsGrade(int subj){
    ListNode * p = students->first;
    while(p){
        struct student * stud = p->data;
        if(stud->grades[subj] == -1){
            printf("Please Input \033[1;32m%s\033[0m's Grade: ", stud->name);
            int grade;
            scanf("%d", &grade);
            getchar();
            stud->grades[subj] = grade;
            int ave = averageGrade(stud);
            stud->grades[average] = ave;
        }
        p = p->next;
    }
}

int averageGrade(struct student * stud){
    int subj = 0;
    int sum = 0;
    for(int i=1; i<SUBJ_NUMS; i++){
        if(stud->grades[i] == -1){
            continue;
        }
        sum += stud->grades[i];
        subj++;
    }
    return sum/subj;
}

int showGradeColor(int grade){
    if(grade>=80){
        printf("\033[1;32m%d\033[0m", grade);
    }
    else if(grade>=60){
        printf("\033[1;33m%d\033[0m", grade);
    }
    else{
        printf("\033[1;31m%d\033[0m", grade);
    }
}

int showStudGrade(struct student * stud){
    printf("Grades: \n");
    for(int i=0; i < SUBJ_NUMS; i++){
        if(stud->grades[i] == -1){
            continue;
        }
        switch (i){
        case cLanguage:
            printf("\t cLanguage: ");
            break;
        case cppLanguage:
            printf("\t cppLanguage: ");
            break;
        case dataStruct:
            printf("\t dataStruct: ");
            break;
        case oprtSystem:
            printf("\t oprtSystem: ");
            break;
        case average:
            printf("\t average: ");
            break;
        default:
            break;
        }
        printf("\t");
        showGradeColor(stud->grades[i]);
        puts("");
    }
}

int sortStudentById(){
    ListNode * p = students->first;
    while(p){
        ListNode * q = p->next;
        while(q){
            if(strcmp(p->data->id, q->data->id) > 0){
                struct student * temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int sortStudentByGrade(int subj){
    ListNode * p = students->first;
    while(p){
        ListNode * q = p->next;
        while(q){
            if(q->data->grades[subj] - p->data->grades[subj] > 0){
                struct student * temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int deleteStudent(char * id){
    struct student * stud = getStudentById(id);
    if(stud == NULL){
        printf("Not Found!");
        return 0;
    }
    Delete_ListNode_X(students, stud);
    return 1;
}

int changePasswd(char * id){
    // 通过id获取学生
    struct student * stud = getStudentById(id);
    // 检查是否成功获取到学生
    if(stud == NULL){
        printf("\033[1;31m ID %s not found.\n \033[0m", id);
        return -1;
    }
    // 输入新的密码
    char newPasswd[32];
    printf("Input the new password: ");
    getInputString(newPasswd, sizeof(newPasswd));
    clearTerm();

    // 检查密码长度
    int passwdLen = strlen(newPasswd);
    if(passwdLen < 6){
        printf("\033[1;31m Too short \n\033[0m", id);
        return 0;
    }
    else if(passwdLen < 6){
        printf("\033[1;31m Too long \n\033[0m", id);
        return 0;
    }
    // 对新密码进行加密处理
    char passwdHash[8];
    easyHash(newPasswd, passwdHash);
    strcpy(stud->passwd, passwdHash);

    return 1;
}