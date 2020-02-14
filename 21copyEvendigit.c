#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void display(struct node**);
void createNode(struct node**);
void reverse(struct node**);
int count(struct node**);
void LLcopyLastnEl(struct node**,struct node**);
int main(){
	struct node *head=NULL;
	struct node *dest=NULL;
	int itr1,num,from;
	printf("Enter no. of nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		createNode(&head);	
	}
	printf("Input src Linked List: ");
	display(&head);
		LLcopyLastnEl(&head,&dest);
	printf("\nOutput destination Linked List: ");
	display(&dest);
	return 0;
}
int count(struct node **head){
	struct node *temp=*head;
	int cnt=1;
	if(*head==NULL){
		return 0;
	}
	while(temp->next!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
void LLcopyLastnEl(struct node **head,struct node **dest){
	struct node *htemp=*head;
	int itr1,itr2;
	int cnt=count(head);
	int arr[cnt];
	for(itr1=0;itr1<cnt;itr1++){
		arr[itr1]=htemp->data;
		htemp=htemp->next;
	}
	int no,sum,no1,prime=0;
	struct node *dtemp=*dest;
	struct node *newNode=NULL;
	for(itr1=0;itr1<cnt;itr1++){
		no=arr[itr1];
		sum=0;
			while(no>0){
				no1=no%10;
				sum=sum+no1;
				no=no/10;
			}
		if(sum%2==0){
			dtemp=*dest;
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=arr[itr1];
			newNode->next=NULL;
			if(*dest==NULL){
				*dest=newNode;
			}else{
				while(dtemp->next!=NULL){
					dtemp=dtemp->next;
				}
				dtemp->next=newNode;
			}
		}
	}
}
void createNode(struct node **head){
	struct node *temp=*head;
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
void display(struct node **head){
	struct node *temp=*head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|",temp->data);
}
void reverse(struct node **head){
	struct node *first=*head;
	struct node *next1=*head;
	struct node *temp=NULL;
	while(first->next!=NULL){
		next1=first->next;
		first->next=temp;
		temp=first;
		first=next1;
	}
	first->next=temp;
	*head=first;	
}

