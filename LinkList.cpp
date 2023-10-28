#include<cstdio>
using namespace std;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status InitList_L(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return OK;
}

Status DestoryList_L(LinkList &L){
    LinkList p;
    while (L)
    {
        p=L;
        L=L->next;
        delete p;
    }
    return OK;
}

Status ClearList(LinkList &L){
    LinkList p,q;
    p = L->next;
    while(p){
        q=p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;

}

int LintLength_L(LinkList L){
    LinkList p;
    p = L->next;
    int i=0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

int ListEmpty(LinkList L){
    if(L->next) return 0;
    else return 1;
}

Status GetElem_L(LinkList L,int i, ElemType &e){
    LinkList p = L->next;
    int j=1;
    while (p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i) return ERROR;
    e = p->data;
    return OK;

}


LNode *LocateElem_L(LinkList L, Elemtype e){
    LinkList p  = L->next;
    while(p&&p->data!=e){
        p = p->next;
    }
    return p;

}

Status ListInsert_L(LinkList &L,int i,ElemType e){
    LinkList p=L;
    int j=0;
    while (p&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if (!p||j>i-1)
    {
        return ERROR;
    }
    LinkList s = new LNode;
    s->data =e;
    s->next = p->next;
    p->next = s;
    return OK;
    
}

Status ListDelete_L(LinkList &L, int i, ElemType &e){
    LinkList p=L;
    int j=0;
    while (p->next && j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1) return ERROR;
    LinkList q=p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

void CreateList_F(LinkList &L, int n){
    L=new LNode;
    L->next = NULL;
    for(int i=n; i>0; --i){
        LinkList p = new LNode;
        p->next = L->next; 
        L->next = p;
    }
}

void CreateList_L(LinkList &L,int n){
    LinkList L = new LNode;
    L->next = NULL;
    LinkList r = L;
    for (int i = 0; i < n; i++)
    {
        LinkList p = new LNode;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    
}
int main(){

    return 0;
}