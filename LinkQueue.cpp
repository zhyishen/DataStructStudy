#include<cstdio>
#include<stdlib.h>
#define MAXQSIZE 100;
using namespace std;

typedef struct
{
    
}QElemType;

typedef struct QNode{
    QElemType data;
    struct Qnode *next;
}Qnode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (QueuePtr) malloc(sizeof(QNode));
    if(!Q.front) exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status DestoryQueue(LinkQueue &Q){
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
    
}


Status QueueEmpty(LinkQueue Q){
    return (Q.front == Q.rear);
}

Status GetHead(LinkQueue Q, QElemType &e){
    if(Q.front == Q.rear) return ERROR;
    e = Q.front->next->data;
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e){
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next=NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e){
    if(Q.front == Q.rear) return ERROR;
    QueuePtr p = Q.front->next;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear==p) Q.rear = Q.front;
    delete p;
    return OK;

}