#include <stdio.h>
#include <stdlib.h>//其中包含system函数
#include <conio.h>//定义了通过控制台进行 数据输入 和数据输出的函数，如getch函数。
#include <string.h>//定义字符数组
#include <math.h>
#define LEN sizeof(struct book)//有关图书信息的结构体
#define LEN1 sizeof(struct reader)//有关读者信息的结构体
#define LEN2 sizeof(struct land)//有关登录系统的结构体


struct book//图书信息
{
	char num[20],nam[20],aut[20],pub[20],cat[20];
	int  many;
	float price;
	struct book*next;
};

struct reader//读者借阅信息
{
	int jnum;
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
void cxts();//查询图书
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


int tjzs()//统计图书文本个数
{
FILE *fp;
int txcl=0,n;
float tprice=0;
char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%s%s%s%s%s%d%f",tshuhao,tname,tauthor,tchuban,tkind,&txcl,&tprice);
n--;
fclose(fp);//关闭文件
return (n);//返回个数
}


int tjdzzs()//统计文读者本个数函数

{
FILE *fp;
int zhenghao=0,n;
char mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
fp=fopen("reader.txt","r");//打开文件
for (n=0;!feof(fp);n++)//逐个读文件
fscanf(fp,"%d%s%s%s ",&zhenghao,&mingzi,&riqi,&zname);
n--;
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
system ("cls");

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
system ("cls");

printf("****************************************************");

printf("\n 1.增加图书\n\n");

printf("\n 2.删除图书\n\n");

printf("\n 3.查询图书\n\n");

printf("\n 4.库存浏览\n\n");

printf("\n 5.返回上一层\n\n");

printf("\n 请按键选择，回车确定\n");

printf("***************************************************\n");

return ;

}


void main1()
{
	void tsmian();
	void jmain();
	char choose;
	mainmenu();
	scanf(" %c",&choose);
	switch(choose)//功能函数
  {
	  case'1':
	    tsmain();
	    break;
	  case'2':
	  	jmain();
	  	break;
	  case'3':
	  	system("cls");
    getch();
  	exit(0);
  	system ("cls");
	break;
  }
}


void tsmain()
{
	void zjts();
	void scts();
	void ctts();
	void llts();
	char choose;
	tsmenu();
	scanf(" %c",&choose);
	for(;;)
	{
		switch(choose)
	{
	case'1':
		zjts();
		break;
	case'2':
		scts();
		break;
	case'3':
		cxts();
		break;
	case'4':
		llts();
		break;
	case'5':
		main1();
		break;
	}
    }
}


void zjts()//增加图书
{
	FILE*fp;
	char i;
	int many=0;
    float price=0;
    char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
    system ("cls");

    if ((fp=fopen("library.txt","r"))==NULL)//if语句：打开图书馆文件，不存在此文件则新建
	{
      fp=fopen("library.txt","w");
      fclose(fp);
    }
	fp=fopen("library.txt","a");
	
	printf("\n请按以下格式输入图书信息:\n书号 书名 作者 出版社 类别 进库量 单价");
	
	for(;i!=27;)//为了实现输入一次后按esc退出
	{
		printf("请输入:\n");
		scanf("%s%s%s%s%s%d%f",num,nam,aut,pub,cat,&many,&price);
		fprintf(fp,"%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",num,nam,aut,pub,cat,many,price);
	    printf("继续输入请按回车，结束输入请按Esc\n");
        i=getch();//暂停程序当i接收后继续下一条指令
        for (;i!=13&&i!=27;)//保证只能是CR和ESC才能退出循环,输入其他字符无用，暂停程序，按'CR'继续。
        i=getch();
     }

	fclose(fp);
    printf("\n保存成功，按任意键返回上一层!");
    getch();
	tsmain();//返回上一层
}

void scts()//删除图书
{
	   struct book *head=NULL;
       struct book *p,*p1,*p2;
       int tmany=0,n=0,j,k;
       float tprice=0;
       char  tnam[20]={'\0'},taut[20]={'\0'},tcat[20]={'\0'},tpub[20]={'\0'},tnum[20]={'\0'};
	   char jjnam[20]={'\0'};
	   char i;
       FILE *fp;
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
           getch();
           tsmain();
       }

	   else//实现删除的功能
	   {
	      system ("cls");
	      printf("\n请输入你要删除的书名:");//输入删除图书书名
          scanf("%s",jjnam);
          printf("\n确认删除请回车，取消请按Esc\n");
          i=getch();
          for(;i!=13&&i!=27;)
          i=getch();
          if (i==27)
          tsmain();
	      fp=fopen("library.txt","r");
		 j=tjzs();

	   for (k=0;k<j;k++)
       {
	       fscanf(fp,"%s%s%s%s%s%d%f",tnum,tnam,taut,tpub,tcat,&tmany,&tprice);
           if (strcmp(jjnam,tnam))//比较名字，将不同名字的信息复制到链表
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
                strcpy(p1->pub,tpub);//复制出版社
                strcpy(p1->cat,tcat);//复制类别
                p1->many=tmany;//复制个数
                p1->price=tprice;//复制单价
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
   	   fprintf(fp,"%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",p->num,p->nam,p->aut,p->pub,p->cat,p->many,p->price);
   	   p=p->next;
   }
   fclose(fp);
   system ("cls");
   printf("\n删除成功 \n按任意键返回上一层\n");
   getch();//返回上一层
   tsmain();
}


void cxts()//查询图书
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
	   float price=0;
       char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
		   tsmain();
       }
	   system("cls");
       printf("请输入书号,书名,作者或类别查询：\n");
       scanf("%s",chazhao);
       system ("cls");
       m=tjzs();

	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s%s%d%f",num,nam,aut,pub,cat,&many,&price);
        if(!strcmp(chazhao,num)||!strcmp(chazhao,nam)||!strcmp(chazhao,aut)||!strcmp(chazhao,cat))
        {
        	if(k==0)
            {
			  printf("查询结果:\n\n");
			  printf("书号\t书名\t作者\t\t出版社\t\t类别\t\t现存量\t单价\n");
            }
			printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",num,nam,aut,pub,cat,many,price);
            k++;
        }
       }
        if (k==0)//文件夹为空则输出无记录并返回上一层
        { system ("cls");
        printf("\n无符合记录!\n");
        getch();
        tsmain();
		}
		fclose(fp);//查询结束
		getch();
		tsmain();
}


void llts()//浏览图书
{
	FILE *fp;
	int n=0;
       int k=0,m=0,many=0;
	   float price=0;
       char  nam[20]={'\0'},aut[20]={'\0'},cat[20]={'\0'},pub[20]={'\0'},num[20]={'\0'};
  	   char i;
	   if ((fp=fopen("library.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
		   getch();//返回
           tsmain();
	   }
	   n= tjzs();
       if (n==0)
      {
	  system ("cls");
      printf("\n无任何记录!");
      }

	     fp=fopen("library.txt","r");//打开只读文件
         system ("cls");
	     printf("书号\t书名\t作者\t\t出版社\t\t类别\t\t库存量\t单价\n");
  
	   for (m=0;m<n;m++)//输出数据
	     {
	     fscanf(fp,"%s%s%s%s%s%d%f",num,nam,aut,pub,cat,&many,&price);
		 printf("%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",num,nam,aut,pub,cat,many,price);
	 	}
		fclose(fp);
        printf("\n按任意键返回\n");
        getch();
        tsmain();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`!~~~~~~~~~~~~~~~~~~~~~
	
void jmenu()//显示借书菜单
{
	system("cls");
	printf("*****************************************************");
	printf("\n\n 1.借书登记\n\n");
	printf("\n\n 2.还书登记\n\n");
	printf("\n\n 3.借阅情况查看\n\n");
	printf("\n\n 4.查询借书\n\n");
    printf("\n\n 5.返回上一层\n\n");
	printf("\n\n 请按键选择，回车确定\n");
	printf("****************************************************");
	return ;
}


void jmain()//借阅系统函数
{
	void js();
	void hs();
	void lljs();
	void cxjs();
	char choose;
	jmenu();
	scanf(" %c",&choose);
	for(;;)
	{
		switch(choose)
		{
			case'1':
			js();
			break;
			case'2':
			hs();
			break;
			case'3':
			lljs();
			break;
			case'4':
			cxjs();
			break;
			case'5':
			main1();
			break;
		}
	}

}



void js()//借书函数
{
	FILE *fp,*fp3;
	struct book *head=NULL;
    struct book *p,*p1,*p2;
    int i,loop,k,n=0,flag=0,s=0;
	int jnum=0;
	int many=0;
	float tprice=0;
	char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'},
         ttname[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
	char hit=0;

	system("cls");
	if((fp=fopen("library.txt","r"))==NULL)
	{
		system("cls");
		printf("\n 图书馆无库存!按任意键退出!");
		getch();
		exit(0);
	}
	else
	{
        printf("\n请输入借阅书名:\n请输入:");
		scanf("%s",zname);
    k= tjzs();//统计图书馆文件个数

	for (i=0;i<k;i++)//先将图书信息建立链表，更改库存
    	{
    		fscanf(fp,"%s%s%s%s%s%d%f",tshuhao,tname,tauthor,tchuban,tkind,&many,&tprice);
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
			strcpy(p1->pub,tchuban);//复制出版社
			strcpy(p1->cat,tkind);//复制类别
			p1->many=many;//复制现存量
			p1->price=tprice;//复制单价
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
		if(!(strcmp(p->nam,zname)))//判断要借书的是否存在，标记等于1，存在库存减一
		{
			
            flag=1;
		 	loop=p->many;
		 	(p->many)--;
		 }
			p=p->next;
  }
	if(flag&&(loop>0))//存在被借的图书且现存量大于0，把库存量变化后的链表存入文件
    {

		fp=fopen("library.txt","w");
    	fclose(fp);
    	fp=fopen("library.txt","a");
    	p=head;

		for(;p !=NULL;)
    	{
    		fprintf(fp,"%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",p->num,p->nam,p->aut,p->pub,p->cat,p->many,p->price);
   		   	p=p->next;
		}
		free(p);
		fclose(fp);

		if ((fp3=fopen("reader.txt","r"))==NULL)//建读者文件夹存入借书信息
        {
		    fp3=fopen("reader.txt","w");//打开只读文件
            fclose(fp3);
        }
		fp3=fopen("reader.txt","a");

		printf("\n请按以下格式输入读者信息:\n 证号 姓名 借书日期 借书书名\n请输入:");//录入读者信息
 		scanf("%d %s %s %s",&jnum,mingzi,riqi,zname);
		fprintf(fp3,"\n%-8d%-23s%-18s%-10s\n",jnum,mingzi,riqi,zname);
	    fclose(fp3);
        printf("借书成功!请两个月内归还！！！按任意键返回\n");
		getch();//返回
		jmain();//调用借阅系统
   }
	else
    {
    	if(flag!=0)
        printf("此书已被借完!按任意键返回!");//否则输出此书已被借完
		else
		printf("查找无此书!按任意键返回");
	}
	    getch();//返回
        jmain();//调用借阅系统

}


void hs ()//还书函数
{
 	 FILE *fp,*fp3;
	 struct reader *head=NULL;
	 struct reader *p,*p1,*p2;
	 struct book *lhead1=NULL;
	 struct book *zp1,*lp1,*lp2;
	 int txcl=0,i;
	 float tprice=0;
	 char tname[20]={'\0'},tauthor[20]={'\0'},tkind[20]={'\0'},
	 tchuban[20]={'\0'},ttname[20]={'\0'},tshuhao[20]={'\0'};
	 int ttzhenghao=0,tzhenghao=0,n=0,k=0,t=0,flag=0;
	 char tmingzi[20]={'\0'},triqi[20]={'\0'},tzname[20]={'\0'},ttzname[20]={'\0'};
	 char hitkey=0;
	 system ("cls");
{
 	 if ((fp=fopen("reader.txt","r"))==NULL)//不存在读者文件，则输出不能还书
	  {
         system ("cls");
		 printf("\n 不存在借书者!按任意键退出!");
		 getch();
		 system("cls");
		 jmain();
      }

	  else
	  {{
	     printf("\n请输入读者证号和书名:\n请输入:");
		 scanf("%d %s",&ttzhenghao,ttzname);//输入还书证号和书名
		 k=tjdzzs();//获取读者文件夹信息个数
		 for (i=0;i<k;i++)//读取读者文件夹信息
           {
			fscanf(fp,"%d%s%s%s\n ",&tzhenghao,tmingzi,triqi,tzname);
			if((ttzhenghao==tzhenghao)&&!strcmp(ttzname,tzname))//如果证号书名存在，则标记为1
			flag=1;
			}
      fclose(fp);
	  fp=fopen("reader.txt","r");//打开读者文件，删除借书信息
	  if(flag)
	  {
	  for (i=0;i<k;i++)//将读者文件复制到链表
	  {
	  fscanf(fp,"%d%s%s%s\n ",&tzhenghao,tmingzi,triqi,tzname);//读取文件信息
	  if(!((ttzhenghao==tzhenghao)&&!strcmp(ttzname,tzname)))
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
		  p1->jnum=tzhenghao;//复制证号
		  strcpy(p1->jnam,tmingzi);//复制读者名字
		  strcpy(p1->time,triqi);//复制日
		  strcpy(p1->tsnam,tzname);//复制书名
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
		      fprintf(fp,"\n%-8d%-23s%-18s%-10s\n",p->jnum,p->jnam,p->time,p->tsnam);
			  p=p->next;
	      }
		  free(p);
		  fclose(fp);
		  }}}}

		  if(flag)//标记为1，即还书时更改库存
		  {{
		  {
		      printf("确认还书请按回车!");
			  for (;hitkey!=13&&hitkey!=27;)
			  hitkey=getch();
			  if (hitkey==13)
			  printf("成功!按任意键返回!");
			  n=0;flag=0;
			  fp3=fopen("library.txt","r");//打开图书馆文件
			  k=tjzs();//获取图书馆文件个数
			  for (i=0;i<k;i++)//将图书馆文件复制到链表
			  {
			       fscanf(fp3,"%s%s%s%s%s%d%f",tshuhao,tname,tauthor,tchuban,tkind,&txcl,&tprice);//读取信息
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
				   strcpy(lp1->pub,tchuban);//复制出版社
				   strcpy(lp1->cat,tkind);//复制类别
				   lp1->many=txcl; //复制现存量
				   lp1->price=tprice;//复制单价
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
				        if(!(strcmp(zp1->nam,ttzname)))//寻找书名相同
						++(zp1->many);//现存量加1
						zp1=zp1->next;
					}
					fp3=fopen("library.txt","w");//清空图书馆文件
					fclose(fp);
					fp3=fopen("library.txt","a");//追加信息
					zp1=lhead1;
					for (;zp1!=NULL;)//把链表内容覆盖图书馆文件
					{
                         fprintf(fp3,"%-8s%-9s%-14s%-16s%-18s%-7d%-8.2f\n",
        				 zp1->num,zp1->nam,zp1->aut,zp1->pub,zp1->cat,zp1->many,zp1->price);
						 zp1=zp1->next;
				    }
					fclose(fp3);
					getch();//返回
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
    int zhenghao=0,xcl=0,n=0,i=0,j=0;
    char mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
	if ((fp=fopen("reader.txt","r"))==NULL)//打开读者文件夹
    {
        system ("cls");
        printf("\n记录文件不存在!按任意键返回");
	    getch();
	    jmain();
    }
    n=tjdzzs();
    if (n==0)
	{ system ("cls");
	printf("\n无任何记录!");
	}
	fp=fopen("reader.txt","r");
	system ("cls");
	printf("\n证号\t读者姓名\t\t借书日期\t书名\n");
	for (;!feof(fp);)//输出文件信息
	{
	fscanf(fp,"%d%s%s%s\n ",&zhenghao,mingzi,riqi,zname);
	printf("\n%-8d%-23s%-18s%-10s\n", zhenghao,mingzi,riqi,zname);
	}
	fclose(fp);
	printf("\n按任意键返回\n");
	getch();//返回
	jmain();//调用借阅系统
}

					
void cxjs()//查询借书
{
	   FILE *fp;
       int jsnum=0,k=0,many=0,m=0,n=0;

       char  jsnam[20]={'\0'},jstime[20]={'\0'},tsnam[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("reader.txt","r"))==NULL)//打开文件
       {
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
		   jmain();
       }
	   system("cls");
       printf("请输入证号或姓名查询：\n");
       scanf("%s",chazhao);
       system ("cls");
	   m=tjzs();
	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%d%s%s%s",&jsnum,jsnam,jstime,tsnam);
        if(!strcmp(chazhao,jsnam)||(('chazhao'-'0')==jsnum))
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
        { system ("cls");
        printf("\n无符合记录!\n");
        getch();
        jmain();
		}
       fclose(fp);//查询结束
		getch();
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
	char choose;
	lmenu();
	scanf(" %c",&choose);
	switch(choose)//功能函数
  {
	  case'1':
	    xinjian();
	    break;
	  case'2':
	  	land();
	  	break;
	  case'3':
	  	cxts();
	  	break;
	  case'4':
	  	llts();
		break; 
	  default:
		printf("Sorry, that doesn't seem to be an option\n");
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
         system ("cls");
		 printf("\n 还未存在用户!请新建账户");
		 getch();
	 	system("cls");
		lmain();
	
      }


        for(;!feof(fp);)
      {
        fscanf(fp,"%s %s",&zhanghao,password);
        if(strcmp(m,zhanghao)==0)
        {
        	if(strcmp(a,password)==0)
			return 1;
			else
			{
			return -1;
		   }
	    }
	    if((strcmp(m,"librarian")==0)&&(strcmp(a,"librarian")==0))
		{
			return 2;
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
	scanf("%s",&zhanghao);
	printf("Please enter your password: ");
	scanf("%s",&password);
	fp=fopen("land.txt","r");
	fscanf(fp,"%s %s",&m,n);
    if(match(zhanghao, password)==1)
    {
        printf("Sorry, registration unsuccessful, the username you entered already exists.\n");
	}
	else
	{
		fp=fopen("land.txt","a");
		fprintf(fp,"%s %s\n",zhanghao,password);
        fclose(fp);
        printf("创建成功");
	}
	
    lmain();
}


void land()//输入账户密码的登录函数
{
	char zhanghao[20];
	char password[20];
	int i=2,j,k,n;
	char hit=0;
	system("cls");
	do
	{
	   printf("\n请输入账号:\n");
       scanf("%s",&zhanghao);
    }
    while(hit==27);
	 printf("\n请输入密码:\n");
	 scanf("%s",password);
     i=match(zhanghao,password);
     if(i==1)
	 {
       printf("登陆成功!按任意键继续");
	   getch();
	   main1();
	 }
	 if(i==2)
	 {
       printf("登陆成功!");
	   getch();
	   main1();
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
		 system("cls");
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
             system ("cls");

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
	       system ("cls");
           printf("\n记录文件不存在!按任意键返回");
  		   getch();
  		   system("cls");
		   lmain();
       }
	   system("cls");
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
	                system("cls");
   			     }
       			  else
	   			  {
	       		   	  printf("两次输入密码不一致,按任意键退出");
	       			  hit=getch();
		   			  system("cls");
				      lmain();

   				  }
			}
			else
			{
				printf("旧密码错误，按任意键返回！");
				getch();
				system("cls");
				lmain();
	            
			}

        }
      }
	   printf("不存在此账号，按任意键返回");
		fclose(fp);//修改结束
		getch();
		system("cls");
		lmain();
}



int main()
{
	
	lmain();
	return 0;
}


