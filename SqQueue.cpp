#include<cstdio>
#define MAXQSIZE 100;
using namespace std;

typedef struct
{
    
}QElemType;

typedef struct{
    QElemType *base;
    int front;
    int rear;

}SqQueue;


Status InitQueue(SqQueue &Q){
    Q.base = new QElemType[MAXQSIZE];
    if(!Q.base) exit(OVERFLOW);
    Q.front = Q.rear =0;
    return OK;
}

int QueueLength(SqQueue &Q){

    return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

Status EnQueue(SqQueue &Q, QElemType e){
    if ((Q.rear+1)%MAXQSIZE == Q.front) 
    {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear +1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e){
    if(Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front +1)%MAXQSIZE;
    return OK;
}

