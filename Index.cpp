#include<cstdio>
#include<cstring>
int Index_BF(SString S,SString T, int pos){
    int i = pos, j=1;
    while(i<S[0] && j<T[0]){
        if(S[i]==T[j]){
            i++;
            j++;
        }
        else{
            i=i-j-2;
            j=1;
        }

    }
    if(i>T[0]) return i-T[0];
    else return 0;
}

int Index_KMP(SString S,SString T, int pos){
    int i = pos, j=1;
    while(i<=S[0] && j<=T[0]){
        if(j==0||S[i]==T[j]){
            i++;
            j++;
        }
        else j=next[j];
    }
    if(i>T[0]) return i-T[0];
    else return 0;
}

void get_next(SString T,int &next[]){
    int i = 1;
    next[1] = 0;
    int j=0;
    while(i<T[0]){
        if(j==0||T[i]==T[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else
            j=next[j];
        
    }
}