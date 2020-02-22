#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* newNode(int no);
int insertFirst(struct node** src,struct node** tail,int no);
int insertLast(struct node** src,struct node** tail,int no);
void display(struct node**);
struct node* findTail(struct node**);

int main(){
	int itr1,num,data;
	struct node* head=NULL,*tail=NULL;
	printf("Insert number of nodes to be created.\n");
	scanf("%d",&num);
	for(itr1=0;itr1<num;itr1++){
		printf("Enter element %d: ",itr1+1);
		scanf("%d",&data);
		insertLast(&head,&tail,data);
	}
	display(&head);
	return 0;
}

int insertLast(struct node** src,struct node** tail,int no){
	struct node* temp1=*src;
	struct node* Ttemp=*tail;
	struct node* temp2;
	if(*src==NULL){
		temp2=newNode(no);
		temp2->next=temp2->prev=temp2;
		*src=temp2;
		*tail=temp2->prev;	
	}else{
		temp2=newNode(no);
		temp2->next=Ttemp->next;
		Ttemp->next=temp2;
		temp2->prev=Ttemp;
		(*src)->prev=temp2;
		*tail=temp2;
	}
}

int insertFirst(struct node** src,struct node** tail,int no){
	struct node* temp1=*src;
	struct node* temp2;
	if(*src==NULL){
		temp1=newNode(no);
		temp1->prev=temp1->next=temp1;
		*src=temp1;
		*tail=temp1->prev;
		return 0;
	}else{
		temp2=newNode(no);
		temp2->next=temp1;
		temp2->prev=temp1->prev;
		temp1->prev=temp2;
		temp2->prev->next=temp2;
		*src=temp2;
		*tail=temp2->prev;
	}
}

struct node* findTail(struct node** head){
	struct node* temp=*head;
	if(*head==NULL){
		printf("list is empty.\n");
		return NULL;
	}
	while(temp->next!=*head){
		temp=temp->next;
	}
	return temp;
}

void display(struct node** head){
	struct node* temp=*head;
	if(*head==NULL){
		printf("List is empty.\n");
		return;
	}
	printf("Output:\n");
	while(temp->next!=*head){
		printf("|%d|<=>",temp->data);
		temp=temp->next;
	}
		printf("|%d|\n",temp->data);
}

struct node* newNode(int no){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=no;
	new->next=new->prev=NULL;
	return new;
}

