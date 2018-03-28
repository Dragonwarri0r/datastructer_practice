// 比较器.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>  
#define EnyType char

typedef struct linknode //定义一个栈
{
	EnyType data;
	struct linknode *next;
}LS;
void CreateStack(LS* &s) //初始化一个栈
{
	s = (LS*)malloc(sizeof(LS));
	s->next = NULL;
}
int StackEmpty(LS* &s) //判断是否为空
{
	return (s->next == NULL);
}
void Push(LS* &s, EnyType e) //进栈
{
	LS *p;
	p = (LS*)malloc(sizeof(LS));
	p->data = e;
	p->next = s;
	s = p;
}
int Pop(LS* &s, EnyType &e) ///出栈

{	if (s->next == NULL)
		return 0;
	
	else
	{
		LS *p = s;
		e = p->data;
		s = p->next;
		free(p);
		return 1;
	}
}
void PrintStack(LS* &s) //打印栈
{
	LS *p = s;
	while (p->next != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
}
int main()
{
	char local,local1;
	LS *s1, *s2,*l1,*l2;
	CreateStack(s1);
	CreateStack(s2);
	CreateStack(l1);
	CreateStack(l2);
	printf("we already create a linkstack...\n");
	int dis = 0;
	while (1)
	{
		printf("1:push your data into stack\n2:drop the same data\n");
		printf("3:drop the different data\n4:list your data\n5:exit\nplease input your discision:\n");
		scanf_s("%d", &dis);
		switch (dis)
		{
		case 1:
			printf("we input the string 1 ,input ';' to end\n"); 
			while (1)
			{
				scanf_s("%c", &local);
				if (local == ';')break;
				Push(s1, local);
			}
			printf("we input the string 2 ,input ';' to end\n");
			while (1)
			{
				scanf_s("%c", &local);
				if (local == ';')break;
				Push(s2, local);
			}
			break;
		case 2:
			while (!StackEmpty(s1) || !StackEmpty(s2))
			{
				Pop(s1, local);
				Pop(s2, local1);
				if (local != local1)
				{
					Push(l1, local);
					Push(l2, local1);
				}
			}
			while (!StackEmpty(l1)|| !StackEmpty(l2))
			{
				Pop(l1, local);
				Pop(l2, local1);
				Push(s1, local);
				Push(s2, local1);
			}
			printf("we already drop the same things\n");
			break;
		case 3:
			while (!StackEmpty(s1) || !StackEmpty(s2))
			{
				Pop(s1, local);
				Pop(s2, local1);
				if (local == local1)
				{
					Push(l1, local);
				}
			}
			while (!StackEmpty(l1))
			{
				Pop(l1, local);
				Push(s1, local);
				Push(s2, local);
			}
			printf("we already drop the different things\n");
			break;
		case 4:
			printf("string 1:\n");
			PrintStack(s1);
			printf("string 2:\n");
			PrintStack(s2);
			printf("end\n");
			break;
		case 5:
			printf("good bye~");
			return 0;
		default:
		{printf("please reinput:\n"); break;}
		}

	}
	return 0;


}
