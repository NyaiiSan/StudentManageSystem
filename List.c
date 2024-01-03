#include"main.h"

List *createList(){
    List * l = (List *)malloc(sizeof(List));
    l->len = 0;
    l->first = l->last = NULL;

    return l;
}

void insertList(List * l, ListDataType x){
    ListNode *n = (ListNode *)malloc(sizeof(ListNode));
    n->data = x;
    n->next = NULL;

    if(l->first == NULL){
        l->first = n;
        l->last = n;
    }
    else{
        //尾插法
        l->last->next = n;
        l->last = n;
    }
    l->len++;
}

void Printf_List(List *l){
    ListNode *p = l->first;
    while(p){
        // printf("%d ", p->data);
        p = p->next;
    }
    puts("");
}

void Clear_List(List *l){
    ListNode *p = l->first;
    ListNode *r;
    while(p){
        r = p->next;
        p->data = 0;
        p->next = NULL;
        free(p);
        p = r;
    }
    l->first = l->last = NULL;
    l->len = 0;
}

void Destroy_List(List *l){
    Clear_List(l);
    free(l);
}

ListNode *Find_ListNode_X(List *l, ListDataType x){
    ListNode *p = l->first;
    while(p){
        if(p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

void Delete_ListNode_X(List *l, ListDataType x){
    ListNode *p = l->first;
    ListNode *r = NULL;
    while (p)
    {
        if(p->data == x){
            break;
        }
        r = p;
        p = p->next;
    }
    if(p == NULL) return;

    if(r == NULL){
        l->first = p->next;
    }
    else if(p->next == NULL){
        r->next = NULL;
        l->last = r;
    }
    else{
        r->next = p->next;
    }

    free(p);
    l->len--;
}