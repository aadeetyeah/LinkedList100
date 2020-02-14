#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int concatList(struct node**,struct node**);
int insertLast(struct node**,int);
void display(struct node*);
int main(){
	struct node *head1=NULL,*head2=NULL;
	int itr1,num,data;
	printf("Enter number of nodes to be created for List -1.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter data of node %d\n",itr1+1);
		scanf(" %d",&data);
		insertLast(&head1,data);
	}
	printf("Enter number of nodes to be created for List -2.\n");
	scanf("	%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter data of node %d\n",itr1+1);
		scanf(" %d",&data);
		insertLast(&head2,data);
	}
	printf("Input source linked list: ");
	display(head1);
	printf("\nInput destination linked list: ");
	display(head2);
	concatList(&head2,&head1);
	printf("\nOutput destination linked list: ");
	display(head2);
	printf("\n");
	return 0;
}
int insertLast(struct node **head,int data){
	struct node *temp=*head;
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	if(*head==NULL){
		*head=newNode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	return 0;
}
int concatList(struct node **src,struct node **dest){
	struct node *temp=*src;
	struct node *temp2=*dest;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp2->next!=NULL){
		insertLast(src,temp2->data);
		temp2=temp2->next;
	}
	insertLast(src,temp2->data);
	return 0;
}
void display(struct node *head){
	struct node *temp=head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}
