#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>  
#include<string.h>  
#define MAXSIZE 30  
  
typedef int Status; // 定义函数返回值类型  
  
typedef struct  
{  
    char name[20]; // 姓名  
    char num[11]; // 手机号 
    double area; // 家乡区号   
}student;  
  
typedef student list;  
  
typedef struct  
{  
    list *elem; // 存储空间的基地址   
    int length; // 当前长度   
}SqList;  
  
Status InitList(SqList *L) // 构造空的顺序表 L   
{     
    L->elem=(list *)malloc(sizeof(list)*MAXSIZE);  
    L->length=0;  
    return 1;  
}  
  
list GetElem(SqList &L,int i) // 访问顺序表，找到 i位置，返回给 e  
{  
    return L.elem[i];  
}  
  
  
Status ListInsert(SqList &L,int i,list e) // 在 i位置插入某个学生的信息   
{  
    if((i<1)||(i>L.length+1)) 
		return 0;  
    if(L.length==MAXSIZE)  
		return 0;  
    for(int j=L.length;j>=i;j--)  
    {  
        L.elem[j+1]=L.elem[j];  
    }  
    L.elem[i]=e;  
    ++L.length;  
    return 1;  
}  
  
Status ListDelete(SqList &L,int i) // 在顺序表中删除 i位置的学生信息   
{  
    if((i<1)||(i>L.length))  
		return 0;  
    for(int j=i;j<=L.length;j++)  
    {  
        L.elem[j]=L.elem[j+1];  
    }  
    --L.length;  
    return 1;  
}  
  
void Input(list *e)  
{  
    printf("姓名:");  scanf("%s",e->name);  
    printf("手机号:");  scanf("%s",e->num);  
    printf("区号:");  scanf("%lf",&e->area);  
    printf("输入完成\n\n");  
}  
  
void Output(list *e)  
{  
    printf("姓名:%-20s\n手机号:%-11s\n区号:%lf\n\n",e->name,e->num,e->area);  
}  
  
int main()  
{  
    SqList L;  
    list a,b;  

    int x,choose; 
	int i;
    while(1)  
    {   
		printf("\n********************************\n\n");  
        puts("1. 创建学生表");   
        puts("2. 录入学生信息");  
        puts("3. 显示学生信息");  
        puts("4. 在指定位置插入学生信息");  
        puts("5. 在指定位置删除学生信息");  
        puts("0. 退出");  
        printf("\n********************************\n\n");  
        puts("请选择:");  
        scanf("%d",&choose);  
        if(choose==0)   break;  
        switch(choose)  
        {  
            case 1:  
                    if(InitList(&L))  
                        printf("成功建立通讯录\n\n");  
                    else  
                        printf("通讯录建立失败\n\n");  
                    break;  
            case 2:  
                    printf("请输入要录入学生的人数（小于100）:");  
                    scanf("%d",&x);  
                    for( i=1;i<=x;i++)  
                    {  
                        printf("第%d个学生:\n",i);  
                        Input(&L.elem[i]);  
                    }  
                    L.length=x;  
                    puts("");  
                    break;  
            case 3:  
                    for( i=1;i<=x;i++)  
                    {  
                        a=GetElem(L,i);  
                        Output(&a);  
                    }  
                    break;  
            case 4:  
                    printf ("请输入要插入的位置:");  
                    int id2;  
                    scanf("%d",&id2);  
                    printf("请输入学生信息:\n");  
                    Input(&b);  
                    if(ListInsert(L,id2,b))  
                    {  
                        x++;  
                        puts("插入成功");  
                        puts("");  
                    }  
                    else  
                    {  
                        puts("插入失败");  
                        puts("");     
                    }  
                    break;  
            case 5:  
                    printf("请输入要删除的位置:");  
                    int id3;  
                    scanf("%d",&id3);  
                    if(ListDelete(L,id3))  
                    {  
                        x--;  
                        puts("删除成功");  
                        puts("");  
                    }  
                    else  
                    {  
                        puts("删除失败");  
                        puts("");     
                    }  
                    break;  
                    
        }  
    }  
    printf("\n\n请按任意键退出\n\n");  
    system("pause");  
    return 0;  
} 