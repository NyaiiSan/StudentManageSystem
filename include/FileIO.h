#ifndef __FILESIO_H__
#define __FILESIO_H__

#define STUDENTS_DATA_FILE "studentsData.hex" 

#include"main.h"

// 将所有的学生数据保存到文件中
int saveStudentsData();

int loadStudentsData();

#endif