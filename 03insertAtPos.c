#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int count(struct node **head);
int insertLast(struct node **head,int no);
int insertFirst(struct node **head,int no);
int insertAtPos(struct node **head,int no,int pos);
void displayLL(struct node**);
int main(){
	struct node *head=NULL;
	int itr1,num,no,pos;
	printf("Enter number of nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=1;itr1<=num;itr1++){
		printf("Enter data of node %d.\n",itr1);
		scanf(" %d",&no);
		insertLast(&head,no);
	}
	displayLL(&head);
	printf("Enter position of newNode\n");
	scanf(" %d",&pos);
	printf("Enter data of pos node.\n");
	scanf(" %d",&no);
	insertAtPos(&head,no,pos);
	displayLL(&head);
	return 0;
}
int count(struct node **head){
	int cnt=1;
	struct node *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
int insertLast(struct node **head,int no){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=no;
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
		newNode->next=NULL;
	}else{
		struct node *temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	return 0;
}
int insertFirst(struct node **head,int no){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=no;
	if(*head==NULL){
		*head=newNode;
		newNode->next=NULL;
	}else{
		newNode->next=*head;
		*head=newNode;
	}
	return 0;
}
int insertAtPos(struct node **head,int no,int pos){
	int cnt=0;
	struct node *temp=*head;
	cnt=count(head);
	if(pos==1){
		insertFirst(head,no);
	}else if(cnt+1==pos){
		insertLast(head,no);
	}else{	
		struct node *newNode=(struct node*)malloc(sizeof(struct node));
		while(pos-1>1){
			temp=temp->next;
			pos--;
		}
		newNode->data=no;
		newNode->next=temp->next;
		temp->next=newNode;
	}
	return 0;
}
void displayLL(struct node **head){
	struct node *temp=*head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}
