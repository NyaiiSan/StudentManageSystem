#ifndef __STUMANAGESYS_H__
#define __STUMANAGESYS_H__

#include"main.h"

#define SUBJ_NUMS 8

// 定义结构体储存学生信息
struct student {
    char name[32];
    char id[32];
    char passwd[8]; // 登录系统的密码
    int age;
    int grades[SUBJ_NUMS];
};

// 定义结构体储存教师信息
struct teacher {
    char id[32];
    char name[32];
    char passwd[8];
};

// 枚举定义科目
enum SUBJ
{
    average = 0,
    cLanguage,
    cppLanguage,
    dataStruct,
    oprtSystem
};

// 向列表中添加一个学生的信息
int addStudent();

// 打印出学生的信息
void showStudent(struct student * stud);

// 展示所有学生的信息
void showAllStudent();

// 通过学号找到一个学生 
struct student * getStudentById(char * id);

// 学生登录
struct student * studentLogin(char * id, char * passwd);

// 录入学生成绩
int inputStudentsGrade(int subj);

// 计算学生的平均成绩
int averageGrade(struct student * stud);

// 展示学生成绩
int showStudGrade(struct student * stud);

// 将成绩显示为彩色
int showGradeColor(int grade);

// 将学生按照id排序
int sortStudentById();

// 将学生按照学科成绩排序
int sortStudentByGrade(int subj);

// 删除一个学生
int deleteStudent(char * id);

// 学生修改密码
int changePasswd(char * id);

#endif