#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node
{
	DataType  data;         //������ 
	struct node *next;//ָ���� 
}LNode,*LinkList;

LinkList Creat_LinkList1() //ͷ�巨
{
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x!=-1) // ��ֹ����Ϊ-1
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->next = H->next;
		s->data = x;
		H->next = s;
		scanf("%d",&x);
	} 
	return H;
}  

LinkList Creat_LinkList2() //β�巨
{
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s,*r = H;
	int x;
	scanf("%d",&x);
	while(x!=-1) // ��ֹ����Ϊ-1
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	} 
	r->next = NULL;
	return H;
}  

int Length_LinkList(LinkList H)  //��� 
{
	LNode *p = H;
	int cnt = 0;
	while(p->next!=NULL) 
	{
		p=p->next;
		cnt++;
	}	
	return cnt;
} 

LinkList Get_LinkList(LinkList H,int k)//�������а���Ų���
{
	LNode *p = H;
	int j=0;
	while(p->next!=NULL && j<k)
	{
		p = p->next;
		j++;
	}
	if(j==k) return p;
	else return NULL; 
} 

LNode* Locate(LinkList H,DataType  k)//�������а�ֵ����
{
	LNode *p = H->next;
	while(p!=NULL && p->data!=k) p = p->next;
	return p;
} 

int Insert_LinkList(LinkList H,int i,DataType  x)//���� 
{
	LNode *p,*s;
	p = Get_LinkList(H,i-1);
	if(p==NULL) 
	{
		printf("�����λ�ô�������");
		return -1; 
	}
	else
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 0;
	}
}

int Del_LinkList(LinkList H,int i,DataType  x)//ɾ�� 
{
	LinkList p,q;
	p = Get_LinkList(H,i-1);
	if(p==NULL) 
	{
		printf("��%d-1���ڵ㲻���ڣ�",i);
		return -1; 
	}
	else
	{
		if(p->next==NULL)
		{
			printf("��%d���ڵ㲻���ڣ�",i);
			return -1; 
		}
	}

	//���Ĵ��� 
	q = p->next;
	p->next = q->next;
	free(q);
	return 0;

}

void Reverse(LinkList H) //��������� 
{
	LNode *p,*q;
	p = H->next;
	H->next=NULL;
	while(p)
	{
		q = p;
		p = p->next;
		q->next = H->next;	
		H->next = q;
	} 
}

int main()
{
	LinkList H;
	H = Creat_LinkList1();
	H = Creat_LinkList2();
	return 0;
} 

