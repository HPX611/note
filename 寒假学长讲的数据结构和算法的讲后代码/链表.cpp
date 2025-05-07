#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node
{
	DataType  data;         //数据域 
	struct node *next;//指针域 
}LNode,*LinkList;

LinkList Creat_LinkList1() //头插法
{
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x!=-1) // 终止条件为-1
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->next = H->next;
		s->data = x;
		H->next = s;
		scanf("%d",&x);
	} 
	return H;
}  

LinkList Creat_LinkList2() //尾插法
{
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s,*r = H;
	int x;
	scanf("%d",&x);
	while(x!=-1) // 终止条件为-1
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

int Length_LinkList(LinkList H)  //求表长 
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

LinkList Get_LinkList(LinkList H,int k)//单链表中按序号查找
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

LNode* Locate(LinkList H,DataType  k)//单链表中按值查找
{
	LNode *p = H->next;
	while(p!=NULL && p->data!=k) p = p->next;
	return p;
} 

int Insert_LinkList(LinkList H,int i,DataType  x)//插入 
{
	LNode *p,*s;
	p = Get_LinkList(H,i-1);
	if(p==NULL) 
	{
		printf("插入的位置错误诶！");
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

int Del_LinkList(LinkList H,int i,DataType  x)//删除 
{
	LinkList p,q;
	p = Get_LinkList(H,i-1);
	if(p==NULL) 
	{
		printf("第%d-1个节点不存在！",i);
		return -1; 
	}
	else
	{
		if(p->next==NULL)
		{
			printf("第%d个节点不存在！",i);
			return -1; 
		}
	}

	//核心代码 
	q = p->next;
	p->next = q->next;
	free(q);
	return 0;

}

void Reverse(LinkList H) //链表的逆置 
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

