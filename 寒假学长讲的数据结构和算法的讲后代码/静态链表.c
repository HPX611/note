#include<stdio.h>

#define MAXSIZE 1000    //假设链表的最大长度是1000
typedef int ElemType;

typedef struct{
    ElemType data;
    int cur;                //游标（Cursor），为0时表示无指向
} Component,StaticLinkList[MAXSIZE];

int InitList(Component *space)   //初始化 
{
    int i;
    for(i=0; i<MAXSIZE; i++)
	{
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0; //目前静态链表为空，最后一个元素的cur为0
    return 1;
}

int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;                //当前数组第一个元素的cur存的值，就是要返回的第一个备用空间的下标
    if(space[0].cur)
	{
        space[0].cur = space[i].cur;    //把下一个分量用来做备用
    }
    return i;
}

void Free_SSL(Component *space, int k)
{
    space[k].cur = space[0].cur;        //把第一个元素cur值赋值给要删除的分量cur
    space[0].cur = k;                   //把要删除的分量下标赋值给第一个元素的cur
}


int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}


int ListInsert(Component *L, int i, ElemType e){
    int j,k,l;
    k = MAXSIZE - 1;    //注意k首先是最后一个元素的下标
    if(i<1 || i>ListLength(L) + 1){
        return ERROR;
    }
    j = Malloc_SLL(L);
    if(j){
        L[j].data = e;  //将数据赋值给此分量的data
        for(l=1; l<= i-1; l++){ 
            k = L[k].cur;   //找到第i个元素之前的位置
        }
        L[j].cur = L[k].cur;    //把第i个元素之前的cur赋值给新元素的cur
        L[k].cur = j;   //把新元素的下标赋值给第i个元素之前元素的cur
        return OK;
    }
    return ERROR;
}



int ListDelete(Component *L, int i){
    int j,k;
    if(i<1 || i>ListLength(L)+1){
        return ERROR; 
    }
    k = MAXSIZE - 1;
    for(j=1; j<=i-1; j++){
        k = L[k].cur;   //找到第i个元素之前的位置
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    OUTPUT(L);
    Free_SSL(&L, j);
    return OK;
}

int main()
{
	return 0;
 } 
