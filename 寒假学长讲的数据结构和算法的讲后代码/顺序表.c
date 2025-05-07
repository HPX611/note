#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct        //˳��� 
{
	ElemType elem[MAXSIZE];
	int length;
}SeqList;

void Init_SeqList(SeqList *L)//˳����ʼ�� 
{
	L->length=0;
}

int Insert_SeqList(SeqList *L,int i,ElemType x)//˳���Ĳ��� 
{
	int j;
	if(L->length==MAXSIZE - 1)
	{
		printf("����������");
		return -1;      //��������-1 
	}
	
	if(i<1 || i>L->length+1)
	{
		printf("λ�ô�������");
		return -2;		//λ�ô��󷵻�-2 
	} 
	
	for(j=L->length;j>=i;j--) L->elem[j+1] = L->elem[j]; 
	L->elem[i-1] = x;
	L->length++;
	return 0;          //����ɹ�����0 
} 

int Delet_SeqList(SeqList *L,int i,ElemType *e) //˳����ɾ�� 
{
	int j;
	if(i<1 || i>L->length+1)
	{
		printf("�����ڵ�%d��Ԫ�أ�",i);
		return -2;		//λ�ô��󷵻�-2 
	} 
	
	*e = L->elem[i-1];   //��ɾ������Ϣ���� 
	
	for(j=i;j<=L->length-1;j++) L->elem[j] = L->elem[j+1];
	L->length--;
	return 0;          //ɾ���ɹ�����0 
} 

int Location_SeqList(SeqList *L,ElemType x) //˳���Ĳ��� 
{
	int i=1;
	while(i<=L->length && L->elem[i]!=x) i++;
	if(i>L->length) return -1;  //û���ҵ�x���ڵ�λ��
	return i; 
}

int Revise_SeqList(SeqList *L,ElemType x,ElemType y) //˳�����޸� 
{
	int i=1;
	while(i<=L->length && L->elem[i]!=x) i++;
	if(i>L->length) return -1;  //û���ҵ�x���ڵ�λ��
	L->elem[i] = y;
	return 0;                   //�޸ĳɹ�����ֵΪ0 
}

int main()
{
	SeqList *L;
	Init_SeqList(&L);//��ʼ�� 
	
	return 0;
}
 
