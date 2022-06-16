#include<stdio.h>
#include<stdlib.h>

struct Account
{
	char username[100];
	char password[100];	
	
	struct Account * next;
};
typedef struct Account Account;

struct Account
{
	char name[100];//姓名 
	char tel[12];//电话 
	char idCard[19];//身份证	
	char username[20];//银行账号卡号
	char password[7];//密码 
	float money;//余额
	
	struct Account * next; //下一个账户结点的地址 
};
typedef struct Account Account; 

Account * head;//指向头结点的头指针
Account * tail;//指向尾结点的尾指针 

//英文开户 
void signUpEnglish()
{
		//申请一块堆内存空间，将其地址赋值给指针newNodeP（不理解局部变量和全局变量的同学们观看群里的视频C语言内存分配） 
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("Please enter your name：\n"); 
	scanf("%s",newNodeP->name);
	
	printf("Please enter your phone number：\n");
	scanf("%s",newNodeP->tel); 
	
	printf("Please enter your ID card：\n");
	scanf("%s",newNodeP->idCard); 
	
	printf("Please enter your account number：\n");
	scanf("%s",newNodeP->username); //账号应该是有银行给的，应该是系统生成的，思考怎么做？
	
	printf("Please enter the password：\n");
	scanf("%s",newNodeP->password); 
	
	newNodeP->money=0.0f;
	newNodeP->next=NULL;
	
	//添加结点到链表中
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	} 
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("Creating a successful\n");
	system("pause");
}

//英文登录系统 
void signInEnglish()
{
	
}

//中文开户 
void signUpChinese()
{
	//申请一块堆内存空间，将其地址赋值给指针newNodeP（不理解局部变量和全局变量的同学们观看群里的视频C语言内存分配） 
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("请输入姓名：\n"); 
	scanf("%s",newNodeP->name);
	
	printf("请输入电话：\n");
	scanf("%s",newNodeP->tel); 
	
	printf("请输入身份证：\n");
	scanf("%s",newNodeP->idCard); 
	
	printf("请输入账号：\n");
	scanf("%s",newNodeP->username); //账号应该是有银行给的，应该是系统生成的，思考怎么做？
	
	printf("请输入密码：\n");
	scanf("%s",newNodeP->password); 
	
	newNodeP->money=0.0f;
	newNodeP->next=NULL;
	
	//添加结点到链表中
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	} 
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("添加成功\n");
	system("pause");
}

//中文登录 
void signInChinese()
{
	
}

void signOut()
{
	exit(0);
}

//英文登录页面 
void showMenuEnglish()
{
	while(1)
	{
		system("cls");
		printf("Press 1 open an account\n");
		printf("Press 2 login\n");
		printf("Press 3 exit\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpEnglish();
		}
		else if(n==2)
		{
			signInEnglish();
		}
		else if(n==3)
		{
			signOut();
		}
	}
}

//中文登录页面 
void showMenuChinese()
{
	while(2)
	{
		system("cls");
		printf("按1，开户\n");
		printf("按2，登录\n");
		printf("按3，退出\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpChinese();
		}
		else if(n==2)
		{
			signInChinese();
		}
		else if(n==3)
		{
			signOut();
		}
	}
}

Account * head=NULL;//指向头结点 
Account * tail=NULL;//指向尾结点 

//加载成功返回1，否则返回0 
void loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//创建结点
			Account * newNode=(Account *)malloc(sizeof(Account)); 
			
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
			
			//添加结点到链表
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;	
			} 
			else
			{
				tail->next=newNode;
				tail=newNode; 
			}
		}
		fclose(fp);
	} 
} 

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}
}

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w"); 
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s\t%s\n",curP->username,curP->password);
			curP=curP->next; 
		}
		fclose(fp);
	}
}


int main()
{
	loadData();
	printf("Press 1, English Service\n");
	printf("按2，中文服务\n");
	int language;
	scanf("%d",&language);
	if(language==1)
	{
		showMenuEnglish(); //显示英文菜单 
	}
	else if(language==2)
	{
		showMenuChinese(); //显示中文菜单 
	}
	
	
	printLinkedList();
	
	
	saveData();
	
	return 0;
}
