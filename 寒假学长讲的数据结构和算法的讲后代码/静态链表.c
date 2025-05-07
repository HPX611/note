#include<stdio.h>

#define MAXSIZE 1000    //�����������󳤶���1000
typedef int ElemType;

typedef struct{
    ElemType data;
    int cur;                //�α꣨Cursor����Ϊ0ʱ��ʾ��ָ��
} Component,StaticLinkList[MAXSIZE];

int InitList(Component *space)   //��ʼ�� 
{
    int i;
    for(i=0; i<MAXSIZE; i++)
	{
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0; //Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0
    return 1;
}

int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;                //��ǰ�����һ��Ԫ�ص�cur���ֵ������Ҫ���صĵ�һ�����ÿռ���±�
    if(space[0].cur)
	{
        space[0].cur = space[i].cur;    //����һ����������������
    }
    return i;
}

void Free_SSL(Component *space, int k)
{
    space[k].cur = space[0].cur;        //�ѵ�һ��Ԫ��curֵ��ֵ��Ҫɾ���ķ���cur
    space[0].cur = k;                   //��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
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
    k = MAXSIZE - 1;    //ע��k���������һ��Ԫ�ص��±�
    if(i<1 || i>ListLength(L) + 1){
        return ERROR;
    }
    j = Malloc_SLL(L);
    if(j){
        L[j].data = e;  //�����ݸ�ֵ���˷�����data
        for(l=1; l<= i-1; l++){ 
            k = L[k].cur;   //�ҵ���i��Ԫ��֮ǰ��λ��
        }
        L[j].cur = L[k].cur;    //�ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
        L[k].cur = j;   //����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur
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
        k = L[k].cur;   //�ҵ���i��Ԫ��֮ǰ��λ��
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
