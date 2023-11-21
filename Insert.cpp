#include<cstdio>
#define MAXSIZE 20
using namespace std;

typedef struct{
    KeyType key;
    InfoType otherinfo;
}RedType;

typedef struct{
    RedType r[MAXSIZE +1];
    int length;
}SqList;

void InsertSort(SqList &L)
{
    int i,j;
    for(i =2; i<=L.length;i++){
        if(L.r[i].key <L.r[i-1].key){
            L.r[0] = L.r[i];
            L.r[i] = L.r[i-1];
            for(j=i-2; L.r[0].key<L.r[j].key;--j)
                L.r[j+1]=L.r[j];
            L.r[j+1] = L.r[0];
        }
    }
}

void BInsertSort(SqList &L){
    int i,j;
    for(i=2; i<=L.length;i++){
        L.r[0]= L.r[i];
        int low = 1;
        int high = i-1;
        while(low <= high){
            int m = (low+ high);
            if(L.r[0].key < L.r[m]. key) high = m-1;
            else low =m+1;
        }
        for(j = i-1; j>=high+1; j--)
            L.r[j+1] = L.r[j];
        L.r[high+1] = L.r[0];
    }
}


void ShellInsert(SqList &L, int dk){
    for(int i= dk+1; i<=L.length;++i)
    if(L.r[i].key<L.r.[i-dk].key){
        L.r[0] = L.r[i];
        for(int j=i-dk; j>0&&(L.r[0].key<r[j].key); j=j-dk)
            L.r[j+dk] = L.r[j];
        L.r[j+dk] = L.r[0];
    }
}

void ShellSort(SqList &L, int dlta[], int t){
    for(k = 0; k<t; ++k)
        ShellInsert(L, dlta[k]);
}

