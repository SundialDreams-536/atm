#include<stdio.h>
#include<stdlib.h>

struct Account
{
	char username[100];
	char password[100];	
	
	struct Account * next;
};
typedef struct Account Account;

Account * head=NULL;//ָ��ͷ��� 
Account * tail=NULL;//ָ��β��� 

//���سɹ�����1�����򷵻�0 
void loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//�������
			Account * newNode=(Account *)malloc(sizeof(Account)); 
			
			//����ʼ��
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
			
			//��ӽ�㵽����
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

void signUp()
{
	Account * newNode=(Account *)malloc(sizeof(Account));
	newNode->next=NULL;
	printf("�������˺ţ�\n");
	scanf("%s",newNode->username);
	
	printf("���������룺\n");
	scanf("%s",newNode->password);
	
	tail->next=newNode;
	tail=newNode;
	
	printf("ע��ɹ���\n");
}

int main()
{
	loadData();
	
	
	signUp();
	
	printLinkedList();
	
	
	saveData();
	
	return 0;
}
