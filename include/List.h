#ifndef __List_H__
#define __List_H__

#include"main.h"

typedef struct student * ListDataType;

typedef struct listnode 
{
    ListDataType data; //保存“数据” 数据域
    struct listnode * next;//存储下一个元素的地址/指针  指针域
}ListNode; 

typedef struct list
{
    ListNode *first; // 第一个节点地址
    ListNode *last; // 最后一个节点地址
    int len; //链表中的节点个数
}List;

//创建链表
List * createList();

//向链表中插入节点
void insertList(List * l, ListDataType x);

//打印链表
void Printf_List(List *l);

//清空整个链表 把所有的数据节点释放 但是保留头结点
void Clear_List(List *l); 

//销毁整个链表 把所有的数据节点和头结点都释放掉
void Destroy_List(List *l);

//查找一个链表中是否存在数据域为x的节点
ListNode *Find_ListNode_X(List *l, ListDataType x);

//删除一个链表中数据域为x的节点 如果有多个删除第一个 如果没有不操作
void Delete_ListNode_X(List *l, ListDataType x);
				

#endif