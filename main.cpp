#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
typedef struct    
{    
    char *str;    
    int length;    
}String; 

  
    
void InitString(String *S)    
{    
    S->length = 0;    
    S->str = '\0';    
}    
   
int Empty(String S)//�жϴ��Ƿ�Ϊ��    
{    
    if(S.length == 0)    
    {    
        return 1;    
    }    
    else    
    {    
        return 0;    
    }    
}    
int Length(String S)//�󴮵ĳ��Ȳ���    
{    
    return S.length ;    
}   
int Compare(String S,String T)//���ıȽϲ���    
{    
    int i��c=0;    
    for(i = 0;i < S.length&&i < T.length ;i++)//�Ƚ��������е��ַ�    
    {    
        if(S.str[i] != T.str[i])//��������ַ���ͬ���򷵻������ַ��Ĳ�ֵ    
        {    
            c++;    
        }    
    }    
    return c;//����Ƚ���ϣ����������ַ����ĳ��ȵĲ�ֵ    
}   

void Copy(String *T,String S)//���ĸ��Ʋ���(����S�е�ÿһ���ַ�����T)    
{    
    int i;    
    T->str = (char*)malloc(S.length*sizeof(char));    
    if(!T->str)    
    {    
        exit(-1);    
    }    
    for(i = 0;i < S.length ;i++)    
    {    
        T->str[i] = S.str[i];    
    }    
    T->length = S.length ;    
}    
 

void Assign(String *S,char cstr[])//���ĸ�ֵ����(������cstr�е��ַ���ֵ����S)    
{    
    int i = 0,len;    
    if(S->str)    
    {    
        free(S->str);    
    }    
    for(i = 0;cstr[i]!='\0';i++)    
    {    
        ;    
    }    
    len = i;    
    if(!i)    
    {    
        S->length = 0;    
        S->str = '\0';    
    }    
    else    
    {    
        S->str = (char*)malloc(len*sizeof(char));    
        if(!S->str)    
        {    
            exit(-1);    
        }    
        for(i = 0;i < len;i++)    
        {    
            S->str[i] = cstr[i];    
        }    
        S->length = len;    
    }    
} 

int Insert(String *S,int pos,String T)//���Ĳ������(�ڴ�S��pos��λ�ò��봮T)    
{    
    int i;    
    if(pos < 0 || pos-1 > S->length)    
    {    
        printf("����λ�ò���ȷ\n");    
        return 0;    
    }    
    S->str = (char*)realloc(S->str,(S->length+T.length)*sizeof(char));    
    if(!S->str)    
    {    
        printf("�ڴ����ʧ��");    
        exit(-1);    
    }    
    for(i = S->length -1;i >= pos-1;i--)    
    {    
        S->str[i+T.length] = S->str[i];    
    }    
    for(i = 0;i < T.length ;i++)    
    {    
        S->str[i+pos-1] = T.str[i];    
    }    
    S->length = S->length + T.length;    
    return 1;    
}    


int Delete(String *S,int pos,int len)//����ɾ������(�ڴ�S��ɾ��pos��ʼ��len���ַ�,Ȼ�󽫺�����ַ���ǰ�ƶ�)    
{    
    int i;    
    char *p;    
    if(pos < 0 || len < 0 || pos+len-1 > S->length)    
    {    
        printf("ɾ��λ�ò���ȷ������len���Ϸ�\n");    
        return 0;    
    }    
    p = (char*)malloc(S->length-len);    
    if(!p)    
    {    
        exit(-1);    
    }    
    for(i = 0;i < pos-1;i++)//������posλ��֮ǰ���ַ����Ƶ�p��    
    {    
        p[i] = S->str[i];    
    }    
    for(i = pos-1;i < S->length-len;i++)//������pos+lenλ���Ժ���ַ����Ƶ�p��    
    {    
        p[i] = S->str[i+len];    
    }    
    S->length = S->length -len;//�޸Ĵ��ĳ���    
    free(S->str);//�ͷ�ԭ���Ĵ�S���ڴ�ռ�    
    S->str = p;//������strָ��p�ַ���    
    return 1;    
}    




int Concat(String *T,String S)//�������Ӳ���(����S�����ڴ�T�ĺ���)    
{    
    int i;    
    T->str = (char*)realloc(T->str ,(T->length +S.length )*sizeof(char));    
    if(!T->str)    
    {    
        printf("����ռ�ʧ��");    
        exit(-1);    
    }    
    else    
    {    
        for(i = T->length ;i < T->length +S.length ;i++)//����Sֱ�����ӵ�T��ĩβ    
        {    
            T->str[i] = S.str[i-T->length];    
        }    
        T->length = T->length +S.length ;//�޸Ĵ�T�ĳ���    
    }    
    return 1;    
}    

   
int Index(String S,int pos,String T)//���Ķ�λ����(������S�еĵ�pos��λ�ÿ�ʼ�����Ӵ�T,�������S�д����봮Tֵ��ȵ��Ӵ��������Ӵ���������pos���ַ����һ�γ��ֵ�λ��)    
{    
    int i,j;    
    if(Empty(T))    
    {    
        return 0;    
    }    
    i = pos;    
    j = 0;    
    while(i < S.length && j < T.length)    
    {    
        if(S.str[i] == T.str[j])    
        {    
            i++;    
            j++;    
        }    
        else//�����ǰ��Ӧλ�õ��ַ�����ȣ���Ӵ�S����һ���ַ���ʼ����T�ĵ�0���ַ���ʼ�Ƚ�    
        {    
            i = i-j+1;    
            j = 0;    
        }    
    }    
    if(j >= T.length)//����ڴ�S���ҵ���T���򷵻��Ӵ�T������S�е�λ��    
    {    
        return i-j+1;    
    }    
    else    
    {    
        return 0;    
    }    
}    
  
void Clear(String *S)//��մ�����    
{    
    if(S->str)    
    {    
        free(S->str);    
    }    
    S->str = '\0';    
    S->length = 0;    
}    
void Destory(String *S)//�ݻٴ�����    
{    
    if(S->str)    
    {    
        free(S->str);    
    }    
}    
void Print(String S)//�����������    
{    
    int i;    
    for(i = 0;i < S.length ;i++)    
    {    
        printf("%c",S.str[i]);    
    }    
    printf("\n");    
}    
  
  
  
  
int main(void)    
{    
	int a=0;
    String S1,S2,Sub;    
    char ch[20]; 
	char sh[20];
    InitString(&S1);    
    InitString(&S2);    
    InitString(&Sub);   
	while(1)
	{
		printf("1.�������һ���ַ�����\n");    
      	printf("2.������ڶ����ַ�����\n");    
    	printf("3.����S2���ӵ���S1��ĩβ��S1��Ϊ��\n");    
     	printf("4.����S2���뵽��S1�ĵ�һ��λ�ã�\n");
     	printf("5.�Ѵ�S1�ĵ�һ��λ��֮���8���ַ�ɾ����\n");  
		printf("6.�Ƚ�s1��s2�ĳ��Ȳ����س��Ȳ�\n");
		scanf("%d",&a);
		switch(a)
		{
        case 1:
	    	printf("�������һ���ַ���(10λ����)��\n");    
            scanf("%s",ch);
			getchar();
            Assign(&S1,ch); 
			printf("������ֵ������Ĵ�S1��\n"); 
			Print(S1);
			printf("\n\n");
			break;
 		case 2:
	        printf("������ڶ����ַ���(10λ����)��\n");    
            scanf("%s",sh); 
			getchar();
            Assign(&S2,sh);
		    printf("������ֵ������Ĵ�S2��\n");  
		    Print(S2);   
		    printf("\n\n");
		    break;
		case 3:
            Concat(&S1,S2); 
		    printf("����S2���ӵ���S1��ĩβ��S1��Ϊ��\n");    
            Print(S1); 
		    printf("\n\n");
		    break;
		case 4:
	        Insert(&S1,1,Sub);
		    printf("����S2���뵽��S1�ĵ�һ��λ��Ϊ��\n");
            Print(S1); 
		    printf("\n\n");
		    break;
 		case 5:	
            Delete(&S1,1,5); 
       	    printf("�Ѵ�S1�ĵ�һ��λ��֮���5���ַ�ɾ����Ϊ��\n"); 
            Print(S1); 
		    printf("\n\n");
		case 6:
			printf("���ַ����ĳ��Ȳ�Ϊ:\n");
			printf("%d",Compare(S2,S1));
        	printf("\n\n");

		}
	

	}
    return 0;    
}  
