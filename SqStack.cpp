#include<cstdio>
#define MAXSIZE 100
typedef struct 
{
    
}SElemType;



typedef struct
{
    SElemType *base;
    SElemType *top;
    int stackSize;
}SqStack;

//初始化
Status InitStack(SqStack &S){
    S.base = new SElemType[MAXSIZE];
    if(!S.base) return OVERFLOW;
    S.top = S.base;
    S.stackSize = MAXSIZE;
    return OK;
}

//栈长
bool StackEmpty(SqStack S){
    if(S.top == S.base) return true;
    else return false;
}

int StackLength(SqStack S){
    return S.top-S.base;
}

Status ClearStack(SqStack &S){
    if(S.base) S.top = S.base;
    return OK;
}

Status DestoryStack(SqStack &S){
    if(S.base){
        delete S.base;
        S.stackSize = 0;
        S.base = S.top = NULL;
    }
    return OK;
}


Status Push(SqStack &S, SElemType e){
    if(StackLength(S)==S.stackSize) return ERROR;
    *S.top = e;
    S.top++;
    return OK;
}

Status Pop(SqStack &S,SElemType &e){
    if(StackEmpty(S)) return ERROR;
    e = *(S.top-1);
    S.top--;
    return e;
}

Status  GetTop(SqStack S, SElemType &e){
    if(S.top == S.base) return ERROR;
    e= *(S.top -1);
    return OK;
}

