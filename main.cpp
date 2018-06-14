#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define NAME 10
typedef struct fnode
{
	char father[NAME];
	char mom[NAME];
	char son[NAME];
 } fam;
 typedef struct tnode
 {
 	char name[NAME];
 	struct tnode *lch,*rch;
 }tree;
 int n;
 fam fa[MAX];
 tree *create_tree(char *root)
 {
 	int i =0,j;
 	tree *b,*p;
 	b=(tree*)malloc(sizeof(tree));
 	strcpy(b->name,root);
 	b->lch=b->rch=NULL;
 	while(i<n&&strcmp(fa[i].father,root)!=0) i++;
	if(i<n)
	{
		p=(tree*)malloc(sizeof(tree));
		p->lch=p->rch=NULL;
		strcpy(p->name,fa[i].mom);
		b->lch=p;
		for(j=0;j<n;j++)
		{
			if(strcmp(fa[j].father,root)==0)
			{
				p->rch=create_tree(fa[j].son);
				p=p->rch;
			}
		}
	 } 
	 return b;
 }
 void disp_tree(tree *b)
 {
 	if(b!=NULL)
 	{
 		printf("%s",b->name);
 		if(b->lch!=NULL||b->rch!=NULL)
 		{
 			printf("(");
 			disp_tree(b->lch);
 			if(b->rch!=NULL)
 			printf(",");
 			disp_tree(b->rch);
 			printf(")");
		 }
	 }
 }
 tree *find_node(tree *b,char xm[])
 {
 	tree *p;
 	if(b==NULL) return NULL;
 	else 
 	{
 		if(strcmp(b->name,xm)==0) return(b);
 		else 
 		{
 			p=find_node(b->lch,xm);
 			if(p!=NULL) return(p);
 			else
 			return (find_node(b->rch,xm));
 			
		 }
	 }
 }
 void disp_son(tree *b)
 {
 	char xm[MAX];
 	tree *p;
 	printf(">>father>>:");
 	scanf("%S",xm);
 	p=find_node(b,xm);
 	if(p==NULL) printf("can not find!\n");
 	else 
 	{
 		p=p->lch;
 		if(p==NULL) printf("no wife");
 		else 
 		{
 			p=p->rch;
 			if(p==NULL) printf("no son");
 			else
 			{
 				printf(">>%s son:",xm);
 				while(p!=NULL)
 				{
 					printf("%10s",p->name);
 					p=p->rch;
 					
				 }
				 printf("\n");
			 }
		 }
	 }
 }
 int path(tree *b,tree *s)
 {
 	tree *st[MAX];
 	tree *p;
 	int i,top=-1;
 	bool flag;
 	while(top !=-1)
 	{
 	b=st[top];
	 if(b->rch==p)
	 {
	 	if(b==s)
	 	{
	 		printf(">>all father:");
	 		for(i=0;i<top;i++) printf("%s",st[i]->name);
	 		printf("\n");
	 		return 1;
		 }
		 else
		 {
		 	top --;
		 	p=b;
		 }
	 }	
	 }
	 return 0; 
 }
 void ancestor(tree *b)
 {
 	tree *p;
 	char xm[MAX];
 	printf("please input name :");
 	scanf("%s",xm);
 	p-find_node(b,xm);
 	if(p!=NULL) path(b,p);
 	else printf("none %s",xm);
 }
 int del_tree(tree *b)
 {
 	if(b!=NULL)
 	{
 		del_tree(b->lch);
 		del_tree(b->rch);
		 free(b);
	 }
 }
 void read_file()
 {
 	FILE *fp;
 	long len;
 	int i;
 	if((fp=fopen("fam.dat","rb"))==NULL)
 	{
 		n=0;
 		return ;
	 }
	 fseek(fp,0,2);
	 len=ftell(fp);
	 rewind(fp);
	 n=len/sizeof(fam);
	 for(i=0;i<n;i++) fread(&fa[i],sizeof(fam),1,fp);
	 fclose(fp);
 }
 void save_file()
 {
 	int i;
 	FILE *fp;
 	if((fp=fopen("fam.dat","wb"))==NULL)
 	{
 		printf("can nnot open!\n");
 		return ;
	 }
	 for(i=0;i<n;i++)
	 {
	 	fwrite(&fa[i],sizeof(fam),1,fp);
	 }
	 fclose(fp);
 }
 void input()
 {
 	printf(">>input fa,mo,son:");
 	scanf("%s %s %s",fa[n].father,fa[n].mom,fa[n].son);
 	n++;
 }
 void output_file()
 {
 	int i;
 	if(n<=0)
 	{
 		printf("no data!\n");
 		return;
	 }
	 printf(" father mom   son\n");
	 for(i=0;i<n;i++)
	 {
	 	printf("%10s %10s %10s",fa[i].father,fa[i].mom,fa[i].son);
	 }
 }
 void file()
 {
 	int ch;
 	do 
 	{
 		printf("1:input 2:output 9:clear 0:save and back :");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 9:
 				printf("ok\n");break;
 			case 1:
 				input();break;
 			case 2:
 				output_file();break;
 			case 0:
 				save_file;break;
 		 }
	 }while(ch!=0);
 }
 void b_tree()
 {
 	tree *b;
 	int ch;
 	if (n==0) return;
 	b=create_tree(fa[0].father);
 	while(1)
 	{
 		printf("1:()dis 2:fid sb`son 3:find sb`old 0:back :");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 3:
 				printf(">>");ancestor(b);break;
 			case 1:
 				disp_tree(b);break;
 			case 2:
 				disp_son(b);break;
 			case 0:
 				return ;
 		 }
	 }
	 del_tree(b);
 }
 
int main(int argc, char** argv) {
	tree *b;
	int ch;
	read_file();
	while(1)
	{
		printf("1:file 2:family 0:exit :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				file();break;
			case 2:
				b_tree();break;
			case 0:
				return 1;
		}
	}
	return 1;
}
