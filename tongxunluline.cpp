// tongxunluline.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <malloc.h>
#include<string.h>

typedef struct studentl //单节点数据
{
	struct studentl *pr; //头指针
	char name[20]; //名字
	char num[11]; //手机号
	int area; //区号
	struct studentl *next; //尾指针
}student;
//student *create_head(student *p)//初始化头节点
//{
//	p = (student *)malloc(sizeof(student));
//	p->pr = p;
//	p->next = p;
//	strcpy_s(p->name, "tongxunlu");
//	p->area = 0;
//	printf("%d", p);
//	return p;
//}

int insert(student *p,int i)//第一次输入函数，依次为头指针，数量，默认在尾端插入
{
	student *sp = p ,*local;
	if (i < 0)  /*错误处理*/
	{
		i = -i;
		printf("the persons your input auto negate");
	}
	for (;i>0; i--) /*添加n个人*/
	{
		local = (student *)malloc(sizeof(student));
		sp->next = local;
		local->pr = sp;
		local->next = p;
		sp=local;
		printf("it`s %d person:", i);
		scanf("%s", sp->name);
		scanf("%s", sp->num);
		scanf("%d", &sp->area);
		p->area++;
	}
	return 1;
}
int insert2(student *p, int i)//第一次输入函数，依次为头指针，数量，默认在尾端插入
{
	student *sp = p, *local;
	int m = p->area;
	if (i < 0)  /*错误处理*/
	{
		i = -i;
		printf("the persons your input auto negate");
	}
	while (m)
	{
		sp = sp->next;
		m--;
	}
	for (; i>0; i--) /*添加n个人*/
	{
		local = (student *)malloc(sizeof(student));
		sp->next = local;
		local->pr = sp;
		local->next = p;
		sp = local;
		printf("it`s %d person:", i);
		scanf("%s", sp->name);
		scanf("%s", sp->num);
		scanf("%d", &sp->area);
		p->area++;
	}
	return 1;
}
int list(student *p)
{
	student *sp = p;
	int area = p->area;
	sp = sp->next;
	while (area)
	{
		printf("name: %s", sp->name);
		printf("num: %s", sp->num);
		printf("area: %d\n", sp->area);
		sp = sp->next;
		area--;
	}
	return 1;
}

int drop(student *p, char *drop_name, char *drop_num, int drop_area)//删库函数，依次为 头指针，名字，号码，区号
{
	student *sp = p, *localp;
	sp = sp->next;
	while (1)
	{
		if (sp->next == p) break; /*如果遍历一次后没找到会自动跳出*/
		if (sp->name[0] == drop_name[0]&&drop_name[0]!='\0') /*匹配名字*/
		{
			for(int local=1;local<20;local++)
			{
				if (sp->name[local] != drop_name[local]) break;
				if (sp->name[local] == '\0')
				{
					localp = sp;
					sp->next->pr = sp->pr;
					sp->pr->next = sp->next;
					sp = sp->next;
					free(localp);
					p->area--;
				}
			}
		}
		else if (sp->num[0] == drop_num[0] && drop_num[0] != '\0') /*匹配号码*/
		{
			for (int local = 1; local<12; local++)
			{
				if (sp->num[local] != drop_num[local]) break;
				if (sp->num[local] == '\0')
				{
					localp = sp;
					sp->next->pr = sp->pr;
					sp->pr->next = sp->next;
					sp = sp->next;
					free(localp);
					p->area--;
				}
			}
		}
		else if (sp->area==drop_area&&drop_area!=0) /*匹配区号*/
		{
			localp = sp;
			sp->next->pr = sp->pr;
			sp->pr->next = sp->next;
			sp = sp->next;
			free(localp);
			p->area--;
		}
		else sp = sp->next;
	}
	return 1;
}

int alert(student *p, char *alert_name, char *alert_num)//删库函数，依次为 头指针，名字，号码，区号
{
	student *sp = p, *localp;
	while (1)
	{
		if (sp->next == p) break;
		if (sp->name[0] == alert_name[0] && alert_name[0] != '\0') /*匹配名字*/
		{
			for (int local = 1; local<20; local++)
			{
				if (sp->name[local] != alert_name[local]) break;
				if (sp->name[local] == '\0')
				{
					printf("it`s %s person,please input things:\n", alert_name);
					scanf("%s", sp->name);
					scanf("%s", sp->num);
					scanf("%d", &sp->area);
					sp = sp->next;
				}
			}
		}
		else if (sp->num[0] == alert_num[0] && alert_num[0] != '\0') /*匹配号码*/
		{
			for (int local = 1; local<12; local++)
			{
				if (sp->num[local] != alert_num[local]) break;
				if (sp->num[local] == '\0')
				{
					printf("it`s %s person,please input things:\n", alert_num);
					scanf("%s", sp->name);
					scanf("%s", sp->num);
					scanf("%d", &sp->area);
					sp = sp->next;
				}
			}
		}
		else sp = sp->next;
	}
	return 1;
}

int main()
{
	student *p;
	p = (student *)malloc(sizeof(student));
	strcpy_s(p->name, "tongxunlu");
	p->area = 0;
	int choise,i;
	printf("creating your basenumpad:\n");
	while (1)
		{
			char drop_name[20] = { '\0' }, drop_num[11] = { '\0' };
			char alert_name[20] = { '\0' }, alert_num[11] = { '\0' };
			int drop_area = 0;
			printf("welcome to numpad:\n");
			printf("1.create a numpad\n");
			printf("2.input a numpad\n");
			printf("3.alert numpad\n");
			printf("4.drop numpad\n");
			printf("5.list all numpaders\n");
			printf("6.exit\n");
			printf("please input your operation:\n");
			scanf("%d", &choise);
			switch (choise)
			{
			case 1 :
				printf("please input the number you want:\n");
				scanf("%d", &i);
				insert(p, i);
				break;
			case 2 :
				printf("please input the number you want add:\n");
				scanf("%d",&i);
				insert2(p, i);
				break;
			case 3 :
				printf("please input the item you want to alter:\n");
				printf("1.use studen`s name:\n");
				printf("2.use studen`s num:\n");
				scanf("%d",&i);
				if (i == '1')
				{
					printf("input th name:");
					scanf("%s", alert_name);
					alert(p, alert_name, alert_num);
					break;
				}
				else if (i == '2')
				{
					printf("input th num:");
					scanf("%s", alert_num);
					alert(p, alert_name, alert_num);
					break;
				}
				else
					printf("please reinput:\n"); break;
			case 4 :
				printf("please input the item you want to drop:\n");
				printf("1.use studen`s name:\n");
				printf("2.use studen`s num:\n");
				printf("3.use studen`s area:\n");
				scanf("%d",&i);
				if (i == 1)
				{
					printf("input th name:");
					scanf("%s", drop_name);
					drop(p, drop_name, drop_num, drop_area);
					break;
				}
				else if (i == 2)
				{
					printf("input th num:");
					scanf("%s", drop_num);
					drop(p, drop_name, drop_num, drop_area);
					break;
				}
				else if (i == 3)
				{
					printf("input th area:");
					scanf("%d", &drop_area);
					drop(p, drop_name, drop_num, drop_area);
					break;
				}
				else
					printf("please reinput:\n"); break;
			case 5:
				list(p);
				break;
			case 6:
				return 0;
			default:
				printf("please reinput:\n");
				break;
			}
		}
}

