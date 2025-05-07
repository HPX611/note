#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct        //顺序表 
{
	ElemType elem[MAXSIZE];
	int length;
}SeqList;

void Init_SeqList(SeqList *L)//顺序表初始化 
{
	L->length=0;
}

int Insert_SeqList(SeqList *L,int i,ElemType x)//顺序表的插入 
{
	int j;
	if(L->length==MAXSIZE - 1)
	{
		printf("表满啦！！");
		return -1;      //表满返回-1 
	}
	
	if(i<1 || i>L->length+1)
	{
		printf("位置错误啦！");
		return -2;		//位置错误返回-2 
	} 
	
	for(j=L->length;j>=i;j--) L->elem[j+1] = L->elem[j]; 
	L->elem[i-1] = x;
	L->length++;
	return 0;          //插入成功返回0 
} 

int Delet_SeqList(SeqList *L,int i,ElemType *e) //顺序表的删除 
{
	int j;
	if(i<1 || i>L->length+1)
	{
		printf("不存在第%d个元素！",i);
		return -2;		//位置错误返回-2 
	} 
	
	*e = L->elem[i-1];   //将删除的信息返回 
	
	for(j=i;j<=L->length-1;j++) L->elem[j] = L->elem[j+1];
	L->length--;
	return 0;          //删除成功返回0 
} 

int Location_SeqList(SeqList *L,ElemType x) //顺序表的查找 
{
	int i=1;
	while(i<=L->length && L->elem[i]!=x) i++;
	if(i>L->length) return -1;  //没有找到x所在的位置
	return i; 
}

int Revise_SeqList(SeqList *L,ElemType x,ElemType y) //顺序表的修改 
{
	int i=1;
	while(i<=L->length && L->elem[i]!=x) i++;
	if(i>L->length) return -1;  //没有找到x所在的位置
	L->elem[i] = y;
	return 0;                   //修改成功返回值为0 
}

int main()
{
	SeqList *L;
	Init_SeqList(&L);//初始化 
	
	return 0;
}
 
