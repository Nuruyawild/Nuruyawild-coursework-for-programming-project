#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#include <ctype.h>
#define LEN sizeof(struct book)//有关图书信息的结构体
#define LEN1 sizeof(struct reader)//有关读者信息的结构体
#define LEN2 sizeof(struct land)//有关登录系统的结构体


struct book//图书信息
{
	char num[20],nam[20],aut[20],year[20];
	int  many,manyofremain;
	struct book*next;
};

struct reader//读者借阅信息
{
	char jnum[20];
	char jnam[20],time[20],tsnam[20];
	struct reader *next;
};
struct land//登录信息
{
	int zhanghao;
	char password[20];
	struct land*next;
};



int tjzs();//统计library文本个数函数
void xg(int,char[] );
void mainmenu();//显示主菜单
void tsmenu();//显示图书信息菜单
void jmenu();//显示借阅信息菜单
void lmenu();//显示登录菜单

void main1();// 主菜单功能
void tsmain();//图书菜单功能
void cxts();//查询图书菜单 
void cxtsbyyear();//按照年份查询图书
void cxtsbytitle();//按照标题查询图书
void cxtsbyauthor();//按照作者查询图书 
void zjts();//增加图书
void scts();//删除图书
void llts();//浏览图书

void jmain();//读者借阅信息
void js();//借书
void hs();//还书
void cxjs();//查询借书
void lljs();// 浏览借书情况

void land();//登录功能系统
int xinjian(int,char[] );//创建账号密码
void xgmm();//修改密码
void lmain();//登录界面函数
char user[20];//界面显示用户名



int tjzs()//统计图书文本个数
{
FILE *fp;
int txcl=0,tmany=0,n;
char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%s%d%d",tshuhao,tname,tauthor,tchuban,&tmany,&txcl);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}


int tjdzzs()//统计借书读者个数函数

{
FILE *fp;
int n,i;
char zhenghao[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
fp=fopen("reader.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%s ",&zhenghao,&mingzi,&riqi,&zname);
i++;
fclose(fp);//关闭文件
return (n);//返回个数
}


int tjzs3()//统计账号密码文本个数
{
FILE *fp;
int zhao=0,n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}


void mainmenu()//主菜单
{


printf("**************************************************");

printf("\n\n 1.图书系统\n\n");

printf("\n\n 2.借阅系统\n\n");

printf("\n\n 3.退出系统\n\n");

printf("\n\n 请按键选择，回车确定\n");

printf("*************************************************\n");

return ;
}


void tsmenu() //图书馆信息菜单
{
printf("\n(logged in as: %s)\n",user);
printf("Please choose an option:\n");
printf("1)Add a book\n");
printf("2)Remove a book\n");
printf("3)Search for books\n");
printf("4)Display all books\n");
printf("5)Log out\n");
printf(" Option: ");
return ;
}


void main1()
{
	void tsmian();
	void jmain();
	int a;
	char choose[10]={'\0'};
	mainmenu();
	gets(choose);
	a=atoi(choose);
	switch(a)//功能函数
  {
	  case'1':
	    tsmain();
	    break;
	  case'2':
	  	jmain();
	  	break;
	  case'3':
	  	 
    
  	exit(0);
  	 
	break;
  }
}


void tsmain()
{
	void zjts();
	void scts();
	void ctts();
	void llts();
	int a;
	char choose[2]={'\0'};
	tsmenu();
	gets(choose);
	a=atoi(choose);
	for(;;)
	{
		switch(a)
	{
	case 1:
		zjts();
		break;
	case 2:
		scts();
		break;
	case 3:
		cxts();
		break;
	case 4:
		llts();
		break;
	case 5:
		lmain();
		break;
	}
    }
}


void zjts()//增加图书
{
	FILE*fp;
	char i;
	int c;
	int a;
	int n;
	int year;
	int num=0;
	int many;
	int manyofremain;
    char  nam[20]={'\0'},aut[20]={'\0'},many1[10]={'\0'},year1[20]={'\0'};
     

    if ((fp=fopen("library.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
    
    fp=fopen("library.txt", "rb");
    if(fp)
    {
        while((c=fgetc(fp)) != EOF)
            if(c=='\n') num++;
        fclose(fp);
    }
    
	fp=fopen("library.txt","a");

		printf("Enter the title of the book you wish to add: ");
		gets(nam);
		
		printf("Enter the author of the book you wish to add: ");
		gets(aut);
		
		printf("Enter the year that the book you wish to add was released: ");
		gets(year1);
		
		printf("Enter the number of copies of the book you wish to add: ");
		gets(many1);
		
		many=atoi(many1);
		manyofremain=atoi(many1);
		
		if(isdigit(year1[0])!=0)
		{
			year=atoi(year1);
			fprintf(fp,"%-8d%-19s%-14s%-18d%-8d%-8d\n",num+1,nam,aut,year,many,manyofremain);
			printf("\nBook was successfully added!\n");
		}
		else
		{
			printf("Sorry, you attempt to add an invalid book, please try again.\n\n");
		}

	fclose(fp);
	tsmain();//返回上一层
}

void scts()//删除图书
{
	   struct book *head=NULL;
       struct book *p,*p1,*p2;
       int tmany=0,tmanyofremain=0,n=0,j,k,q;
       char  tnam[20]={'\0'},taut[20]={'\0'},tyear[20]={'\0'},tnum[20]={'\0'};
       char  jnam[20]={'\0'},jaut[20]={'\0'},jyear[20]={'\0'},jnum[20]={'\0'};
	   char jjnum[20]={'\0'};
	   char i;
       FILE *fp,*fp3;
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
           printf("\nThe record file does not exist!");
           tsmain();
       }

	   else//实现删除的功能
	   {
	       
	      printf("\nPlease enter the book you wish to delete:");//输入删除图书书名
          scanf("%s",jjnum);
	      fp=fopen("library.txt","r");
		  j=tjzs();
		  fp3=fopen("reader.txt","r");
		  q=tjdzzs();
		  
		  for(k=0;k<j;k++)
		  {
		  	fscanf(fp3,"%s%s%s%s",jnum,jnam,jaut,jyear);
		  	if(!strcmp(jjnum,jnum))
		  	{
		  		printf("Delete failed! Because someone has already borrowed the book!\n");
		  		goto exit;
			  }
		  }

	   for (k=0;k<j;k++)
       {
	       fscanf(fp,"%s%s%s%s%d%d",tnum,tnam,taut,tyear,&tmany,&tmanyofremain);
           if (strcmp(jjnum,tnum))//比较ID，将不同ID的信息复制到链表
          {
	          n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
	            if (n==1)//建立链表
                {
		          p1=p2=(struct book*)malloc(LEN);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct book*)malloc(LEN);//新建链表
                }

                strcpy(p1->num,tnum);//复制书号
                strcpy(p1->nam,tnam);//复制书名
                strcpy(p1->aut,taut);//复制作者名字
                strcpy(p1->year,tyear);//复制年份
                p1->many=tmany;//复制个数
                p1->manyofremain=tmanyofremain;//复制剩余个数 
           }
       }
             if (n==0)//如果图书只有一项且这一项刚好和要删除的相同
			 {
			 head=NULL;
			 }
			 else//建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
    }

   fp=fopen("library.txt","w");//清空文件，只写打开，然后关闭
   fclose(fp);
   fp=fopen("library.txt","a");//追加文件
   p=head;

   for (;p!=NULL;)//把链表内容覆盖到文件
   {
   	   fprintf(fp,"%-8s%-9s%-14s%-18s%-8d%-8d\n",p->num,p->nam,p->aut,p->year,p->many,p->manyofremain);
   	   p=p->next;
   }
   fclose(fp);
   printf("\nDelete book successfully!");
   exit:tsmain();
}

void findbymenu()//目录系统 
{
	printf("\n1)Find book by title\n");
	printf("2)Find book by author\n");
	printf("3)Find book by year\n");
	printf("4)Return to previous menu\n");
	return ;
 } 
 
void funcoffindbymenu()
{
	void cxtsbytitle();
	void cxtsbyauthor();
	void cxtsbyyear();
	char choose;
	scanf(" %c",&choose);
	for(;;)
	{
		switch(choose)
		{
			case'1':
			cxtsbytitle();
			break;
			case'2':
			cxtsbyauthor();
			break;
			case'3':
			cxtsbyyear();
			break;
			case'4':
			tsmain();
			break;
		}
	}
 } 
 
void cxts()//查询图书
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       findbymenu();
       funcoffindbymenu();
}

void cxtsbytitle()//按照标题查询图书
{
	   FILE *fp;
       int k=0,many=0,manyofremain=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
           printf("\nThe record file does not exist!");
		   tsmain();
       }
	   
       printf("Please enter tltle: ");
       scanf("%s",chazhao);
       m=tjzs();

	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s%d",num,nam,aut,year,&many,&manyofremain);
        if(!strcmp(chazhao,nam))
        {
        	if(k==0)
            {
			  printf("\nID\tTitle\t\t\tAuthors\t\tYear\tCopies\tCopies of remain\n");
            }
			printf("%-8s%-24s%-16s%-16s%-8d%-8d\n",num,nam,aut,year,many,manyofremain);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\nThere is no matching item!\n");
        tsmain();
		}
		fclose(fp);//查询结束
		cxts();
}

void cxtsbyauthor()//按作者查询图书
{
	   FILE *fp;
       int k=0,many=0,manyofremain=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
           printf("\nThe record file does not exist!");
		   tsmain();
       }
	   
       printf("Please enter tltle: ");
       scanf("%s",chazhao);
       m=tjzs();

	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s%d",num,nam,aut,year,&many,&manyofremain);
        if(!strcmp(chazhao,aut))
        {
        	if(k==0)
            {
			  printf("\nID\tTitle\t\t\tAuthors\t\tYear\tCopies\tCopies of remain\n");
            }
			printf("%-8s%-24s%-16s%-16s%-8d%-8d\n",num,nam,aut,year,many,manyofremain);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\nThere is no matching item!\n");
        tsmain();
		}
		fclose(fp);//查询结束
		cxts();
}

void cxtsbyyear()//按照年份查询图书
{
	   FILE *fp;
       int k=0,many=0,manyofremain=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
           printf("\nThe record file does not exist!");
		   tsmain();
       }
	   
       printf("Please enter tltle: ");
       scanf("%s",chazhao);
       m=tjzs();

	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s%d",num,nam,aut,year,&many,&manyofremain);
        if(!strcmp(chazhao,year))
        {
        	if(k==0)
            {
			  printf("\nID\tTitle\t\t\tAuthors\t\tYear\tCopies\tCopies of remain\n");
            }
			printf("%-8s%-24s%-16s%-16s%-8d%-8d\n",num,nam,aut,year,many,manyofremain);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\nThere is no matching item!\n");
        tsmain();
		}
		fclose(fp);//查询结束
		cxts();
}


void llts()//浏览图书
{
	FILE *fp;
	int n=0;
       int k=0,m=0,many=0,manyofremain=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
  	   char i;
	   if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	        
           printf("\nRecord file does not exist!");
           tsmain();
	   }
	   n= tjzs();
       if (n==0)
      {
	   
      printf("\nNo record exists!");
      }

	     fp=fopen("library.txt","r");//打开只读文件
	     printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies\tCopies of remain\n");
  
	   for (m=0;m<n;m++)//输出数据
	     {
	     fscanf(fp,"%s%s%s%s%d%d",num,nam,aut,year,&many,&manyofremain);
		 printf("%-8s%-40s%-40s%-8s%-8d%-8d\n",num,nam,aut,year,many,manyofremain);
	 	}
		fclose(fp);
        lmain();
}

	
void jmenu()//显示借书菜单
{
	printf("\n(logged in as: %s)\n",user); 
	printf("1)Borrow a book\n");
	printf("2)Return a book\n");
	printf("3)Search for books\n");
	printf("4)Display all books\n");
    printf("5)Log out\n");
	printf(" Option: ");
	return ;
}


void jmain()//借阅系统函数
{
	void js();
	void hs();
	void lljs();
	void cxjs();
	int a;
	char choose[1]={'\0'};
	jmenu();
	gets(choose);
	a=atoi(choose);
	
		switch(a)
		{
			case 1:
			js();
			break;
			case 2:
			hs();
			break;
			case 3:
			cxts();
			break;
			case 4:
			llts();
			break;
			case 5:
			printf("\nLogging out...\n");
			lmain();
			break;
		}
	

}



void js()//借书函数
{
	FILE *fp,*fp3;
	struct book *head=NULL;
    struct book *p,*p1,*p2;
    int i,loop,k,flag=0,s=0;
    int m=0,n=0;
    char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
	char jnum[20]={'\0'};
	int many=0,manyofremain=0;
	char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tyear[20]={'\0'},tshuhao[20]={'\0'},
         ttname[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},znum[20]={'\0'};
    char num1[20]={'\0'},nam1[20]={'\0'},aut1[20]={'\0'},year1[20]={'\0'};
	char hit=0;

	 
	if((fp=fopen("library.txt","r"))==NULL)
	{
		 
		printf("\n No books in the library!");
		exit(0);
	}
	else
	{
        printf("\nEnter the ID number of the book you wish to borrow:");
		scanf("%s",znum);
    k=tjzs();//统计图书馆文件个数
	for (i=0;i<k;i++)//先将图书信息建立链表，更改库存
    	{
    		fscanf(fp,"%s%s%s%s%d%d",tshuhao,tname,tauthor,tyear,&many,&manyofremain);
			n++;
			if(n==1)
			{
				p1=p2=(struct book*)malloc(LEN);
				head=p1;
			}
		    else
           	{
                p2->next=p1;
                p2=p1;
                p1=(struct book*)malloc(LEN);

            }
			strcpy(p1->num,tshuhao);//复制书号
			strcpy(p1->nam,tname);//复制书名
			strcpy(p1->aut,tauthor);//复制作者
			strcpy(p1->year,tyear);//复制年份
			p1->many=many;//复制现存量
			p1->manyofremain=manyofremain;//复制剩余量 
        }
        if(n==0)
 		head=NULL;
		else
		 {
		 	p2->next=p1;
		 	p1->next=NULL;
		 	fclose(fp);
		 }

	}
	p=head;
	
	for (;p!=NULL;)
	{
		if(!(strcmp(p->num,znum)))//判断要借书的是否存在，标记等于1，存在库存减一
		{
            flag=1;
		 	loop=p->manyofremain;
		 	(p->manyofremain)--;
		 }
			p=p->next;
  }
	if((flag==1)&&(loop>0))//存在被借的图书且现存量大于0，把库存量变化后的链表存入文件
    {

		fp=fopen("library.txt","w");
    	fclose(fp);
    	fp=fopen("library.txt","a");
    	p=head;

		for(;p !=NULL;)
    	{
    		fprintf(fp,"%-8s%-19s%-14s%-18s%-8d%-8d\n",p->num,p->nam,p->aut,p->year,p->many,p->manyofremain);
   		   	p=p->next;
		}
		free(p);
		fclose(fp);

		if ((fp3=fopen("reader.txt","r"))==NULL)//建读者文件夹存入借书信息
        {
		    fp3=fopen("reader.txt","w");//如果文件不存在则创建文件
            fclose(fp3);
        }
        
		fp3=fopen("reader.txt","r");
        fp=fopen("library.txt","r");
        
        for (n=0;n<k;n++)
        {
        	if(!strcmp(znum,num1))
            {
        	printf("Sorry, you already have a copy of this book on loan.\n");
        	goto exit;
		    }
			fscanf(fp3,"%s%s%s%s",num1,nam1,aut1,year1);
		}
		fclose(fp3);
		
		fp3=fopen("reader.txt","a");
        for (n=0;n<k;n++)
	    {
	    fscanf(fp,"%s%s%s%s",num,nam,aut,year);
        if(!strcmp(znum,num))
        {
			
			fprintf(fp3,"%-8s%-19s%-14s%-18s\n",num,nam,aut,year);
			printf("You have successfully borrowed the book!\n");
        }
        }
        
        fclose(fp);
	    fclose(fp3);
		exit:jmain();//调用借阅系统
   }
	else
    {
    	if(loop==0)
        printf("此书已被借完!");//否则输出此书已被借完
		if(flag==0)
		printf("查找无此书!");
	}
        jmain();//调用借阅系统

}


void hs ()//还书函数
{
 	 FILE *fp,*fp3;
	 struct reader *head=NULL;
	 struct reader *p,*p1,*p2;
	 struct book *lhead1=NULL;
	 struct book *zp1,*lp1,*lp2;
	 int txcl=0,tmany=0,i;
	 char tname[20]={'\0'},tauthor[20]={'\0'},tkind[20]={'\0'},
	 tchuban[20]={'\0'},ttname[20]={'\0'},tshuhao[20]={'\0'},ttnum[20]={'\0'},tnum[20]={'\0'};
	 int n=0,k=0,t=0,flag=0;
	 char ttitle[20]={'\0'},tyear[20]={'\0'};
	 char hitkey=0;
	 
     {
 	 if ((fp=fopen("reader.txt","r"))==NULL)//不存在读者文件，则输出不能还书
	  {
		 printf("\n 不存在借书者!按任意键退出!");
		 jmain();
      }

	  else
	  {{
	  	 lljs();
	     printf("\n请输入ID:\n请输入:");
		 scanf("%s",ttnum);//输入ID
		 k=tjdzzs();//获取读者文件夹信息个数
		 for(;!feof(fp);)//读取读者文件夹信息
           {
			fscanf(fp,"%s%s%s%s\n ",&tnum,ttitle,tauthor,tyear);
			if(!(strcmp(tnum,ttnum)))//如果ID存在，则标记为1
			flag=1;
			}
      fclose(fp);
	  fp=fopen("reader.txt","r");//打开读者文件，删除借书信息
	  if(flag)
	  {
	  for (i=0;i<k;i++)//将读者文件复制到链表
	  {
	  fscanf(fp,"%s%s%s%s\n ",&tnum,ttitle,tauthor,tyear);//读取文件信息
	  if(strcmp(ttnum,tnum)!=0)
	  {
          n++;
		  if (n==1)
		  {
		      p1=p2=(struct reader*)malloc(LEN1);//新建链表
			  head=p1;
		  }
		  else
		  {
		        p2->next=p1;
				p2=p1;
				p1=(struct reader*)malloc(LEN1);//新建链表
          }
		  strcpy(p1->jnum,tnum);//复制ID
		  strcpy(p1->jnam,ttitle);//复制书名 
		  strcpy(p1->time,tauthor);//复制作者 
		  strcpy(p1->tsnam,tyear);//复制日期 
		  }}
		  if (n==0)
		  head=NULL;
		  else
		  {
		       p2->next=p1;
			   p1->next=NULL;
			   fclose(fp);
	      }
		  fp=fopen("reader.txt","w");//清空读者文件
		  fclose(fp);
		  fp=fopen("reader.txt","a");//追加信息
		  p=head;
		  for (;p!=NULL;)//把链表内容覆盖读者文件
		  {
		      fprintf(fp,"\n%-8s%-23s%-18s%-10s\n",p->jnum,p->jnam,p->time,p->tsnam);
			  p=p->next;
	      }
		  free(p);
		  fclose(fp);
		  }}}}

		  if(flag==1)//标记为1，即还书时更改库存
		  {{
		  {
			  n=0;flag=0;
			  fp3=fopen("library.txt","r");//打开图书馆文件
			  k=tjzs();//获取图书馆文件个数
			  for (i=0;i<k;i++)//将图书馆文件复制到链表
			  {
			       fscanf(fp3,"%s%s%s%s%d%d",tshuhao,tname,tauthor,tyear,&tmany,&txcl);//读取信息
				   n++;
				   if (n==1)
				   {
				       lp1=lp2=(struct book*)malloc(LEN);//新建链表
					   lhead1=lp1;
				   }
				   else
				   {
				       lp2->next=lp1;
					   lp2=lp1;
					   lp1=(struct book*)malloc(LEN);//新建链表
				   }
				   strcpy(lp1->num,tshuhao);//复制书号
				   strcpy(lp1->nam,tname);//复制书名
				   strcpy(lp1->aut,tauthor);//复制作者
				   strcpy(lp1->year,tyear);//复制年份
				   lp1->many=tmany; //复制现存量
				   lp1->manyofremain=txcl;//复制剩余量 
				   }
				   if (n==0)
				   {
 	  		          lhead1=NULL;
				   }
				   else
				   {
				   	   lp2->next=lp1;
				   	   lp1->next=NULL;
				   	   fclose(fp3);
				   }}}
				   zp1=lhead1;
				   for (;zp1!=NULL;)
				   {
				        if(!(strcmp(zp1->num,ttnum)))//寻找书名相同
						++(zp1->manyofremain);//现存量加1
						zp1=zp1->next;
					}
					fp3=fopen("library.txt","w");//清空图书馆文件
					fclose(fp);
					fp3=fopen("library.txt","a");//追加信息
					zp1=lhead1;
					for (;zp1!=NULL;)//把链表内容覆盖图书馆文件
					{
                         fprintf(fp3,"%-8s%-9s%-14s%-18s%-8d%-8d\n",
        				 zp1->num,zp1->nam,zp1->aut,zp1->year,zp1->many,zp1->manyofremain);
						 zp1=zp1->next;
				    }
				    printf("成功！"); 
					fclose(fp3);
					jmain();//调用借阅系统
					}
					else
					printf("不存在此信息!按任意键返回!");
					getch();//返回
					jmain();//调用借阅系统
}


void lljs()//显示借书情况函数

{
    FILE *fp;
    int xcl=0,n=0,i=0,j=0;
    char zhenghao[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
	if ((fp=fopen("reader.txt","r"))==NULL)//打开读者文件夹
    {
         
        printf("\n记录文件不存在!按任意键返回");
	    jmain();
    }
    n=tjdzzs();
    if(n==0)
	{  
	printf("\n无任何记录!");
	}
	fp=fopen("reader.txt","r");
	 
	printf("\nID\tTitle\t\t\tAuthor\t\tYear\n");
	for (;!feof(fp);)//输出文件信息
	{
	fscanf(fp,"%s%s%s%s\n",zhenghao,mingzi,riqi,zname);
	printf("\n%-8s%-24s%-16s%-8s\n", zhenghao,mingzi,riqi,zname);
	}
	fclose(fp);
}
					
void cxjs()//查询借书
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
       

       char  jsnum[20]={'\0'},jsnam[20]={'\0'},jstime[20]={'\0'},tsnam[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("reader.txt","r"))==NULL)//打开文件
       {
	        
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
		   jmain();
       }
	    
       printf("请输入证号或姓名查询：\n");
       scanf("%s",chazhao);
        
	   m=tjzs();
	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s",jsnum,jsnam,jstime,tsnam);
        if(!strcmp(chazhao,jsnum))
        {
        	if(k==0)
            {
			  printf("查询结果:\n\n");
			  printf("\n证号\t读者姓名\t\t借书日期\t书名\n");
            }
			printf("\n%-8d%-23s%-18s%-10s\n",jsnum,jsnam,jstime,tsnam);
            k++;
         }
       }
	    if (k==0)//文件夹为空则输出无记录并返回上一层
        {  
        printf("\n无符合记录!\n");
        getch();
        jmain();
		}
       fclose(fp);//查询结束
		
		jmain();
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`

void lmenu()//显示登录菜单
{


printf("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
return ;
}


void lmain()//登录功能函数
{
	void land();
	void xinjian();
	int a;
	char choose[2]={'\0'};
	lmenu();
	gets(choose);
	a=atoi(choose);
	switch(a)//功能函数
  {
	  case 1:
	    xinjian();
	    break;
	  case 2:
	  	land();
	  	break;
	  case 3:
	  	cxts();
	  	break;
	  case 4:
	  	llts();
		break; 
	  case 5:
	  	printf("\nThank you for using the library!\n");
	  	printf("Goodbye!");
	  	exit(0);
	  default:
		printf("\nSorry, the option you entered was invalid, please try again.\n");
		lmain();
    getch();
  	exit(0);
	break;
  }
}


int match(char m[20],char a[20])//匹配数据库中的账号密码
{
	FILE*fp;
	int n=0,i=0;
	char zhanghao[20];
	char password[20];

	if ((fp=fopen("land.txt","r"))==NULL)//不存在读者文件
	  {
          
		 printf("\nPlease register an account!");
	 	 
		lmain();
	
      }


        for(;!feof(fp);)
      {
        fscanf(fp,"%s %s",&zhanghao,password);
        if((strcmp(m,"librarian")==0)&&(strcmp(a,"librarian")==0))
		{
			return 2;
		}
        if(strcmp(m,zhanghao)==0)
        {
        	if(strcmp(a,password)==0)
			return 1;
			else
			{
			return -1;
		   }
	    }
	    
	    
	  }
	  return 0;
 }


void xinjian()//新建账户密码
{
	FILE *fp;
	char m[20];
	char n[20];
	char zhanghao[20];
	char password[20];
	int i;
	if ((fp=fopen("land.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("land.txt","w");
      fclose(fp);
    }
	
	printf("Please enter your username: ");
	gets(zhanghao);
	printf("Please enter your password: ");
	gets(password);
	fp=fopen("land.txt","r");
	fscanf(fp,"%s %s",&m,n);
    if(match(zhanghao, password)==1||match(zhanghao, password)==2)
    {
        printf("Sorry, registration unsuccessful, the username you entered already exists.\n");
	}
	else
	{
		fp=fopen("land.txt","a");
		fprintf(fp,"%s %s\n",zhanghao,password);
        fclose(fp);
        printf("Registered library account successfully!");
	}
	
    lmain();
}


void land()//输入账户密码的登录函数
{
	char zhanghao[20];
	char password[20];
	int i=2,j,k,n;
	char hit=0;
	 
	
	printf("Please enter your username: ");
    gets(zhanghao);
    
	printf("Please enter your password: ");
	gets(password);
     i=match(zhanghao,password);
     if(i==1)
	 {
	   strcpy(user,zhanghao);
	   jmain();
	 }
	 if(i==2)
	 {
	   strcpy(user,zhanghao);
	   tsmain(); 
	 }
	 else
	 {
	 	if(i==-1)
		 {
		 printf("密码错误!");
		 getch();
         land();
		 }
		 if(i==0)
		 printf("不存在此用户");
		 getch();
		  
		 lmain();
	 }
}

void xg(int z,char m[20])//修改函数
{
	FILE *fp;
	int zhanghao1,n,j,k;
	char mima1[20];
	struct land *head,*p,*p1,*p2;

	 fp=fopen("land.txt","r");
	   j =tjzs3();

	   for (k=0;k<=j;k++)
       {
	       fscanf(fp,"%d %s",&zhanghao1,mima1);
           if (z!=zhanghao1)//比较名字，将不同名字的信息复制到链表
          {
	            n++;//相同返回值为0不执行if语句继续循环，不同则执行直到将所有不同的书名建立成链表
	            if (n==1)//建立链表
                {
		          p1=p2=(struct land*)malloc(LEN2);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN2);//新建链表
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);//复制账号密码
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else//建立链表的最后剩余一个储存空间，所以封底
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
			  fp=fopen("land.txt","w");//清空文件，只写打开，然后关闭
              fclose(fp);
              fp=fopen("land.txt","a");//追加文件
              p=head;
            for (;p!=NULL;)//把链表内容覆盖到文件
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
              

}



void xgmm()//修改密码
{

	   FILE *fp;
       int zh=0,k=0,many=0,m=0,n=0;
       int chazhao,hit;
       char mima[20]={'\0'},password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;

       if ((fp=fopen("land.txt","r"))==NULL)//打开文件
       {
	        
           printf("\n记录文件不存在!按任意键返回");
		   lmain();
       }
	    
       printf("请输入你的帐号和旧密码：\n");
       scanf("%d %s",&chazhao,mima);
	   m =tjzs3();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,mima))
        	{
        		printf("请输入新的密码");
        		scanf("%s",mima);
       		    printf("再次输入密码:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	   			 {
		             xg(chazhao,mima);
		            getch();
				    lmain();
	                 
   			     }
       			  else
	   			  {
	       		   	  printf("两次输入密码不一致,按任意键退出");
	       			  hit=getch();
		   			   
				      lmain();

   				  }
			}
			else
			{
				printf("旧密码错误，按任意键返回！");
				getch();
				 
				lmain();
	            
			}

        }
      }
	   printf("不存在此账号，按任意键返回");
		fclose(fp);//修改结束
		getch();
		 
		lmain();
}



int main()
{
	
	lmain();
	return 0;
}


