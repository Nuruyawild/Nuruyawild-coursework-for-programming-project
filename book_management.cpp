#include <stdio.h>
#include <stdlib.h>//���а���system����
#include <conio.h>//������ͨ������̨���� �������� ����������ĺ�������getch������
#include <string.h>//�����ַ�����
#include <math.h>
#include <ctype.h>
#define LEN sizeof(struct book)//�й�ͼ����Ϣ�Ľṹ��
#define LEN1 sizeof(struct reader)//�йض�����Ϣ�Ľṹ��
#define LEN2 sizeof(struct land)//�йص�¼ϵͳ�Ľṹ��


struct book//ͼ����Ϣ
{
	char num[20],nam[20],aut[20],year[20];
	int  many,manyofremain;
	struct book*next;
};

struct reader//���߽�����Ϣ
{
	char jnum[20];
	char jnam[20],time[20],tsnam[20];
	struct reader *next;
};
struct land//��¼��Ϣ
{
	int zhanghao;
	char password[20];
	struct land*next;
};



int tjzs();//ͳ��library�ı���������
void xg(int,char[] );
void mainmenu();//��ʾ���˵�
void tsmenu();//��ʾͼ����Ϣ�˵�
void jmenu();//��ʾ������Ϣ�˵�
void lmenu();//��ʾ��¼�˵�

void main1();// ���˵�����
void tsmain();//ͼ��˵�����
void cxts();//��ѯͼ��˵� 
void cxtsbyyear();//������ݲ�ѯͼ��
void cxtsbytitle();//���ձ����ѯͼ��
void cxtsbyauthor();//�������߲�ѯͼ�� 
void zjts();//����ͼ��
void scts();//ɾ��ͼ��
void llts();//���ͼ��

void jmain();//���߽�����Ϣ
void js();//����
void hs();//����
void cxjs();//��ѯ����
void lljs();// ����������

void land();//��¼����ϵͳ
int xinjian(int,char[] );//�����˺�����
void xgmm();//�޸�����
void lmain();//��¼���溯��
char user[20];//������ʾ�û���



int tjzs()//ͳ��ͼ���ı�����
{
FILE *fp;
int txcl=0,tmany=0,n;
char tname[20]={'\0'},tauthor[20]={'\0'},tchuban[20]={'\0'},tkind[20]={'\0'},tshuhao[20]={'\0'};
fp=fopen("library.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%s%s%s%s%d%d",tshuhao,tname,tauthor,tchuban,&tmany,&txcl);
n--;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}


int tjdzzs()//ͳ�ƽ�����߸�������

{
FILE *fp;
int n,i;
char zhenghao[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
fp=fopen("reader.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%s%s%s%s ",&zhenghao,&mingzi,&riqi,&zname);
i++;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}


int tjzs3()//ͳ���˺������ı�����
{
FILE *fp;
int zhao=0,n;
char mm[20]={'\0'};
fp=fopen("land.txt","r");//���ļ�
for (n=0;!feof(fp);n++)//������ļ�
fscanf(fp,"%d %s",&zhao,mm);
n--;
fclose(fp);//�ر��ļ�
return (n);//���ظ���
}


void mainmenu()//���˵�
{


printf("**************************************************");

printf("\n\n 1.ͼ��ϵͳ\n\n");

printf("\n\n 2.����ϵͳ\n\n");

printf("\n\n 3.�˳�ϵͳ\n\n");

printf("\n\n �밴��ѡ�񣬻س�ȷ��\n");

printf("*************************************************\n");

return ;
}


void tsmenu() //ͼ�����Ϣ�˵�
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
	switch(a)//���ܺ���
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


void zjts()//����ͼ��
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
     

    if ((fp=fopen("library.txt","r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
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
	tsmain();//������һ��
}

void scts()//ɾ��ͼ��
{
	   struct book *head=NULL;
       struct book *p,*p1,*p2;
       int tmany=0,tmanyofremain=0,n=0,j,k,q;
       char  tnam[20]={'\0'},taut[20]={'\0'},tyear[20]={'\0'},tnum[20]={'\0'};
       char  jnam[20]={'\0'},jaut[20]={'\0'},jyear[20]={'\0'},jnum[20]={'\0'};
	   char jjnum[20]={'\0'};
	   char i;
       FILE *fp,*fp3;
       if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
       {
           printf("\nThe record file does not exist!");
           tsmain();
       }

	   else//ʵ��ɾ���Ĺ���
	   {
	       
	      printf("\nPlease enter the book you wish to delete:");//����ɾ��ͼ������
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
           if (strcmp(jjnum,tnum))//�Ƚ�ID������ͬID����Ϣ���Ƶ�����
          {
	          n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
	            if (n==1)//��������
                {
		          p1=p2=(struct book*)malloc(LEN);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct book*)malloc(LEN);//�½�����
                }

                strcpy(p1->num,tnum);//�������
                strcpy(p1->nam,tnam);//��������
                strcpy(p1->aut,taut);//������������
                strcpy(p1->year,tyear);//�������
                p1->many=tmany;//���Ƹ���
                p1->manyofremain=tmanyofremain;//����ʣ����� 
           }
       }
             if (n==0)//���ͼ��ֻ��һ������һ��պú�Ҫɾ������ͬ
			 {
			 head=NULL;
			 }
			 else//������������ʣ��һ������ռ䣬���Է��
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
    }

   fp=fopen("library.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
   fclose(fp);
   fp=fopen("library.txt","a");//׷���ļ�
   p=head;

   for (;p!=NULL;)//���������ݸ��ǵ��ļ�
   {
   	   fprintf(fp,"%-8s%-9s%-14s%-18s%-8d%-8d\n",p->num,p->nam,p->aut,p->year,p->many,p->manyofremain);
   	   p=p->next;
   }
   fclose(fp);
   printf("\nDelete book successfully!");
   exit:tsmain();
}

void findbymenu()//Ŀ¼ϵͳ 
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
 
void cxts()//��ѯͼ��
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       findbymenu();
       funcoffindbymenu();
}

void cxtsbytitle()//���ձ����ѯͼ��
{
	   FILE *fp;
       int k=0,many=0,manyofremain=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
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
        if (k==0)//�ļ���Ϊ��������޼�¼��������һ��
        {  
        printf("\nThere is no matching item!\n");
        tsmain();
		}
		fclose(fp);//��ѯ����
		cxts();
}

void cxtsbyauthor()//�����߲�ѯͼ��
{
	   FILE *fp;
       int k=0,many=0,manyofremain=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
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
        if (k==0)//�ļ���Ϊ��������޼�¼��������һ��
        {  
        printf("\nThere is no matching item!\n");
        tsmain();
		}
		fclose(fp);//��ѯ����
		cxts();
}

void cxtsbyyear()//������ݲ�ѯͼ��
{
	   FILE *fp;
       int k=0,many=0,manyofremain=0,m=0,n=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
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
        if (k==0)//�ļ���Ϊ��������޼�¼��������һ��
        {  
        printf("\nThere is no matching item!\n");
        tsmain();
		}
		fclose(fp);//��ѯ����
		cxts();
}


void llts()//���ͼ��
{
	FILE *fp;
	int n=0;
       int k=0,m=0,many=0,manyofremain=0;
       char  nam[20]={'\0'},aut[20]={'\0'},year[20]={'\0'},num[20]={'\0'};
  	   char i;
	   if ((fp=fopen("library.txt","r"))==NULL)//���ļ�
       {
	        
           printf("\nRecord file does not exist!");
           tsmain();
	   }
	   n= tjzs();
       if (n==0)
      {
	   
      printf("\nNo record exists!");
      }

	     fp=fopen("library.txt","r");//��ֻ���ļ�
	     printf("\nID\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies\tCopies of remain\n");
  
	   for (m=0;m<n;m++)//�������
	     {
	     fscanf(fp,"%s%s%s%s%d%d",num,nam,aut,year,&many,&manyofremain);
		 printf("%-8s%-40s%-40s%-8s%-8d%-8d\n",num,nam,aut,year,many,manyofremain);
	 	}
		fclose(fp);
        lmain();
}

	
void jmenu()//��ʾ����˵�
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


void jmain()//����ϵͳ����
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



void js()//���麯��
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
    k=tjzs();//ͳ��ͼ����ļ�����
	for (i=0;i<k;i++)//�Ƚ�ͼ����Ϣ�����������Ŀ��
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
			strcpy(p1->num,tshuhao);//�������
			strcpy(p1->nam,tname);//��������
			strcpy(p1->aut,tauthor);//��������
			strcpy(p1->year,tyear);//�������
			p1->many=many;//�����ִ���
			p1->manyofremain=manyofremain;//����ʣ���� 
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
		if(!(strcmp(p->num,znum)))//�ж�Ҫ������Ƿ���ڣ���ǵ���1�����ڿ���һ
		{
            flag=1;
		 	loop=p->manyofremain;
		 	(p->manyofremain)--;
		 }
			p=p->next;
  }
	if((flag==1)&&(loop>0))//���ڱ����ͼ�����ִ�������0���ѿ�����仯�����������ļ�
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

		if ((fp3=fopen("reader.txt","r"))==NULL)//�������ļ��д��������Ϣ
        {
		    fp3=fopen("reader.txt","w");//����ļ��������򴴽��ļ�
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
		exit:jmain();//���ý���ϵͳ
   }
	else
    {
    	if(loop==0)
        printf("�����ѱ�����!");//������������ѱ�����
		if(flag==0)
		printf("�����޴���!");
	}
        jmain();//���ý���ϵͳ

}


void hs ()//���麯��
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
 	 if ((fp=fopen("reader.txt","r"))==NULL)//�����ڶ����ļ�����������ܻ���
	  {
		 printf("\n �����ڽ�����!��������˳�!");
		 jmain();
      }

	  else
	  {{
	  	 lljs();
	     printf("\n������ID:\n������:");
		 scanf("%s",ttnum);//����ID
		 k=tjdzzs();//��ȡ�����ļ�����Ϣ����
		 for(;!feof(fp);)//��ȡ�����ļ�����Ϣ
           {
			fscanf(fp,"%s%s%s%s\n ",&tnum,ttitle,tauthor,tyear);
			if(!(strcmp(tnum,ttnum)))//���ID���ڣ�����Ϊ1
			flag=1;
			}
      fclose(fp);
	  fp=fopen("reader.txt","r");//�򿪶����ļ���ɾ��������Ϣ
	  if(flag)
	  {
	  for (i=0;i<k;i++)//�������ļ����Ƶ�����
	  {
	  fscanf(fp,"%s%s%s%s\n ",&tnum,ttitle,tauthor,tyear);//��ȡ�ļ���Ϣ
	  if(strcmp(ttnum,tnum)!=0)
	  {
          n++;
		  if (n==1)
		  {
		      p1=p2=(struct reader*)malloc(LEN1);//�½�����
			  head=p1;
		  }
		  else
		  {
		        p2->next=p1;
				p2=p1;
				p1=(struct reader*)malloc(LEN1);//�½�����
          }
		  strcpy(p1->jnum,tnum);//����ID
		  strcpy(p1->jnam,ttitle);//�������� 
		  strcpy(p1->time,tauthor);//�������� 
		  strcpy(p1->tsnam,tyear);//�������� 
		  }}
		  if (n==0)
		  head=NULL;
		  else
		  {
		       p2->next=p1;
			   p1->next=NULL;
			   fclose(fp);
	      }
		  fp=fopen("reader.txt","w");//��ն����ļ�
		  fclose(fp);
		  fp=fopen("reader.txt","a");//׷����Ϣ
		  p=head;
		  for (;p!=NULL;)//���������ݸ��Ƕ����ļ�
		  {
		      fprintf(fp,"\n%-8s%-23s%-18s%-10s\n",p->jnum,p->jnam,p->time,p->tsnam);
			  p=p->next;
	      }
		  free(p);
		  fclose(fp);
		  }}}}

		  if(flag==1)//���Ϊ1��������ʱ���Ŀ��
		  {{
		  {
			  n=0;flag=0;
			  fp3=fopen("library.txt","r");//��ͼ����ļ�
			  k=tjzs();//��ȡͼ����ļ�����
			  for (i=0;i<k;i++)//��ͼ����ļ����Ƶ�����
			  {
			       fscanf(fp3,"%s%s%s%s%d%d",tshuhao,tname,tauthor,tyear,&tmany,&txcl);//��ȡ��Ϣ
				   n++;
				   if (n==1)
				   {
				       lp1=lp2=(struct book*)malloc(LEN);//�½�����
					   lhead1=lp1;
				   }
				   else
				   {
				       lp2->next=lp1;
					   lp2=lp1;
					   lp1=(struct book*)malloc(LEN);//�½�����
				   }
				   strcpy(lp1->num,tshuhao);//�������
				   strcpy(lp1->nam,tname);//��������
				   strcpy(lp1->aut,tauthor);//��������
				   strcpy(lp1->year,tyear);//�������
				   lp1->many=tmany; //�����ִ���
				   lp1->manyofremain=txcl;//����ʣ���� 
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
				        if(!(strcmp(zp1->num,ttnum)))//Ѱ��������ͬ
						++(zp1->manyofremain);//�ִ�����1
						zp1=zp1->next;
					}
					fp3=fopen("library.txt","w");//���ͼ����ļ�
					fclose(fp);
					fp3=fopen("library.txt","a");//׷����Ϣ
					zp1=lhead1;
					for (;zp1!=NULL;)//���������ݸ���ͼ����ļ�
					{
                         fprintf(fp3,"%-8s%-9s%-14s%-18s%-8d%-8d\n",
        				 zp1->num,zp1->nam,zp1->aut,zp1->year,zp1->many,zp1->manyofremain);
						 zp1=zp1->next;
				    }
				    printf("�ɹ���"); 
					fclose(fp3);
					jmain();//���ý���ϵͳ
					}
					else
					printf("�����ڴ���Ϣ!�����������!");
					getch();//����
					jmain();//���ý���ϵͳ
}


void lljs()//��ʾ�����������

{
    FILE *fp;
    int xcl=0,n=0,i=0,j=0;
    char zhenghao[20]={'\0'},mingzi[20]={'\0'},riqi[20]={'\0'},zname[20]={'\0'};
	if ((fp=fopen("reader.txt","r"))==NULL)//�򿪶����ļ���
    {
         
        printf("\n��¼�ļ�������!�����������");
	    jmain();
    }
    n=tjdzzs();
    if(n==0)
	{  
	printf("\n���κμ�¼!");
	}
	fp=fopen("reader.txt","r");
	 
	printf("\nID\tTitle\t\t\tAuthor\t\tYear\n");
	for (;!feof(fp);)//����ļ���Ϣ
	{
	fscanf(fp,"%s%s%s%s\n",zhenghao,mingzi,riqi,zname);
	printf("\n%-8s%-24s%-16s%-8s\n", zhenghao,mingzi,riqi,zname);
	}
	fclose(fp);
}
					
void cxjs()//��ѯ����
{
	   FILE *fp;
       int k=0,many=0,m=0,n=0;
       

       char  jsnum[20]={'\0'},jsnam[20]={'\0'},jstime[20]={'\0'},tsnam[20]={'\0'};
       char i;
       char chazhao[20]={'\0'};
       if ((fp=fopen("reader.txt","r"))==NULL)//���ļ�
       {
	        
           printf("\n��¼�ļ�������!�����������");
  		   getch();
		   jmain();
       }
	    
       printf("������֤�Ż�������ѯ��\n");
       scanf("%s",chazhao);
        
	   m=tjzs();
	   for (n=0;n<m;n++)
	   {
	    fscanf(fp,"%s%s%s%s",jsnum,jsnam,jstime,tsnam);
        if(!strcmp(chazhao,jsnum))
        {
        	if(k==0)
            {
			  printf("��ѯ���:\n\n");
			  printf("\n֤��\t��������\t\t��������\t����\n");
            }
			printf("\n%-8d%-23s%-18s%-10s\n",jsnum,jsnam,jstime,tsnam);
            k++;
         }
       }
	    if (k==0)//�ļ���Ϊ��������޼�¼��������һ��
        {  
        printf("\n�޷��ϼ�¼!\n");
        getch();
        jmain();
		}
       fclose(fp);//��ѯ����
		
		jmain();
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`

void lmenu()//��ʾ��¼�˵�
{


printf("\nPlease choose an option:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\nOption: ");
return ;
}


void lmain()//��¼���ܺ���
{
	void land();
	void xinjian();
	int a;
	char choose[2]={'\0'};
	lmenu();
	gets(choose);
	a=atoi(choose);
	switch(a)//���ܺ���
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


int match(char m[20],char a[20])//ƥ�����ݿ��е��˺�����
{
	FILE*fp;
	int n=0,i=0;
	char zhanghao[20];
	char password[20];

	if ((fp=fopen("land.txt","r"))==NULL)//�����ڶ����ļ�
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


void xinjian()//�½��˻�����
{
	FILE *fp;
	char m[20];
	char n[20];
	char zhanghao[20];
	char password[20];
	int i;
	if ((fp=fopen("land.txt","r"))==NULL)//if��䣺��ͼ����ļ��������ڴ��ļ����½�
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


void land()//�����˻�����ĵ�¼����
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
		 printf("�������!");
		 getch();
         land();
		 }
		 if(i==0)
		 printf("�����ڴ��û�");
		 getch();
		  
		 lmain();
	 }
}

void xg(int z,char m[20])//�޸ĺ���
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
           if (z!=zhanghao1)//�Ƚ����֣�����ͬ���ֵ���Ϣ���Ƶ�����
          {
	            n++;//��ͬ����ֵΪ0��ִ��if������ѭ������ͬ��ִ��ֱ�������в�ͬ����������������
	            if (n==1)//��������
                {
		          p1=p2=(struct land*)malloc(LEN2);
                  head=p1;
				}
                else
			    {
			      p2->next=p1;
				  p2=p1;
                  p1=(struct land*)malloc(LEN2);//�½�����
                }
 				p1->zhanghao=zhanghao1;
                strcpy(p1->password,mima1);//�����˺�����
          }
       }
        if (n==0)
			 {
			 head=NULL;
			 }
			 else//������������ʣ��һ������ռ䣬���Է��
			 {
			 p2->next=p1;
			 p1->next=NULL;
			 fclose(fp);
			 }
			  fp=fopen("land.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
              fclose(fp);
              fp=fopen("land.txt","a");//׷���ļ�
              p=head;
            for (;p!=NULL;)//���������ݸ��ǵ��ļ�
   			{
   	   		 	fprintf(fp,"%d %s%\n",p->zhanghao,p->password);
   	   			p=p->next;
	        }
	        fprintf(fp,"%d %s\n",z,m);
            fclose(fp);
              

}



void xgmm()//�޸�����
{

	   FILE *fp;
       int zh=0,k=0,many=0,m=0,n=0;
       int chazhao,hit;
       char mima[20]={'\0'},password1[20]={'\0'};
       char  mm[20]={'\0'};
       char i;

       if ((fp=fopen("land.txt","r"))==NULL)//���ļ�
       {
	        
           printf("\n��¼�ļ�������!�����������");
		   lmain();
       }
	    
       printf("����������ʺź;����룺\n");
       scanf("%d %s",&chazhao,mima);
	   m =tjzs3();
	   for (n=0;n<=m;n++)
	   {
	    fscanf(fp,"%d %s",&zh,mm);
        if(zh==chazhao)
        {
        	if(!strcmp(mm,mima))
        	{
        		printf("�������µ�����");
        		scanf("%s",mima);
       		    printf("�ٴ���������:\n");
	            scanf("%s",password1);
	             if(strcmp(mima,password1)==0)
	   			 {
		             xg(chazhao,mima);
		            getch();
				    lmain();
	                 
   			     }
       			  else
	   			  {
	       		   	  printf("�����������벻һ��,��������˳�");
	       			  hit=getch();
		   			   
				      lmain();

   				  }
			}
			else
			{
				printf("��������󣬰���������أ�");
				getch();
				 
				lmain();
	            
			}

        }
      }
	   printf("�����ڴ��˺ţ������������");
		fclose(fp);//�޸Ľ���
		getch();
		 
		lmain();
}



int main()
{
	
	lmain();
	return 0;
}


