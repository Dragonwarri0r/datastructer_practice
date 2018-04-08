// 进程管理器环形队列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<malloc.h>
#define MAXSIZE 20

typedef struct cirqueue //定义环形队列结构体
{
	int pid[MAXSIZE]; //进程pid
	char name[MAXSIZE]; //进程名字
	int front, rear; //头尾标号
}cirq;

int create_cirq(cirq *&q) //创建环形序列
{
	q = (cirq*)malloc(sizeof(cirq));
	q->front = q->rear = 0;
	return 0;
}
int input_cirq(cirq *q, int pid, char name) //加入元素，指向队列的指针，pid，名字
{
	int b = q->rear;
	b++;
	b = b % 20;
	if (b == q->front)
	{
		return 0;
	}
	else
	{
		q->rear++;
		q->rear = q->rear% MAXSIZE;
		q->pid[q->rear] = pid;
		q->name[q->rear] = name;
		return 1;
	}
}
int output_cirq(cirq *q, int &pid, char &name) //出队列，指向队列的指针，pid，名字
{
	if ((q->front++) % 20 == q->rear)
	{
		return 0;
	}
	q->front = (q->front + 1) % MAXSIZE;
	pid = q->pid[q->rear];
	name = q->name[q->rear];
	return 1;
}
int is_empty(cirq *q) //判断是否为空
{
	if (q->rear == q->front)
	{
		return 1;
	}
	return 0;
}
int is_full(cirq *q)
{
	int a = q->rear;
	a++;
	a = a % 20;
	if (a == q->front)
	{
		return 1;
	}
	return 0;
}
int list_task(cirq *q) //打印队列
{
	int a = q->front;
	int b = q->rear;
	a++;
	b++;
	while (a != b)
	{
		printf("\n%d task pid:%d name:%c", a, q->pid[a],q->name[a]);
		a++;
		a = a % 20;
	}
	return 0;
}
int main()
{
	cirq *q;
	int chose;
	int size, pid;
	char name;
	if (!create_cirq(q))
	{
		printf("we already create a circle queue!it`s can store MAXSIZE\n");
	}
	while (1)
	{
		printf("1.input tasks\n2.output a task\n3.Is queue empty?\n4.Is queue full?\n5.list all\n6.exit\n");
		printf("please input your dision:");
		scanf_s("%d", &chose);
		switch (chose)
		{
		case 1:
			printf("\nplease input your tasks numbers:");
			scanf_s("%d", &size);
			if (size > MAXSIZE || size < 0) break;
			while (size)
			{
				printf("\nplease input your task %d: pid name ",size);
				scanf_s("%d %c", &pid,&name);
				input_cirq(q, pid, name);
				size--;
			}
			break;
		case 2:
				output_cirq(q, pid, name);
				printf("\ncomplete your task pid:%d", pid);
				printf("\nyour task %s name:", name);
				break;
		case 3:
			if (is_empty(q))
			{
				printf("It`s empty!");
				}
			else printf("It`s not empty!");
			break;
		case 4:
			if (is_full (q))
			{
				printf("It`s full!");
			}
			else printf("It`s not full!");
			break;
		case 5:
			list_task(q);
			break;
		case 6:
			return 0;
		default:
			printf("please reinput!\n");
			break;
		}
	}
	return 0;
}

