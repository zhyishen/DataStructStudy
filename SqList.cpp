#include<cstdio>
using namespace std;
Status InitList_Sq(SqList &L){
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

void DestoryList(SqList &L){
    if(L.elem) delete[]L.elem;
}

void ClearList(SqList &L){
    L.length = 0;
}

int GetLength(SqList L){
    return (L.length);
}

int IsEmpty(SqList L){
    if(L.length==0) return 1;
    else return 0;
}

int GetElem(SqList L, int i, ElemType &e){
    if(i<1||i>L.ength) return ERROR;

    e=L.elem[i-1];
    return OK;

}

int main(){
    printf("hello, world");
    return 0;
}