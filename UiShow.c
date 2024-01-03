#include"main.h"

extern List * students;
extern struct teacher * teacher;


int p_hr(){
    for(int i=0; i<40; i++){
        printf("=");
    }
    puts("");
    return 0;
}

// 清屏
int clearTerm(){
    printf("\033[2J\033[H");
    return 0;
}

int printTitle(char * title){
    p_hr();
    printf("\033[1;46m %s \033[0m\n", title);
    return 1;
}

int indexMenu(){
indexMenuStart:
    // 给用户打印提示
    printTitle("Manage System");
    printf(" Input the num. \n");
    printf("\t1. Enter Student Side\n");
    printf("\t2. Enter Teacher Side\n");
    printf("\t0. Exit\n");

    printf("Please select a function: ");

    char ipt = getInputChar();

    clearTerm();

    switch (ipt)
    {
    case '1':
        studentLoginPage();
        break;
    case '2':
        teacherLoginPage();
        break;
    case '0':
        return 0;
        break;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        break;
    }

    goto indexMenuStart;

    return 0;
}

int studentLoginPage(){
studentLoginStart:
    printTitle("Student Login");
    // 输入id
    char id[32];
    printf("Input Your ID: ");
    getInputString(id, 32);
    puts("");
    // 输入密码
    char passwd[32];
    printf("Input Your Password: ");
    getInputString(passwd, 32);
    puts("");

    clearTerm();

    struct student * stud = studentLogin(id, passwd);// 尝试登录

    if(stud != NULL){
        studentSideMenu(stud); // 登录成功进入学生端
        return 1;
    }

selectFunction:
    // 登录失败
    p_hr();
    printf("\033[1;41m Login Failed! \033[0m\n");
    printf(" Input the num. \n");
    printf("\t1. Retry.\n");
    printf("\t2. Forgot id or password.\n");
    printf("\t0. Exit\n");

    printf("Please select a function: ");

    char ipt = getInputChar();

    clearTerm();

    switch (ipt)
    {
    case '1': // 重试
        break;
    case '2': // 忘记密码
        printf("\033[1;31mPlease contact the teacher.\033[0m\n");
        break;
    case '0':
        return 0;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        goto selectFunction;
        break;
    }
    goto studentLoginStart;
}

int studentSideMenu(struct student * stud){
    studentSideStart:
    // 给用户打印提示
    printTitle("Student");
    printf(" Hello \033[1;36m%s\n\033[0m", stud->name);
    printf("Your ");
    showStudGrade(stud);
    printf(" Input the num. \n");
    printf("\t0. Exit\n");
    printf("\t1. Change the password.\n");

    printf("Please select a function: ");

    char ipt = getInputChar();

    clearTerm();
    switch (ipt)
    {
    case '0':
        return 0;
        break;
    case '1':
        changePasswdPage(stud->id);
        break;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        break;
    }

    goto studentSideStart;

    return 0;
}

int teacherLoginPage(){
teacherLoginStart:
    printTitle("Teacher Login");
    // 输入id
    char id[32];
    printf("Input Your ID: ");
    getInputString(id, 32);
    puts("");
    // 输入密码
    char passwd[32];
    printf("Input Your Password: ");
    getInputString(passwd, 32);
    puts("");

    clearTerm();

    char passwdHash[8];
    easyHash(passwd, passwdHash);

    if(strcmp(id, teacher->id) == 0 && strcpy(passwdHash, teacher->passwd)){
        teacherSideMenu(); // 登录成功进入学生端
        return 1;
    }

selectFunction:
    // 登录失败
    p_hr();
    printf("\033[1;41m Login Failed! ID or Password Wrong \033[0m\n");
    printf(" Input the num. \n");
    printf("\t1. Retry.\n");
    printf("\t0. Exit\n");

    printf("Please select a function: ");

    char ipt = getInputChar();

    clearTerm();

    switch (ipt)
    {
    case '1': // 重试
        break;
    case '0':
        return 0;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        goto selectFunction;
        break;
    }
    goto teacherLoginStart;
}

int teacherSideMenu(){
    teacherSideStart:
    // 给用户打印提示
    printTitle("Teacher");
    printf(" Input the num. \n");
    printf("\t1. Show all student info. \n");
    printf("\t2. Add a student info. \n");
    printf("\t3. Input students grade. \n");
    printf("\t4. Sort student. \n");
    printf("\t5. Delete studen.t \n");
    printf("\t6. Change student's passwd. \n");
    printf("\t0. Exit\n");

    printf("Please select a function: ");

    char ipt = getInputChar();

    clearTerm();
    switch (ipt)
    {
    case '0':
        return 0;
        break;
    case '1':
        showAllStudent();
        break;
    case '2':
        addStudent();
        break;
    case '3':
        gradesInputPage();
        break;
    case '4':
        sortStudentPage();
        break;
    case '5':
        deleteStudentPage();
        break;
    case '6':{
        char id[32];
        strcpy(id, "null");
        changePasswdPage(id);
        break;
    }
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        break;
    }

    goto teacherSideStart;

    return 0;
}

int gradesInputPage(){
    printTitle("Grades Input");
    printf(" Choose a subject \n");
    printf("\t1. C Language \n");
    printf("\t2. Cpp Language \n");
    printf("\t3. Data Struct \n");
    printf("\t4. Opration System \n");
    printf("\t0. Exit\n");

    printf("Please select a subject: ");

    char ipt = getInputChar();

    clearTerm();
    switch (ipt)
    {
    case '0':
        return 0;
        break;
    case '1':
        inputStudentsGrade(cLanguage);
        break;
    case '2':
        inputStudentsGrade(cppLanguage);
        break;
    case '3':
        inputStudentsGrade(dataStruct);
        break;
    case '4':
        inputStudentsGrade(oprtSystem);
        break;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Subject Number\033[0m\n");
        break;
    }

    return 1;
}

int sortStudentPage(){
    sortStudentStart:
    // 给用户打印提示
    printTitle("Sort Student");
    printf(" Input the num. \n");
    printf("\t1. Sort Student By Id. \n");
    printf("\tSort Student By Grade. \n");
    printf("\t\t2. cLanguage: \n");
    printf("\t\t3. cppLanguage: \n");
    printf("\t\t4. dataStruct: \n");
    printf("\t\t5. oprtSystem: \n");
    printf("\t\t6. average: \n");
    printf("\t0. Exit\n");

    printf("Please select a function: ");

    char ipt = getInputChar();

    clearTerm();
    switch (ipt)
    {
    case '0':
        return 0;
        break;
    case '1':
        sortStudentById();
        return 1;
        break;
    case '2':
        sortStudentByGrade(cLanguage);
        return 1;
        break;
    case '3':
        sortStudentByGrade(cppLanguage);
        return 1;
        break;
    case '4':
        sortStudentByGrade(dataStruct);
        return 1;
        break;
    case '5':
        sortStudentByGrade(oprtSystem);
        return 1;
        break;
    case '6':
        sortStudentByGrade(average);
        return 1;
        break;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        break;
    }

    goto sortStudentStart;

    return 0;
}

int deleteStudentPage(){
    printTitle("Delete Student");
    char del_id[32];
    printf("Input Student's ID: ");
    getInputString(del_id, 32);

    clearTerm();

    if(deleteStudent(del_id) == 0){
        printf("\033[1;31m ID %s not found.\n\033[0m", del_id);
    }
    else{
        printf("\033[1;32m Deleted. \n\033[0m");
    }
    return 0;
}

int changePasswdPage(char * id){

changePasswd:
    printTitle("Change Password");
    if(strcmp(id, "null") == 0){
        printf("Input studnet's ID: ");
        getInputString(id, 32);
    }

    int chr = changePasswd(id);

    if(chr == 1){
        printf("\033[1;32m Change Password Success \n\033[0m", id);
        return 1;
    }
    else if(chr == -1){
        strcpy(id, "null");
    }
    p_hr();
    printf("\033[1;31m Change Password Failed \n\033[0m", id);
    printf(" Input the num. \n");
    printf("\t1. Retry.\n");
    printf("\t0. Exit\n");

    printf("Please select a function: ");
    char ipt = getInputChar();

    clearTerm();

    switch (ipt)
    {
    case '1': // 重试
        break;
    case '0':
        return 0;
    default:
        p_hr();
        printf("\033[1;31mUnknow command: %c\033[0m\n", ipt=='\n' ? ' ' : ipt);
        printf("\033[1;31mPlease Input Function Number\033[0m\n");
        break;
    }
    goto changePasswd;
}