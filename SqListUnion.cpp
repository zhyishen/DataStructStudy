void union(SqList &La, SqList Lb){
    int La_len = ListLength(La);
    int Lb_len = ListLength(Lb);
    for(int i=1; i<=Lb_len; i++){
        ElemType e;
        GetElem(Lb, i, e);
        if(!LocateElem(La.e))
            ListInsert(&La,++La_len,e);
    }

} 