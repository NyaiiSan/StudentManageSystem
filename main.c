#include"main.h"

List * students;
struct teacher * teacher;

void init(){
    students = createList();
    if(loadStudentsData() == -1){
        // 打开学生数据文件失败，可能是文件不存在
    }

    // 初始化教师信息
    teacher = malloc(sizeof(struct teacher));
    strcpy(teacher->name, "Tony");
    strcpy(teacher->id, "230000");                  
    easyHash("123", teacher->passwd);

    clearTerm();
}

int main(){
    init();
    // 进入主界面
    indexMenu();

    // 保存数据
    saveStudentsData();

    return 0;
}