#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;	
};

int insertFirst(struct node**,int);
struct node* newNode(int);
void display(struct node**);

int main(){
	struct node* head=NULL;
	int itr1=0,num,no;
	printf("How many nodes to be created.\n");
	scanf("%d",&num);

	for(itr1=0;itr1<num;itr1++){
		printf("Element no. %d :",itr1+1);
		scanf("%d",&no);
		insertFirst(&head,no);
	}
	display(&head);
	return 0;
}

int insertFirst(struct node** Head,int no){
	struct node* temp=NULL;
	if(*Head==NULL){
		temp=newNode(no);
		*Head=temp;
	}else{
		temp=newNode(no);
		temp->prev=NULL;
		temp->next=*Head;
		*Head=temp;		
	}
}

struct node* newNode(int no){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Was not able to allocate memory.\n");
		return 0;
	}
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=no;
	return temp;
}

void display(struct node** Head){
	struct node *temp=*Head;
	if(*Head==NULL){
		printf("Nothing to display.\n");
		return;
	}else{
		while(temp->next!=NULL){
			printf("|%d|->",temp->data);
			temp=temp->next;
		}
			printf("|%d|\n",temp->data);
	}
}
