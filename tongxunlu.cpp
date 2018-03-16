#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>  
#include<string.h>  
#define MAXSIZE 30  
  
typedef int Status; // ���庯������ֵ����  
  
typedef struct  
{  
    char name[20]; // ����  
    char num[11]; // �ֻ��� 
    double area; // ��������   
}student;  
  
typedef student list;  
  
typedef struct  
{  
    list *elem; // �洢�ռ�Ļ���ַ   
    int length; // ��ǰ����   
}SqList;  
  
Status InitList(SqList *L) // ����յ�˳��� L   
{     
    L->elem=(list *)malloc(sizeof(list)*MAXSIZE);  
    L->length=0;  
    return 1;  
}  
  
list GetElem(SqList &L,int i) // ����˳����ҵ� iλ�ã����ظ� e  
{  
    return L.elem[i];  
}  
  
  
Status ListInsert(SqList &L,int i,list e) // �� iλ�ò���ĳ��ѧ������Ϣ   
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
  
Status ListDelete(SqList &L,int i) // ��˳�����ɾ�� iλ�õ�ѧ����Ϣ   
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
    printf("����:");  scanf("%s",e->name);  
    printf("�ֻ���:");  scanf("%s",e->num);  
    printf("����:");  scanf("%lf",&e->area);  
    printf("�������\n\n");  
}  
  
void Output(list *e)  
{  
    printf("����:%-20s\n�ֻ���:%-11s\n����:%lf\n\n",e->name,e->num,e->area);  
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
        puts("1. ����ѧ����");   
        puts("2. ¼��ѧ����Ϣ");  
        puts("3. ��ʾѧ����Ϣ");  
        puts("4. ��ָ��λ�ò���ѧ����Ϣ");  
        puts("5. ��ָ��λ��ɾ��ѧ����Ϣ");  
        puts("0. �˳�");  
        printf("\n********************************\n\n");  
        puts("��ѡ��:");  
        scanf("%d",&choose);  
        if(choose==0)   break;  
        switch(choose)  
        {  
            case 1:  
                    if(InitList(&L))  
                        printf("�ɹ�����ͨѶ¼\n\n");  
                    else  
                        printf("ͨѶ¼����ʧ��\n\n");  
                    break;  
            case 2:  
                    printf("������Ҫ¼��ѧ����������С��100��:");  
                    scanf("%d",&x);  
                    for( i=1;i<=x;i++)  
                    {  
                        printf("��%d��ѧ��:\n",i);  
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
                    printf ("������Ҫ�����λ��:");  
                    int id2;  
                    scanf("%d",&id2);  
                    printf("������ѧ����Ϣ:\n");  
                    Input(&b);  
                    if(ListInsert(L,id2,b))  
                    {  
                        x++;  
                        puts("����ɹ�");  
                        puts("");  
                    }  
                    else  
                    {  
                        puts("����ʧ��");  
                        puts("");     
                    }  
                    break;  
            case 5:  
                    printf("������Ҫɾ����λ��:");  
                    int id3;  
                    scanf("%d",&id3);  
                    if(ListDelete(L,id3))  
                    {  
                        x--;  
                        puts("ɾ���ɹ�");  
                        puts("");  
                    }  
                    else  
                    {  
                        puts("ɾ��ʧ��");  
                        puts("");     
                    }  
                    break;  
                    
        }  
    }  
    printf("\n\n�밴������˳�\n\n");  
    system("pause");  
    return 0;  
} 