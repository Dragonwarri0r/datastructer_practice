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
   
int Empty(String S)//判断串是否为空    
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
int Length(String S)//求串的长度操作    
{    
    return S.length ;    
}   
int Compare(String S,String T)//串的比较操作    
{    
    int i，c=0;    
    for(i = 0;i < S.length&&i < T.length ;i++)//比较两个串中的字符    
    {    
        if(S.str[i] != T.str[i])//如果出现字符不同，则返回两个字符的差值    
        {    
            c++;    
        }    
    }    
    return c;//如果比较完毕，返回两个字符串的长度的差值    
}   

void Copy(String *T,String S)//串的复制操作(将串S中的每一个字符赋给T)    
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
 

void Assign(String *S,char cstr[])//串的赋值操作(将常量cstr中的字符赋值给串S)    
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

int Insert(String *S,int pos,String T)//串的插入操作(在串S的pos个位置插入串T)    
{    
    int i;    
    if(pos < 0 || pos-1 > S->length)    
    {    
        printf("插入位置不正确\n");    
        return 0;    
    }    
    S->str = (char*)realloc(S->str,(S->length+T.length)*sizeof(char));    
    if(!S->str)    
    {    
        printf("内存分配失败");    
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


int Delete(String *S,int pos,int len)//串的删除操作(在串S中删除pos开始的len个字符,然后将后面的字符向前移动)    
{    
    int i;    
    char *p;    
    if(pos < 0 || len < 0 || pos+len-1 > S->length)    
    {    
        printf("删除位置不正确，参数len不合法\n");    
        return 0;    
    }    
    p = (char*)malloc(S->length-len);    
    if(!p)    
    {    
        exit(-1);    
    }    
    for(i = 0;i < pos-1;i++)//将串第pos位置之前的字符复制到p中    
    {    
        p[i] = S->str[i];    
    }    
    for(i = pos-1;i < S->length-len;i++)//将串第pos+len位置以后的字符复制到p中    
    {    
        p[i] = S->str[i+len];    
    }    
    S->length = S->length -len;//修改串的长度    
    free(S->str);//释放原来的串S的内存空间    
    S->str = p;//将串的str指向p字符串    
    return 1;    
}    




int Concat(String *T,String S)//串的连接操作(将串S连接在串T的后面)    
{    
    int i;    
    T->str = (char*)realloc(T->str ,(T->length +S.length )*sizeof(char));    
    if(!T->str)    
    {    
        printf("分配空间失败");    
        exit(-1);    
    }    
    else    
    {    
        for(i = T->length ;i < T->length +S.length ;i++)//将串S直接连接到T的末尾    
        {    
            T->str[i] = S.str[i-T->length];    
        }    
        T->length = T->length +S.length ;//修改串T的长度    
    }    
    return 1;    
}    

   
int Index(String S,int pos,String T)//串的定位操作(在主串S中的第pos个位置开始查找子串T,如果主串S中存在与串T值相等的子串，返回子串在主串第pos个字符后第一次出现的位置)    
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
        else//如果当前对应位置的字符不相等，则从串S的下一个字符开始，从T的第0个字符开始比较    
        {    
            i = i-j+1;    
            j = 0;    
        }    
    }    
    if(j >= T.length)//如果在串S中找到串T，则返回子串T在主串S中的位置    
    {    
        return i-j+1;    
    }    
    else    
    {    
        return 0;    
    }    
}    
  
void Clear(String *S)//清空串操作    
{    
    if(S->str)    
    {    
        free(S->str);    
    }    
    S->str = '\0';    
    S->length = 0;    
}    
void Destory(String *S)//摧毁串操作    
{    
    if(S->str)    
    {    
        free(S->str);    
    }    
}    
void Print(String S)//串的输出声明    
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
		printf("1.请输入第一个字符串：\n");    
      	printf("2.请输入第二个字符串：\n");    
    	printf("3.将串S2连接到串S1的末尾，S1串为：\n");    
     	printf("4.将串S2插入到串S1的第一个位置：\n");
     	printf("5.把串S1的第一个位置之后的8个字符删除：\n");  
		printf("6.比较s1与s2的长度并返回长度差\n");
		scanf("%d",&a);
		switch(a)
		{
        case 1:
	    	printf("请输入第一个字符串(10位以内)：\n");    
            scanf("%s",ch);
			getchar();
            Assign(&S1,ch); 
			printf("经过赋值操作后的串S1：\n"); 
			Print(S1);
			printf("\n\n");
			break;
 		case 2:
	        printf("请输入第二个字符串(10位以内)：\n");    
            scanf("%s",sh); 
			getchar();
            Assign(&S2,sh);
		    printf("经过赋值操作后的串S2：\n");  
		    Print(S2);   
		    printf("\n\n");
		    break;
		case 3:
            Concat(&S1,S2); 
		    printf("将串S2连接到串S1的末尾，S1串为：\n");    
            Print(S1); 
		    printf("\n\n");
		    break;
		case 4:
	        Insert(&S1,1,Sub);
		    printf("将串S2插入到串S1的第一个位置为：\n");
            Print(S1); 
		    printf("\n\n");
		    break;
 		case 5:	
            Delete(&S1,1,5); 
       	    printf("把串S1的第一个位置之后的5个字符删除后为：\n"); 
            Print(S1); 
		    printf("\n\n");
		case 6:
			printf("两字符串的长度差为:\n");
			printf("%d",Compare(S2,S1));
        	printf("\n\n");

		}
	

	}
    return 0;    
}  
