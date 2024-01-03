#ifndef __UISHOW_H__
#define __UISHOW_H__

#include"main.h"

// 打印一条分隔线
int p_hr();

//清空终端
int clearTerm();

// 打印标题
int printTitle(char * title);

// 主页面|主菜单
int indexMenu();

// 学生端主菜单
int studentSideMenu(struct student * stud);

// 教师端主菜单
int teacherSideMenu();

// 学生登录页面
int studentLoginPage();

// 教师登录页面
int teacherLoginPage();

// 成绩录入页面
int gradesInputPage();

// 学生排序方式选择页面
int sortStudentPage();

// 删除学生页面
int deleteStudentPage();

// 修改密码页面
int changePasswdPage(char * id);

#endif