#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int no);
int insertLast(struct node **head,int);
int createNode(struct node **);
void display(struct node**);
int insertFirst(struct node **head,struct node **tail,int);

int main(){
	int data;
	struct node *head=NULL;
	createNode(&head);
	display(&head);	
	struct node *tail=head;
	while(tail->next!=head){
		tail=tail->next;
	}
	printf("\nInsert an element at first place.\n");
	scanf("%d",&data);
	insertFirst(&head,&tail,data);
	display(&head);	
	return 0;
}
int insertFirst(struct node **head,struct node **tail,int no){
	struct node *temp=*head;
	struct node *newN=NULL;
	if(*head==NULL){
		newN=newNode(no);
		*head=newN;
		newN->next=*head;
	}else{
		newN=newNode(no);
		newN->next=*head;
		*head=newN;
		(*tail)->next= *head;
	}
	return 0;
}

int createNode(struct node **head){
	int itr1,data,num;
	printf("How many nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter element no. %d : ",itr1+1);
		scanf("%d",&data);
		insertLast(head,data);
	}
}

int insertLast(struct node **head,int no){
	struct node *temp=*head;
	struct node *newN=NULL;
	if(*head==NULL){
		newN=newNode(no);
		*head=newN;
		newN->next=*head;
	}else{
		while(temp->next!=*head){
			temp=temp->next;
		}
		newN=newNode(no);
		temp->next=newN;
		newN->next=*head;
	}
	return 0;
}

struct node* newNode(int no){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	new->data=no;
	new->next=NULL;
	return new;
}

void display(struct node **head){
	struct node *temp=*head;
	printf("\n\nOUTPUT:\n");
	while(temp->next!=*head){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
		printf("|%d|\n",temp->data);
}
