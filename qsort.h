#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED



#endif // QSORT_H_INCLUDED
#pragma once
/*
排序，可以自己定义cmp函数
比较的数据应该有相同的内存大小，否则在复制时出现问题
*/
template<class T>class Qsort{
private :
    void copy(T &a,T &b){
        if(&a==&b)return ;
        char *pa=(char *)&a;
        char *pb=(char *)&b;
        for(int i=0;i<sizeof(T);i++)*(pa+i)=*(pb+i);
    }

    void Swap(T & a,T & b){
        T buf;
        copy(buf,a);
        copy(a,b);
        copy(b,buf);
    }
public :
    void qsort(T d[],int l,int r,int (*cmp)(const T& a,const T& b)){
        if(l>=r)return ;

        Swap(d[l],d[(l+r)>>1]);
        int last=l;

        for(int i=l+1;i<=r;i++)
            if(cmp(d[l],d[i])>0)
                Swap(d[++last],d[i]);
        Swap(d[l],d[last]);

        qsort(d,l,last-1,cmp);
        qsort(d,last+1,r,cmp);
    }
};
