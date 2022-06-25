#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000 
#include<conio.h>

struct chuhu
{
	char idnum[20];//账户 
	char name[20];//姓名
	char idnumber[20];//省份证号
	char password[7];//密码 
	double cunkuan;//存款 
}hu[N]; 

void date();//显示当前日期
int a,a1;//主界面选择变量 
void Flag0();//选择语言界面 
void Flag1();//主界面
void Flag1English();
void Flag2();//用户界面 
void Flag2English();
void zhuce();//注册 
void signUp();
int yanzheng();//验证存单号或密码 
int verification();
void qukaun();//取款
void drawMoney(); 
void cunkaun();//存款
void saveMoney();
void zhuanzhang();//转账 
void transfer();
void xiugai();//密码修改 
void updatePassword();
void chaxun();//查找 
void enquiry();

int A,key;//开户人数 
int i;//控制密码循环 
char ch='y';//是否继续注册 
double jin;//存的钱 
int t;
char id[20],password[7];

int main()
{ 
	int a,b,t;
	Flag0(); //语言界面 
	printf("\n\t\t\t\t             请选择您需要的语言:");
	scanf("%d",&b);
	switch(b)
	{
		case 1:
		{
			Flag1();//注册、登录界面 
			do{
				printf("\n\t\t\t\t               请选择您要办理的业务：");
				scanf("%d",&a); 
				switch(a)
				{
					case 1:
					{
						zhuce();//注册函数 
						Flag1(); 
						break;
					}
					case 2:
					{
						t=yanzheng();//验证函数 
						fflush(stdin);//防止跳过数据
						Flag2();//登录函数 
						break;
					} 
					case 3:exit(0);
					break;
					default:printf("\n\n\n\t\t请您输入正确的选项!\n\n\n\n\n");	
				}
			}while(1);
		}
		case 2:
		{
			Flag1English();//注册、登录界面 
			do
			{
				printf("\n\t\t\t\t Please select the business you wish to conduct：");
				scanf("%d",&a); 
				switch(a)
				{
					case 1:
					{
						signUp();//注册 
						Flag1English(); 
						break;
					}
					case 2:
					{
						t=verification();//验证 
						fflush(stdin);///好东西，以防跳过数据
						Flag2English();
						break;
					} 
					case 3:exit(0);
					break;
					default:printf("\n\t\t\t\tPlease enter the correct option!\n\n\n\n\n");	
				}
			}while(1);
		}
		default:printf("\n\t\t\t\tPlease enter the correct option!\n\n\n\n\n");
	}
	
}


//中英文选择函数 
void Flag0()
{
	date();
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##            请选择您需要的语言              ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##   please select the language you need      ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##             1.  中文                       ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##             2.  Enlish                     ##"); 
	printf("\n\t\t\t\t################################################");	
}



//注册、登录函数 
void Flag1()
{
	date(); 
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##              自动取款机系统                ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                  1.注册                    ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                  2.登录                    ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                  3.退出                    ##"); 
	printf("\n\t\t\t\t################################################");
} 

void Flag1English()
{
	date();
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                ATM system                  ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                1.sign up                   ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                2.sign in                   ##");
	printf("\n\t\t\t\t################################################");
	printf("\n\t\t\t\t##                3.drop out                  ##"); 
	printf("\n\t\t\t\t################################################");		
}



//********************************************************************************************************************

//业务选择界面函数 
void Flag2()
{
   int a;//选择功能的变量
   char ch;
   do{
		printf("\n\n按ENTER键进入、返回主菜单 \n");
		fflush(stdin);
		scanf("%c",&ch);
		system("cls");//清屏
		date(); 
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           存款业务       请按 1            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           取款业务       请按 2            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           查询业务       请按 3            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           转账业务       请按 4            ##"); 
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           修改密码       请按 5            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           退出系统       请按 6            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t             请选择您要办理的业务：");
		fflush(stdin);
		scanf("%d",&a);
		switch(a)
		{
			case 1: 
			{ 
				system("cls");fflush(stdin);cunkaun();break;//存款
			} 
			case 2:  
			{
				system("cls");fflush(stdin);qukaun();break;//取款
			}
			case 3: 
			{
				chaxun();//查询业务
				break;
			}
			case 4:
			{
				system("cls");fflush(stdin);zhuanzhang();break;//转账 
			}
			case 5: 
			{
				system("cls");fflush(stdin);xiugai();break;//密码修改
			}
			case 6: exit(0);
			default:printf("请您输入正确的选项!：\n");
		}
	} while(1);
} 

void Flag2English()
{
   int a;//选择功能的变量
   char ch;
   do{
		printf("\n\nPress ENTER to ENTER and return to the main menu\n");
		fflush(stdin);
		scanf("%c",&ch);
		system("cls");//清屏
		date();
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           1.Deposit    business            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           2.Withdrwal  business            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           3.Enquiry    Service             ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           4.Money Transfer Service         ##"); 
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           5.Change the password            ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t##           6.Exit the system                ##");
		printf("\n\t\t\t\t################################################");
		printf("\n\t\t\t\t  Select the business you want to conduct：");
		fflush(stdin);
		scanf("%d",&a);
		switch(a)
		{
			case 1: 
			{ 
				system("cls");fflush(stdin);saveMoney();break;//存款
			} 
			case 2:  
			{
				system("cls");fflush(stdin);drawMoney();break;//取款
			}
			case 3: 
			{
				enquiry();//查询业务
				break;
			}
			case 4:
			{
				system("cls");fflush(stdin);transfer();break;//转账 
			}
			case 5: 
			{
				system("cls");fflush(stdin);updatePassword();break;//密码修改
			}
			case 6: exit(0);
			default:printf("You have entered an incorrect selection. Please enter the correct selection:\n");
		                                            	         
		}
	}while(1);
} 


//开户 
void zhuce()
{
	FILE *nchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	int i;
	do
	{
		system("cls");
		date(); 
		printf("\n\t\t\t\t##########################################################");
    	printf("\n\n\t\t\t                      请输入新储户的信息");
		fscanf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,&hu[A].cunkuan); 
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      请输入储户存单：");
		fflush(stdin);
		gets(hu[A].idnum);
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      请输入姓名：");
		fflush(stdin);
		gets(hu[A].name);
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      请输入储户密码（6位）：");
		for(i=0;i<6;i++)
		{
			fflush(stdin);
			hu[A].password[i]=getch();
			printf("*");
	    }  
		do
		{
			printf("\n\t\t\t\t##########################################################");
			printf("\n\n\t\t\t                      请输入身份证号码(18位)：");
			fflush(stdin);
			gets(hu[A].idnumber);
			if(strlen(hu[A].idnumber)!=18)//strlen 代表的意思
			printf("\n\t\t\t\t       输入错误！\t请正确输入身份证！");
			for(i=0;i<A;i++)
			if(strcmp(hu[A].idnumber,hu[i].idnumber)==0&&strcmp(hu[A].name,hu[i].name)==0) 
			break;
			if(i<A)
			printf("\n\t\t\t\t       前面已经有人用过此身份证注册，请重新输入身份证号：\n");
		}while((strlen(hu[A].idnumber)!=18)||(strcmp(hu[A].idnumber,hu[i].idnumber)==0)&&(strcmp(hu[A].name,hu[i].name)!=0) );
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t                              请输入存储的金额：");
		fflush(stdin);
		scanf("%lf",&hu[A].cunkuan);	
		fprintf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
		A++;
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      是否继续是(y)/否(n):");
		fflush(stdin);
		scanf("%c",&ch); 
	}while(ch=='y'||ch=='Y');
	printf("注册成功！");
	system("cls");
	fclose(nchuhu);
}

void signUp()
{
	FILE *nchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	int i;
	do
	{
		system("cls");
		date(); 
		printf("\n\t\t\t\t##########################################################");
    	printf("\n\n\t\t\t                      Please enter new user information");
		fscanf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,&hu[A].cunkuan); 
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      Please enter your account：");
		fflush(stdin);
		gets(hu[A].idnum);
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      Please enter your name：");
		fflush(stdin);
		gets(hu[A].name);
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      Please enter the password(6)：");
		for(i=0;i<6;i++)
		{
			fflush(stdin);
			hu[A].password[i]=getch();
			printf("*");
	    } 
 
		do
		{
			printf("\n\t\t\t\t##########################################################");
			printf("\n\n\t\t\t                      Please enter your ID card(18)：");
			fflush(stdin);
			gets(hu[A].idnumber);
			if(strlen(hu[A].idnumber)!=18)//strlen 代表的意思
			printf("\n\t\t\t\t       input error！");
			for(i=0;i<A;i++)
			if(strcmp(hu[A].idnumber,hu[i].idnumber)==0&&strcmp(hu[A].name,hu[i].name)==0) 
			break;
			if(i<A)
			printf("\n\t\t\t\t       Duplicate, please re-enter：\n");
		}while((strlen(hu[A].idnumber)!=18)||(strcmp(hu[A].idnumber,hu[i].idnumber)==0)&&(strcmp(hu[A].name,hu[i].name)!=0) );
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t                              Please enter the amount to be stored：");
		fflush(stdin);
		scanf("%lf",&hu[A].cunkuan);	
		fprintf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
		A++;
		printf("\n\t\t\t\t##########################################################");
		printf("\n\n\t\t\t                      Whether or not to continue YES(y)/NO(n):");
		fflush(stdin);
		scanf("%c",&ch); 
	}while(ch=='y'||ch=='Y');
	printf("registered successfully！");
	system("cls");
	fclose(nchuhu);
}



//验证存单号或密码 
int yanzheng()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	int count=0;
	char id[20];
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	do
	{
		system("cls");
		
		printf("\t\t             ☆   存单号或者密码有误自动返回   ☆         \n");
		printf("\n\n\n\t\t      请输入您的存单号：  ");
		scanf("%s",id);
		printf("\n\n\n\t\t      请输入您的密码：  ");
		for(i=0;i<6;i++)
		{
			fflush(stdin);
		    password[i]=getch();
			printf("*");
		} 
		password[6]='\0';
		fflush(stdin);
		scanf("%c",&ch);
		printf("\n\n\t\t");
		for(i=0;i<99;i++)
		{
			if(strcmp(id,hu[i].idnum)==0&&strcmp(password,hu[i].password)==0)
			{
				fclose(fchuhu);
				return 0;
			}
		}		
	}while(count==0);
	fclose(fchuhu);
}

int verification()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	int count=0;
	char id[20];
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	do
	{
		system("cls");
		printf("\t\t||The deposit slip number or password is returned automatically in error  ||\n");
		printf("\n\n\n\t\t  Please enter your deposit slip number：  \n");
		scanf("%s",id);
		printf("\n\n\n\t\t  Please enter your password：  \n");
		for(i=0;i<6;i++)
		{
			fflush(stdin);
		    password[i]=getch();
			printf("*");
		} 
		password[6]='\0';
		fflush(stdin);
		scanf("%c",&ch);
		printf("\n\n\t\t");
		for(i=0;i<99;i++)
		{
			if(strcmp(id,hu[i].idnum)==0&&strcmp(password,hu[i].password)==0)
			{
				fclose(fchuhu);
				return 0;
			}
		}	
	}while(count==0);
	fclose(fchuhu);
	return count;
}


//存款
void cunkaun()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	FILE *achuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","w");
	char id[20];int i;
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}	
	int a;
	date();
	printf("\n\t\t\t\t\t\t            请再次输入并确认存单：");
	scanf("%s",id);
	for(i=0;i<=100;i++)
	{
		if(strcmp(id,hu[i].idnum)==0)
		{		
			printf("\n\n"); 
		 	printf("\n\t\t\t\t#################################################################");
		 	printf("\n\t\t\t\t#                          *存款金额*                           #");
		 	printf("\n\t\t\t\t#                                                               #");
		 	printf("\n\t\t\t\t#         1、200        2、400        3、600        4、800      #");
		 	printf("\n\t\t\t\t#                                                               #");
		    printf("\n\t\t\t\t#         5、1000       6、2000       7、4000       8、6000     #");
		 	printf("\n\t\t\t\t#                                                               #");
		 	printf("\n\t\t\t\t#                                                               #");
		 	printf("\n\t\t\t\t#################################################################");
		 	printf("\n\t\t\t\t\t\t          请输入你的取款金额：");
		 	scanf("%d",&a);
		 	switch(a)
			{
		 		case 1:
				{
					jin=200;
			 		printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 2: 
				{
					jin=400;
			 		printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功");  
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 3:
				{
					jin=600;
					printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功");  
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 4:
				{
					jin=800;
					printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 5:
				{
					jin=1000;
		 			printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 6:
				{   
					jin=2000;
			 		printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 7:
				{
					jin=4000;
					printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 8:
				{
					jin=6000;
					printf("\t\t\t存款%lf元",jin);
					printf("\n\n\n\t\t\t存款成功"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				default:printf("\n\n\n\t\t\t您的选择金额不在服务范围内！！！\n\n\n\t\t\t请重新选择业务："); 
					 
			}			
			fclose(fchuhu);
		    fclose(achuhu);
	        system("D:/重庆工程学院/计算机类/atm.txt.txt");
	        rename("D:/重庆工程学院/计算机类/atm.txt","D:/重庆工程学院/计算机类/atm.txt");//rename(旧的，新的） 
	        break;		
		}
	}
}


void saveMoney()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	FILE *achuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","w");
	char id[20];int i;
	if(!fchuhu) printf("The file can not be opened：");
	if(!achuhu) printf("The file can not be created");
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	int a; 
	printf("\n\n\t\t##Please re-enter and confirm the certificate of deposit：");
	scanf("%s",id);
	for(i=0;i<=100;i++)
	{
		if(strcmp(id,hu[i].idnum)==0)
		{		
			printf("\n\n"); 
		 	printf("\t\t||================================================================||\n");
		 	printf("\t\t||                       *Amount of deposit*                      ||\n");
		 	printf("\t\t||                                                                ||\n");
		 	printf("\t\t||         1、200        2、400        3、600        4、800       ||\n");
		 	printf("\t\t||                                                                ||\n");
		 	printf("\t\t||                                                                ||\n");
		    printf("\t\t||         5、1000       6、2000      7、4000        8、6000      ||\n");
		 	printf("\t\t||                                                                ||\n");
		 	printf("\t\t||================================================================||\n");
		 	printf("\n\n\t\t\tPlease enter your withdrawal amount：");
		 	scanf("%d",&a);
		 	switch(a)
			{
				case 1:
				{
					jin=200;
			 		printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 2:
				{
					jin=400;
			 		printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success");  
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 3:
				{
					jin=600;
					printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success");  
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 4:
				{
					jin=800;
					printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 5:
				{
					jin=1000;
			 		printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 6:
				{
					jin=2000;
			 		printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 7:
				{
					jin=4000;
					printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 8:
				{
					jin=6000;
					printf("\t\t\tDeposit %lf yuan",jin);
					printf("\n\n\n\t\t\tDeposit success"); 
					hu[i].cunkuan+=jin;
					printf("\n\n\t\t\tYour balance is:%lf yuan",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				default:printf("\n\n\n\t\t\tYour selection amount is not covered by the service！！！\n\n\n\t\t\tPlease re-select business：\n"); 					 
			}			
			fclose(fchuhu);
	        fclose(achuhu);
            system("D:/重庆工程学院/计算机类/atm.txt");
            rename("D:/重庆工程学院/计算机类/atm.txt","D:/重庆工程学院/计算机类/atm.txt");//rename(旧的，新的） 
            break;		
		}
	}
}


//取款 
void qukaun()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	FILE *achuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","w");
	int i,a;
	char id[20];
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	date();
	printf("\n\t\t\t\t\t\t            请再次输入并确认存单：");
	scanf("%s",id);
	for(i=0;i<=99;i++)
	{
	 	if(strcmp(id,hu[i].idnum)==0)
		{
			printf("\n\n"); 
		 	printf("\n\t\t\t\t#################################################################");
		 	printf("\n\t\t\t\t#                          *存款金额*                           #");
		 	printf("\n\t\t\t\t#                                                               #");
		 	printf("\n\t\t\t\t#         1、200        2、400        3、600        4、800      #");
		 	printf("\n\t\t\t\t#                                                               #");
		    printf("\n\t\t\t\t#         5、1000       6、2000       7、4000       8、6000     #");
		 	printf("\n\t\t\t\t#                                                               #");
		 	printf("\n\t\t\t\t#                                                               #");
		 	printf("\n\t\t\t\t#################################################################");
		 	printf("\n\t\t\t\t\t\t          请输入你的取款金额：");
		 	scanf("%d",&a);
		 	switch(a)
			{
		 		case 1:
				{
					jin=200;
			 		printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功"); 
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 2:
				{
					jin=400;
			 		printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功"); 
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 3:
				{
					jin=600;
					printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功");  
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 4:
				{
					jin=800;
					printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功"); 
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 5:
				{
					jin=1000;
				 	printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功"); 
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 6:
				{
					jin=2000;
		 			printf("\t\t\t取出%lf元",jin);
				    printf("\n\n\n\t\t\t取款成功"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 7:
				{
					jin=4000;
					printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功"); 
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 8:
				{
					jin=6000;
					printf("\t\t\t取出%lf元",jin);
					printf("\n\n\n\t\t\t取款成功"); 
					hu[i].cunkuan-=jin;
					printf("\n\n\t\t\t您的余额为：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				default:printf("\n\n\n\t\t\t您的选择金额不在服务范围内！！！\n\n\n\t\t\t请重新选择业务："); 
					 
			}
			fclose(fchuhu);
     		fclose(achuhu);
            system("D:/重庆工程学院/计算机类/atm.txt");
            rename("D:/重庆工程学院/计算机类/atm.txt","D:/重庆工程学院/计算机类/atm.txt");
			break;
        }

	}

}

void drawMoney()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	FILE *achuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","w");
	int i,a;
	char id[20];
	if(!fchuhu) printf("The file can not be opened：\n");
	if(!achuhu) printf("A new file can not be created：");
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
 	date();
 	printf("\n\n\t\tPlease re-enter and confirm the certificate of deposit：");
 	scanf("%s",id);
 	for(i=0;i<=99;i++)
	{
 		if(strcmp(id,hu[i].idnum)==0)
		{
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                      *Withdrawal Amount*                       ||\n");
	 		printf("\t\t||         1、200        2、400        3、600        4、800       ||\n");
	 		printf("\t\t||                                                                ||\n");
	 	 	printf("\t\t||         5、1000       6、2000       7、4000       8、6000      ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\n\n\t\t\tPlease enter your withdrawal amount：\n");
	 		scanf("%d",&a);
	 		switch(a)
			{
	 			case 1:
				{
					jin=200;
		 			printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 2:
				{
					jin=400;
		 			printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 3:
				{
					jin=600;
					printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^");  
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 4:
				{
				 	jin=800;
					printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
			 	}
				case 5:
				{
					jin=1000;
		 			printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 6:
				{
					jin=2000;
		 		    printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
					fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 7:
				{
					jin=4000;
					printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				case 8:
				{
				 	jin=6000;
					printf("\t\t\tGets the %lf yuan",jin);
				    printf("\n\n\n\t\t\t^^^^The withdrawal was successful^^^^"); 
				    hu[i].cunkuan-=jin;
				    printf("\n\n\t\t\t$Your balance is：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				}
				default:printf("\n\n\n\t\t\tYour selection amount is not covered by the service！！！\n\n\n\t\t\tPlease re-select business：\n"); 	 
			}
			fclose(fchuhu);
 	        fclose(achuhu);
         	system("D:/重庆工程学院/计算机类/atm.txt");
         	rename("D:/重庆工程学院/计算机类/atm.txt","D:/重庆工程学院/计算机类/atm.txt");
			break;
		}

	}
}


//转账
void transfer()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r+");
	int i;
	char id[20];
	if(!fchuhu) printf("The file can not be opened：");
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	date();
	printf("\n\n\t\tPlease enter the deposit slip number of the transferor：");
	scanf("%s",id);
	for(i=0;i<=99;i++)
	{
	 	if(strcmp(id,hu[i].idnum)==0)
		{
			printf("\n\n\t\tPlease enter the amount to be transferred：");
			scanf("%lf",&jin);
			printf("\n\n\t\t  Please confirm the number：%lf",jin); 
			hu[i].cunkuan+=jin;
			printf("\n\n\nThe transfer was successful"); 
			fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
			fclose(fchuhu);
			fclose(fchuhu);
			break;
		}
	}
} 

void zhuanzhang()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r+");
	int i;
	char id[20];
	for(i=0;i<=100;i++)
	{
	    fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}	
	date();
	printf("\n\n\t\t请输入转账人的存单号：");
	scanf("%s",id);
	for(i=0;i<=99;i++)
	{
		if(strcmp(id,hu[i].idnum)==0)
		{
			printf("\n\n\t\t请输入要转账的金额：");
			scanf("%lf",&jin);
			printf("\n\n\t\t请确认数目：%lf",jin); 
			hu[i].cunkuan+=jin;
			printf("\n\n\n转账成功"); 
			fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
			fclose(fchuhu);
			break;
		}
	}
}


//修改密码 
void xiugai()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	FILE *achuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","w");
	int j,i;
	char id[20];
	for(i=0;i<=100;i++)
	{
    	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	date();
	printf("\n\n\t\t请再次输入并确认存单：");
	scanf("%s",id);
	for(i=0;i<=99;i++)
	{
		if(strcmp(id,hu[i].idnum)==0)
		{ 
			printf("请输入新的密码：\n");
			printf("\n\t\t储户密码（6位）：");
			for(j=0;j<6;j++)
			{
				fflush(stdin);
				hu[i].password[j]=getch();
				printf("*");
			} 
			printf("\n\n\t\t新的密码：%s\n",hu[i].password);				
			printf("\n\n\t\t修改成功"); 
			fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
			fclose(fchuhu);
			fclose(achuhu);
			system("D:/重庆工程学院/计算机类/atm.txt");
			rename("D:/重庆工程学院/计算机类/atm.txt","D:/重庆工程学院/计算机类/atm.txt");
			break;
	    }
	}
}

void updatePassword()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	FILE *achuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","w");
	int j,i;
	char id[9];
	if(!fchuhu) printf("The file can not be opened：\n");
	if(!achuhu) printf("A new file can not be created：");
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	date();
	printf("\n\n\t\tPlease re-enter and confirm the certificate of deposit：\n");
	scanf("%s",id);
	for(i=0;i<=99;i++)
	{
		if(strcmp(id,hu[i].idnum)==0)
		{
			printf("Please enter a new password：\n");
			printf("\n\t\tUser Password (6 digits)：");
			for(j=0;j<6;j++)
			{
				fflush(stdin);
				hu[i].password[j]=getch();
				printf("*");	
			} 
			printf("\n\n\t\t新的密码：%s\n",hu[i].password);
			
			printf("\n\n\t\tModification successful"); 
			fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
			fclose(fchuhu);
			fclose(achuhu);
			system("D:/重庆工程学院/计算机类/atm.txt");
			rename("D:/重庆工程学院/计算机类/atm.txt","D:/重庆工程学院/计算机类/atm.txt");
			break;
		}	
   }
}


//查询信息 
void chaxun()
{
	FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
	int i,n=0;
	char fnumb[20];
	system("cls");
	for(i=0;i<=100;i++)
	{
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
	}
	date();
	printf("\n\n\n\t\t\t\t\t请输入你的存单号：");
	scanf("%s",fnumb);
	printf("\n\n\n");
	printf("\t\t\t\t\t您的个人信息如下：");
	printf("\n\n");
	for(i=0;i<=99;i++)
		if(strcmp(fnumb,hu[i].idnum)==0)
		{
			printf("存单号：%s\t姓名：%s\t身份证：%s\t密码：%s\t存款金额：%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
			n=1;
			fclose(fchuhu);
			system("pause"); 
            break; 
		}
    if(n==0) printf("此账单不存在！！！\n");
    fclose(fchuhu);
}

void enquiry()
{
		FILE *fchuhu=fopen("D:/重庆工程学院/计算机类/atm.txt","r");
		int i,n=0;
		char fnumb[20];
		system("cls");
		for(i=0;i<=100;i++)
		{
			fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,&hu[i].cunkuan);
		}
		date();
		printf("\n\n\n\t\t\t\t\t Please enter your deposit slip number：");
		scanf("%s",fnumb);
		printf("\n\n\n");
		printf("\t\t\t\t\tYour personal information is as follows：");
		printf("\n\n");
		for(i=0;i<=99;i++)
			if(strcmp(fnumb,hu[i].idnum)==0)
			{
				printf("Certificate number：%s\tname：%s\tid card：%s\tpassord：%s\tAmount of deposit：%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
				n=1;
				fclose(fchuhu);
				system("pause"); 
	            break; 
			}
	    if(n==0) printf("This bill does not exist！！！\n");
	    fclose(fchuhu);
}


//显示当前日期 
void date()
{
	printf("当前日期：");
	system("date/t");
	printf("当前时间：");
	system("time/t"); 

}
